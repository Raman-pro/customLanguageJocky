#pragma once

#include <llvm/IR/Module.h>

#include <random>

// IR-level obfuscation / polymorphism passes (the LLVM analog of the C-source
// postprocessing in prot1). These run on the generated module, after codegen
// and before the driver runs the optimizer:
//
//   level 1: opaque predicates (volatile-guarded always-true branches)
//   level 2: + string encryption + junk functions (never called, kept via
//            compiler.used). String encryption is a module-level pass so it
//            covers the linked C runtime as well as user `.rd` literals.
//   level 3: + entry-point trampoline chain (real main is buried)
namespace obfuscate {

void run(llvm::Module& M, std::mt19937_64& rng, int level);

}  // namespace obfuscate