#include "codegen.h"

#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Transforms/Utils/ModuleUtils.h>

#include <cstdint>
#include <stdexcept>

// Runtime (runtime.c) function ABI. Return/param types are expressed in LLVM.
// "ptr" is the opaque pointer type used for `str`.
namespace {

struct RtSig {
    std::string ret;                  // "ptr" | "void" | "i32" | "i1"
    std::vector<std::string> params;  // same vocabulary
};

const std::unordered_map<std::string, RtSig> kRuntimeSigs = {
    {"sys.process_list", {"ptr", {}}},
    {"sys.cwd",          {"ptr", {}}},
    {"sys.now",          {"ptr", {}}},
    {"sys.sleep",        {"void", {"i32"}}},
    {"env.get",          {"ptr", {"ptr"}}},
    {"net.sockets",      {"ptr", {}}},
    {"fs.read",          {"ptr", {"ptr"}}},
    {"fs.write",         {"void", {"ptr", "ptr"}}},
    {"fs.list",          {"ptr", {"ptr"}}},
    {"fs.exists",        {"i1", {"ptr"}}},
    {"reg.list",         {"ptr", {"ptr"}}},
    {"mem.dump",         {"void", {"i32", "ptr"}}},
};

}  // namespace

Codegen::Codegen(Sema& sema, int64_t seed, int obfLevel)
    : sema_(sema), seed_(seed), obfLevel_(obfLevel),
      rng_(seed >= 0 ? static_cast<uint64_t>(seed) : std::random_device{}()) {}

llvm::Type* Codegen::llvmType(const std::string& t) {
    if (t == "int") return llvm::Type::getInt32Ty(ctx_);
    if (t == "bool") return llvm::Type::getInt1Ty(ctx_);
    if (t == "str") return llvm::PointerType::get(ctx_, 0);   // opaque ptr == i8*
    return llvm::Type::getVoidTy(ctx_);
}

// ---- polymorphism helpers ----------------------------------------------------

void Codegen::registerName(const std::string& name) {
    if (seed_ < 0) return;
    if (renames_.count(name)) return;
    if (name == "main") return;   // C entry point must stay literal
    static const char* chars = "abcdefghijklmnopqrstuvwxyz0123456789";
    std::string candidate;
    do {
        candidate = "j_";
        for (int i = 0; i < 8; ++i) candidate += chars[rng_() % 36];
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
        for (int i = 0; i < 8; ++i) candidate += chars[rng_() % 36];
    } while (renames_.count(candidate));
    return candidate;
}

std::string Codegen::emitBuildMarker() {
    std::string m = randName();
    return m;
}

void Codegen::addBuildMarkersToModule() {
    // Two volatile globals with per-build random values. Volatile + compiler.used
    // means -O2 cannot remove them, so every build ships different .data bytes.
    for (int i = 0; i < 2; ++i) {
        llvm::Type* ty = llvm::Type::getInt32Ty(ctx_);
        auto* gv = new llvm::GlobalVariable(
            *mod_, ty, /*isConstant=*/false, llvm::GlobalValue::InternalLinkage,
            llvm::ConstantInt::get(ty, static_cast<int64_t>(rng_() & 0xFFFF)),
            "j_m_" + emitBuildMarker());
        gv->setDSOLocal(true);
        markers_.push_back(gv);
    }
    std::vector<llvm::GlobalValue*> keep;
    for (auto* gv : markers_) keep.push_back(gv);
    llvm::appendToCompilerUsed(*mod_, keep);
}

// ---- scoping -----------------------------------------------------------------

void Codegen::pushScope() { scopes_.emplace_back(); }
void Codegen::popScope() { scopes_.pop_back(); }

void Codegen::declareVar(const std::string& name, llvm::AllocaInst* a) {
    if (scopes_.empty()) scopes_.emplace_back();
    scopes_.back()[name] = a;
}

llvm::AllocaInst* Codegen::lookupVar(const std::string& name) {
    for (auto it = scopes_.rbegin(); it != scopes_.rend(); ++it) {
        auto f = it->find(name);
        if (f != it->end()) return f->second;
    }
    return nullptr;
}

llvm::AllocaInst* Codegen::createAlloca(llvm::Type* ty, const std::string& name) {
    // Insert allocas at the very top of the entry block so mem2reg / the
    // optimizer can promote them. The saved entryBlock_ is set once per function.
    llvm::IRBuilder<> ab(entryBlock_, entryBlock_->begin());
    return ab.CreateAlloca(ty, nullptr, name);
}

void Codegen::emitFnParams(llvm::Function* f, Stmt& fn) {
    llvm::Function::arg_iterator ai = f->arg_begin();
    for (size_t i = 0; i < fn.params.size(); ++i) {
        registerName(fn.params[i].first);
        llvm::Type* ty = llvmType(fn.params[i].second);
        llvm::AllocaInst* slot = createAlloca(ty, cname(fn.params[i].first));
        builder_.CreateStore(&*ai, slot);
        declareVar(fn.params[i].first, slot);
        ++ai;
    }
}

// ---- runtime / builtins -------------------------------------------------------

llvm::FunctionCallee Codegen::getRuntimeFn(const std::string& cname, llvm::Type* retTy,
                                           std::vector<llvm::Type*> args, bool vararg) {
    llvm::FunctionType* ft = llvm::FunctionType::get(retTy, args, vararg);
    return mod_->getOrInsertFunction(cname, ft);
}

llvm::Value* Codegen::getCString(const std::string& s) {
    auto it = cstrings_.find(s);
    if (it != cstrings_.end()) return it->second;
    llvm::Value* g = builder_.CreateGlobalString(s, "j_s");
    cstrings_[s] = g;
    return g;
}

llvm::Value* Codegen::getPrintFormat(const std::string& type) {
    if (type == "int") return getCString("%d\n");
    return getCString("%s\n");
}

// ---- string literal (optionally encrypted at obfLevel >= 2) ------------------

llvm::Value* Codegen::emitStringLiteral(const std::string& s) {
    if (obfLevel_ < 2) return getCString(s);

    auto it = strDecryptors_.find(s);
    if (it != strDecryptors_.end()) {
        return builder_.CreateCall(it->second);
    }

    // Encrypt the literal byte-for-byte; create a decryptor function with its
    // own static buffer so concurrent string uses never clobber each other.
    size_t n = s.size();
    int key = 1 + static_cast<int>(rng_() % 255);
    std::vector<uint8_t> enc(n);
    for (size_t i = 0; i < n; ++i)
        enc[i] = static_cast<uint8_t>(s[i]) ^ static_cast<uint8_t>(key);

    std::string tag = randName();

    // @enc = constant [n x i8]  (encrypted bytes stay in .rodata)
    llvm::ArrayType* encTy = llvm::ArrayType::get(llvm::Type::getInt8Ty(ctx_), n);
    llvm::Constant* encInit = llvm::ConstantDataArray::get(ctx_, enc);
    auto* encG = new llvm::GlobalVariable(*mod_, encTy, /*isConstant=*/true,
                                          llvm::GlobalValue::InternalLinkage, encInit,
                                          "j_enc_" + tag);
    encG->setDSOLocal(true);

    // @buf = internal global [n+1 x i8] zeroinitializer  (per-string static)
    llvm::ArrayType* bufTy = llvm::ArrayType::get(llvm::Type::getInt8Ty(ctx_), n + 1);
    auto* bufG = new llvm::GlobalVariable(*mod_, bufTy, /*isConstant=*/false,
                                          llvm::GlobalValue::InternalLinkage,
                                          llvm::ConstantAggregateZero::get(bufTy),
                                          "j_buf_" + tag);
    bufG->setDSOLocal(true);

    // define internal ptr @decrypt() { loop load volatile enc[i] ^ key -> buf[i]; buf[n]=0; ret buf }
    llvm::FunctionType* ft = llvm::FunctionType::get(llvm::PointerType::get(ctx_, 0), {}, false);
    auto* fn = llvm::Function::Create(ft, llvm::GlobalValue::InternalLinkage, "j_dc_" + tag, *mod_);
    fn->setDSOLocal(true);

    llvm::BasicBlock* entry = llvm::BasicBlock::Create(ctx_, "", fn);
    llvm::BasicBlock* loop = llvm::BasicBlock::Create(ctx_, "loop", fn);
    llvm::BasicBlock* done = llvm::BasicBlock::Create(ctx_, "done", fn);

    llvm::IRBuilder<> b(entry);
    b.CreateBr(loop);

    b.SetInsertPoint(loop);
    llvm::PHINode* idx = b.CreatePHI(llvm::Type::getInt32Ty(ctx_), 2, "i");
    idx->addIncoming(llvm::ConstantInt::get(ctx_, llvm::APInt(32, 0)), entry);
    llvm::Value* p0 = b.CreateGEP(encTy, encG,
                                  {llvm::ConstantInt::get(ctx_, llvm::APInt(32, 0)), idx});
    llvm::Value* e = b.CreateLoad(llvm::Type::getInt8Ty(ctx_), p0, /*isVolatile=*/true, "enc");
    llvm::Value* d = b.CreateXor(e, llvm::ConstantInt::get(ctx_, llvm::APInt(8, key)));
    llvm::Value* q0 = b.CreateGEP(bufTy, bufG,
                                  {llvm::ConstantInt::get(ctx_, llvm::APInt(32, 0)), idx});
    b.CreateStore(d, q0);
    llvm::Value* next = b.CreateAdd(idx, llvm::ConstantInt::get(ctx_, llvm::APInt(32, 1)));
    idx->addIncoming(next, loop);
    llvm::Value* cmp = b.CreateICmpULT(next, llvm::ConstantInt::get(ctx_, llvm::APInt(32, n)));
    b.CreateCondBr(cmp, loop, done);

    b.SetInsertPoint(done);
    llvm::Value* last = b.CreateGEP(bufTy, bufG,
                                    {llvm::ConstantInt::get(ctx_, llvm::APInt(32, 0)),
                                     llvm::ConstantInt::get(ctx_, llvm::APInt(32, n))});
    b.CreateStore(llvm::ConstantInt::get(ctx_, llvm::APInt(8, 0)), last);
    b.CreateRet(bufG);

    strDecryptors_[s] = fn;
    return builder_.CreateCall(fn);
}

// ---- statements ---------------------------------------------------------------

void Codegen::emitBody(std::vector<StmtPtr>& body) {
    for (auto& s : body) emitStmt(*s);
    // If the block is unterminated (void function that fell off the end, or
    // after a top-level statement list) close it with the right return.
    llvm::BasicBlock* cur = builder_.GetInsertBlock();
    if (cur && cur->getTerminatorOrNull() == nullptr) {
        if (curFn_ && curFn_->getReturnType()->isVoidTy()) builder_.CreateRetVoid();
    }
}

void Codegen::emitStmt(Stmt& s) {
    switch (s.kind) {
        case Stmt::K::Let: {
            registerName(s.varName);
            std::string type = s.varType.empty() ? sema_.exprType(*s.init) : s.varType;
            llvm::Type* ty = llvmType(type);
            llvm::AllocaInst* slot = createAlloca(ty, cname(s.varName));
            if (s.init) builder_.CreateStore(emitExpr(*s.init), slot);
            else if (type == "str") builder_.CreateStore(getCString(""), slot);
            else if (type == "bool") builder_.CreateStore(llvm::ConstantInt::get(ctx_, llvm::APInt(1, 0)), slot);
            else builder_.CreateStore(llvm::ConstantInt::get(ctx_, llvm::APInt(32, 0)), slot);
            declareVar(s.varName, slot);
            break;
        }

        case Stmt::K::ExprStmt:
            emitExpr(*s.init);
            break;

        case Stmt::K::If: {
            llvm::Value* cond = emitExpr(*s.cond);
            llvm::Function* f = builder_.GetInsertBlock()->getParent();
            llvm::BasicBlock* thenBB = llvm::BasicBlock::Create(ctx_, "j_then", f);
            llvm::BasicBlock* elseBB = llvm::BasicBlock::Create(ctx_, "j_else", f);
            llvm::BasicBlock* mergeBB = llvm::BasicBlock::Create(ctx_, "j_merge", f);
            builder_.CreateCondBr(cond, thenBB, elseBB);

            builder_.SetInsertPoint(thenBB);
            pushScope();
            emitBody(s.thenBody);
            popScope();
            if (builder_.GetInsertBlock()->getTerminatorOrNull() == nullptr) builder_.CreateBr(mergeBB);

            builder_.SetInsertPoint(elseBB);
            pushScope();
            emitBody(s.elseBody);
            popScope();
            if (builder_.GetInsertBlock()->getTerminatorOrNull() == nullptr) builder_.CreateBr(mergeBB);

            builder_.SetInsertPoint(mergeBB);
            break;
        }

        case Stmt::K::While: {
            llvm::Function* f = builder_.GetInsertBlock()->getParent();
            llvm::BasicBlock* condBB = llvm::BasicBlock::Create(ctx_, "j_cond", f);
            llvm::BasicBlock* bodyBB = llvm::BasicBlock::Create(ctx_, "j_body", f);
            llvm::BasicBlock* endBB = llvm::BasicBlock::Create(ctx_, "j_end", f);
            builder_.CreateBr(condBB);

            builder_.SetInsertPoint(condBB);
            llvm::Value* cond = emitExpr(*s.loopCond);
            builder_.CreateCondBr(cond, bodyBB, endBB);

            builder_.SetInsertPoint(bodyBB);
            pushScope();
            emitBody(s.body);
            popScope();
            if (builder_.GetInsertBlock()->getTerminatorOrNull() == nullptr) builder_.CreateBr(condBB);

            builder_.SetInsertPoint(endBB);
            break;
        }

        case Stmt::K::For: {
            llvm::Function* f = builder_.GetInsertBlock()->getParent();
            llvm::BasicBlock* condBB = llvm::BasicBlock::Create(ctx_, "j_cond", f);
            llvm::BasicBlock* bodyBB = llvm::BasicBlock::Create(ctx_, "j_body", f);
            llvm::BasicBlock* stepBB = llvm::BasicBlock::Create(ctx_, "j_step", f);
            llvm::BasicBlock* endBB = llvm::BasicBlock::Create(ctx_, "j_end", f);

            pushScope();
            emitStmt(*s.forInit);           // the `let` loop var
            builder_.CreateBr(condBB);

            builder_.SetInsertPoint(condBB);
            llvm::Value* cond = emitExpr(*s.forCond);
            builder_.CreateCondBr(cond, bodyBB, endBB);

            builder_.SetInsertPoint(bodyBB);
            pushScope();
            emitBody(s.body);
            popScope();
            if (builder_.GetInsertBlock()->getTerminatorOrNull() == nullptr) builder_.CreateBr(stepBB);

            builder_.SetInsertPoint(stepBB);
            emitExpr(*s.forStep);
            if (builder_.GetInsertBlock()->getTerminatorOrNull() == nullptr) builder_.CreateBr(condBB);

            builder_.SetInsertPoint(endBB);
            popScope();
            break;
        }

        case Stmt::K::Return: {
            llvm::Type* rt = curFn_ ? curFn_->getReturnType() : llvm::Type::getVoidTy(ctx_);
            if (s.retExpr) {
                builder_.CreateRet(emitExpr(*s.retExpr));
            } else if (rt->isVoidTy()) {
                builder_.CreateRetVoid();
            } else {
                // main() (i32) with a bare `return;` -> return 0
                builder_.CreateRet(llvm::ConstantInt::get(rt, 0));
            }
            // Continue in a fresh unreachable block so later statements in the
            // same function body still have a valid insertion point.
            llvm::Function* f = builder_.GetInsertBlock()->getParent();
            llvm::BasicBlock* after = llvm::BasicBlock::Create(ctx_, "j_after", f);
            builder_.SetInsertPoint(after);
            break;
        }

        case Stmt::K::Fn:
            throw std::runtime_error("codegen: nested function not allowed");
            break;

        case Stmt::K::Switch:
            throw std::runtime_error("codegen: switch not supported in LLVM backend");
            break;
    }
}

// ---- expressions --------------------------------------------------------------

llvm::Value* Codegen::emitExpr(const Expr& e) {
    switch (e.kind) {
        case Expr::K::IntLit:
            return llvm::ConstantInt::get(ctx_, llvm::APInt(32, e.iVal, /*isSigned=*/true));

        case Expr::K::StrLit:
            return emitStringLiteral(e.name);

        case Expr::K::BoolLit:
            return llvm::ConstantInt::get(ctx_, llvm::APInt(1, e.iVal ? 1 : 0));

        case Expr::K::Ident: {
            llvm::AllocaInst* slot = lookupVar(e.name);
            if (!slot) throw std::runtime_error("codegen: undefined variable '" + e.name + "'");
            return builder_.CreateLoad(slot->getAllocatedType(), slot, cname(e.name));
        }

        case Expr::K::Unary: {
            llvm::Value* v = emitExpr(*e.lhs);
            if (e.op == "-")
                return builder_.CreateNeg(v, "j_neg");
            if (e.op == "!")
                return builder_.CreateXor(v, llvm::ConstantInt::get(ctx_, llvm::APInt(1, 1)), "j_not");
            throw std::runtime_error("codegen: unknown unary '" + e.op + "'");
        }

        case Expr::K::Binary:
            if (e.op == "=") return emitAssign(e);
            if (e.op == "&&") return emitShortCircuit(e, true);
            if (e.op == "||") return emitShortCircuit(e, false);
            return emitBinary2(e);

        case Expr::K::Call:
            return emitCall(e);
    }
    throw std::runtime_error("codegen: unknown expression");
}

// (helper split out so emitExpr stays readable)
llvm::Value* Codegen::emitAssign(const Expr& e) {
    llvm::AllocaInst* slot = lookupVar(e.lhs->name);
    if (!slot) throw std::runtime_error("codegen: assignment to undefined variable '" + e.lhs->name + "'");
    llvm::Value* v = emitExpr(*e.rhs);
    builder_.CreateStore(v, slot);
    return v;  // assignment evaluates to the assigned value
}

llvm::Value* Codegen::emitShortCircuit(const Expr& e, bool isAnd) {
    llvm::Function* f = builder_.GetInsertBlock()->getParent();
    llvm::BasicBlock* lhsBB = builder_.GetInsertBlock();
    llvm::BasicBlock* rhsBB = llvm::BasicBlock::Create(ctx_, "j_rhs", f);
    llvm::BasicBlock* endBB = llvm::BasicBlock::Create(ctx_, "j_short", f);

    llvm::Value* lhs = emitExpr(*e.lhs);
    if (isAnd) builder_.CreateCondBr(lhs, rhsBB, endBB);
    else       builder_.CreateCondBr(lhs, endBB, rhsBB);

    builder_.SetInsertPoint(rhsBB);
    llvm::Value* rhs = emitExpr(*e.rhs);
    builder_.CreateBr(endBB);

    builder_.SetInsertPoint(endBB);
    llvm::PHINode* phi = builder_.CreatePHI(llvm::Type::getInt1Ty(ctx_), 2, "j_sc");
    phi->addIncoming(lhs, lhsBB);
    phi->addIncoming(rhs, rhsBB);
    return phi;
}

// ---- binary operators ---------------------------------------------------------

llvm::Value* Codegen::emitBinary2(const Expr& e) {
    // String equality / inequality goes through strcmp-like runtime helper.
    std::string lt = sema_.exprType(*e.lhs);
    if (lt == "str") {
        llvm::FunctionCallee eq = getRuntimeFn("j_str_eq", llvm::Type::getInt1Ty(ctx_),
                                               {llvm::PointerType::get(ctx_, 0), llvm::PointerType::get(ctx_, 0)});
        llvm::Value* a = emitExpr(*e.lhs);
        llvm::Value* b = emitExpr(*e.rhs);
        llvm::Value* r = builder_.CreateCall(eq, {a, b});
        if (e.op == "==") return r;
        if (e.op == "!=") return builder_.CreateXor(r, llvm::ConstantInt::get(ctx_, llvm::APInt(1, 1)));
        throw std::runtime_error("codegen: bad str operator '" + e.op + "'");
    }

    llvm::Value* l = emitExpr(*e.lhs);
    llvm::Value* r = emitExpr(*e.rhs);
    llvm::Type* it = llvm::Type::getInt32Ty(ctx_);

    if (e.op == "+") return builder_.CreateAdd(l, r, "j_add");
    if (e.op == "-") return builder_.CreateSub(l, r, "j_sub");
    if (e.op == "*") return builder_.CreateMul(l, r, "j_mul");
    if (e.op == "/") return builder_.CreateSDiv(l, r, "j_div");
    if (e.op == "%") return builder_.CreateSRem(l, r, "j_mod");

    if (e.op == "==") return builder_.CreateICmpEQ(l, r, "j_eq");
    if (e.op == "!=") return builder_.CreateICmpNE(l, r, "j_ne");
    if (e.op == "<")  return builder_.CreateICmpSLT(l, r, "j_lt");
    if (e.op == "<=") return builder_.CreateICmpSLE(l, r, "j_le");
    if (e.op == ">")  return builder_.CreateICmpSGT(l, r, "j_gt");
    if (e.op == ">=") return builder_.CreateICmpSGE(l, r, "j_ge");

    throw std::runtime_error("codegen: unknown binary '" + e.op + "'");
}

// ---- function calls -----------------------------------------------------------

llvm::Value* Codegen::emitCall(const Expr& e) {
    if (e.name == "print") {
        const Expr& arg = *e.args[0];
        std::string t = sema_.exprType(arg);
        llvm::FunctionCallee printfFn =
            getRuntimeFn("printf", llvm::Type::getInt32Ty(ctx_), {llvm::PointerType::get(ctx_, 0)}, /*vararg=*/true);
        llvm::Value* fmt = getPrintFormat(t);
        if (t == "int" || t == "str") {
            return builder_.CreateCall(printfFn, {fmt, emitExpr(arg)});
        }
        // bool: select "true"/"false" then %s
        llvm::Value* c = emitExpr(arg);
        llvm::Value* tru = getCString("true");
        llvm::Value* fls = getCString("false");
        llvm::Value* sel = builder_.CreateSelect(c, tru, fls, "j_sel");
        return builder_.CreateCall(printfFn, {fmt, sel});
    }

    if (e.name == "len") {
        llvm::FunctionCallee lenFn =
            getRuntimeFn("j_str_len", llvm::Type::getInt32Ty(ctx_), {llvm::PointerType::get(ctx_, 0)});
        return builder_.CreateCall(lenFn, {emitExpr(*e.args[0])});
    }

    // Forensics stdlib -> external runtime.c functions.
    auto rt = kRuntimeSigs.find(e.name);
    if (rt != kRuntimeSigs.end()) {
        const RtSig& sig = rt->second;
        llvm::Type* retTy = llvmType(sig.ret == "ptr" ? "str" : (sig.ret == "i32" ? "int" : (sig.ret == "i1" ? "bool" : "void")));
        std::vector<llvm::Type*> args;
        for (auto& p : sig.params)
            args.push_back(llvmType(p == "ptr" ? "str" : (p == "i32" ? "int" : "bool")));
        std::string cname = "j_" + e.name;   // sys.process_list -> j_sys_process_list
        for (auto& ch : cname) if (ch == '.') ch = '_';
        llvm::FunctionCallee f = getRuntimeFn(cname, retTy, args);
        std::vector<llvm::Value*> av;
        for (auto& a : e.args) av.push_back(emitExpr(*a));
        return builder_.CreateCall(f, av);
    }

    // User function.
    llvm::Function* f = mod_->getFunction(cname(e.name));
    if (!f) throw std::runtime_error("codegen: undefined function '" + e.name + "'");
    std::vector<llvm::Value*> av;
    for (auto& a : e.args) av.push_back(emitExpr(*a));
    return builder_.CreateCall(f, av);
}

// ---- module emission -----------------------------------------------------------

std::unique_ptr<llvm::Module> Codegen::emit(const Program& prog) {
    mod_ = std::make_unique<llvm::Module>("jocky", ctx_);

    // ---- 1. Collect signatures, create LLVM functions (forward refs OK).
    std::vector<Stmt*> userFns;
    Stmt* mainFn = nullptr;
    for (auto& s : prog.stmts) {
        if (s->kind != Stmt::K::Fn) continue;
        if (s->fnName == "main") { mainFn = s.get(); continue; }
        registerName(s->fnName);
        std::vector<llvm::Type*> params;
        for (auto& p : s->params) params.push_back(llvmType(p.second));
        llvm::FunctionType* ft = llvm::FunctionType::get(llvmType(s->fnRetType), params, false);
        auto* f = llvm::Function::Create(ft, llvm::GlobalValue::InternalLinkage, cname(s->fnName), *mod_);
        f->setDSOLocal(true);
        userFns.push_back(s.get());
    }

    // ---- 2. Create `main` as i32(void) like a C entry point.
    llvm::FunctionType* mainTy = llvm::FunctionType::get(llvm::Type::getInt32Ty(ctx_), {}, false);
    auto* mainF = llvm::Function::Create(mainTy, llvm::GlobalValue::ExternalLinkage, "main", *mod_);
    mainF->setDSOLocal(true);

    // ---- 3. Emit user function bodies.
    for (auto* fnStmt : userFns) {
        llvm::Function* f = mod_->getFunction(cname(fnStmt->fnName));
        curFn_ = f;
        llvm::BasicBlock* entry = llvm::BasicBlock::Create(ctx_, "entry", f);
        entryBlock_ = entry;
        builder_.SetInsertPoint(entry);
        pushScope();
        emitFnParams(f, *fnStmt);
        emitBody(fnStmt->fnBody);
        popScope();
        // Ensure a terminator for non-void functions that might fall off the end.
        if (f->getReturnType()->isVoidTy()) {
            // emitBody already terminates void functions.
        } else {
            llvm::BasicBlock* cur = builder_.GetInsertBlock();
            if (cur && cur->getTerminatorOrNull() == nullptr) {
                llvm::Value* zero = llvm::Constant::getNullValue(f->getReturnType());
                builder_.CreateRet(zero);
            }
        }
    }

    // ---- 4. Emit `main`: top-level statements, then the user main body.
    curFn_ = mainF;
    llvm::BasicBlock* entry = llvm::BasicBlock::Create(ctx_, "entry", mainF);
    entryBlock_ = entry;
    builder_.SetInsertPoint(entry);
    pushScope();
    for (auto& s : prog.stmts) {
        if (s->kind != Stmt::K::Fn) emitStmt(*s);
    }
    if (mainFn) {
        for (auto& body : mainFn->fnBody) emitStmt(*body);
    }
    if (builder_.GetInsertBlock()->getTerminatorOrNull() == nullptr) {
        builder_.CreateRet(llvm::ConstantInt::get(ctx_, llvm::APInt(32, 0)));
    }
    popScope();
    curFn_ = nullptr;

    // ---- 5. Build markers (polymorphism): always emitted.
    addBuildMarkersToModule();

    if (llvm::verifyModule(*mod_, &llvm::errs())) {
        throw std::runtime_error("codegen: LLVM verifier failed");
    }

    return std::move(mod_);
}