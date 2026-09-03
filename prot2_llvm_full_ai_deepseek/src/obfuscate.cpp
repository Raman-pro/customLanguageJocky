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
    llvm::Value* sq = b.CreateMul(g, g, "j_sq");
    llvm::Value* c = b.CreateICmpSGE(sq, llvm::ConstantInt::get(llvm::Type::getInt32Ty(C), 0), "j_c");
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
    llvm::Value* mod = b.CreateSRem(mul, llvm::ConstantInt::get(i32, 1009), "j_q");
    b.CreateUnreachable();
    return f;
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
    if (level >= 2) {
        junk = makeJunkFunction(M, rng);
        std::vector<llvm::GlobalValue*> keep = {junk};
        llvm::appendToCompilerUsed(M, keep);
        // A couple of extra unreferenced junk functions at level 3.
        int extra = (level >= 3) ? 2 + static_cast<int>(rng() % 3) : 0;
        std::vector<llvm::GlobalValue*> more;
        for (int i = 0; i < extra; ++i) more.push_back(makeJunkFunction(M, rng));
        if (!more.empty()) llvm::appendToCompilerUsed(M, more);
    }

    for (auto& F : M) {
        if (F.isDeclaration()) continue;
        int n = 1 + static_cast<int>(rng() % 3);
        for (int i = 0; i < n; ++i) insertOpaquePredicate(F, marker, junk, rng);
    }

    if (level >= 3) trampolineMain(M, rng);
}

}  // namespace obfuscate