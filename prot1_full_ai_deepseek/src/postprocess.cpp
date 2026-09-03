#include "postprocess.h"

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>

namespace postprocess {
namespace {

const char kRngChars[] = "abcdefghijklmnopqrstuvwxyz0123456789";

std::string randTag(std::mt19937_64& rng, int n) {
    std::string r;
    for (int i = 0; i < n; ++i) r += kRngChars[rng() % 36];
    return r;
}

bool isIdChar(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9') || ch == '_';
}

// ---------------------------------------------------------------------------
// Shared source scanner: skips comments, char literals, string literals and
// preprocessor lines. Used to locate string literals (for encryption) and
// integer literals (for constant folding noise) safely.
// ---------------------------------------------------------------------------

struct StringHit {
    size_t start;       // index of opening quote
    size_t end;         // index of closing quote
    std::string raw;    // content between quotes (escape sequences intact)
};

std::vector<StringHit> findStrings(const std::string& c) {
    std::vector<StringHit> hits;
    size_t n = c.size();
    bool lineStart = true;
    bool preproc = false;
    size_t i = 0;
    while (i < n) {
        if (lineStart) {
            size_t j = i;
            while (j < n && (c[j] == ' ' || c[j] == '\t')) ++j;
            preproc = (j < n && c[j] == '#');
        }
        char ch = c[i];
        if (ch == '\n') { lineStart = true; preproc = false; ++i; continue; }
        lineStart = false;
        if (preproc) { while (i < n && c[i] != '\n') ++i; continue; }
        if (ch == '/' && i + 1 < n && c[i + 1] == '/') {
            while (i < n && c[i] != '\n') ++i;
            continue;
        }
        if (ch == '/' && i + 1 < n && c[i + 1] == '*') {
            i += 2;
            while (i + 1 < n && !(c[i] == '*' && c[i + 1] == '/')) ++i;
            i += 2;
            continue;
        }
        if (ch == '\'') {
            ++i;
            while (i < n) {
                if (c[i] == '\\') { i = (i + 1 < n) ? i + 2 : i + 1; continue; }
                if (c[i] == '\'') { ++i; break; }
                ++i;
            }
            continue;
        }
        if (ch == '"') {
            size_t start = i;
            ++i;
            std::string raw;
            while (i < n) {
                if (c[i] == '\\') {
                    raw += c[i];
                    if (i + 1 < n) raw += c[i + 1];
                    i = (i + 1 < n) ? i + 2 : i + 1;
                    continue;
                }
                if (c[i] == '"') break;
                raw += c[i];
                ++i;
            }
            size_t end = i;
            if (i < n) ++i;
            hits.push_back({start, end, raw});
            continue;
        }
        ++i;
    }
    return hits;
}

// Decodes C escape sequences in a string literal's raw content so we encrypt
// the actual runtime bytes (a `\\` in the source must become a single `\`).
std::string unescapeC(const std::string& raw) {
    std::string out;
    size_t i = 0, n = raw.size();
    auto hexVal = [](char ch) -> int {
        if (ch >= '0' && ch <= '9') return ch - '0';
        if (ch >= 'a' && ch <= 'f') return ch - 'a' + 10;
        if (ch >= 'A' && ch <= 'F') return ch - 'A' + 10;
        return -1;
    };
    while (i < n) {
        char ch = raw[i];
        if (ch != '\\' || i + 1 >= n) { out += ch; ++i; continue; }
        char e = raw[i + 1];
        switch (e) {
            case 'n': out += '\n'; i += 2; break;
            case 't': out += '\t'; i += 2; break;
            case 'r': out += '\r'; i += 2; break;
            case 'a': out += '\a'; i += 2; break;
            case 'b': out += '\b'; i += 2; break;
            case 'f': out += '\f'; i += 2; break;
            case 'v': out += '\v'; i += 2; break;
            case '0': out += '\0'; i += 2; break;
            case '\\': out += '\\'; i += 2; break;
            case '"': out += '"'; i += 2; break;
            case '\'': out += '\''; i += 2; break;
            case 'x': {
                if (i + 3 < n) {
                    int hi = hexVal(raw[i + 2]);
                    int lo = hexVal(raw[i + 3]);
                    if (hi >= 0 && lo >= 0) {
                        out += static_cast<char>((hi << 4) | lo);
                        i += 4;
                        break;
                    }
                }
                out += 'x';
                i += 2;
                break;
            }
            default:
                out += e;
                i += 2;
                break;
        }
    }
    return out;
}

// ---------------------------------------------------------------------------
// Pass 5: string encryption.
// ---------------------------------------------------------------------------

void encryptStrings(std::string& c, std::mt19937_64& rng) {
    std::vector<StringHit> hits = findStrings(c);

    struct Enc {
        StringHit hit;
        int idx;
        int key;
    };
    std::vector<Enc> encs;
    std::string defs;
    int idx = 0;
    for (const StringHit& h : hits) {
        // Format strings must stay plaintext so printf/snprintf parse them.
        if (h.raw.find('%') != std::string::npos) continue;
        std::string bytes = unescapeC(h.raw);
        if (bytes.empty()) continue;

        int key = 1 + static_cast<int>(rng() % 255);
        std::string blob;
        for (size_t k = 0; k < bytes.size(); ++k) {
            if (k) blob += ", ";
            unsigned char b = static_cast<unsigned char>(bytes[k]) ^ static_cast<unsigned char>(key);
            char tmp[8];
            std::snprintf(tmp, sizeof tmp, "0x%02X", (unsigned)b);
            blob += tmp;
        }
        std::string n = std::to_string(idx);
        // The array is `volatile` so GCC/Clang cannot constant-fold the XOR
        // loop back into the plaintext string at compile time -- without this,
        // -O2 materializes the plaintext in .data and defeats the encryption.
        defs += "static const volatile uint8_t j_enc_" + n + "[] = {" + blob + "};\n";
        defs += "static const char* j_dc_" + n + "(void) {\n";
        defs += "    static char j_rb[" + std::to_string(bytes.size() + 1) + "];\n";
        defs += "    for (int j_i = 0; j_i < " + std::to_string(bytes.size()) + "; j_i++) j_rb[j_i] = j_enc_" + n + "[j_i] ^ " + std::to_string(key) + ";\n";
        defs += "    j_rb[" + std::to_string(bytes.size()) + "] = 0;\n";
        defs += "    return j_rb;\n";
        defs += "}\n\n";
        encs.push_back({h, idx, key});
        ++idx;
    }
    if (encs.empty()) return;

    // Replace literals end-to-start so earlier offsets stay valid.
    for (auto it = encs.rbegin(); it != encs.rend(); ++it) {
        size_t start = it->hit.start;
        size_t len = it->hit.end - it->hit.start + 1;
        c.replace(start, len, "j_dc_" + std::to_string(it->idx) + "()");
    }

    // Insert decryptor definitions right after the includes / runtime helpers,
    // before the first runtime function, so every use in the file is preceded
    // by a definition (and stdint.h's uint8_t is already in scope).
    size_t pos = c.find("static int32_t j_str_len");
    if (pos == std::string::npos) pos = c.find("\nstatic ");
    if (pos == std::string::npos) pos = 0;
    c.insert(pos, defs);
}

// ---------------------------------------------------------------------------
// Pass 6: constant folding noise.
// ---------------------------------------------------------------------------

void constantNoise(std::string& c, std::mt19937_64& rng) {
    size_t n = c.size();
    bool lineStart = true;
    bool preproc = false;
    std::vector<std::pair<size_t, size_t>> literals;
    size_t i = 0;
    while (i < n) {
        if (lineStart) {
            size_t j = i;
            while (j < n && (c[j] == ' ' || c[j] == '\t')) ++j;
            preproc = (j < n && c[j] == '#');
        }
        char ch = c[i];
        if (ch == '\n') { lineStart = true; preproc = false; ++i; continue; }
        lineStart = false;
        if (preproc) { while (i < n && c[i] != '\n') ++i; continue; }
        if (ch == '/' && i + 1 < n && c[i + 1] == '/') {
            while (i < n && c[i] != '\n') ++i;
            continue;
        }
        if (ch == '/' && i + 1 < n && c[i + 1] == '*') {
            i += 2;
            while (i + 1 < n && !(c[i] == '*' && c[i + 1] == '/')) ++i;
            i += 2;
            continue;
        }
        if (ch == '\'') {
            ++i;
            while (i < n) {
                if (c[i] == '\\') { i = (i + 1 < n) ? i + 2 : i + 1; continue; }
                if (c[i] == '\'') { ++i; break; }
                ++i;
            }
            continue;
        }
        if (ch == '"') {
            ++i;
            while (i < n) {
                if (c[i] == '\\') { i = (i + 1 < n) ? i + 2 : i + 1; continue; }
                if (c[i] == '"') { ++i; break; }
                ++i;
            }
            continue;
        }
        if (ch >= '0' && ch <= '9') {
            size_t s = i;
            while (i < n && c[i] >= '0' && c[i] <= '9') ++i;
            literals.push_back({s, i});
            continue;
        }
        ++i;
    }

    for (auto it = literals.rbegin(); it != literals.rend(); ++it) {
        size_t s = it->first, e = it->second;
        if (s > 0 && isIdChar(c[s - 1])) continue;          // identifier / hex prefix
        if (e < n && isIdChar(c[e])) continue;               // suffix (100L, 0x..)
        if (e < n && (c[e] == '.' || c[e] == 'e' || c[e] == 'E' || c[e] == 'f' || c[e] == 'F')) continue;  // floats
        {
            size_t j = s;
            while (j > 0 && (c[j - 1] == ' ' || c[j - 1] == '\t')) --j;
            size_t k = j;
            while (k > 0 && isIdChar(c[k - 1])) --k;
            if (j - k == 4 && c.compare(k, 4, "case") == 0) continue;  // switch labels
        }
        if (rng() % 2) continue;  // ~50% of literals get noise

        int64_t v = std::strtoll(c.substr(s, e - s).c_str(), nullptr, 10);
        if (v < 0) continue;
        int64_t a = static_cast<int64_t>(rng() % (static_cast<uint64_t>(v) + 1));
        int64_t b = v - a;
        std::string rep;
        if (rng() % 2) {
            int64_t k = static_cast<int64_t>(rng() % 10000);
            rep = "((" + std::to_string(a) + " + " + std::to_string(b) + ") ^ (" +
                  std::to_string(k) + " ^ " + std::to_string(k) + "))";
        } else {
            rep = "(" + std::to_string(a) + " + " + std::to_string(b) + ")";
        }
        c.replace(s, e - s, rep);
    }
}

// ---------------------------------------------------------------------------
// Pass 8: junk function injection (2..5 unused static functions).
// ---------------------------------------------------------------------------

std::string junkFunction(std::mt19937_64& rng, const std::string& name) {
    switch (rng() % 3) {
        case 0:
            return "__attribute__((used)) static int32_t " + name + "(int32_t j_a, int32_t j_b) {\n"
                   "    int32_t j_r = 0;\n"
                   "    for (int32_t j_i = 0; j_i < j_a; j_i++) {\n"
                   "        j_r = j_r + j_b;\n"
                   "        if (j_r > 1000) j_r = j_r - 1000;\n"
                   "    }\n"
                   "    return j_r;\n"
                   "}\n";
        case 1:
            return "__attribute__((used)) static int32_t " + name + "(int32_t j_n) {\n"
                   "    int32_t j_s = 0;\n"
                   "    int32_t j_i = 1;\n"
                   "    while (j_i <= j_n) {\n"
                   "        if ((j_i % 3) == 0) j_s = j_s + j_i;\n"
                   "        else j_s = j_s + j_i * 2;\n"
                   "        j_i = j_i + 1;\n"
                   "    }\n"
                   "    return j_s;\n"
                   "}\n";
        default:
            return "__attribute__((used)) static int32_t " + name + "(int32_t j_a, int32_t j_b, int32_t j_c) {\n"
                   "    int32_t j_r = j_a;\n"
                   "    int32_t j_t = 0;\n"
                   "    while (j_t < j_b) {\n"
                   "        j_r = (j_r * 31 + j_c) % 10007;\n"
                   "        j_t = j_t + 1;\n"
                   "    }\n"
                   "    return j_r;\n"
                   "}\n";
    }
}

void injectJunkFunctions(std::string& c, std::mt19937_64& rng) {
    int n = 2 + static_cast<int>(rng() % 4);  // 2..5
    std::string junk;
    for (int i = 0; i < n; ++i) {
        junk += junkFunction(rng, "j_z_" + randTag(rng, 6));
        junk += "\n";
    }
    size_t pos = c.find("int32_t main(void)");
    if (pos == std::string::npos) return;
    c.insert(pos, junk);
}

// ---------------------------------------------------------------------------
// Pass 7: trampoline / entry-point shuffle.
// ---------------------------------------------------------------------------

void trampolineMain(std::string& c, std::mt19937_64& rng) {
    const std::string sig = "int32_t main(void)";
    size_t pos = c.find(sig);
    if (pos == std::string::npos) return;
    size_t brace = c.find('{', pos);
    if (brace == std::string::npos) return;
    int depth = 0;
    size_t end = std::string::npos;
    for (size_t i = brace; i < c.size(); ++i) {
        if (c[i] == '{') ++depth;
        else if (c[i] == '}') { --depth; if (depth == 0) { end = i; break; } }
    }
    if (end == std::string::npos) return;

    std::string body = c.substr(brace, end - brace + 1);
    int hops = 1 + static_cast<int>(rng() % 3);  // 1..3 intermediate trampolines
    std::string real = "j_tr_" + randTag(rng, 6);
    std::string rep;
    rep += "static int32_t " + real + "(void) " + body + "\n";
    std::string prev = real;
    for (int i = hops; i >= 1; --i) {
        std::string cur = "j_tr_" + randTag(rng, 6);
        rep += "static int32_t " + cur + "(void) { return " + prev + "(); }\n";
        prev = cur;
    }
    rep += "int32_t main(void) { return " + prev + "(); }\n";
    c.replace(pos, end - pos + 1, rep);
}

}  // namespace

std::string run(std::string c, std::mt19937_64& rng, int level) {
    if (level >= 3) {
        injectJunkFunctions(c, rng);
        trampolineMain(c, rng);
    }
    if (level >= 2) {
        encryptStrings(c, rng);
    }
    if (level >= 3) {
        constantNoise(c, rng);
    }
    return c;
}

}  // namespace postprocess