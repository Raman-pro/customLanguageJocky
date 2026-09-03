# JOCKY (LLVM backend) — Read Language Compiler

A purpose-built forensic-analysis language ("Read", `.rd` files) compiled by a
real **LLVM frontend** written in C++. This is the LLVM-powered successor to
`prot1_full_ai_deepseek`: instead of transpiling to C and shelling out to a C
compiler, this compiler builds **LLVM IR in memory**, runs the O2 optimization
pipeline, emits a native object file, and links it against a small C runtime.

Every build is automatically **polymorphic** (seeded identifier renaming,
volatile build markers, IR-level opaque predicates, XOR string encryption,
junk functions, and a trampolined entry point) so analysis tooling isn't
pre-flagged by signature/reputation engines. Cross-compiles to Linux/macOS and
Windows (mingw) from one source.

> **Authorized use only.** This is a dual-use project. Run it in your own lab
> (VMs with snapshots) for research/education/sanctioned testing. Never against
> systems you don't own or lack written permission to test.

## Requirements

- **LLVM 15+** (developed against LLVM 23 via Homebrew `llvm`), on PATH or at
  `/opt/homebrew/opt/llvm/bin/llvm-config`
- A C compiler (`cc`/`clang`) for the host, plus `x86_64-w64-mingw32-gcc` for
  Windows cross-compiles

## Build the compiler

```bash
cmake -S . -B build && cmake --build build
```

## Use it

```bash
# dump tokens / AST / LLVM IR
./build/jocky --tokens scripts/demo.rd
./build/jocky --ast    scripts/demo.rd
./build/jocky --emit-ir scripts/demo.rd

# semantic check only
./build/jocky --check  scripts/demo.rd

# optimize + emit object + link -> native binary
./build/jocky --build scripts/demo.rd && ./scripts/demo

# cross-compile a Windows exe (PE32+)
./build/jocky --target mingw --build scripts/demo.rd

# polymorphism: same source, different seed -> different binary every time
./build/jocky --seed 42 --obf-level 3 --build scripts/demo.rd && shasum scripts/demo
./build/jocky --seed 7  --obf-level 3 --build scripts/demo.rd && shasum scripts/demo
```

## Test

```bash
./tests/run_tests.sh
```

Runs every `scripts/*.rd` against its `.expect` at all four obfuscation levels
(seed 424242) plus the semantic-error cases.

## The pipeline

```
.rd source
  └─ lexer → parser/AST → sema (type check)
       └─ LLVM IR codegen            (IRBuilder, in-memory module)
            └─ obfuscation passes    (markers, opaque preds, strings, junk, trampoline)
                 └─ PassBuilder O2   (new pass manager)
                      └─ emit object (TargetMachine)
                           └─ link against runtime/runtime.c → binary
```

- `--seed` drives renaming + marker values: same seed → byte-identical binary,
  different seeds → different hashes.
- `--obf-level 0-3` (default 2 when a seed is given, else 0):
  0 rename + build markers · 1 + opaque predicates · 2 + string encryption +
  junk functions · 3 + entry-point trampoline.
- The forensic stdlib is a portable C runtime (`runtime/runtime.c`) compiled
  and linked on demand; Windows-only collectors degrade gracefully elsewhere.

## Status

- [x] LLVM IR frontend (types, vars, control flow, recursion, shadowing)
- [x] `print` / `len` builtins
- [x] Forensic stdlib: `sys.*`, `env.get`, `net.sockets`, `fs.*`, `reg.list`,
      `mem.dump` — Linux/macOS/Windows
- [x] Polymorphism: seeded renaming, build markers, opaque predicates,
      string encryption, junk functions, trampoline entry
- [x] Native + mingw cross-compile
- [x] Test suite across all obfuscation levels

Try the forensics demo: `./build/jocky --build scripts/forensics.rd && ./scripts/forensics`

See `LANGUAGE.md` for the language reference and `plan.md` for the roadmap.