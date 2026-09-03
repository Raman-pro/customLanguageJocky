#pragma once

#include "ast.h"

#include <cstdint>
#include <random>

// AST-level obfuscation passes. Run AFTER semantic analysis and BEFORE
// codegen, so the injected nodes never have to survive a type check.
//
// Passes implemented here:
//   Pass 4 - Enhanced opaque predicates (multi-family, volatile-backed)
//   Pass 2 - Dead code injection
//   Pass 3 - Bogus control flow (diamond subgraphs)
//   Pass 1 - Control flow flattening (while(true) { switch(state) { ... } })
//
// Level mapping (see --obf-level):
//   level >= 1 : Pass 4 + Pass 2
//   level >= 2 : also Pass 3 + Pass 1
namespace obfuscate {

// Applies the AST transforms for the requested obfuscation level to every
// function body in the program. Uses `rng` for all randomness so builds are
// reproducible when seeded.
void run(Program& prog, std::mt19937_64& rng, int level);

}  // namespace obfuscate