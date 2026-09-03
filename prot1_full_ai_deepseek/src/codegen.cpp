#include "codegen.h"

#include <cstdint>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <unordered_map>

// Builtin -> generated-C runtime function name.
static const std::unordered_map<std::string, std::string> kRuntimeFns = {
    {"sys.process_list", "j_sys_process_list"},
    {"sys.cwd",          "j_sys_cwd"},
    {"sys.now",          "j_sys_now"},
    {"sys.sleep",        "j_sys_sleep"},
    {"env.get",          "j_env_get"},
    {"net.sockets",      "j_net_sockets"},
    {"fs.read",          "j_fs_read"},
    {"fs.write",         "j_fs_write"},
    {"fs.list",          "j_fs_list"},
    {"fs.exists",        "j_fs_exists"},
    {"reg.list",         "j_reg_list"},
    {"mem.dump",         "j_mem_dump"},
};

Codegen::Codegen(Sema& sema, int64_t polySeed, int obfLevel)
    : sema_(sema), polySeed_(polySeed), obfLevel_(obfLevel),
      rng_(polySeed >= 0 ? static_cast<uint64_t>(polySeed) : std::random_device{}()) {}

std::string Codegen::typeToC(const std::string& t) {
    if (t == "int") return "int32_t";
    if (t == "str") return "const char*";
    if (t == "bool") return "bool";
    // Internal type used by the obfuscation pass: a function-local guard that
    // the optimizer must not fold away. The `_local` variant is a non-static
    // local (may hold a runtime-computed initializer); the plain variant is a
    // `static` local (constant initializer only).
    if (t == "volatile_int64") return "static volatile int64_t";
    if (t == "volatile_int64_local") return "volatile int64_t";
    return "void";
}

std::string Codegen::escape(const std::string& s) {
    std::string r;
    for (char c : s) {
        switch (c) {
            case '\n': r += "\\n"; break;
            case '\t': r += "\\t"; break;
            case '\r': r += "\\r"; break;
            case '"': r += "\\\""; break;
            case '\\': r += "\\\\"; break;
            default: r += c;
        }
    }
    return r;
}

void Codegen::line(const std::string& text) {
    out_ += std::string(static_cast<size_t>(indent_) * 4, ' ');
    out_ += text;
    out_ += "\n";
}

void Codegen::openBlock() { line("{"); indent_++; }
void Codegen::closeBlock() { indent_--; line("}"); }

void Codegen::registerName(const std::string& name) {
    if (polySeed_ < 0) return;
    if (renames_.count(name)) return;
    // keep `main` literal; C requires it
    if (name == "main") return;
    static const char* chars = "abcdefghijklmnopqrstuvwxyz0123456789";
    std::string candidate;
    do {
        candidate = "j_";
        for (int i = 0; i < 8; ++i) {
            candidate += chars[rng_() % 36];
        }
    } while (renames_.count(candidate));
    renames_[name] = candidate;
}

std::string Codegen::cname(const std::string& name) {
    auto it = renames_.find(name);
    return it != renames_.end() ? it->second : name;
}

std::string Codegen::randName() {
    static const char* chars = "abcdefghijklmnopqrstuvwxyz0123456789";
    std::string candidate;
    do {
        candidate = "j_";
        for (int i = 0; i < 8; ++i) {
            candidate += chars[rng_() % 36];
        }
    } while (renames_.count(candidate));
    return candidate;
}

std::string Codegen::emitBuildMarker() {
    if (markersEmitted_) return "";
    markersEmitted_ = true;
    // Two volatile globals with per-build random values/names. The optimizer
    // cannot remove them, so every build ships different .data bytes -> unique hash.
    std::string m1 = randName(), m2 = randName();
    int64_t v1 = static_cast<int64_t>(rng_() & 0xFFFF), v2 = static_cast<int64_t>(rng_() & 0xFFFF);
    std::string code;
    code += "static volatile int32_t " + m1 + " = " + std::to_string(v1) + ";\n";
    code += "static volatile int32_t " + m2 + " = " + std::to_string(v2) + ";\n\n";
    return code;
}

void Codegen::injectOpaquePredicates() {
    if (polySeed_ < 0) return;
    int n = 1 + static_cast<int>(rng_() % 3);  // 1..3 guards per function
    for (int i = 0; i < n; ++i) {
        std::string g = randName();
        int64_t c = static_cast<int64_t>(rng_() % 100000);
        // `g*g >= 0` is always true but not provable: the branch survives -O2,
        // so each build emits different control flow bytes.
        out_ += std::string(static_cast<size_t>(indent_) * 4, ' ');
        out_ += "static volatile int64_t " + g + " = " + std::to_string(c) + ";\n";
        line("if ((" + g + " * " + g + ") >= 0)");
        openBlock();
        closeBlock();
        line("else");
        openBlock();
        line("printf(\"%d\\n\", 0);");
        closeBlock();
    }
}

std::string Codegen::emit(const Program& prog) {
    // Prepass: classify top-level statements.
    for (auto& s : prog.stmts) {
        if (s->kind == Stmt::K::Fn && s->fnName == "main") mainFn_ = s.get();
        else if (s->kind == Stmt::K::Fn) {
            // register fn name for renaming
            registerName(s->fnName);
            for (auto& p : s->params) registerName(p.first);
        } else {
            topLevelStmts_.push_back(s.get());
        }
    }

    if (emitBuildHeader_) {
        auto now = std::time(nullptr);
        std::tm tmv{};
        localtime_r(&now, &tmv);
        char buf[32];
        std::strftime(buf, sizeof buf, "%Y-%m-%d %H:%M:%S", &tmv);
        std::stringstream hs;
        hs << "// JOCKY build " << std::hex << std::uppercase << rng_() << std::dec
           << " seed=" << polySeed_ << " date=" << buf;
        out_ += hs.str();
        out_ += "\n";
    }

    out_ += R"JOCKY(#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <tlhelp32.h>
#include <direct.h>
#elif defined(__APPLE__)
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <libproc.h>
#else
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#endif

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == 0; }

static char j_buf[65536];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = 0;
    for (const char* p = s; *p && o + 8 < cap; ++p) {
        unsigned char c = (unsigned char)*p;
        switch (c) {
            case '"': out[o++] = '\\'; out[o++] = '"'; break;
            case '\\': out[o++] = '\\'; out[o++] = '\\'; break;
            case '\n': out[o++] = '\\'; out[o++] = 'n'; break;
            case '\r': out[o++] = '\\'; out[o++] = 'r'; break;
            case '\t': out[o++] = '\\'; out[o++] = 't'; break;
            default:
                if (c < 0x20) {
                    out[o++] = '\\'; out[o++] = 'u'; out[o++] = '0'; out[o++] = '0';
                    out[o++] = "0123456789abcdef"[c >> 4];
                    out[o++] = "0123456789abcdef"[c & 15];
                } else out[o++] = (char)c;
        }
    }
    out[o] = '\0';
}

static const char* j_sys_now(void) {
    time_t t = time(NULL);
#if defined(_WIN32)
    struct tm* tmv = localtime(&t);
    strftime(j_buf, J_BUF_CAP, "%Y-%m-%dT%H:%M:%S", tmv);
#else
    struct tm tmv;
    localtime_r(&t, &tmv);
    strftime(j_buf, J_BUF_CAP, "%Y-%m-%dT%H:%M:%S", &tmv);
#endif
    return j_buf;
}

static void j_sys_sleep(int32_t ms) {
#if defined(_WIN32)
    Sleep((DWORD)ms);
#else
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (long)(ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
#endif
}

static const char* j_sys_cwd(void) {
#if defined(_WIN32)
    _getcwd(j_buf, (int)J_BUF_CAP);
#else
    getcwd(j_buf, J_BUF_CAP);
#endif
    return j_buf;
}

static const char* j_env_get(const char* name) {
    const char* v = getenv(name);
    return v ? v : "";
}

static bool j_fs_exists(const char* path) {
#if defined(_WIN32)
    return GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES;
#else
    return access(path, F_OK) == 0;
#endif
}

static const char* j_fs_read(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) return "";
    size_t n = fread(j_buf, 1, J_BUF_CAP - 1, f);
    fclose(f);
    j_buf[n] = '\0';
    return j_buf;
}

static void j_fs_write(const char* path, const char* data) {
    FILE* f = fopen(path, "wb");
    if (f) { fputs(data, f); fclose(f); }
}

static const char* j_fs_list(const char* dir) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    char pattern[1024];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[0] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[1024];
            j_json_escape(esc, sizeof esc, fd.cFileName);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : 0);
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
#else
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[1024];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : 0);
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_sys_process_list(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - 400) break;
                char name[1024];
                size_t k = 0;
                for (size_t i = 0; pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[2048];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > 0 ? n : 0);
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[8192];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = 0; i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - 400) break;
        char name[256];
        int len = proc_name(pid, name, sizeof name);
        if (len <= 0) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = 0;
        char esc[512];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > 0 ? n : 0);
    }
#else
    DIR* d = opendir("/proc");
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[0] > '9') continue;
            int pid = atoi(de->d_name);
            char p[64], name[256];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, "r");
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, "\n")] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - 400) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[512];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static void j_net_proc_parse(const char* path, size_t* off, int* first) {
    FILE* f = fopen(path, "r");
    if (!f) return;
    char line[512];
    int skip = 1;
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = 0; continue; }
        char laddr[64], raddr[64], st[16];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != 3) continue;
        if (*off > J_BUF_CAP - 300) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = 0;
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > 0 ? n : 0);
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    ULONG sz = 0;
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);
    char* t = (char*)malloc(sz ? sz : 1);
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0) == NO_ERROR) {
            for (DWORD i = 0; i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[64], ri[64];
                snprintf(li, sizeof li, "%s:%u", inet_ntoa(*(struct in_addr*)&r->dwLocalAddr), (unsigned)ntohs((u_short)r->dwLocalPort));
                snprintf(ri, sizeof ri, "%s:%u", inet_ntoa(*(struct in_addr*)&r->dwRemoteAddr), (unsigned)ntohs((u_short)r->dwRemotePort));
                const char* state = "?";
                switch (r->dwState) {
                    case 2:  state = "LISTEN"; break;
                    case 5:  state = "ESTABLISHED"; break;
                    case 8:  state = "CLOSE_WAIT"; break;
                    case 11: state = "TIME_WAIT"; break;
                    default: state = "OTHER"; break;
                }
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen("netstat -an -p tcp 2>/dev/null", "r");
    if (ns) {
        char line[512];
        while (fgets(line, sizeof line, ns)) {
            char proto[8], laddr[64], raddr[64], st[32];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == 4) {
                if (strncmp(proto, "tcp", 3) != 0) continue;
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        pclose(ns);
    }
#else
    j_net_proc_parse("/proc/net/tcp", &off, &first);
    j_net_proc_parse("/proc/net/tcp6", &off, &first);
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_reg_list(const char* key) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, "HKLM\\", 5) == 0) { root = HKEY_LOCAL_MACHINE; sub = key + 5; }
    else if (strncmp(key, "HKCU\\", 5) == 0) { root = HKEY_CURRENT_USER; sub = key + 5; }
    else if (strncmp(key, "HKCR\\", 5) == 0) { root = HKEY_CLASSES_ROOT; sub = key + 5; }
    else if (strncmp(key, "HKU\\", 4) == 0) { root = HKEY_USERS; sub = key + 4; }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, 0, KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = 0; ; ++i) {
            char s[256];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - 400) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[512];
            j_json_escape(esc, sizeof esc, s);
            int n2 = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n2 > 0 ? n2 : 0);
        }
        RegCloseKey(hk);
    }
#else
    (void)key;
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static void j_mem_dump(int32_t pid, const char* path) {
#if defined(_WIN32)
    HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, (DWORD)pid);
    if (!h) return;
    FILE* out = fopen(path, "wb");
    if (!out) { CloseHandle(h); return; }
    unsigned char* base = NULL;
    MEMORY_BASIC_INFORMATION mbi;
    unsigned long regions = 0;
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < 100000) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : 1);
            SIZE_T read = 0;
            if (chunk && ReadProcessMemory(h, mbi.BaseAddress, chunk, mbi.RegionSize, &read) && read) {
                fwrite(chunk, 1, read, out);
            }
            free(chunk);
        }
        base = (unsigned char*)mbi.BaseAddress + mbi.RegionSize;
    }
    fclose(out);
    CloseHandle(h);
#else
    (void)pid; (void)path;
#endif
}

)JOCKY";

    out_ += emitBuildMarker();

    // Forward declarations for all user functions. Sema already resolves calls
    // to functions declared later in the file, so the generated C must too --
    // otherwise a function calling a function defined below it would fail to
    // compile (C requires a declaration before use for static functions).
    bool hasUserFns = false;
    for (auto& s : prog.stmts) {
        if (s->kind == Stmt::K::Fn && s->fnName != "main") {
            hasUserFns = true;
            std::string proto = "static " + typeToC(s->fnRetType) + " " + cname(s->fnName) + "(";
            for (size_t i = 0; i < s->params.size(); ++i) {
                if (i) proto += ", ";
                proto += typeToC(s->params[i].second) + " " + cname(s->params[i].first);
            }
            proto += ");";
            line(proto);
        }
    }
    if (hasUserFns) out_ += "\n";

    // Emit user functions (all but main).
    for (auto& s : prog.stmts) {
        if (s->kind == Stmt::K::Fn && s->fnName != "main") emitStmt(*s);
    }

    // Emit main.
    line("int32_t main(void)");
    openBlock();
    if (obfLevel_ < 1) injectOpaquePredicates();
    for (auto* s : topLevelStmts_) emitStmt(*s);
    if (mainFn_) {
        for (auto& body : mainFn_->fnBody) emitStmt(*body);
    }
    line("return 0;");
    closeBlock();

    return out_;
}

void Codegen::emitStmt(Stmt& s) {
    switch (s.kind) {
        case Stmt::K::Let: {
            registerName(s.varName);
            std::string type = s.varType.empty() ? sema_.exprType(*s.init) : s.varType;
            std::string name = cname(s.varName);
            std::string init;
            if (s.init) init = " = " + emitExpr(*s.init);
            else if (type == "str") init = " = \"\"";
            else if (type == "bool") init = " = false";
            else init = " = 0";
            line(typeToC(type) + " " + name + init + ";");
            break;
        }
        case Stmt::K::ExprStmt: {
            std::string e = emitExpr(*s.init);
            // avoid unused-result warnings for pure calls
            if (s.init->kind == Expr::K::Call) line("(void)" + e + ";");
            else line(e + ";");
            break;
        }
        case Stmt::K::If: {
            line("if (" + emitExpr(*s.cond) + ")");
            openBlock();
            for (auto& st : s.thenBody) emitStmt(*st);
            closeBlock();
            if (!s.elseBody.empty()) {
                line("else");
                openBlock();
                for (auto& st : s.elseBody) emitStmt(*st);
                closeBlock();
            }
            break;
        }
        case Stmt::K::While: {
            line("while (" + emitExpr(*s.loopCond) + ")");
            openBlock();
            for (auto& st : s.body) emitStmt(*st);
            closeBlock();
            break;
        }
        case Stmt::K::For: {
            registerName(s.forInit->varName);
            std::string init = cname(s.forInit->varName) + " = " +
                               (s.forInit->init ? emitExpr(*s.forInit->init) : "0");
            line("for (" + typeToC("int") + " " + init + "; " +
                 emitExpr(*s.forCond) + "; " + emitExpr(*s.forStep) + ")");
            openBlock();
            for (auto& st : s.body) emitStmt(*st);
            closeBlock();
            break;
        }
        case Stmt::K::Return: {
            if (s.retExpr) line("return " + emitExpr(*s.retExpr) + ";");
            else line("return;");
            break;
        }
        case Stmt::K::Switch: {
            line("switch (" + emitExpr(*s.switchExpr) + ")");
            openBlock();
            for (auto& c : s.cases) {
                line("case " + std::to_string(c.first) + ":");
                indent_++;
                for (auto& st : c.second) emitStmt(*st);
                line("break;");
                indent_--;
            }
            line("default:");
            indent_++;
            for (auto& st : s.defaultCase) emitStmt(*st);
            line("break;");
            indent_--;
            closeBlock();
            break;
        }
        case Stmt::K::Fn: {
            std::string retC = s.fnName == "main" ? "int32_t" : typeToC(s.fnRetType);
            std::string sig = "static " + retC + " " + cname(s.fnName) + "(";
            for (size_t i = 0; i < s.params.size(); ++i) {
                if (i) sig += ", ";
                sig += typeToC(s.params[i].second) + " " + cname(s.params[i].first);
            }
            sig += ")";
            line(sig);
            openBlock();
            if (obfLevel_ < 1) injectOpaquePredicates();
            for (auto& body : s.fnBody) emitStmt(*body);
            // satisfy C on non-void functions that might fall off the end
            if (s.fnRetType != "void") line("return 0;");
            closeBlock();
            out_ += "\n";
            break;
        }
    }
}

std::string Codegen::emitExpr(const Expr& e) {
    switch (e.kind) {
        case Expr::K::IntLit: return std::to_string(e.iVal);
        case Expr::K::StrLit: return "\"" + escape(e.name) + "\"";
        case Expr::K::BoolLit: return e.iVal ? "true" : "false";
        case Expr::K::Ident: return cname(e.name);

        case Expr::K::Unary:
            return e.op + "(" + emitExpr(*e.lhs) + ")";

        case Expr::K::Binary: {
            std::string op = e.op;
            std::string lt = sema_.exprType(*e.lhs);
            if (op == "==" || op == "!=") {
                if (lt == "str") {
                    return std::string(op == "==" ? "j_str_eq(" : "!j_str_eq(") +
                           emitExpr(*e.lhs) + ", " + emitExpr(*e.rhs) + ")";
                }
            }
            if (op == "=") {
                return cname(e.lhs->name) + " = " + emitExpr(*e.rhs);
            }
            return "(" + emitExpr(*e.lhs) + " " + op + " " + emitExpr(*e.rhs) + ")";
        }

        case Expr::K::Call: return emitCall(e);
    }
    return "";
}

std::string Codegen::emitCall(const Expr& e) {
    if (e.name == "print") {
        const Expr& arg = *e.args[0];
        std::string t = sema_.exprType(arg);
        if (t == "int") return "printf(\"%d\\n\", " + emitExpr(arg) + ")";
        if (t == "str") return "printf(\"%s\\n\", " + emitExpr(arg) + ")";
        return "printf(\"%s\\n\", " + emitExpr(arg) + " ? \"true\" : \"false\")";
    }
    if (e.name == "len") {
        return "j_str_len(" + emitExpr(*e.args[0]) + ")";
    }
    auto it = kRuntimeFns.find(e.name);
    if (it != kRuntimeFns.end()) {
        std::string call = it->second + "(";
        for (size_t i = 0; i < e.args.size(); ++i) {
            if (i) call += ", ";
            call += emitExpr(*e.args[i]);
        }
        call += ")";
        return call;
    }
    std::string call = cname(e.name) + "(";
    for (size_t i = 0; i < e.args.size(); ++i) {
        if (i) call += ", ";
        call += emitExpr(*e.args[i]);
    }
    call += ")";
    return call;
}