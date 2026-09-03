# JOCKY — LLVM Backend Implementation Plan

> A forensic-analysis language + compiler (SIH 2026) whose distinguishing
> feature is a **real LLVM frontend** instead of the C-transpilation used by
> `prot1_full_ai_deepseek`.

**IMPORTANT — AUTHORIZED USE ONLY**
This plan describes techniques that are dual-use (defensive + offensive).
Everything here is intended strictly for **authorized** security testing: your
own lab machines, CTFs, university research, or sanctioned red-team
engagements where you have written permission. Keep every test inside a
controlled, disconnected lab environment (VMs with snapshots). Never deploy
any component of this project against systems you do not own or have explicit
written consent to test.

---

## 0. Why an LLVM backend?

prot1 transpiles JOCKY → C and relies on `cc`/`gcc`/MinGW for codegen. The
compiler's "custom artifact" claim rests on renamed identifiers and a mutating
C postprocessor. This project upgrades the backend to **LLVM IR codegen**:

- The compiler itself is a genuine compiler frontend: lexer → parser → AST →
  semantic analysis → **LLVM IR in memory** → optimization → native object.
- Polymorphism happens **at the IR level** (markers, opaque predicates, string
  encryption, junk functions, trampolines), not by text-munging C.
- One pipeline serves Linux, macOS, and Windows (mingw) via LLVM targets and a
  portable C runtime.

## 1. Architecture

```
src/
  token / lexer / parser / ast / sema   — frontend (language "Read", .rd)
  codegen.h/.cpp                        — LLVM IRBuilder codegen
  obfuscate.h/.cpp                      — IR-level polymorphism passes
  main.cpp                              — CLI, PassBuilder O2, object emit, link
runtime/runtime.c                       — forensic stdlib (compiled on demand)
scripts/*.rd + *.expect                 — deterministic test programs
tests/run_tests.sh                      — full suite at obf levels 0..3
```

### Frontend (inherited from prot1, language-agnostic)

- Recursive-descent parser; AST with source positions; sema builds symbol
  tables and resolves every expression's type (recorded for codegen).

### LLVM codegen

| Read | LLVM |
|---|---|
| `int` | `i32` |
| `str` | `ptr` (opaque i8*) |
| `bool` | `i1` |
| `void` | `void` |

- Variables → entry-block allocas (promotable by mem2reg at O2).
- `if`/`while`/`for` → basic blocks; `&&`/`||` → short-circuit blocks + `phi`.
- Recursion / mutual recursion → all `Function`s created before bodies.
- `main` → `i32 @main()` (C entry), wrapping top-level statements + user body.
- Builtins: `print` → `printf` (typed format), `len` → `j_str_len`,
  stdlib collectors → external `j_*` calls linked from `runtime.c`.

### Obfuscation (IR-level)

| Level | Passes |
|---|---|
| 0 | seeded renaming (functions, globals, allocas) + volatile build markers kept via `llvm.compiler.used` |
| 1 | opaque predicates: `load volatile g; g*g >= 0` diamond branches that survive O2 |
| 2 | per-string XOR encryptors (volatile decrypt loops, encrypted `.rodata`) + junk functions |
| 3 | entry-point trampoline chain (1..3) burying the real `main` |

### Driver (`--build`)

1. codegen → `Module`
2. obfuscation passes
3. `PassBuilder::buildPerModuleDefaultPipeline(O2)` (new PM)
4. `TargetMachine::addPassesToEmitFile` (legacy PM) → `.o`
5. `cc`/mingw-gcc compile `runtime.c` and link

## 2. Work packages

| # | WP | Status |
|---|---|---|
| 1 | LLVM 23 toolchain discovery + CMake skeleton | done |
| 2 | LLVM IR codegen for the full core language | done |
| 3 | IR obfuscation: markers, opaque preds, string enc, junk, trampoline | done |
| 4 | Forensic runtime (`runtime.c`) + native/mingw linking | done |
| 5 | Scripts + `.expect` + test runner (all obf levels) | done |
| 6 | Docs (README / LANGUAGE / plan) | done |
| 7 | CI matrix (native + mingw, 20-build hash table) | next |
| 8 | Management console ingestion of JSON artifacts | next |

## 3. Definition of done (demo)

1. Write `forensics.rd` listing processes, TCP sockets, and reading a file.
2. `jocky --build` → native binary; `--target mingw` → `.exe`.
3. `--seed 42` vs `--seed 7` at `--obf-level 3` → different SHA-256 hashes;
   same seed → identical.
4. `strings` on the level-2/3 binary shows no plaintext literals.
5. Test suite passes at levels 0–3.

## 4. Risks & mitigations

| Risk | Mitigation |
|---|---|
| LLVM API churn (headers differ across versions) | pin `llvm-config` discovery; isolated in `main.cpp`/`codegen.cpp` |
| Optimizer folding away obfuscation | volatile globals/loads + `llvm.compiler.used` so O2 cannot remove them |
| Cross-platform runtime drift | single portable `runtime.c`, `#ifdef` per OS, graceful no-ops for Windows-only collectors |
| Ethical/legal exposure | authorized-lab-only posture in README/plan; forensic mission first |