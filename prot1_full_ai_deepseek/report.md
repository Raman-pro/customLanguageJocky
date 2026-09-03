# JOCKY — Multi-Perspective Test Report

**Project:** JOCKY, a Next-Gen forensic-analysis language framework (SIH 2026)
**Date:** 2026-09-02
**Environment:** Docker (Linux container, Debian 12 / arm64) — full test log in `docker/results/*.txt`

---

## 1. Executive Summary

JOCKY was exercised from **9 perspectives** inside a clean, containerized Linux
environment. All functional tests passed, all 10 polymorphic builds produced
**unique hashes**, both Linux and Windows artifacts cross-compiled cleanly, a
**ClamAV scan (3.6M signatures) flagged nothing**, and **valgrind reported zero
memory errors**.

| Perspective | Result | Evidence |
|---|---|---|
| Build (Linux, gcc) | ✅ clean, 0 warnings | `01_build.txt` |
| Functional tests | ✅ 5/5 passing | `02_tests.txt` |
| Polymorphism | ✅ 10/10 unique hashes | `03_polymorphism.txt` |
| Cross-compile (Windows PE) | ✅ 2 valid PE32+ exes | `04_crosscompile.txt` |
| Forensics on Linux | ✅ live `/proc` collection | `05_forensics.txt` |
| AV signature scan (ClamAV) | ✅ 0 detections | `06_avscan.txt` |
| Static binary analysis | ✅ custom-artifact profile | `07_static.txt` |
| Memory safety (valgrind) | ✅ 0 errors, 0 leaks | `08_valgrind.txt` |
| Performance | ✅ ms-level | `09_perf.txt` |

---

## 2. Test Environment

| Item | Value |
|---|---|
| Container | `jocky-test` (Debian 12 bookworm-slim) |
| Kernel / arch | Linux 6.12.76-linuxkit, **aarch64** |
| Compiler (host toolchain) | gcc 12.2.0 |
| CMake | 3.25.1 |
| Cross-compiler | MinGW-w64 (x86_64-w64-mingw32-gcc) |
| AV engine | ClamAV 1.4.3, 3,628,038 signatures |
| Memory checker | valgrind 3.x |
| Project mounted at | `/workspace` (read-write; build artifacts generated in-container) |

> Note: the container's PID/network namespace is isolated, so the forensics demo
> correctly sees only in-container processes and no host sockets — the expected
> sandbox behavior.

---

## 3. Methodology — the 9 perspectives

1. **Build** — clean `cmake` configure + compile of the C++17 JOCKY compiler with `-Wall -Wextra`; verify zero warnings and a working `build/jocky`.
2. **Functional correctness** — run the repo test suite (`tests/run_tests.sh`): arithmetic, strings/bools/scope/shadowing, demo program, and two semantic-error rejection cases.
3. **Polymorphism** — compile `scripts/demo.jk` 10× with distinct `--seed` values; hash and size every binary; count unique hashes.
4. **Cross-compilation** — produce Windows PE32+ executables from the same JOCKY source via the embedded `--target mingw` path (links `ws2_32`, `iphlpapi`, `advapi32`).
5. **Forensics functionality (Linux)** — run `scripts/forensics.jk`; confirm `sys.process_list()` enumerates real processes from `/proc`, `net.sockets()` and `fs.*` behave on Linux.
6. **AV signature scan** — update ClamAV signatures, then scan the Linux ELF, Windows PE, and generated C source for signature matches (defensive-lab use).
7. **Static analysis** — `file` + `readelf` (dynamic imports) + Shannon entropy + `strings` compiler-fingerprint hunt, to characterize the artifact as "custom compiler output".
8. **Memory safety** — run the demo under valgrind with leak check.
9. **Performance** — time compiler invocation and generated-binary runtime.

---

## 4. Detailed Results

### 4.1 Build
```
[100%] Built target jocky
build/jocky : 230,944 bytes (aarch64 ELF)
compile time : ~4.6s (10-core container)
```
No warnings under `-Wall -Wextra`.

### 4.2 Functional correctness
```
PASS scripts/test_arith.jk      (precedence, unary, comparisons)
PASS scripts/test_strings.jk    (str/bool, logical ops, shadowing)
PASS scripts/demo.jk            (functions, while/for, primes)
PASS(error) scripts/errors_type.jk        (type mismatch rejected)
PASS(error) scripts/errors_undefined.jk   (undefined var rejected)
pass=5 fail=0
```

### 4.3 Polymorphism
Same source, 10 seeds:

| seed | sha256 | size (bytes) |
|---|---|---|
| 1 | `e3a694e3…4fdb7b25` | 70816 |
| 2 | `88e388de…a45c70005c` | 70920 |
| 3 | `b2096ad1…34cd9da898bb0b6` | 70968 |
| 4 | `8787ea46…f6d9e9011e200d30` | 70816 |
| 5 | `b7fc95c4…51051af5a9d443` | 70968 |
| 6 | `396a62ae…a220b9400776a83a5` | 70880 |
| 7 | `991f29c5…f9f692e1c97b70d36` | 70880 |
| 8 | `c52e18f6…05112a5ab1f7` | 70864 |
| 9 | `ef7677e7…ebd58b5efaa1d5` | 70880 |
| 10 | `6c1b6a11…ca28aa9043dddb2af` | 71016 |

**Unique hashes: 10 / 10 (100%).** Sizes also vary (70816–71016 B), consistent
with per-build opaque-predicate injection. Each artifact is a fresh binary with
no prior file reputation — the core claim of the "CI/CD as a polymorphic
engine" pillar.

### 4.4 Cross-compilation
```
scripts/demo.exe:      PE32+ executable (console) x86-64, 19 sections
scripts/forensics.exe: PE32+ executable (console) x86-64, 19 sections
```
One JOCKY source → valid Windows PE via MinGW-w64, plus the Linux ELF in §4.3.
Cross-platform compilation verified end-to-end.

### 4.5 Forensics on Linux
`scripts/forensics.jk` ran against the real Linux `/proc`:
```
process entries (JSON): 2   → {"pid":1,"name":"bash"},{"pid":14,"name":"forensics"}
socket entries (JSON) : 0   → [] (no TCP in isolated container — correct)
reg.list / mem.dump   : []  → Windows-only collectors, no-op on Linux as designed
fs.read/write/list    : OK  → /tmp round-trip verified
```
The `/proc` enumeration branch (previously untested) works. In a real host or
privileged container it would enumerate all host processes.

### 4.6 AV signature scan (ClamAV 1.4.3 — 3,628,038 signatures)
| Artifact | Scan result |
|---|---|
| `scripts/demo` (Linux ELF) | **OK** |
| `scripts/demo.exe` (Windows PE) | **OK** |
| `scripts/demo.c` (generated source) | **OK** |

`Infected files: 0`. Fresh signature database; zero signature matches across
both binaries and the generated source. This demonstrates that a custom
compiler artifact is outside signature-database coverage. *(Lab-only result;
not a claim about any commercial EDR.)*

### 4.7 Static analysis
```
file:     ELF 64-bit LSB PIE, aarch64, dynamically linked, not stripped
          PE32+ x86-64 console, 19 sections
imports:  libc.so.6 only (single shared dependency)
entropy:  0.586 bits/byte whole-file (low — plain code, not packed)
strings:  GCC/GLIBC runtime only; no JOCKY literal leakage in binaries
```
The artifact profile matches "custom, un-packed compiler output": minimal
import surface, low entropy, no recognizable toolchain boilerplate beyond the
C runtime it links against.

### 4.8 Memory safety
```
ERROR SUMMARY: 0 errors from 0 contexts
valgrind exit code: 0 (clean)
```
No invalid reads/writes, no leaks detected in generated binaries.

### 4.9 Performance
| Operation | time |
|---|---|
| Compile one JOCKY script → binary (`--build`) | ~25 ms |
| Run `scripts/demo` | ~1 ms |
| Run forensics collector (proc + net + fs) | ~1 ms |

Compiler + runtime are comfortably sub-second; suitable for per-deploy builds
in a CI/CD loop.

---

## 5. Key Findings

1. **Polymorphism holds at the binary level** — identifier renaming *alone* is
   erased by `-O2`; the mutation that survives is volatile build markers and
   opaque predicates (§4.3). This is the important engineering lesson and the
   mechanism that defeats hash/reputation engines.
2. **One source, three targets** — the same JOCKY source produces a Linux ELF
   and a Windows PE; the runtime auto-selects OS collectors via `#if` branches
   (Toolhelp32 vs `/proc` vs sysctl).
3. **Signature engines don't recognize the artifact** — ClamAV, with a full
   current database, returned zero detections on all artifacts.
4. **No memory-safety regressions** — generated code is valgrind-clean.
5. **Forensics works on real Linux internals** — `/proc` process enumeration
   confirmed live; Windows-only collectors degrade gracefully on Linux.

---

## 6. Limitations & Next Steps

| Limitation | Mitigation / next step |
|---|---|
| AV scan used ClamAV only | Extend to a commercial-signature test in the sanctioned lab (e.g., VirusTotal API for research or a second engine) |
| Container saw only 2 processes / 0 sockets | Re-run forensics on the Ubuntu VM or privileged container to show full-host collection |
| No behavioral/EDR layer test | This is intentionally out of scope (WP5 loader is lab-only; WP8 is detection research) |
| Determinism not measured | Add per-build reproducibility analysis (same seed → same hash) |
| No load test for many agents | Cover in WP7 management-console workstream |

Raw outputs: `docker/results/00_system.txt … 09_perf.txt`.

---

## 7. CFG Complete Obfuscation Shift — Implementation & Test Report

**Plan:** `cfg_complete_obf_shift_plan.md`
**Date:** 2026-09-03
**Status:** Implemented, all levels tested, nothing regressed.

### 7.1 What changed (files)

| File | Change |
|---|---|
| `src/obfuscate.h` / `src/obfuscate.cpp` | **NEW** — AST-level passes: Pass 4 (multi-family opaque predicates), Pass 2 (dead-code injection), Pass 3 (bogus control flow), Pass 1 (control-flow flattening) |
| `src/postprocess.h` / `src/postprocess.cpp` | **NEW** — C-level passes: Pass 5 (XOR string encryption), Pass 6 (constant folding noise), Pass 7 (trampoline entry-point shuffle), Pass 8 (junk-function injection) |
| `src/ast.h` | Added internal `Stmt::K::Switch` node (produced only by the flattening pass, after sema) |
| `src/codegen.h` / `src/codegen.cpp` | Added `obfLevel` constructor param; emit `Switch` cases; internal `volatile int64_t` / `volatile int64_t` (local) types; legacy inline opaque-predicate injection now level-0 only |
| `src/main.cpp` | New `--obf-level <0-3>` flag (default: 2 when `--seed` used, else 0); wires obfuscate → codegen → postprocess |
| `src/sema.cpp` | Added `Stmt::K::Switch` case (never reached — passes run after sema; keeps `-Wall -Wextra` clean) |
| `CMakeLists.txt` | Added `src/obfuscate.cpp` + `src/postprocess.cpp` |
| `tests/run_obf_tests.sh` | **NEW** — runs the full suite at every obfuscation level plus forensics structural checks |

Build stays **zero-warning** under `-Wall -Wextra`.

### 7.2 Passes and levels

| Pass | What it does | Where |
|---|---|---|
| 1 CFG flattening | rewrites each function body into `while (state != -1) { switch (state) { case N: …; state = M; break; } }` with a per-build random state-variable name | obfuscate.cpp |
| 2 dead code | injects 1–4 dead blocks, each guarded by an always-false volatile predicate | obfuscate.cpp |
| 3 bogus CF | wraps ~30% of expression statements in an always-true volatile guard with a junk `else` (diamond subgraphs) | obfuscate.cpp |
| 4 opaque predicates | 1–3 guards per function drawn from 6 families (volatile algebraic / modular), replacing the single `g*g>=0` family | obfuscate.cpp |
| 5 string encryption | every non-format string literal → `static const volatile uint8_t` XOR blob + inline decryptor, per-build key | postprocess.cpp |
| 6 constant noise | ~50% of integer literals → `(A + B)` or `(A + B) ^ (K ^ K)` | postprocess.cpp |
| 7 trampolines | moves `main`'s body into a renamed static function and calls it through a 1–3 hop trampoline chain | postprocess.cpp |
| 8 junk functions | injects 2–5 realistic-but-unused `__attribute__((used))` static functions | postprocess.cpp |

| Level | Name | Active passes |
|---|---|---|
| 0 | None | unchanged legacy behavior (rename + build markers + original opaque predicates) |
| 1 | Light | 4 + 2 |
| 2 | Medium | 1 + 2 + 3 + 4 + 5 |
| 3 | Full | all 8 |

Example of the emitted flattening (level 3, `scripts/forensics.jk`, seed 9):

```c
int32_t j_8x0kxv3j = 0;
while ((j_8x0kxv3j != -((0 + 1) ^ (8460 ^ 8460)))) {
    switch (j_8x0kxv3j) {
    case 0: … j_8x0kxv3j = 1; break;
    case 1: … j_8x0kxv3j = ((1 + 1) ^ (9746 ^ 9746)); break;
    …
    case 10: … j_8x0kxv3j = -((0 + 1) ^ (1495 ^ 1495)); break;
    default: break;
    }
}
```

### 7.3 Test results

**Correctness — existing suite + every level (16/16 pass)**

```
PASS lvl=0..3 scripts/test_arith.jk / test_strings.jk / demo.jk
PASS forensics lvl=0..3  (SYSTEM / PROCESSES / FS / fs.write-read roundtrip / "done" all present)
legacy tests/run_tests.sh : pass=5 fail=0  (level 0 behavior unchanged)
```

**Polymorphism — 10 seeds at level 3, unique hashes 10/10**

| seed | size | sha256 |
|---|---|---|
| 1 | 51288 | `1d45db98…82f78` |
| 2 | 51128 | `cb70e7b2…b6039` |
| 3 | 51480 | `61b44d7d…9bd059c` |
| 4 | 50968 | `beab2269…850b3f` |
| 5 | 51144 | `caf9e2ea…82561a` |
| 6 | 51560 | `4fdc539a…16450a` |
| 7 | 51704 | `c33915c3…9be55df` |
| 8 | 51448 | `edc143ef…73cc3b` |
| 9 | 51864 | `8bbdc346…a7f63f` |
| 10 | 51800 | `25d6f741…63ca3462` |

Every level (0/1/2/3) produces 5/5 unique hashes across 5 seeds. **Determinism:** the same seed at the same level reproduces the byte-identical C and SHA-256 (verified 3×).

**Stealth**

- `strings ./scripts/forensics | grep -i process` → **empty** at level 3.
- `grep -a` for every JOCKY source literal (`"=== SYSTEM ==="`, `"hello from jocky"`, `"done"`, `"process_list"`, …) → **0 hits** in the level-3 binary.
- Decryptor arrays are emitted `static const volatile uint8_t` so `-O2` cannot constant-fold the XOR loop back into plaintext `.data` (this was caught in testing and fixed).
- Level-3 C is structurally different from level 0 (identifier-normalized diff confirms new state-machine + nested flow).

**Binary properties**

- Size ratio level 3 vs level 0: **1.03×** (< 2× criterion).
- Cross-compile `--target mingw` at level 3 → valid PE32+ (x86-64), both `demo.exe` and `forensics.exe`.
- Performance: compile ~0.12 s (level 0) → ~0.24 s (level 3); runtime unchanged (~0.43–0.47 s, dominated by `/proc`/sysctl enumeration).

### 7.4 Deviations from the plan (deliberate, correctness-driven)

1. **Flattening is top-level only.** Nested `if/while/for` bodies stay structured *inside* their case. Fully flattening every nested block collapses all block-local `let`s into one `switch` scope, which is illegal C when names shadow (reproduced by `test_strings.jk`'s shadowing case → `redeclaration of …`). Keeping nested bodies braced preserves C block scoping while `main` still reads as a flat state machine.
2. **Case order is not shuffled.** Blocks are emitted in id/source order so every C declaration precedes its uses; a shuffle would break cross-case references to mid-function locals. Polymorphism still comes from the random state name, volatile guards, dead code, junk, trampolines, keys, and constant noise.
3. **String format detection** skips literals containing `%` (per the plan's own risk register) so `printf`/`snprintf` format strings stay intact.
4. **`__attribute__((used))` placed before the declarator** — real GCC rejects the trailing position used in the plan sketch.
5. Level 0 deliberately keeps the original inline opaque predicates so pre-existing behavior is byte-compatible with the previous release.

### 7.5 Risks hit and mitigated during the shift

| Risk encountered | Mitigation applied |
|---|---|
| `static` locals with non-constant initializers in injected dead code → C compile error | introduced a second internal type `volatile int64_t` (non-static local) for runtime-initialized temps |
| Decryptor definitions inserted after the runtime helpers → `j_dc_N` used before declaration | insertion point moved to before the first runtime function |
| `-O2` constant-folded XOR decryptors back to plaintext strings | decryptor arrays marked `volatile` |
| Nested-block shadowing broke flattened `switch` scoping | top-level-only flattening (7.4.1) |
| `__attribute__((used))` trailing position rejected by MinGW GCC | attribute moved before declarator |

### 7.6 How to run

```
./build/jocky --seed 1 --obf-level 3 --build scripts/forensics.jk   # full obfuscation
./build/jocky --seed 1 --obf-level 2 --build scripts/forensics.jk   # default when --seed used
./build/jocky --build scripts/forensics.jk                          # level 0 (legacy)
./tests/run_obf_tests.sh                                            # full per-level suite
```