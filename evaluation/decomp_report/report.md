# JOCKY — Decompiled-Binary Differential Analysis Report

**Scope:** What a Ghidra reverse engineer actually sees when JOCKY-generated binaries are decompiled, compared head-to-head against hand-written C programs with *identical logic*.
**Date:** 2026-09-03
**Host:** macOS (Apple clang 21 / arm64) — all artifacts in `decomp_report/`

---

## Table of contents

1. [Executive summary](#1-executive-summary)
2. [Why JOCKY exists (purpose analysis)](#2-why-jocky-exists)
3. [Methodology & environment](#3-methodology--environment)
4. [Test corpus: `.jk` ↔ equivalent `.c`](#4-test-corpus)
5. [Perspective A — Decompiled CFG across obfuscation levels](#5-perspective-a--decompiled-cfg-across-obfuscation-levels)
6. [Perspective B — Hash / seeding / polymorphism / determinism](#6-perspective-b--hash--seeding--polymorphism--determinism)
7. [Perspective C — Forensics support](#7-perspective-c--forensics-support)
8. [Perspective D — String encryption & stealth](#8-perspective-d--string-encryption--stealth)
9. [Perspective E — Symbol surface & binary properties](#9-perspective-e--symbol-surface--binary-properties)
10. [Perspective F — Compiler introspection, diagnostics, cross-compile](#10-perspective-f--compiler-introspection-diagnostics-cross-compile)
11. [Findings: latent bugs & platform caveats](#11-findings-latent-bugs--platform-caveats)
12. [The decompiled-binary comparison table](#12-the-decompiled-binary-comparison-table)
13. [Conclusions](#13-conclusions)
14. [Reproducing this analysis](#14-reproducing-this-analysis)

---

## 1. Executive summary

JOCKY compiles a small forensic-scripting language to C, then to a binary, and can
polymorphically mutate every build. We decompiled **30 binaries** (6 programs ×
4 obfuscation levels + 6 hand-written C equivalents) with **Ghidra 12.1.2 headless**
and compared what the decompiler reconstructs.

| Question | Answer (evidence) |
|---|---|
| Is a level-0 JOCKY binary distinguishable from hand-written C? | **Yes.** ~2.5–8× more CFG blocks from injected opaque predicates (`if (g*g < 0)`), 3–6× larger `entry`, and the real algorithm survives `-O2` (the C version is constant-folded to nothing). |
| Does CFG flattening survive `-O2` into the binary? | **Partially, and it is visible.** Level 2/3 decompiles show a state-variable dispatcher (`while/do` chains keyed on `iVar6`), trampolined `entry` that Ghidra **cannot** resolve (`(*(code *)(ushort*4+base))()`), and XOR string decryptors with recoverable keys (`_j_enc_38 ^ 0xcf`). |
| Do strings survive? | Level 0: all literals readable. Level 2+: **zero** literal hits (`strings` + grep = 0). |
| Are JOCKY functions identifiable as a separate toolchain? | Level 0: trivially — every helper is a separate `_j_*` function, and the JSON schema strings of the forensic runtime are visible. Level 3: identifiers are gone; junk hash functions (`% 0x2717` loops) appear; the entry point is buried. |
| Is a JOCKY binary "cleaner" than hand-written C at `-O2`? | No — the opposite. JOCKY's volatile guards **defeat the optimizer**, so the reverse engineer sees *more* of the original algorithm than in the C binary. Obfuscation only pays off at level 2+. |
| Deterministic? | Emitted C is byte-identical per seed. On macOS the final binary is **not** byte-identical (linker `LC_UUID`); the project's Linux report shows byte-identical binaries there. |
| C-keyword robustness | **Bug:** the default build (no `--seed`) disables renaming, so any JOCKY function named `double`, `int`, `for`, `struct`, `return`, `static`… produces invalid C. With `--seed` it is renamed away and works. |

---

## 2. Why JOCKY exists

Synthesized from `README.md`, `LANGUAGE.md`, `plan.md`, `report.md`, and
`cfg_complete_obf_shift_plan.md`:

**Purpose.** JOCKY is a *domain-specific forensic-scripting language + C++ compiler* for
writing host-investigation agents. Its design goal is a one-shot, self-contained
artifact (script → C → binary) whose forensic collectors (processes, sockets, files,
registry, memory) are **cross-platform** (Linux/macOS/Windows from one source) and whose
**every build is a unique artifact** so that hash/reputation engines cannot pre-flag it.

The core thesis (from `report.md`) is the **"CI/CD as a polymorphic engine"** pillar:
renaming identifiers alone is erased by `-O2`, so the surviving mutation comes from
*volatile build markers + opaque predicates + CFG obfuscation* — which is exactly what we
see survive into the decompiled output.

**Deliberately small language.** 3 value types (`int`, `str`, `bool`), no arrays/lists/maps,
no strings operators beyond `len`/`==`, no `else if`/`break`/`continue`, no floats/bitwise.
The power is in the stdlib + polymorphism, not the grammar.

**Obfuscation architecture** (`cfg_complete_obf_shift_plan.md`): AST passes
(CFG flattening, dead code, bogus control flow, opaque predicates) + C post-process passes
(string XOR encryption, constant noise, trampolines, junk functions) exposed as
`--obf-level 0–3`.

---

## 3. Methodology & environment

```
JOCKY source (.jk)                       hand-written C (.c) [same logic, same output]
   │  build/jocky --seed 12345 --obf-level 0..3 --emit-c   │  cc -O2
   ▼                                     ▼
30 Mach-O binaries (arm64) ──────────────► Ghidra analyzeHeadless
   (ExportDecomp.java: per-function decompiled C + decompiler-CFG blocks/edges)
   ▼
metrics/hashes.txt, metrics/cfg_metrics.txt, decomp/*.c
```

- Compiler: `build/jocky` (the repo's own build).
- Host compiler: Apple clang 21 (`cc -O2`) — the same command JOCKY's `--build` invokes.
- Decompiler: Ghidra 12.1.2 headless (`analyzeHeadless` + custom `ExportDecomp.java` post-script).
- All `.jk` builds use **seed 12345** and levels 0,1,2,3. C equivalents are compiled at `-O2`.
- Correctness gate: every JOCKY binary's runtime output is byte-identical to its C
  equivalent at every level (16/16 for deterministic programs; forensics/system verified
  structurally on the live host).

---

## 4. Test corpus

| `.jk` | hand-written equivalent | What it exercises |
|---|---|---|
| `tour.jk` | `c_equiv/tour.c` | every language feature; ~20 functions, recursion, shadowing |
| `algorithms.jk` | `c_equiv/algorithms.c` | number theory: fib, gcd, primes, collatz, palindromes |
| `demo.jk` | `c_equiv/demo.c` | primes + `sum_up_to`, loops |
| `obfuscation_demo.jk` | `c_equiv/obfuscation_demo.c` | collatz + classify, multi-function module |
| `forensics.jk` | `c_equiv/forensics.c` | live evidence collection (proc/net/fs/json) |
| `system.jk` | `c_equiv/system.c` | full stdlib tour |

All C equivalents are idiomatic, hand-written C (not JOCKY-emitted) and produce identical output.

---

## 5. Perspective A — Decompiled CFG across obfuscation levels

### 5.1 Level 0: the algorithm survives, polluted by opaque predicates

`obfuscation_demo` at `-O2`:

- **Hand-written C** — the optimizer **constant-folded the whole program**. Ghidra recovers
  a trivial `entry` (6 blocks, 8 edges): `_puts("=== COLLATZ STEPS ==="); _printf("%d\n"); _puts("negative"); …`
  Every Collatz/classification computation was evaluated at compile time. The algorithm is
  **absent** from the binary.
- **JOCKY level 0** — `entry` is **67 blocks / 100 edges (1,368 bytes)**. The real Collatz
  loop is intact and readable:

```c
uVar4 = 1;
do {
    uVar1 = uVar4;
    if (_j_oiwo6t0n_j_jd8trjgc * _j_oiwo6t0n_j_jd8trjgc < 0) { _printf("%d\n"); }   // OPAQUE PREDICATE
    while (uVar1 != 1) {
        if (_j_t2hghb9f_j_0m3tuz7o * _j_t2hghb9f_j_0m3tuz7o < 0) { _printf("%d\n"); } // OPAQUE PREDICATE
        iVar3 = uVar1 * 3;
        uVar2 = uVar1 & 1;
        uVar1 = (int)uVar1 >> 1;
        if (uVar2 != 0) { uVar1 = iVar3 + 1; }
    }
    _printf("%d\n");
    uVar4 = uVar4 + 1;
} while (uVar4 != 9);
```

The `volatile` build markers + `g*g < 0` guards (which clang cannot fold) **accidentally
disable whole-program constant folding**, so the attacker-visible logic is richer than in
the hand-written C. The cost: the decompiled CFG is polluted with dozens of never-taken
`if (g*g < 0) printf(...)` blocks.

### 5.2 Levels 1–3: the state machine, trampoline and decryptors

`demo.jk` level 3 (Ghidra output):

```
FUNCTION entry  @ 0x1000007a8 size=2232  CFG blocks=70 edges=113   ← real main
FUNCTION _j_z_5ppufq @ 0x100000598 size=472  CFG blocks=19 edges=24 ← junk/helper
FUNCTION _j_z_hy797h @ 0x100000770 size=56                          ← injected junk hash
```

- **String decryption is reconstructed — including the key:**
```c
do { (&_j_dc_38_j_rb)[lVar8] = (&_j_enc_38)[lVar8] ^ 0xcf; lVar8 = lVar8 + 1; }
    while (lVar8 != 0x1c);
```
  Ghidra sees the encrypted blob `_j_enc_38`, the static buffer `_j_dc_38_j_rb`, and the
  XOR constant `0xcf`. Level-3 *string encryption* therefore resists `strings` but not a
  decompiler.
- **Opaque predicates** now use multiple families, all visible:
  `v*v + v < 0`, `(v*v+v & 0x8000000000000001) == 1` (modular), etc.
- **CFG flattening survives `-O2` as a state dispatcher.** The state variable `iVar6` walks
  `0→1→2→3` and the decompiler reconstructs deeply nested `do/while/if(iVar6==k)` chains —
  i.e. the structured `if/else/while` of the source is *gone* and replaced by a flat
  dispatcher. Clang partially merges the `switch` back into conditionals, but the
  flattened structure remains identifiable.
- **Entry-point burial works.** In `obfuscation_demo` level 3, Ghidra recovers `entry` as a
  **single block that it cannot follow**:
```c
void entry(void) {
    /* WARNING: Could not recover jumptable at 0x1000008b4. Too many branches */
    (*(code *)((ulong)USHORT_100001792 * 4 + 0x100000804))();   // indirect jump through table
}
```
  The trampoline/jump shuffle genuinely breaks decompiler entry-point recovery.

### 5.3 Function granularity

At `-O2` the C compiler inlines small helpers; JOCKY's helpers do **not** inline because
they are bloated with dead branches:

- `c_tour`: `entry` (1,420 B) + one `_fib` (76 B). Everything else inlined.
- `jk_tour_l3`: `entry` (10,580 B) + **5 surviving `_j_*` functions of 580–824 B each**,
  18–22 blocks each — each helper is a small program in its own right.

---

## 6. Perspective B — Hash / seeding / polymorphism / determinism

### 6.1 Polymorphism (hash uniqueness)

`obfuscation_demo.jk`, level 3, seeds 1–6 → **6/6 unique SHA-256**, sizes 51,416–52,568 B:

| seed | sha256 (first 16) | size |
|---|---|---|
| 1 | `098e988da8181712` | 52,568 |
| 2 | `a947f3acb468fe8d` | 51,976 |
| 3 | `d606d8d1b4ee4d53` | 52,536 |
| 4 | `fbbd426acb8cdf6f` | 51,704 |
| 5 | `cf06e32107639421` | 51,416 |
| 6 | `97073309fbeba35a` | 52,264 |

Also visible in the decompiled output: identifiers, opaque-predicate constants and the
XOR key differ seed-to-seed.

### 6.2 Determinism — the platform caveat

Same seed 42, level 2, three rebuilds:

- Emitted C: **byte-identical** (cmp → identical) ✅ JOCKY's transformation is fully seeded/deterministic.
- Final binary: **different hashes** (`b8b57475… / 81505ec9… / 45451c26…`) ❌ on macOS.

Root cause: the Mach-O linker embeds a **random `LC_UUID`** (16 B) plus other metadata
(49 differing bytes total). The project's Linux/container run (`report.md` §7.3) reports
byte-identical same-seed binaries — so binary reproducibility is a *toolchain* property,
not a JOCKY property. To get reproducible macOS binaries you would strip/zero the UUID.

---

## 7. Perspective C — Forensics support

The forensic collectors are the language's reason for being; they decompile faithfully:

- **Import / API surface is nearly identical** between the JOCKY and hand-written binaries:
  `proc_listallpids`, `proc_name`, `popen/netstat`, `opendir/readdir/closedir`,
  `getcwd`, `getenv`, `localtime_r/strftime/time`, `fopen/fread/fputs`, `access`.
  `diff` of the two symbol sets = only `_j_json_escape` (JOCKY's JSON escaper, inlined in
  the C version) and `_printf` vs `_puts`.
- **The collector logic is fully recoverable** at level 0; Ghidra even shows the JSON schema:
```c
uVar1 = _proc_listallpids(local_8098, 0x8000);
...
_j_json_escape(local_8398, 0x200, acStack_8198);
uVar3 = _snprintf((char *)((long)&_j_buf + 1), 0xffff, "{\"pid\":%d,\"name\":\"%s\"}");
```
- **Behavior verified live**: both the JOCKY and C forensics binaries enumerate real
  processes/sockets/files on the host; output differs only by live-host variation.
- **Windows-only collectors degrade gracefully** (`reg.list`/`mem.dump` → `[]`/no-op on macOS).

Defensive takeaway: the *forensic* nature of the binary is obvious at level 0 (JSON
collectors, `/proc`/libproc APIs). Encryption (level 2+) removes the plaintext markers but
not the API surface — an EDR watching `proc_listallpids`/`netstat` sees the same signal
regardless of obfuscation level.

---

## 8. Perspective D — String encryption & stealth

| binary | `strings` hits for JOCKY literals (`COLLATZ`, `===`, `negative`, …) |
|---|---|
| `c_obfuscation_demo` | 7 |
| `jk_obfuscation_demo_l0` | 7 |
| `jk_obfuscation_demo_l2` | **0** |
| `jk_obfuscation_demo_l3` | **0** |

- Level 0 leaks everything (`=== COLLATZ STEPS ===`… readable).
- Level 2+ hides all literals from `strings`/`grep`.
- But the **decryptor + key are recoverable** by Ghidra (see §5.2) — so "stealth" is
  strings-level only, not decompiler-level.

---

## 9. Perspective E — Symbol surface & binary properties

| artifact | size | entropy | exported functions |
|---|---|---|---|
| `c_*` (6) | 33,464–34,600 | 0.39–1.15 | 2–5 (`_main` + helpers) |
| `jk_*_l0` (6) | 50,232–51,184 | 0.43–1.21 | 2 |
| `jk_*_l2` (6) | 51,176–73,784 | 0.88–3.06 | 2 |
| `jk_*_l3` (6) | 51,288–74,040 | 1.01–2.61 | 2 |

- JOCKY declares every helper `static`, so binaries export only `main` (plus the Mach-O
  header) — a **minimal symbol surface by design**. (Normalizing the C equivalents to
  `static` helpers gives the same 1-symbol surface, confirming it is a codegen convention.)
- Entropy rises with obfuscation (encrypted blobs, junk code), but stays far below packed
  binaries (~7.9), i.e. JOCKY artifacts remain *unpacked custom compiler output*.
- Size overhead of full obfuscation vs level 0: ~1.0–1.4× (tour is the outlier at 1.46×
  because it has many literals/functions); ≤ the <2× design criterion.

---

## 10. Perspective F — Compiler introspection, diagnostics, cross-compile

- `--tokens`, `--ast`, `--check`, `--emit-c` all work; semantic errors are precise
  (`semantic error at line 2, col 5: type mismatch …`, exit 1).
- **Cross-compile verified**: `--target mingw` (seed 7, level 3) → valid
  `PE32+ executable (console) x86-64`, links CRT (`Sleep`, `DeleteCriticalSection`, …).
- **Correctness at every level**: all 4 deterministic programs produce byte-identical
  output at levels 0–3 and to the C equivalents; forensics/system run live at all levels.

---

## 11. Findings: latent bugs & platform caveats

1. **C-keyword collision (default build).** With no `--seed` (default = `seed -2`), the
   renaming pass is disabled (`registerName` returns when `polySeed_ < 0`), so any JOCKY
   identifier that is a C keyword produces **invalid C**. We reproduced failures for
   functions named `double` (tour.jk ships one!), `int`, `static`, `return`, `for`,
   `struct`. With `--seed N` renaming fixes it. This contradicts the documented default
   ("default = random") and breaks the documented quick-start
   (`./build/jocky --build scripts/tour.jk`). **Fix: always rename, or at least rename
   C-reserved words; or never allow them.**
2. **Reproducibility is toolchain-dependent.** Seeded/deterministic C, but macOS binaries
   differ by `LC_UUID` (see §6.2).
3. **`-Wc23-extensions` warnings.** The level-2/3 flattening emits labels directly before
   declarations (`case N: static volatile int64_t j_x = …;`), which clang flags as a C23
   extension (also `-Wparentheses-equality`). Harmless, but noisy and non-portable.
4. **`_UNK_`/`_DAT_` globals in decompilation.** Ghidra names JOCKY's volatile globals
   `_DAT_…`, `_UNK_…`, `PTR_…` — a readable "JOCKY footprint" at level 0/1 that an analyst
   can recognize.

---

## 12. The decompiled-binary comparison table

Ghidra's recovered CFG for the main/entry function (blocks = decompiler basic blocks,
edges = CFG edges). Bigger ≠ safer; it reflects injected branches.

| artifact | functions* | entry blocks/edges | entry size | opaque-looking conds |
|---|---|---|---|---|
| c_demo | 1 | 10 / 14 | 180 | 0 |
| **jk_demo_l0** | 1 | **28 / 41** | 512 | 9 |
| **jk_demo_l1** | 1 | **40 / 59** | 880 | 13 |
| **jk_demo_l2** | 1 | **70 / 113** | 2236 | 10 |
| **jk_demo_l3** | 3 | **70 / 113** | 2232 | 10 |
| c_tour | 3 | 23 / 35 | 1420 | 0 |
| **jk_tour_l0** | 4 | **56 / 82** | 1900 | 30 |
| **jk_tour_l1** | 3 | **104 / 154** | 3204 | 37 |
| **jk_tour_l2** | 7 | 1 / 0 (tramp) → body 19 / 30 | 10572 | 18 |
| **jk_tour_l3** | 9 | 1 / 0 (tramp) → body 19 / 30 | 10580 | 18 |
| c_algorithms | 2 | 22 / 32 | 876 | 0 |
| **jk_algorithms_l0** | 3 | **188 / 281** | 3828 | 99 |
| **jk_algorithms_l1** | 6 | **125 / 186** | 3088 | 66 |
| **jk_algorithms_l2** | 11 | 1 / 0 → body 32 / 51 | 5932 | 33 |
| **jk_algorithms_l3** | 13 | 1 / 0 → body 32 / 51 | 5888 | 33 |
| c_obfuscation_demo | 1 | 6 / 8 | 436 | 0 |
| **jk_obf_demo_l0** | 1 | **67 / 100** | 1368 | 28 |
| **jk_obf_demo_l1** | 2 | 23 / 33 | 952 | 20 |
| **jk_obf_demo_l2** | 2 | 1 / 0 → body 42 / 67 | 2576 | 9 |
| **jk_obf_demo_l3** | 4 | 1 / 0 → body 42 / 67 | 2560 | 9 |
| c_forensics | 3 | 59 / 88 | 1356 | 0 |
| jk_forensics_l0 | 4 | 47 / 69 | 1384 | 2 |
| jk_forensics_l2 | 4 | 1 / 0 → body 21 / 30 | 4544 | 1 |
| jk_forensics_l3 | 6 | 1 / 0 → body 21 / 30 | 4512 | 1 |

\* non-libc functions. "1 / 0 (tramp)" = `entry` is a 1-block trampoline; the real body
moved to a renamed `_j_*` function.

**Reading the table.** Level 0–1 ≈ *"bloated but structured"* (blocks multiply via
opaque predicates). Level 2–3 ≈ *"trampolined + flattened"* (`entry` collapses to a
1-block indirect jump, the body is a renamed state machine). The hand-written C at `-O2`
tends to compress toward a small `entry` (constant folding) — the *opposite* of JOCKY's
level-0 output.

---

## 13. Conclusions

1. **Level 0 is the most "recoverable" by a decompiler** — functions are intact, named
   `_j_*`, literals in clear, algorithm readable. It is *more* readable than `-O2`
   hand-written C, because JOCKY's volatile guards block constant folding.
2. **Level 2+ delivers the advertised effects in the decompiled output:** flattened state
   dispatcher, buried entry (Ghidra gives up on the trampoline), zero literal hits,
   XOR decryptors, junk functions. The weak spot is that **XOR keys are trivially
   recoverable** by any decompiler.
3. **The forensic nature is visible at the API level regardless of obfuscation.**
   `proc_listallpids`/`popen("netstat …")`/JSON collectors are the strongest fingerprint;
   identifier renaming cannot hide them.
4. **Determinism holds in codegen, not always in the binary.** The polymorphic-hash claim
   (unique SHA-256 per build) is solid; the reproducibility claim is Linux-toolchain
   dependent.
5. **One real robustness bug surfaced**: C-keyword identifier collisions on default
   (no-`--seed`) builds — `tour.jk` itself cannot be built by the documented command.
6. **JOCKY binaries are not packed** (entropy ≤ 3.1) — the "custom compiler output"
   profile is what differentiates them from obfuscators, for both red and blue teams.

---

## 14. Reproducing this analysis

```bash
cd decomp_report
./build.sh          # builds all 30 artifacts + hashes/entropy → metrics/hashes.txt
./decompile.sh      # Ghidra headless on every binary → decomp/*.c
python3 metrics.py  # CFG comparison table → metrics/cfg_metrics.txt
```

Artifacts: `c_equiv/` (hand-written C), `c_emitted/` (JOCKY-emitted C per level),
`builds/` (30 binaries), `decomp/` (Ghidra output), `metrics/` (tables).
Ghidra post-script: `ghidra_script/ExportDecomp.java`.

---

# PART II — Antivirus triggering: plain C vs the JOCKY build

**Question asked:** write a C program that antivirus flags, port the same logic to
JOCKY, build it, and test whether the JOCKY binary is still triggered by AV.

## P2.1 The bait

`av_test/av_bait.c` / `av_test/av_bait.jk` — a benign "credential-collection / recon"
sample embedding three **AV byte-signature markers**:

| marker | purpose | bytes |
|---|---|---|
| `sekurlsa::logonpasswords` | mimikatz credential-theft command string | no `%` |
| `c2.evil-domain.com/beacon` | hardcoded C2 beacon URL | no `%` |
| EICAR test string | canonical AV test string | **contains `%`** |

Both files implement the identical behavior profile (process enumeration,
`/etc/passwd`+`/etc/shadow` reads, env credential dump, staging write to `/tmp`,
Windows `mem.dump`) — the C via libc calls, the JOCKY via its forensic builtins.

## P2.2 What we scanned and how

- Binaries: `c_av_bait` (cc -O2), `jk_av_bait_l0`, `jk_av_bait_l2`, `jk_av_bait_l3`
  (jocky, seed 31337) + sources and emitted C.
- Engine: **ClamAV 1.x** in a Docker container (arm64), real CVD database
  (`main` 3,287,027 + `daily` + `bytecode` sigs) downloaded via freshclam.
- Plus a **custom `.ndb` signature file** (`custom.ndb`) containing one byte-pattern
  rule per marker — this models exactly how a commercial AV signature engine works
  (it is how any AV vendor would flag the sample's distinctive strings).

> Note: ClamAV's built-in `Eicar-Test-Signature` only fires on a whole-file EICAR,
> and real CVD signatures target specific malware *families*, so a hand-written
> sample will not hit the real DB. The `.ndb` rules give the deterministic,
> mechanism-identical test.

## P2.3 Results

Scan with `--allmatch` using the custom signature DB:

| artifact | `MimikatzCmd` | `C2Domain` | `EicarEmbedded` |
|---|---|---|---|
| `av_bait.c` (C source) | **FOUND** | **FOUND** | — |
| `av_bait.jk` (JOCKY source) | **FOUND** | **FOUND** | — |
| `av_bait_l0_emitted.c` | **FOUND** | **FOUND** | — |
| `c_av_bait` (plain C binary) | **FOUND** | **FOUND** | **FOUND** |
| `jk_av_bait_l0` | **FOUND** | **FOUND** | **FOUND** |
| **`jk_av_bait_l2`** | clean | clean | **FOUND** |
| **`jk_av_bait_l3`** | clean | clean | **FOUND** |

Scan with the real ClamAV database: only the standalone EICAR file is flagged;
all binaries/sources are clean (hand-written sample matches no family).

## P2.4 Why this happens (verified in the emitted C)

- **Level 2/3 string encryption is effective for ordinary strings.** At level 3,
  `sekurlsa::logonpasswords` and `c2.evil-domain.com/beacon` become `j_dc_N()`
  decryptor calls and their bytes are XOR blobs — so byte-signature rules stop
  matching. A commercial AV using a byte/string signature for the plain C binary
  would **miss** the level-2/3 JOCKY builds.
- **Strings containing `%` are NEVER encrypted.** The encryption pass skips any
  literal containing `%` (`src/postprocess.cpp:164`) to protect `printf` format
  strings. The EICAR string (`X5O!P%@AP[4\PZX…`) contains `%`, so it stays a
  **plaintext literal** in the emitted C and in the binary at *every* level
  (confirmed: `EicarEmbedded` is FOUND in l0, l2 and l3). Any signature string
  containing `%` will survive JOCKY's strongest obfuscation.
- **`strings` confirms it:** mimikatz/c2 present in `c_av_bait` and `jk_av_bait_l0`,
  absent from l2/l3; EICAR present in all four.

## P2.5 Conclusions (AV test)

1. **Answer to the question:** the plain-C bait is flagged; the JOCKY build of the
   *same logic* is **not** flagged at obfuscation level 2+, because the signature
   bytes are XOR-encrypted and never appear in the binary.
2. **Level 0 gives no evasion at all** — strings are in clear, so a byte-signature
   AV flags the level-0 JOCKY binary exactly like the C binary.
3. **Blind spot:** `%`-containing signature strings (EICAR, printf formats) are
   never encrypted, so they remain detectable at every level. An AV signature
   writer would trivially target such strings.
4. **Honest caveat:** this tested *byte-signature* detection. Behavioral/EDR
   detection (API telemetry such as `proc_listallpids`, `netstat`, `OpenProcess`)
   is unaffected by obfuscation — the forensic API surface (§7) is a fingerprint
   at every level.
5. **Bug found while building the test:** JOCKY level-3 emits **invalid C** for any
   program whose string literals contain `{` or `}`. `trampolineMain` used a naive
   brace counter that counted braces inside string literals, so the EICAR `}` broke
   the trampoline insertion mid-function. Fixed in `src/postprocess.cpp`
   (`findMatchingBrace`, string/char/comment-aware) and the compiler rebuilt;
   level-3 then compiles cleanly.

Artifacts: `av_test/` (sources, binaries, `custom.ndb`, scan logs in
`scan_results_custom_sig.txt` / `scan_results_real_db.txt`, `Dockerfile.scan`).