#include "obfuscate.h"

#include <algorithm>
#include <map>
#include <stdexcept>
#include <unordered_set>
#include <utility>

namespace obfuscate {
namespace {

// ---------------------------------------------------------------------------
// AST construction helpers (all nodes carry no source position -> safe to
// inject after sema, and codegen never consults `tok`).
// ---------------------------------------------------------------------------

const char kRngChars[] = "abcdefghijklmnopqrstuvwxyz0123456789";

std::string randName(std::mt19937_64& rng, std::unordered_set<std::string>& used) {
    std::string r;
    do {
        r = "j_o_";
        for (int i = 0; i < 6; ++i) r += kRngChars[rng() % 36];
    } while (used.count(r));
    used.insert(r);
    return r;
}

ExprPtr mkInt(int64_t v) {
    ExprPtr e = std::make_unique<Expr>();
    e->kind = Expr::K::IntLit;
    e->iVal = v;
    return e;
}

ExprPtr mkIdent(const std::string& n) {
    ExprPtr e = std::make_unique<Expr>();
    e->kind = Expr::K::Ident;
    e->name = n;
    return e;
}

ExprPtr mkBinary(const std::string& op, ExprPtr l, ExprPtr r) {
    ExprPtr e = std::make_unique<Expr>();
    e->kind = Expr::K::Binary;
    e->op = op;
    e->lhs = std::move(l);
    e->rhs = std::move(r);
    return e;
}

StmtPtr mkLet(const std::string& name, const std::string& type, ExprPtr init) {
    StmtPtr s = std::make_unique<Stmt>();
    s->kind = Stmt::K::Let;
    s->varName = name;
    s->varType = type;
    s->init = std::move(init);
    return s;
}

StmtPtr mkExprStmt(ExprPtr e) {
    StmtPtr s = std::make_unique<Stmt>();
    s->kind = Stmt::K::ExprStmt;
    s->init = std::move(e);
    return s;
}

StmtPtr mkIf(ExprPtr cond, std::vector<StmtPtr> thenB, std::vector<StmtPtr> elseB) {
    StmtPtr s = std::make_unique<Stmt>();
    s->kind = Stmt::K::If;
    s->cond = std::move(cond);
    s->thenBody = std::move(thenB);
    s->elseBody = std::move(elseB);
    return s;
}

StmtPtr mkAssign(const std::string& lhs, int64_t v) {
    return mkExprStmt(mkBinary("=", mkIdent(lhs), mkInt(v)));
}

StmtPtr mkPrintInt(int64_t v) {
    ExprPtr call = std::make_unique<Expr>();
    call->kind = Expr::K::Call;
    call->name = "print";
    call->args.push_back(mkInt(v));
    return mkExprStmt(std::move(call));
}

// ---------------------------------------------------------------------------
// Pass 4: opaque predicates, multiple families.
//
// All families are backed by a `static volatile int64_t` guard so GCC/Clang
// cannot prove the condition and fold the branch away. Volatile reads are not
// assumed to satisfy any algebraic identity.
// ---------------------------------------------------------------------------

// Builds an opaque condition over volatile guard `g`. `alwaysTrue` tells the
// caller whether the condition is mathematically always-true or always-false
// (which path is the "real" one).
ExprPtr makeOpaqueCond(std::mt19937_64& rng, const std::string& g, bool& alwaysTrue) {
    switch (rng() % 6) {
        case 0:  alwaysTrue = true;  return mkBinary(">=", mkBinary("+", mkBinary("*", mkIdent(g), mkIdent(g)), mkIdent(g)), mkInt(0));
        case 1:  alwaysTrue = false; return mkBinary("<",  mkBinary("+", mkBinary("*", mkIdent(g), mkIdent(g)), mkIdent(g)), mkInt(0));
        case 2:  alwaysTrue = true;  return mkBinary("==", mkBinary("%", mkBinary("*", mkIdent(g), mkBinary("+", mkIdent(g), mkInt(1))), mkInt(2)), mkInt(0));
        case 3:  alwaysTrue = false; return mkBinary("==", mkBinary("%", mkBinary("*", mkIdent(g), mkBinary("+", mkIdent(g), mkInt(1))), mkInt(2)), mkInt(1));
        case 4:  alwaysTrue = true;  return mkBinary("<",  mkBinary("%", mkBinary("*", mkIdent(g), mkIdent(g)), mkInt(4)), mkInt(2));
        default: alwaysTrue = false; return mkBinary("==", mkBinary("%", mkBinary("*", mkIdent(g), mkIdent(g)), mkInt(4)), mkInt(3));
    }
}

// Force an always-true predicate (used when a pass needs the guard branch to
// actually be the reachable one).
ExprPtr alwaysTrueCond(const std::string& g) {
    return mkBinary(">=", mkBinary("+", mkBinary("*", mkIdent(g), mkIdent(g)), mkIdent(g)), mkInt(0));
}

// Force an always-false predicate (dead code must never run).
ExprPtr alwaysFalseCond(const std::string& g) {
    return mkBinary("<", mkBinary("+", mkBinary("*", mkIdent(g), mkIdent(g)), mkIdent(g)), mkInt(0));
}

// Inserts a fresh guard variable declaration + guarded block at a random spot.
void insertGuard(std::vector<StmtPtr>& body, std::mt19937_64& rng,
                 std::unordered_set<std::string>& used, bool wantTrue) {
    std::string g = randName(rng, used);
    int64_t c = static_cast<int64_t>(rng() % 100000);
    bool at = false;
    ExprPtr cond = makeOpaqueCond(rng, g, at);
    if (wantTrue && !at) cond = alwaysTrueCond(g);
    if (!wantTrue && at) cond = alwaysFalseCond(g);

    std::vector<StmtPtr> thenB, elseB;
    if (!wantTrue) thenB.push_back(mkPrintInt(0));   // never reached
    else elseB.push_back(mkPrintInt(0));             // never reached
    StmtPtr guard = mkIf(std::move(cond), std::move(thenB), std::move(elseB));

    size_t pos = rng() % (body.size() + 1);
    body.insert(body.begin() + static_cast<long>(pos), std::move(guard));
    body.insert(body.begin() + static_cast<long>(pos), mkLet(g, "volatile_int64", mkInt(c)));
}

// Pass 4: inject 1..3 enhanced opaque-predicate guards per function.
void injectOpaquePredicates(Stmt& fn, std::mt19937_64& rng) {
    if (fn.fnBody.empty()) return;
    std::unordered_set<std::string> used;
    int n = 1 + static_cast<int>(rng() % 3);
    for (int i = 0; i < n; ++i) insertGuard(fn.fnBody, rng, used, /*wantTrue=*/rng() % 2 == 0);
}

// ---------------------------------------------------------------------------
// Pass 2: dead code injection. Each dead block is guarded by an always-false
// opaque predicate whose condition the compiler cannot evaluate away.
// ---------------------------------------------------------------------------

void injectDeadCode(Stmt& fn, std::mt19937_64& rng) {
    if (fn.fnBody.empty()) return;
    std::unordered_set<std::string> used;
    int n = 1 + static_cast<int>(rng() % 4);
    for (int i = 0; i < n; ++i) {
        std::string g = randName(rng, used);
        int64_t c = static_cast<int64_t>(rng() % 100000);
        int64_t k = 1 + static_cast<int64_t>(rng() % 100);

        std::string tmp = randName(rng, used);
        std::vector<StmtPtr> dead;
        dead.push_back(mkLet(tmp, "volatile_int64_local",
                             mkBinary("+", mkBinary("*", mkIdent(g), mkInt(k)), mkInt(c % 1000))));
        dead.push_back(mkPrintInt(0));

        StmtPtr guard = mkIf(alwaysFalseCond(g), std::move(dead), {});
        size_t pos = rng() % (fn.fnBody.size() + 1);
        fn.fnBody.insert(fn.fnBody.begin() + static_cast<long>(pos), std::move(guard));
        fn.fnBody.insert(fn.fnBody.begin() + static_cast<long>(pos),
                         mkLet(g, "volatile_int64", mkInt(c)));
    }
}

// ---------------------------------------------------------------------------
// Pass 3: bogus control flow. With probability ~30% an expression statement is
// wrapped in an always-true volatile guard; the else arm computes junk that is
// never used. This creates diamond subgraphs that confuse decompilers while
// preserving semantics (the real statement only runs when the guard is true,
// and the guard is always true at runtime).
// ---------------------------------------------------------------------------

void injectBogusControlFlow(Stmt& fn, std::mt19937_64& rng) {
    if (fn.fnBody.empty()) return;
    std::unordered_set<std::string> used;
    std::vector<StmtPtr> newBody;
    newBody.reserve(fn.fnBody.size());
    for (auto& st : fn.fnBody) {
        if (st->kind == Stmt::K::ExprStmt && rng() % 100 < 30) {
            std::string g = randName(rng, used);
            int64_t c = static_cast<int64_t>(rng() % 100000);
            std::string tmp = randName(rng, used);

            std::vector<StmtPtr> thenB;
            thenB.push_back(std::move(st));
            std::vector<StmtPtr> elseB;
            elseB.push_back(mkLet(tmp, "volatile_int64_local",
                                  mkBinary("+", mkBinary("*", mkIdent(g), mkInt(2)), mkInt(1))));

            newBody.push_back(mkLet(g, "volatile_int64", mkInt(c)));
            newBody.push_back(mkIf(alwaysTrueCond(g), std::move(thenB), std::move(elseB)));
        } else {
            newBody.push_back(std::move(st));
        }
    }
    fn.fnBody = std::move(newBody);
}

// ---------------------------------------------------------------------------
// Pass 1: control flow flattening.
//
// Rewrites a function body into a top-level state machine:
//
//   int32_t j_state = 0;
//   while (j_state != -1) {
//       switch (j_state) {
//       case 0: <straight-line stmts>; j_state = 1; break;
//       case 1: <straight-line stmts + one structured if/while/for>;
//               j_state = 2; break;
//       ...
//       default: break;
//       }
//   }
//
// Only the TOP-LEVEL function flow is linearized into switch cases; nested
// if/while/for bodies stay structured so their block scopes (and therefore
// C's shadowing rules) are preserved. This is the key correctness constraint:
// fully flattening nested bodies would collapse every `let` into a single
// `switch` scope, producing redeclaration errors for block-local names.
//
// Blocks are emitted in id order (== source order) so every C declaration
// precedes its uses. Polymorphism is still provided by the random state-variable
// name, volatile guards, and the injected junk.
// ---------------------------------------------------------------------------

const int kExit = -1;

struct Block {
    enum class T { Fall, Exit };
    int id = 0;
    T kind = T::Fall;
    int nextId = kExit;   // Fall
    std::vector<StmtPtr> body;
};

class Flattener {
public:
    Flattener(const std::string& state) : state_(state) {}

    // Linearizes `stmts` starting at a fresh block; the block that ends the
    // sequence falls through to `fallId`. Returns the id of the entry block.
    int emitSeq(std::vector<StmtPtr>& stmts, int fallId) {
        if (stmts.empty()) return fallId;
        int id = nextId_++;
        Block b;
        b.id = id;
        size_t i = 0;
        bool done = false;
        while (i < stmts.size()) {
            Stmt& s = *stmts[i];
            switch (s.kind) {
                case Stmt::K::Let:
                case Stmt::K::ExprStmt:
                    b.body.push_back(std::move(stmts[i]));
                    ++i;
                    break;

                case Stmt::K::Return:
                    b.body.push_back(std::move(stmts[i]));
                    b.kind = Block::T::Exit;
                    ++i;
                    if (i < stmts.size()) {
                        std::vector<StmtPtr> rest;
                        for (size_t j = i; j < stmts.size(); ++j) rest.push_back(std::move(stmts[j]));
                        emitSeq(rest, fallId);  // unreachable, but keep the statements
                    }
                    done = true;
                    break;

                case Stmt::K::If:
                case Stmt::K::While:
                case Stmt::K::For:
                    // Structured control flow stays nested (its braces keep the
                    // inner declarations scoped). End this block after it and
                    // let the remaining statements start a fresh case.
                    b.body.push_back(std::move(stmts[i]));
                    ++i;
                    if (i < stmts.size()) {
                        std::vector<StmtPtr> rest;
                        for (size_t j = i; j < stmts.size(); ++j) rest.push_back(std::move(stmts[j]));
                        b.kind = Block::T::Fall;
                        b.nextId = emitSeq(rest, fallId);
                    } else {
                        b.kind = Block::T::Fall;
                        b.nextId = fallId;
                    }
                    done = true;
                    break;

                default:
                    b.body.push_back(std::move(stmts[i]));
                    ++i;
                    break;
            }
            if (done) break;
        }
        if (!done) {
            b.kind = Block::T::Fall;
            b.nextId = fallId;
        }
        blocks_[id] = std::move(b);
        return id;
    }

    // Builds the flattened body for function `fn`.
    void flattenInto(Stmt& fn) {
        int startId = emitSeq(fn.fnBody, kExit);
        if (startId == kExit) {  // empty body: need a block so state 0 exits
            int id = nextId_++;
            Block b;
            b.id = id;
            b.kind = Block::T::Fall;
            b.nextId = kExit;
            blocks_[id] = std::move(b);
            startId = id;
        }

        StmtPtr sw = std::make_unique<Stmt>();
        sw->kind = Stmt::K::Switch;
        sw->switchExpr = mkIdent(state_);
        for (auto& kv : blocks_) {
            Block& blk = kv.second;
            std::vector<StmtPtr> body = std::move(blk.body);
            if (blk.kind == Block::T::Fall) body.push_back(mkAssign(state_, blk.nextId));
            sw->cases.push_back({blk.id, std::move(body)});
        }

        StmtPtr wh = std::make_unique<Stmt>();
        wh->kind = Stmt::K::While;
        wh->loopCond = mkBinary("!=", mkIdent(state_), mkInt(kExit));
        wh->body.push_back(std::move(sw));

        std::vector<StmtPtr> newBody;
        newBody.push_back(mkLet(state_, "int", mkInt(0)));
        newBody.push_back(std::move(wh));
        fn.fnBody = std::move(newBody);
    }

private:
    std::string state_;
    std::map<int, Block> blocks_;
    int nextId_ = 0;
};

void flattenFunction(Stmt& fn, std::mt19937_64& rng) {
    if (fn.fnBody.empty()) return;
    std::unordered_set<std::string> used;
    std::string state = randName(rng, used);
    Flattener f(state);
    f.flattenInto(fn);
}

}  // namespace

void run(Program& prog, std::mt19937_64& rng, int level) {
    if (level < 1) return;
    for (auto& s : prog.stmts) {
        if (s->kind != Stmt::K::Fn) continue;
        Stmt& fn = *s;
        injectOpaquePredicates(fn, rng);
        injectDeadCode(fn, rng);
        if (level >= 2) {
            injectBogusControlFlow(fn, rng);
            flattenFunction(fn, rng);
        }
    }
}

}  // namespace obfuscate