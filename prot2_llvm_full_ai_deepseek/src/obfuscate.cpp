#include "obfuscate.h"

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Transforms/Utils/ModuleUtils.h>

#include <unordered_set>

namespace obfuscate {
namespace {

const char kChars[] = "abcdefghijklmnopqrstuvwxyz0123456789";

std::string tag(std::mt19937_64& rng, int n) {
    std::string r;
    for (int i = 0; i < n; ++i) r += kChars[rng() % 36];
    return r;
}

// One volatile i32 marker per module; its value is unknown to the optimizer so
// `g*g >= 0` cannot be folded away.
llvm::GlobalVariable* getMarker(llvm::Module& M, std::mt19937_64& rng) {
    auto* ty = llvm::Type::getInt32Ty(M.getContext());
    auto* gv = new llvm::GlobalVariable(
        M, ty, /*isConstant=*/false, llvm::GlobalValue::InternalLinkage,
        llvm::ConstantInt::get(ty, static_cast<int64_t>(rng() & 0xFFFF)),
        "j_g_" + tag(rng, 6));
    gv->setDSOLocal(true);
    return gv;
}

// Injects an always-true opaque-predicate diamond at the head of `F`:
//   %g = load volatile i32, ptr @marker
//   %sq = mul i32 %g, %g            ; g*g >= 0 for every g
//   %c = icmp sge i32 %sq, 0
//   br i1 %c, label %orig, label %dead
//   dead: call @junk(); br %orig
//   orig: <original entry>
// The volatile load survives -O2, so the dead branch is genuinely dead but
// not provably so to the compiler.
void insertOpaquePredicate(llvm::Function& F, llvm::GlobalVariable* marker,
                           llvm::Function* junk, std::mt19937_64& rng) {
    if (F.isDeclaration() || F.empty()) return;
    llvm::LLVMContext& C = F.getContext();
    llvm::BasicBlock* orig = &F.getEntryBlock();
    llvm::BasicBlock* pred = llvm::BasicBlock::Create(C, "j_pred_" + tag(rng, 4), &F, orig);
    llvm::BasicBlock* dead = llvm::BasicBlock::Create(C, "j_dead_" + tag(rng, 4), &F, orig);

    // `pred` is now the function's first block => the new entry.
    llvm::IRBuilder<> b(pred);
    llvm::Value* g = b.CreateLoad(llvm::Type::getInt32Ty(C), marker, /*isVolatile=*/true, "j_g");
    // Promote to 64-bit before squaring: the marker can be up to 0xFFFF, and
    // g*g in 32-bit signed arithmetic overflows for g > 46340 (e.g. 61233^2
    // wraps negative), which would make the "always true" predicate FALSE and
    // route execution into the dead branch. In 64-bit the product always fits
    // and g*g >= 0 holds unconditionally.
    llvm::Value* ge = b.CreateSExt(g, llvm::Type::getInt64Ty(C), "j_ge");
    llvm::Value* sq = b.CreateMul(ge, ge, "j_sq");
    llvm::Value* c = b.CreateICmpSGE(sq, llvm::ConstantInt::get(llvm::Type::getInt64Ty(C), 0), "j_c");
    b.CreateCondBr(c, orig, dead);

    llvm::IRBuilder<> db(dead);
    if (junk) db.CreateCall(junk);
    db.CreateBr(orig);
}

// A junk function: internal, never called by the program, but kept alive via
// llvm.compiler.used. Random arithmetic body. Parameterless + void return so
// it can be invoked from opaque-predicate dead blocks with no arguments.
llvm::Function* makeJunkFunction(llvm::Module& M, std::mt19937_64& rng) {
    llvm::LLVMContext& C = M.getContext();
    auto* i32 = llvm::Type::getInt32Ty(C);
    llvm::FunctionType* ft = llvm::FunctionType::get(llvm::Type::getVoidTy(C), {}, false);
    auto* f = llvm::Function::Create(ft, llvm::GlobalValue::InternalLinkage,
                                     "j_z_" + tag(rng, 6), &M);
    f->setDSOLocal(true);
    llvm::BasicBlock* bb = llvm::BasicBlock::Create(C, "", f);
    llvm::IRBuilder<> b(bb);
    llvm::Value* a = b.CreateAdd(llvm::ConstantInt::get(i32, rng() & 0xFF),
                                 llvm::ConstantInt::get(i32, rng() & 0xFF), "j_s");
    llvm::Value* mul = b.CreateMul(a, llvm::ConstantInt::get(i32, rng() & 0xFF), "j_m");
    b.CreateSRem(mul, llvm::ConstantInt::get(i32, 1009), "j_q");
    b.CreateUnreachable();
    return f;
}

// Encrypts every C-string literal in the module *in place* and decrypts it
// once at the start of main. Because the linked C runtime lives in the same
// module by the time this runs, this covers runtime literals (the webhook URL,
// the curl command, JSON keys, ...) as well as user `.rd` strings -- which is
// what the old codegen-only encryptor missed.
//
// Each candidate global is a constant, NUL-terminated byte array. Its
// initializer is XORed with a per-string key and it is made writable so the
// plaintext only ever exists in memory at run time. The key is read through a
// volatile load so -O2 cannot constant-fold the XOR back into plaintext.
void encryptStrings(llvm::Module& M, std::mt19937_64& rng) {
    llvm::LLVMContext& C = M.getContext();
    auto* i8Ty = llvm::Type::getInt8Ty(C);
    auto* i32Ty = llvm::Type::getInt32Ty(C);

    struct Entry {
        llvm::GlobalVariable* g;
        uint64_t len;                    // number of non-NUL bytes
        llvm::GlobalVariable* keyG;
    };
    std::vector<Entry> entries;

    for (llvm::GlobalVariable& G : M.globals()) {
        if (!G.hasInitializer() || !G.isConstant()) continue;
        if (G.getName().starts_with("llvm.")) continue;   // llvm.ident / llvm.used
        auto* at = llvm::dyn_cast<llvm::ArrayType>(G.getValueType());
        if (!at || !at->getElementType()->isIntegerTy(8)) continue;
        uint64_t n = at->getNumElements();
        if (n < 2) continue;                              // need >= 1 char + NUL

        std::vector<uint8_t> bytes;
        bytes.reserve(n);
        if (auto* cda = llvm::dyn_cast<llvm::ConstantDataArray>(G.getInitializer())) {
            for (uint64_t i = 0; i < n; ++i)
                bytes.push_back(static_cast<uint8_t>(cda->getElementAsInteger(i)));
        } else if (auto* ca = llvm::dyn_cast<llvm::ConstantArray>(G.getInitializer())) {
            for (llvm::Value* op : ca->operands()) {
                auto* ci = llvm::dyn_cast<llvm::ConstantInt>(op);
                if (!ci || !ci->getType()->isIntegerTy(8)) { bytes.clear(); break; }
                bytes.push_back(static_cast<uint8_t>(ci->getZExtValue()));
            }
        } else {
            continue;
        }
        if (bytes.size() != n || bytes.back() != 0) continue;
        bool embeddedNul = false;
        for (uint64_t i = 0; i + 1 < n; ++i)
            if (bytes[i] == 0) { embeddedNul = true; break; }
        if (embeddedNul) continue;

        int key = 1 + static_cast<int>(rng() % 255);
        std::vector<uint8_t> enc(n);
        for (uint64_t i = 0; i + 1 < n; ++i)
            enc[i] = static_cast<uint8_t>(bytes[i] ^ static_cast<uint8_t>(key));
        enc[n - 1] = 0;

        G.setInitializer(llvm::ConstantDataArray::get(C, enc));
        G.setConstant(false);
        G.setUnnamedAddr(llvm::GlobalValue::UnnamedAddr::None);
        G.setAlignment(llvm::Align(1));

        auto* keyG = new llvm::GlobalVariable(
            M, i32Ty, /*isConstant=*/false, llvm::GlobalValue::InternalLinkage,
            llvm::ConstantInt::get(i32Ty, key), "j_sk_" + tag(rng, 6));
        keyG->setDSOLocal(true);

        entries.push_back({&G, n - 1, keyG});
    }

    if (entries.empty()) return;

    auto* ft = llvm::FunctionType::get(llvm::Type::getVoidTy(C), {}, false);
    auto* init = llvm::Function::Create(ft, llvm::GlobalValue::InternalLinkage,
                                        "j_string_init", &M);
    init->setDSOLocal(true);

    llvm::BasicBlock* entry = llvm::BasicBlock::Create(C, "entry", init);
    llvm::IRBuilder<> b(entry);
    llvm::BasicBlock* pred = entry;
    for (const Entry& e : entries) {
        llvm::ArrayType* at = llvm::cast<llvm::ArrayType>(e.g->getValueType());
        llvm::BasicBlock* loop = llvm::BasicBlock::Create(C, "j_dec", init);
        llvm::BasicBlock* done = llvm::BasicBlock::Create(C, "j_done", init);
        b.CreateBr(loop);

        b.SetInsertPoint(loop);
        llvm::PHINode* idx = b.CreatePHI(i32Ty, 2, "j_i");
        idx->addIncoming(llvm::ConstantInt::get(i32Ty, 0), pred);
        llvm::Value* kv = b.CreateLoad(i32Ty, e.keyG, /*isVolatile=*/true, "j_kv");
        llvm::Value* k8 = b.CreateTrunc(kv, i8Ty, "j_k8");
        llvm::Value* p = b.CreateGEP(at, e.g,
                                     {llvm::ConstantInt::get(i32Ty, 0), idx}, "j_p");
        llvm::Value* c = b.CreateLoad(i8Ty, p, /*isVolatile=*/false, "j_c");
        llvm::Value* d = b.CreateXor(c, k8, "j_d");
        b.CreateStore(d, p);
        llvm::Value* next = b.CreateAdd(idx, llvm::ConstantInt::get(i32Ty, 1), "j_next");
        idx->addIncoming(next, loop);
        llvm::Value* cmp = b.CreateICmpULT(next, llvm::ConstantInt::get(i32Ty, e.len), "j_cmp");
        b.CreateCondBr(cmp, loop, done);

        b.SetInsertPoint(done);
        pred = done;
    }
    b.CreateRetVoid();

    // Decrypt everything before any string can be used.
    llvm::Function* main = M.getFunction("main");
    if (main && !main->isDeclaration() && !main->empty()) {
        llvm::BasicBlock& eb = main->getEntryBlock();
        llvm::IRBuilder<> mb(&eb, eb.begin());
        mb.CreateCall(init);
    }
}

// Hides the real main behind 1..3 trampolines:
//   real: j_tr_X() { ...body... }
//   t1:  j_tr_Y() { return j_tr_X(); }
//   t2:  j_tr_Z() { return t1(); }
//   main(){ return t2(); }
void trampolineMain(llvm::Module& M, std::mt19937_64& rng) {
    llvm::Function* main = M.getFunction("main");
    if (!main || main->isDeclaration()) return;
    llvm::LLVMContext& C = M.getContext();
    llvm::FunctionType* ft = main->getFunctionType();

    std::string realName = "j_tr_" + tag(rng, 6);
    main->setName(realName);

    llvm::Function* prev = main;
    int hops = 1 + static_cast<int>(rng() % 3);
    for (int i = 0; i < hops; ++i) {
        auto* tramp = llvm::Function::Create(ft, llvm::GlobalValue::InternalLinkage,
                                             "j_tr_" + tag(rng, 6), &M);
        tramp->setDSOLocal(true);
        llvm::BasicBlock* bb = llvm::BasicBlock::Create(C, "", tramp);
        llvm::IRBuilder<> b(bb);
        llvm::Value* r = b.CreateCall(prev);
        if (ft->getReturnType()->isVoidTy()) b.CreateRetVoid();
        else b.CreateRet(r);
        prev = tramp;
    }

    auto* newMain = llvm::Function::Create(ft, llvm::GlobalValue::ExternalLinkage, "main", &M);
    newMain->setDSOLocal(true);
    llvm::BasicBlock* bb = llvm::BasicBlock::Create(C, "", newMain);
    llvm::IRBuilder<> b(bb);
    llvm::Value* r = b.CreateCall(prev);
    if (ft->getReturnType()->isVoidTy()) b.CreateRetVoid();
    else b.CreateRet(r);
}

}  // namespace

void run(llvm::Module& M, std::mt19937_64& rng, int level) {
    if (level < 1) return;

    llvm::GlobalVariable* marker = getMarker(M, rng);

    llvm::Function* junk = nullptr;
    std::unordered_set<llvm::Function*> junkFns;
    if (level >= 2) {
        junk = makeJunkFunction(M, rng);
        junkFns.insert(junk);
        std::vector<llvm::GlobalValue*> keep = {junk};
        llvm::appendToCompilerUsed(M, keep);
        // A couple of extra unreferenced junk functions at level 3.
        int extra = (level >= 3) ? 2 + static_cast<int>(rng() % 3) : 0;
        std::vector<llvm::GlobalValue*> more;
        for (int i = 0; i < extra; ++i) {
            llvm::Function* jf = makeJunkFunction(M, rng);
            junkFns.insert(jf);
            more.push_back(jf);
        }
        if (!more.empty()) llvm::appendToCompilerUsed(M, more);

        // String encryption must see every global (user + linked runtime), so
        // it runs before the per-function predicate pass adds anything new.
        encryptStrings(M, rng);
    }

    for (auto& F : M) {
        if (F.isDeclaration()) continue;
        // Never insert opaque predicates into the junk functions: they are
        // unreferenced dead code, and their predicate's dead branch calls
        // `junk` (== themselves), which turns the dead branch into an
        // unbounded self-recursion if it is ever reached.
        if (junkFns.count(&F)) continue;
        int n = 1 + static_cast<int>(rng() % 3);
        for (int i = 0; i < n; ++i) insertOpaquePredicate(F, marker, junk, rng);
    }

    if (level >= 3) trampolineMain(M, rng);
}

}  // namespace obfuscate