#pragma once

#include <cstdint>
#include <random>
#include <string>

// C-level post-processing passes that mutate the emitted C text after codegen.
// These need no AST knowledge -- they operate on the final C source string.
//
// Passes implemented here:
//   Pass 5 - String encryption (XOR blobs + inline decryptors)
//   Pass 6 - Constant folding noise
//   Pass 7 - Trampoline / entry-point shuffle
//   Pass 8 - Junk function injection
//
// Level mapping (see --obf-level):
//   level >= 2 : Pass 5
//   level >= 3 : Pass 6 + Pass 7 + Pass 8
namespace postprocess {

// Returns the transformed C source. `level` selects which passes run and
// `rng` drives all randomness (seeded -> reproducible builds).
std::string run(std::string c, std::mt19937_64& rng, int level);

}  // namespace postprocess