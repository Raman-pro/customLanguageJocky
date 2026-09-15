# CFG Complete Obfuscation Shift Plan

> How to transform JOCKY's codegen from "basic opaque predicates" to full
> control-flow graph obfuscation, making the emitted C (and thus the compiled
> binary) structurally different on every build.

---

## 0. Current State (What We Have)

| Feature | Status | Location |
|---------|--------|----------|
| Opaque predicates (`g*g >= 0`) | Done | `src/codegen.cpp:106-124` |
| Identifier renaming (RNG-based) | Done | `src/codegen.cpp:60-79` |
| Build markers (volatile globals) | Done | `src/codegen.cpp:93-104` |
| Build header comment | Done | `src/codegen.cpp:139-150` |

**What's missing:**
- Control flow flattening
- Basic block reordering
- Dead code / bogus control flow injection
- String/constant encryption
- Import table reordering
- Entry point shuffling / trampoline injection
- Enhanced opaque predicates (multiple families)

---

## 1. Architecture Decision

**We will NOT add an LLVM IR layer.** Instead, we will implement all obfuscation
passes at two levels:

1. **AST Transformation Passes** — Transform the AST *before* code emission.
   This is where control flow flattening, dead code injection, and bogus
   control flow happen. Clean, testable, and works with the existing codegen.

2. **C-Level Post-Processing** — Mutate the emitted C string *after* codegen.
   This is where string encryption, import reordering, and trampoline injection
   happen. These are text-level transformations that don't need AST knowledge.

```
JOCKY Source
    |
    v
[Lexer] -> [Parser] -> [Sema]
                         |
                         v
              +--- AST Transformation Passes (NEW) ---+
              |  1. Control Flow Flattening            |
              |  2. Dead Code Injection                |
              |  3. Bogus Control Flow                 |
              |  4. Enhanced Opaque Predicates         |
              +----------------------------------------+
                         |
                         v
                    [Codegen]  (existing, mostly unchanged)
                         |
                         v
              +--- C-Level Post-Processing (NEW) -----+
              |  5. String Encryption (XOR/RC4)       |
              |  6. Constant Folding Noise             |
              |  7. Trampoline / Entry Point Shuffle   |
              |  8. Junk Function Injection            |
              +----------------------------------------+
                         |
                         v
              Emitted C -> gcc/clang/MinGW -> Binary
```

---

## 2. New Files to Create

| File | Purpose |
|------|---------|
| `src/obfuscate.h` | Declares all AST transformation passes |
| `src/obfuscate.cpp` | Implements AST-level obfuscation (flattening, dead code, bogus CF) |
| `src/postprocess.h` | Declares C-level post-processing passes |
| `src/postprocess.cpp` | Implements C-level obfuscation (string encrypt, trampolines) |

**Modified files:**

| File | Change |
|------|--------|
| `src/main.cpp` | Add `--obf-level <0-3>` flag, wire in obfuscate + postprocess |
| `src/codegen.h` | Add `--obf-level` parameter; expose `emitRaw()` for post-processing |
| `src/codegen.cpp` | Reduce inline opaque predicates (moved to obfuscate pass) |
| `CMakeLists.txt` | Add new source files |

---

## 3. Pass-by-Pass Implementation Plan

### Pass 1: Control Flow Flattening (AST Transform)

**What it does:** Transforms every function body from structured control flow
(if/while/for) into a single `while(true) { switch(state) { ... } }` loop.
Each basic block becomes a case. The state variable determines which block
executes next.

**Why it matters:** This is the single most impactful CFG transformation. It
destroys the original program structure. A reverse engineer sees a flat
state machine instead of readable if/else/while patterns.

**Example transformation:**
```
// BEFORE (JOCKY source)                    // AFTER (emitted C)
fn main() {                                 int32_t main(void) {
    let x = 0;                                  int j_state = 0;
    if (x == 0) {                               int32_t j_x = 0;
        print(x);                               while (1) {
    } else {                                        switch (j_state) {
        print(42);                                  case 0:
    }                                                   j_x = 0;
}                                                       j_state = (j_x == 0) ? 1 : 3;
                                                        break;
                                                    case 1:
                                                        printf("%d\n", j_x);
                                                        j_state = 5;
                                                        break;
                                                    case 3:
                                                        printf("%d\n", 42);
                                                        j_state = 5;
                                                        break;
                                                    case 5:
                                                        return 0;
                                                }
                                            }
                                        }
```

**Implementation approach:**
- Operate on `Stmt::K::Fn` nodes. For each function body:
  1. Walk the statement list and identify basic blocks (straight-line sequences
     ending in a branch/return).
  2. Assign each block a unique integer ID.
  3. Build a "next state" mapping: for each block, what state(s) can follow it.
  4. Emit a `while(true) { switch(state) { case N: ... state = next; break; } }`.
- Since we emit C (not machine code), we can do this transformation at the
  **C emission level** inside `Codegen::emitStmt()` for `Stmt::K::Fn`.
- The state variable name is randomized per build.
- Case ordering is shuffled per build.

**Complexity:** Medium. We need to handle `if/else`, `while`, `for`, and
`return` inside the flattening. Key insight: we don't need to transform the
AST — we can emit the flattened C directly in `Codegen::emitStmt(Fn)`.

**Files touched:** `src/codegen.cpp` (rewrite `emitStmt` for `Stmt::K::Fn`)

---

### Pass 2: Dead Code Injection (AST Transform)

**What it does:** Inserts unreachable code between real basic blocks. The dead
code looks real (variable assignments, function calls, branches) but is
guaranteed unreachable because it's guarded by an opaque predicate that's
always false.

**Example:**
```c
// Dead code injected between two real blocks:
static volatile int64_t j_dead_guard = -1;
if ((j_dead_guard * j_dead_guard + j_dead_guard) < 0) {
    // This block is NEVER reached (x^2 + x >= 0 for all int x when
    // combined with the volatile, the compiler can't prove it)
    int32_t j_unused = j_some_real_var + 42;
    printf("%d\n", j_unused);
}
```

**Implementation approach:**
- After emitting each real basic block in a function, emit a dead-code block
  guarded by an opaque predicate that is always false.
- The dead code body is randomly generated: pick from `let x = expr`,
  `print(expr)`, `if (cond) { ... }`.
- Number of dead blocks per function: `1 + rng() % 4`.
- Dead code variables use `volatile` to prevent compiler elimination.

**Files touched:** `src/codegen.cpp` (new method `injectDeadCode()`)

---

### Pass 3: Bogus Control Flow (AST Transform)

**What it does:** Inserts fake branches that merge back into real code. Unlike
dead code, these branches ARE reachable — they just compute useless values
that don't affect program output. This creates "diamond" patterns in the CFG
that confuse decompilers.

**Example:**
```c
// Bogus control flow: both paths execute, but the else path is useless
int32_t j_bogus = j_real_var;
if (j_bogus >= 0) {
    // Real path continues here
    j_real_var = j_real_var + 1;
} else {
    // Bogus path: computes something but result is never used
    j_bogus = j_bogus * 2 + 1;
}
// Both paths merge; j_bogus is never read again
```

**Implementation approach:**
- Before emitting a real statement, with probability 0.3, emit a bogus
  if/else where:
  - The condition involves a volatile variable that makes it always true.
  - The else branch computes something but the result is dead.
  - The then branch contains the real statement.
- This creates diamond-shaped subgraphs in the CFG.

**Files touched:** `src/codegen.cpp` (new method `emitBogusBranch()`)

---

### Pass 4: Enhanced Opaque Predicates (AST Transform)

**What it does:** Replaces the single `g*g >= 0` family with multiple families
of opaque predicates, making pattern-based detection harder.

**Families to implement:**

| Family | Always True | Always False | Hard to Prove |
|--------|-------------|--------------|---------------|
| Algebraic | `x*(x+1) % 2 == 0` | `x*(x+1) % 2 == 1` | Yes |
| Bitwise | `(x & ~x) == 0` | `(x & ~x) != 0` | Yes |
| Math | `abs(x) >= 0` | `abs(x) < 0` | Yes |
| Modular | `(x*x) % 4 == 0 or 1` | `(x*x) % 4 == 2` | Yes |
| Volatile combo | `(v*v + v) >= 0` (volatile v) | `(v*v + v) < 0` | Compiler can't optimize away |

**Implementation approach:**
- Replace `injectOpaquePredicates()` with `injectOpaquePredicate(int family)`.
- `family` is chosen randomly per predicate.
- Each family generates a different volatile variable and condition.

**Files touched:** `src/codegen.cpp` (rewrite `injectOpaquePredicates()`)

---

### Pass 5: String Encryption (C Post-Processing)

**What it does:** Replaces all string literals in the emitted C with
XOR-encrypted blobs + inline decryptors. Each build uses a different key.

**Example:**
```c
// BEFORE:
printf("%s\n", "process_list");

// AFTER (build with key 0xA7):
static const uint8_t j_enc_0[] = {0xC5, 0xE5, 0xC3, 0xC6, 0xC6, 0xC7, 0xC6, 0xC6, 0xC1, 0xC4, 0xC5, 0xC7, 0xC6, 0xC4, 0xC3, 0xC6, 0x00};
static const char* j_dec_0(void) {
    static char buf[64];
    for (int i = 0; i < 17; i++) buf[i] = j_enc_0[i] ^ 0xA7;
    return buf;
}
printf("%s\n", j_dec_0());
```

**Implementation approach:**
- After `Codegen::emit()` produces the C string, run a regex-based pass that:
  1. Finds all `"..."` string literals.
  2. XOR-encrypts each with a per-build random key.
  3. Replaces the literal with a call to a generated decryptor function.
- The decryptor functions are emitted at the top of the C file.
- Keys are stored as `#define` constants with random names.

**Files touched:** `src/postprocess.cpp` (new file)

---

### Pass 6: Constant Folding Noise (C Post-Processing)

**What it does:** Replaces integer constants with equivalent expressions that
the compiler must evaluate but that look different in the source.

**Example:**
```c
// BEFORE:
int32_t j_x = 42;

// AFTER:
int32_t j_x = (17 + 25) ^ (3 ^ 3);   // still 42, but source looks different
```

**Implementation approach:**
- Regex pass over emitted C that finds integer literals.
- Replaces `N` with `(A + B)` where `A + B == N`, and `A`, `B` are random.
- Optionally XOR with `(K ^ K)` which is always 0.
- Probability: 50% of integer literals get noise.

**Files touched:** `src/postprocess.cpp`

---

### Pass 7: Trampoline / Entry Point Shuffle (C Post-Processing)

**What it does:** Instead of `main()` jumping directly to the real code, it
calls through a chain of 2-3 trampoline functions with random names. The
real entry point is buried 2-3 calls deep.

**Example:**
```c
// BEFORE:
int32_t main(void) { /* real code */ }

// AFTER:
static int32_t j_trampoline_2(void) { /* real code */ }
static int32_t j_trampoline_1(void) { return j_trampoline_2(); }
static int32_t j_trampoline_0(void) { return j_trampoline_1(); }
int32_t main(void) { return j_trampoline_0(); }
```

**Implementation approach:**
- After codegen, find the `main` function body in the C string.
- Extract it into `j_trampoline_N`.
- Generate a chain of N trampolines (N = 1 + rng() % 3).
- `main` just calls the first trampoline.

**Files touched:** `src/postprocess.cpp`

---

### Pass 8: Junk Function Injection (C Post-Processing)

**What it does:** Injects 2-5 functions that look real (have parameters, local
variables, loops, and returns) but are never called. They increase the
apparent complexity of the binary and waste analyst time.

**Example:**
```c
static int32_t j_junk_0(int32_t j_a, int32_t j_b) {
    int32_t j_r = 0;
    for (int32_t j_i = 0; j_i < j_a; j_i++) {
        j_r = j_r + j_b;
        if (j_r > 1000) j_r = j_r - 1000;
    }
    return j_r;
}
```

**Implementation approach:**
- Generate random function bodies using templates:
  - "accumulator loop" template
  - "string scan" template
  - "math reduction" template
- Insert them before `main` in the C output.
- They are `static` so they don't pollute the global namespace.

**Files touched:** `src/postprocess.cpp`

---

## 4. Obfuscation Levels (CLI Integration)

We expose 4 levels via `--obf-level <0-3>`:

| Level | Name | Passes Active | Effect |
|-------|------|---------------|--------|
| 0 | None | None | Current behavior (rename + build marker only) |
| 1 | Light | 4 (enhanced opaque preds) + 2 (dead code) | Different bytes, same structure |
| 2 | Medium | 1 (flattening) + 2 + 3 (bogus CF) + 4 + 5 (string encrypt) | CFG is flattened, strings encrypted |
| 3 | Full | All 8 passes | Maximum obfuscation; CFG destroyed, strings encrypted, trampolines, junk functions |

Default: `--obf-level 2` when `--seed` is used, `0` otherwise.

---

## 5. Implementation Order (Sprint Plan)

### Sprint 1 (Day 1-2): Foundation
- [ ] Create `src/obfuscate.h` / `src/obfuscate.cpp` skeleton
- [ ] Create `src/postprocess.h` / `src/postprocess.cpp` skeleton
- [ ] Add `--obf-level` flag to `main.cpp`
- [ ] Wire obfuscate passes into the compile pipeline in `main.cpp`
- [ ] Update `CMakeLists.txt`

### Sprint 2 (Day 2-3): AST-Level Passes
- [ ] Implement Pass 4: Enhanced Opaque Predicates (rewrite existing)
- [ ] Implement Pass 2: Dead Code Injection
- [ ] Implement Pass 3: Bogus Control Flow
- [ ] Test each pass individually with `--emit-c`

### Sprint 3 (Day 3-4): Control Flow Flattening
- [ ] Implement Pass 1: Control Flow Flattening in `Codegen::emitStmt(Fn)`
- [ ] Handle `if/else` flattening
- [ ] Handle `while` flattening
- [ ] Handle `for` flattening
- [ ] Handle `return` in flattened context
- [ ] Test with `scripts/demo.jk` and `scripts/forensics.jk`

### Sprint 4 (Day 4-5): C-Level Passes
- [ ] Implement Pass 5: String Encryption
- [ ] Implement Pass 6: Constant Folding Noise
- [ ] Implement Pass 7: Trampoline Entry Point
- [ ] Implement Pass 8: Junk Function Injection

### Sprint 5 (Day 5-6): Integration + Testing
- [ ] End-to-end test: `--obf-level 3 --build scripts/forensics.jk`
- [ ] Verify binary runs correctly at each level
- [ ] Verify hash differs across builds at same level
- [ ] Verify ClamAV scan results (should be clean at level 2+)
- [ ] Add `--obf-level` to `tests/run_tests.sh`

### Sprint 6 (Day 6-7): Polish
- [ ] Update `README.md` with `--obf-level` documentation
- [ ] Update `plan.md` to mark CFG obfuscation as done
- [ ] Generate comparison: level 0 vs level 3 C output side-by-side
- [ ] Record hash table across 10 builds at level 3

---

## 6. Verification Strategy

### Correctness
- Run `./tests/run_tests.sh` at each obfuscation level.
- All existing tests must pass (obfuscation must not change semantics).
- `forensics.jk` must produce correct JSON output at every level.

### Polymorphism
- Build the same script 10 times with different seeds at level 3.
- All 10 binaries must have unique SHA-256 hashes.
- All 10 C files must be structurally different (not just different names).

### Stealth
- Run ClamAV scan on level-3 binaries (should be clean).
- Run `objdump -d` and verify the disassembly shows flattened control flow.
- Run `strings` and verify no plaintext strings from the JOCKY source appear.

### Performance
- Level 3 binary should be < 2x the size of level 0 binary.
- Execution time overhead should be < 20% (opaque predicates add branches).

---

## 7. Risk Register

| Risk | Impact | Mitigation |
|------|--------|------------|
| Control flow flattening breaks complex scripts | High | Implement incrementally: if/else first, then while, then for. Test after each. |
| String encryption breaks format strings (`printf("%d", ...)`) | High | Only encrypt string *data*, not format strings. Detect `%` in strings and skip. |
| GCC/Clang optimizes away dead code | Medium | Use `volatile` for all dead-code variables. Use `__attribute__((used))` on dead functions. |
| Obfuscation makes binary too slow | Medium | Limit opaque predicates to 2 per function at level 2. Profile with `perf`. |
| Trampoline chain confuses our own debugger | Low | Add `--obf-level 0` escape hatch for development builds. |

---

## 8. Success Criteria

The implementation is complete when:

1. `./build/jocky --obf-level 3 --build scripts/forensics.jk` produces a
   working binary that collects forensics data correctly.
2. 10 builds with different seeds produce 10 unique SHA-256 hashes.
3. `strings ./scripts/forensics | grep -i "process"` returns nothing at level 3.
4. `objdump -d ./scripts/forensics` shows a flat switch-case structure in
   `main` (not nested if/else).
5. All existing tests pass at every obfuscation level.
6. ClamAV scan returns "OK" on level-3 binaries.
