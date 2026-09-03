#pragma once

#include <llvm/IR/Module.h>

#include <random>

// IR-level obfuscation / polymorphism passes (the LLVM analog of the C-source
// postprocessing in prot1). These run on the generated module, after codegen
// and before the driver runs the optimizer:
//
//   level 1: opaque predicates (volatile-guarded always-true branches)
//   level 2: + junk functions (never called, kept via compiler.used)
//   level 3: + entry-point trampoline chain (real main is buried)
//
// String encryption (level >= 2) is applied inside codegen (each literal gets
// an XOR-decryptor), so it is not repeated here.
namespace obfuscate {

void run(llvm::Module& M, std::mt19937_64& rng, int level);

}  // namespace obfuscate