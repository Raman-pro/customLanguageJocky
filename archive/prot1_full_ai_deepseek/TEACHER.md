# JOCKY — TEACHER.md (Live Learning Journal)

> **This file teaches you everything, in order, as we build.**
> Every concept, tool, and API we touch gets an entry here. Read the modules in order.
> By the end you'll understand not just *what* we build but *why* it works.
>
> ⚖️ **The one rule that keeps this legal and honest:**
> Everything here is dual-use. The only difference between a forensic instrument and malware is
> **authorization**. We only ever run this in our own lab (VMs we own, snapshots on). The knowledge
> is the same either way — the *ethics* are what we control. Stay an ethical researcher.

---

## How to use this file
- Each **module** = one prerequisite area. Read them in order **before** we start coding.
- Each module has: *What it is → Why we need it → The core ideas → Mini-practice*.
- When we start building, I'll append **Module 9: The Build Diary** with dated entries, every
  function we write, every bug we hit, every trick we learn.

---

## MODULE 1 — Cybersecurity fundamentals we actually need

### 1.1 What malware actually is (our honest starting point)
Malware = software that does something the system owner didn't authorize. Our project produces
software that *evades* detection — so the only thing separating us from malware authors is
permission. Learn this distinction now, it matters in every module below.

### 1.2 How antivirus / EDR detect bad stuff (5 detection layers)
Think of detection as layered filters. We'll refer back to this constantly:

| Layer | How it works | How to beat it (conceptually) |
|-------|--------------|-------------------------------|
| **Static signature** | hash or byte-pattern match against known-malware database | unique build every time → no known hash/pattern |
| **Reputation** | "has anyone else seen this file / hash?" (cloud) | CI/CD → every file is brand new, zero reputation |
| **Heuristic / static analysis** | scans for suspicious structure (packed, high entropy, weird imports, custom compiler) | balanced obfuscation so you don't look TOO weird |
| **Behavioral (EDR user-mode hooks)** | hooks APIs like `CreateProcess`, `NtAllocateVirtualMemory` to catch malicious *behavior* | in-memory execution, direct syscalls, unhooking |
| **Kernel-level (EDR callbacks, ETW)** | monitors from kernel via callbacks/ETW | BYOVD/rootkit-level tricks (we only *study* this) |

**Key takeaway:** the problem statement is essentially "beat layers 1–3 with a custom language +
CI/CD, and beat layer 4 with in-memory execution." Layer 5 is the BYOVD part we treat as
detection research only.

### 1.3 The paradigm shift the problem statement talks about
AV databases are built on *repeated artifacts*. A CI/CD pipeline that recompiles with random
mutations means **every artifact is a one-time file**. No hash database can keep up. That's the
whole trick — and it's a *delivery* trick, not a *code* trick. You can explain this in one
sentence to a judge.

### 1.4 Threat modeling in one paragraph
Before we write any code, answer: *who is the attacker in our story?* In our story, the
"attacker" is an APT that lives in-memory and uses BYOVD; our framework is the *analysis
instrument* used by the SOC team to find them. Keep that lens. It's the difference between "we
wrote an EDR-killer" (bad) and "we wrote a forensic agent that can operate under adversarial
conditions" (good).

**Mini-practice:** For each detection layer in the table above, write one sentence: *"If I were a
forensic agent, why would this layer flag me, and how would I avoid it?"*

---

## MODULE 2 — C++ prerequisites (beyond competitive programming)

You know CP-style C++. Here's what *systems* C++ adds. All of this is used in the actual codebase.

### 2.1 Pointers vs. references vs. stack/heap (quick refresher)
- Stack = fast, automatic lifetime. Heap = manual, survives function return.
- `new`/`delete` = manual heap. In CP you often ignore leaks; here **you will learn RAII**.
- **RAII (Resource Acquisition Is Initialization):** wrap every resource (memory, file handle,
  socket, mutex) in an object whose *destructor* frees it. If an exception or early return
  happens, the destructor runs anyway. This is THE C++ idiom.

### 2.2 Smart pointers (`#include <memory>`)
- `std::unique_ptr<T>` — sole owner. Moved, never copied.
- `std::shared_ptr<T>` — refcounted shared ownership (use rarely; unique is preferred).
- `std::unique_ptr<FILE, decltype(&fclose)>` pattern: attach a custom deleter to a raw resource —
  you'll see this for file handles.

### 2.3 The STL containers you'll actually use
- `std::vector<unsigned char>` — *binary data* lives in here, not `std::string`.
- `std::string` / `std::string_view` — string_view is a non-owning "peek" at a string, zero-copy,
  great for parsers.
- `std::unordered_map` — symbol tables, import-hash tables.
- `std::span<T>` (C++20) — non-owning view over an array; parsers love it.
- Iterators + `std::find_if`, `std::transform` — you know these from CP.

### 2.4 Reading/writing raw bytes (the skill that unlocks everything)
Everything on disk is bytes. A file is just bytes. An executable is just bytes with a header.
You must be 100% comfortable doing:
```cpp
std::ifstream f(path, std::ios::binary);
std::vector<unsigned char> buf((std::istreambuf_iterator<char>(f)), {});
uint32_t val = (buf[0]) | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
```
That last line is **little-endian** byte order — Windows/Intel is little-endian. You'll read
PE/ELF headers this way.

### 2.5 Structs, packing, and `#pragma pack`
Headers in files are fixed-layout structs. In memory the compiler *aligns* fields (adds padding);
on disk there is no padding. So when we model the PE header we use:
```cpp
#pragma pack(push, 1)
struct DOS_HEADER { uint16_t e_magic; ... };
#pragma pack(pop)
```
`pack(1)` = no padding = matches the file format exactly. This trips everyone up — remember it.

### 2.6 Namespaces, `static` locals, and anonymous namespaces
- `static` inside a function = initialized once, keeps state across calls (perfect for our RNG).
- `namespace { }` (anonymous) = "private to this .cpp file".
- You'll build libraries (static libs) with CMake; headers get include guards `#pragma once`.

### 2.7 Move semantics (you'll see it in codegen)
`std::move` transfers ownership instead of copying. Example: building an AST, `children.push_back(std::move(node))`. Don't deep-dive; just recognize the pattern.

**Mini-practice:** write a `read_bytes(path)` returning `std::vector<unsigned char>`, and a
function `as_u32(const std::vector<unsigned char>&, size_t off)` that reads a little-endian u32.
We'll use both tomorrow.

---

## MODULE 3 — How compilers & languages work (the heart of JOCKY)

### 3.1 The pipeline (our high-level map)
```
source text → [lexer] → tokens → [parser] → AST → [semantic/typecheck] → [codegen] → output
```
Every compiler in the world is this. Ours: JOCKY text → C text. Then gcc/MinGW turns C into a
binary. That's called a **transpiler** (source-to-source). Simpler than full codegen — perfect.

### 3.2 Lexer (tokenizer)
Turns `let x = 5 + 3;` into tokens:
`[LET, IDENT("x"), EQ, INT(5), PLUS, INT(3), SEMICOLON]`
- Hand-written: loop over chars, match keywords (`let`, `if`...), identifiers (`[a-zA-Z_]\w*`),
  numbers, operators, string literals.
- Each token = `{Kind, lexeme, line, col}`. Line/col are for error messages — we WILL need them.

### 3.3 Parser (recursive descent)
Builds the **AST** from tokens. For each grammar rule, a function:
- `parseExpr()` → calls `parseTerm()` → `parseFactor()` → etc. (precedence climbing)
- `parseStmt()` dispatches on the leading token (`if` → if-statement, `let` → declaration...)
- Each function returns an AST node, e.g. `struct BinaryExpr { unique_ptr<Expr> lhs, rhs; Token op; };`

### 3.4 AST (Abstract Syntax Tree)
A tree that *removes syntactic sugar*: `let x = 5 + 3;` becomes
```
Decl(name="x")
└── BinaryExpr(op=+)
    ├── IntLit(5)
    └── IntLit(3)
```
The AST is our data. The **polymorphic mutator** walks this tree and rewrites it (adds dead
branches, swaps orders) before codegen — that's how we get unique control flow per build.

### 3.5 Semantic analysis (type checking)
Walk the AST again: are identifiers declared? Is `"a" + 5` rejected? Maintain a **symbol table**
(`unordered_map<string, Symbol>`). This catches 90% of bugs before codegen.

### 3.6 Codegen (our transpiler)
Walk the AST and print C. Example mapping: `let x = 5+3;` → `int32_t x = (5 + 3);`.
- Indentation engine: track depth, emit `{`/`}` at right levels.
- Every AST node → a `void emit(Node&, Emitter&)` overload (or a visitor).
- This is the biggest single file in the project; keep it dumb and mechanical.

### 3.7 Why "C as the target" satisfies the problem statement
The claim is "custom compiler output defeats signature engines." A transpiled-from-custom-language
C file compiled by gcc produces binaries with **our** token/control-flow fingerprint, not the
standard MSVC boilerplate that signature databases already know. And transpiling is ~10x less work
than writing an x86 backend. Win-win. (LLVM frontend = stretch goal, mentioned in plan.md.)

**Mini-practice:** write a mini-lexer that tokenizes `let x = 42;` and prints tokens. 50 lines.
This is literally Work Package 1, so you'll write the real one soon.

---

## MODULE 4 — Platform internals (PE, ELF, memory, Windows APIs)

### 4.1 The PE format (Windows executables) — we WILL edit this
A `.exe`/`.dll` is a **Portable Executable**. Layout:

```
DOS header (MZ)  →  e_lfanew offset
    └── PE header ("PE\0\0") → COFF file header → Optional header
         └── Section table
              ├── .text  (code)
              ├── .data  (initialized data)
              ├── .rdata (read-only, import table lives here)
              └── .rsrc  (resources)
```
- **EntryPoint:** stored in the Optional header (`AddressOfEntryPoint`). The OS starts execution
  there. Changing it = "altered entry points" in the problem statement.
- **Import table (.idata):** list of DLLs + functions the exe imports at load. Signature engines
  scan this to guess what the program *does*. Reordering/randomizing it = the "altered import
  tables" claim. (Each `.idata` entry has a *name* and an *ordinal hint*; we'll shuffle the
  descriptor order.)
- **DOS header** first bytes are `MZ` (`0x5A4D`), magic sanity check when we parse.

We'll parse & rewrite PE headers with our `#pragma pack(1)` structs from Module 2.5. This is the
most "wow" code in the project and also the most educational.

### 4.2 The ELF format (Linux) — we parse it, rarely edit it
`ELF` magic = `0x7F 'E' 'L' 'F'`. Similar idea: ELF header → program headers → section headers
→ `.text`/`.data`. Linux is more open; our Linux binary can be a normal-ish binary. We mostly
build Linux for the *console/agent* side and Windows for the *loader demos*.

### 4.3 Windows process memory model
- Each process = isolated virtual address space. **VirtualAlloc** reserves/commits pages.
- Classic layout: 0x00000000–0x7FFFFFFF user space (x86), high half = kernel.
- `ImageBase` = where the exe maps; typical 0x140000000 (x64). DLLs get mapped anywhere (ASLR).

### 4.4 The Windows API layers (two of them — important)
```
Win32 API (kernel32.dll): CreateProcess, VirtualAllocEx, WriteProcessMemory...
Native API (ntdll.dll)  : NtCreateProcessEx, NtAllocateVirtualMemory... (syscall stubs)
Kernel (ntoskrnl.exe)   : actual system services
```
- Win32 is the friendly layer; Native (ntdll) is the syscall boundary.
- **Direct syscalls:** instead of calling `NtAllocateVirtualMemory` in ntdll (which EDR hooks),
  you copy the syscall number + stub inline and call the kernel yourself → skips the hook.
- This is a documented technique; we do an *educational PoC* for 2–3 APIs in the lab, and pair
  each with a detection note.

### 4.5 Key APIs we'll touch (learn the names, we'll use a few)
| API | What it does |
|-----|--------------|
| `VirtualAlloc` / `VirtualAllocEx` | allocate memory in self / remote process |
| `CreateProcess` (with `CREATE_SUSPENDED`) | spawn suspended → used by process hollowing |
| `WriteProcessMemory` | write into another process's memory |
| `SetThreadContext` / `GetThreadContext` | read/set a thread's registers |
| `NtUnmapViewOfSection` | unmap a process's original image (hollowing step) |
| `GetProcAddress` | resolve a function address at runtime (import shuffling) |

### 4.6 In-memory execution techniques (names + one-liners; lab-only)
- **Process hollowing:** create suspended process → unmap its image → write ours → fix entry →
  resume. The process *appears* to be the trusted exe in process lists.
- **Reflective DLL injection:** a DLL that maps itself (reads its own headers, allocs, copies
  sections, resolves imports) without `LoadLibrary`. Never touches disk, never uses the loader.
- **Thread hijacking:** suspend a thread of a target, set its RIP to your shellcode, resume.
- **API unhooking:** read clean ntdll from disk, overwrite the hooked bytes, or use direct syscalls.

**Important framing:** in this project these live behind a hard lab-only gate and each has a
detection write-up. We're building an *educational demonstration*, not a weapon.

### 4.7 BYOVD (conceptual — we research & detect, we don't weaponize)
**BYOVD = Bring Your Own Vulnerable Driver.** Signed drivers ship with vulnerabilities (e.g.,
arbitrary read/write primitives via IOCTLs). Attackers load a *legitimately signed* vulnerable
driver — signature check passes — then exploit its bug to get kernel read/write, disable ETW/EDR
callbacks, or elevate privileges. Why it matters for us: it's the modern way to blind layer-5
detection. Our deliverable = an analysis doc + YARA/Sigma detection rules + a harmless dummy
driver that just logs, for learning the loading flow. Never a real EDR-bypass.

**Mini-practice:** using a hex editor, open any `.exe` on your Windows VM and verify the first
two bytes are `MZ`, then use a Python script to find `e_lfanew` at offset 0x3C and print the
offset where `PE\0\0` appears. This connects Modules 2 and 4.

---

## MODULE 5 — Build tooling & CI/CD

### 5.1 CMake (our build system)
`CMakeLists.txt` describes targets; cmake generates native build files (Makefiles, VS solutions).
Minimal project:
```cmake
cmake_minimum_required(VERSION 3.20)
project(jocky CXX)
add_executable(jocky src/main.cpp src/lexer.cpp src/parser.cpp)
target_compile_features(jocky PRIVATE cxx_std_17)
```
Why CMake: cross-platform builds from one file, easy for CI, standard in the industry.

### 5.2 Cross-compilation (Windows binary from Linux / from Mac)
To build a Windows exe on a non-Windows machine you need **MinGW-w64**: a Windows-targeting GCC.
- Homebrew: `brew install mingw-w64`
- CMake: a *toolchain file* tells cmake to use `x86_64-w64-mingw32-g++`.
- One source → both `jocky` (Linux) and `jocky.exe` (Windows). This is a headline feature.

### 5.3 CI/CD in one paragraph
**CI/CD = automate: (1) build+test on every push, (2) ship artifacts.** GitHub Actions = YAML
workflows running on hosted machines (runners). A `matrix` runs the same job on windows + ubuntu.
The **genius trick for us**: the mutation of the binary happens *inside* the build step, so every
CI run emits a different artifact. "CI/CD as a polymorphic engine" is our story.

### 5.4 Versioning artifacts
Every run: compute `sha256sum`, store in a `build-report.json` (hash, imports, entropy, size).
We can demo a table of 10 builds → 10 unique hashes. Judges love tables.

**Mini-practice:** install CMake + MinGW-w64; create a hello-world with a cross-toolchain file;
produce both a Linux and a Windows binary from the same source. If you get this, you've de-risked
the hardest infrastructure part.

---

## MODULE 6 — Detection & evasion concepts (educational)

### 6.1 Static detection details
- **Hashing:** AV computes MD5/SHA1/SHA256 + fuzzy hashes (ssdeep — "similarity" hash). Unique
  bytes per build beats both.
- **YARA rules:** pattern-based rules (`rule X { strings: $a = "..." condition: $a }`). Custom
  compilers produce unusual sequences → YARA rules *for us* would be weak, which is the point.
- **Entropy:** packed/encrypted sections look "random" (entropy ≈ 8.0). If we encrypt *everything*,
  we look suspicious in a different way → we only encrypt *strings*, keep code normal. Balance.

### 6.2 Obfuscation vocabulary (we implement 3–4)
- **String encryption:** encrypt literals at compile time, decrypt at runtime → YARA can't match
  `"malware.exe"` in the file.
- **Opaque predicates:** `if (x*x >= 0) { real_code } else { fake_code }` — the condition is
  *always true* but hard to prove; injects fake branches to confuse static analysis.
- **Control-flow flattening:** turn a natural `if/for` structure into a switch-dispatch state
  machine → CFG looks flat, IDA/Ghidra gets confused. (Advanced; optional.)
- **Import hiding:** resolve imports via `GetProcAddress` + hash at runtime instead of listing
  them in `.idata`.

### 6.3 Polymorphism vs. metamorphism (know the difference for the poster)
- **Polymorphic:** payload changes but *shape/behavior* stays recognizable — decryption loop
  stays the same, key changes. Easiest.
- **Metamorphic:** the whole structure rewrites itself into equivalent-but-different code.
- We build **polymorphism** (per-deploy mutation) + a dash of **metamorphic-ish** rewrites in the
  JOCKY transpiler (reorder branches, rename tokens). Saying this precisely in the demo = instant
  technical credibility.

### 6.4 Behavioral detection & the red team's answer
EDR hooks user-mode functions; malware avoids them via direct syscalls / unhooking / running in
memory. **Our stance:** we implement these *for the lab demo* and document exactly how an EDR
would detect us (ETW, kernel callbacks, memory scanning). "Know your attacker" includes "know
how you'd be caught." That reflex makes the whole project defensible.

### 6.5 The ethical boundary (re-read this one)
Implementing: JOCKY language, transpiler, mutation pipeline, forensics modules, SOCKS5 client,
console. **Not implementing:** anything that disables a real EDR/AV, any privilege escalation on
a real system, any driver that does real kernel damage. Research + detection rules for BYOVD.
Memorize this list.

**Mini-practice:** write the string-encryptor as a tiny C++ program: take a file, XOR every byte
with a key, store key+encrypted blob. Then the reverse. That's 80% of `mutate_strings`.

---

## MODULE 7 — Networking (SOCKS5, TLS, domain fronting)

### 7.1 Sockets 101 (BSD sockets)
`socket()` → `connect()` → `send()/recv()`. On Windows, same functions with `WSAStartup()` first
and `#define WIN32_LEAN_AND_MEAN` + `winsock2.h`. We'll write a small socket wrapper once.

### 7.2 SOCKS5 protocol (RFC 1928) in one page
A SOCKS5 server relays TCP for us. Handshake:
1. **Greeting:** client → `[0x05, 0x01, 0x00]` (version 5, 1 method, no-auth).
2. **Reply:** server → `[0x05, 0x00]` (chosen method: no-auth).
3. **Connect request:** client → `[0x05, 0x01, 0x00, addrtype, address, port]`
   (`addrtype=0x01` IPv4: 4 bytes; `0x03` domain: 1 len byte + name).
4. **Reply:** server → `[0x05, 0x00, 0x00, ...]` (success).
Then the tunnel is a normal TCP stream. ~80 lines of C++. Very demoable.

### 7.3 TLS
Wrap the socket with TLS using OpenSSL (`SSL_new`, `SSL_connect`, `SSL_read/write`) or mbedTLS.
Purpose here: keep agent→console traffic private. (We own both ends.)

### 7.4 Domain fronting (the legal way)
- **Concept:** TLS request goes to CDN edge (e.g., Cloudflare), but the HTTP Host header points at
  your origin server. CDN looks like the destination; real origin is hidden behind it.
- **Our legal version:** our own domain → Cloudflare/Azure Front Door edge → our origin VM. Agent
  talks to the *edge* over HTTPS. We own the whole path. Same idea bad guys abuse, zero
  criminality because it's our infra.
- **Why it matters to the problem statement:** "traffic between management interface and client
  should be routed through trusted cloud infrastructure/CDNs." This is that requirement, done
  honestly.

### 7.5 Console → agent protocol (keep it JSON)
Agent POSTs `{ "agent_id": "...", "artifacts": { "processes": [...], "sockets": [...] } }` to our
Flask endpoint. Console GETs `/tasks` for queued JOCKY scripts. Simple REST keeps the demo clean.

**Mini-practice:** write a minimal SOCKS5 client that connects to a public test proxy
(like `socks5://...` in your lab only) and fetches a page through it. Print the bytes of each
handshake step.

---

## MODULE 8 — Lab setup & repo layout (do this before we write code)

### 8.1 Machines
1. **Host (you):** Mac — build machine. Tools: Homebrew, CMake, MinGW-w64, VS Code/CLion.
2. **Ubuntu VM:** runs our Linux agent + console. (UTM/VMware/VirtualBox.)
3. **Windows 10/11 VM (snapshotted!):** runs the in-memory loader demos and PE mutation tests.
   Snapshot = rollback safety net when we experiment.

### 8.2 Repo layout (we'll grow this)
```
jocky/
├── CMakeLists.txt
├── src/            # C++ compiler + tools
│   ├── lexer.cpp/.h
│   ├── parser.cpp/.h
│   ├── ast.h
│   ├── sema.cpp/.h
│   ├── codegen.cpp/.h
│   ├── stdlib/     # forensics modules (process, net, fs, reg, mem)
│   └── tools/      # mutate_strings, mutate_imports, mutate_entry, report_build
├── scripts/        # .jk JOCKY example scripts
├── console/        # Flask dashboard + agent API
├── ci/             # GitHub Actions workflows
├── research/       # BYOVD knowledge base + YARA/Sigma detection rules
├── plan.md
└── TEACHER.md      # ← you are here
```

### 8.3 Checkpoint — before we write a line
You should be able to say yes to all of:
- [ ] I can read/write raw bytes in C++ (little-endian u32, `vector<unsigned char>`).
- [ ] I can explain lexer → parser → AST → codegen to a friend.
- [ ] I can find `MZ`, `e_lfanew`, `PE\0\0` in a hex view of any exe.
- [ ] I have both a Linux and a Windows hello-world binary built from one CMake source.
- [ ] I can list the 5 detection layers and how our framework addresses each.
- [ ] I have a snapshotted Windows VM and an Ubuntu VM.
- [ ] I can explain SOCKS5's 4 steps.
- [ ] I have re-read Module 6.5 (the ethical boundary) and agree.

If any box is unchecked, come back — that's exactly what TEACHER.md is for.

---

## MODULE 9 — The Build Diary (appended as we build)

> Every session, I'll append a dated entry here:
> what we built, what we learned, what broke, what we fixed.
> This becomes your study guide and our judge-facing engineering story.

---

### Session 1 — 2026-09-02: WP1–3, the JOCKY language core (DONE)

**What we built**
- `src/token.h/.cpp` — the token enum + `Token` struct.
- `src/lexer.*` — hand-written lexer (keywords, identifiers, ints, strings with
  escapes, `//` and `/* */` comments, all operators, longest-match).
- `src/ast.h` — `Expr`/`Stmt` nodes. Note the design trick: a *flat* struct with
  a `kind` field + optional fields instead of a deep class hierarchy. For a small
  language this avoids 30 files of virtual visitor boilerplate.
- `src/parser.*` — recursive descent with precedence climbing
  (`||` < `&&` < `==/!=` < relational < additive < mult < unary < call).
- `src/sema.*` — symbol-table stack (scopes), full type checking, and a map of
  `Expr* -> resolved type` that codegen reuses (so we never compute types twice).
- `src/codegen.*` — JOCKY → C transpiler. `int→int32_t`, `str→const char*`,
  `bool→bool`. `print`/`len` builtins map to `printf`/`j_str_len`.
- `src/main.cpp` — CLI: `--tokens --ast --check --emit-c -o --build --target
  --seed`. `--target mingw` cross-compiles a real Windows PE via MinGW-w64.
- `tests/run_tests.sh` — compares program output to `.expect` files + checks
  semantic errors are rejected. **5/5 passing.**

**The three bugs we hit (and the lessons)**
1. **`for` loops failed to parse.** `parseFor` called `parseLet()` without first
   consuming the `let` keyword (only `parseStmt` consumed it). Lesson: be
   *symmetric* about who consumes the leading keyword of a construct.
2. **`[[noreturn]]` warning.** I marked `error()` as `noreturn` but it called a
   non-`noreturn` `errorAt()`; clang correctly complained it could return. Fix:
   mark the throwing function `[[noreturn]]` too. Lesson: `noreturn` must be
   consistent down the call chain.
3. **THE big one — renaming didn't change the binary.** We renamed every
   identifier per seed (different C output!), but the compiled binary hash was
   *identical*. Why? `-O2` erased all the names; only the header comment differed
   and comments don't survive compilation. This is the honest core of the whole
   project: **polymorphism that matters must mutate things that survive
   compilation** — constants, control flow, string bytes, import tables — not
   just source text. So we added:
   - `emitBuildMarker()`: two `volatile` globals with per-build random values.
     Volatile means the optimizer can't remove them → different `.data` bytes
     every build.
   - `injectOpaquePredicates()`: `if (g*g >= 0)` guards with random `volatile
     int64_t` values. Unprovable for the optimizer → real CFG differences.
   - Result: **3 seeds → 3 unique SHA-256 hashes.** We even hit a sub-bug: using
     `int32_t` for the guard made `g*g` overflow and sometimes run the else
     branch (printing stray `0`s). Switched to `int64_t`. Lesson: **always
     double-check overflow when you invent an "always true" predicate.**

**Concepts that came alive today (all in Modules 1–6)**
- Transpiler pipeline: lexer → parser → AST → sema → codegen (Module 3).
- Little-endian / binary handling (Module 2.4–2.5) — used for reading source and
  the eventual PE work.
- Opaque predicates + volatile as the difference between "source-level" and
  "binary-level" mutation (Module 6.2).
- Cross-compilation with MinGW-w64 toolchain (Module 5.2) → one source, two OSes.

**Try it**
```bash
./build/jocky --seed 42 --build scripts/demo.jk && shasum scripts/demo
./build/jocky --seed 7  --build scripts/demo.jk && shasum scripts/demo
./build/jocky --target mingw --build scripts/demo.jk   # -> scripts/demo.exe
./tests/run_tests.sh
```

**Where this leaves us / next session**
The language core (WP1–3) is done. Next we attack **WP3b: the forensics stdlib**
(`sys.process_list()`, `net.sockets()`, `fs.read()`, ...) which makes JOCKY an
actual *forensic* language instead of a toy — that's the demos-with-judges win.

---

### Session 2 — 2026-09-02: WP3b, the forensics stdlib (DONE)

**What we built**
- **Namespaces via dotted names.** Added a `Dot` token and parser support so
  JOCKY has real namespaced builtins: `sys.process_list()`, `net.sockets()`,
  `fs.read(path)`, `env.get(name)`, `reg.list(key)`, `mem.dump(pid, path)`.
  Parsing is a `while (match(Dot))` loop building `a.b.c` from identifiers.
- **Builtin signatures in sema.** `kBuiltins` table: name → (return type,
  param types). Type-checked exactly like user functions. `print`/`len` stay
  special-cased (print takes *any* non-void type).
- **A full cross-platform C runtime embedded in the transpiler** (`codegen.cpp`):
  - `sys.process_list` → Toolhelp32 snapshot (Windows) / `/proc` scan (Linux) /
    `proc_listallpids` (macOS)
  - `net.sockets` → `GetExtendedTcpTable` (Windows) / `/proc/net/tcp{,6}`
    (Linux) / `netstat` parsing (macOS)
  - `fs.read/write/list/exists`, `sys.cwd/now/sleep`, `env.get`
  - `reg.list` (Windows registry subkeys) and `mem.dump` (VirtualQueryEx +
    ReadProcessMemory) — **Windows-only, `#ifdef`'d to no-ops elsewhere**
  - All collectors return **JSON strings** into a shared 64KB static buffer —
    the future console can ingest them as-is.
- `--target mingw` now links `-lws2_32 -liphlpapi -ladvapi32` for the Windows
  APIs. The demo (`scripts/forensics.jk`) builds to a valid PE32+ exe.

**What we learned (the good stuff)**
1. **Design decision — "forensics returns JSON strings, not native lists."**
   We *could* have added `list<T>` to the language, but that's a big language
   change (lexer/parser/sema/codegen + runtime containers). Returning JSON
   strings is 10× less work and *exactly* what a management console needs.
   Trade-off understood: JOCKY can't iterate the list natively yet. That's
   fine — the console does the analysis. **Scope discipline is a feature.**
2. **Cross-platform is a *runtime* problem, not just a compiler problem.** The
   interesting code is per-OS: Toolhelp32 vs `/proc` vs `sysctl`. The
   `#if/#elif/#else` pattern in the generated C is what makes one source → three
   OSes. And the order matters: `winsock2.h` MUST be included before
   `windows.h`, and `#elif` cannot follow `#else`.
3. **We caught a real preprocessor bug:** I first wrote the OS branches as
   `#if _WIN32 … #else (linux) … #elif __APPLE__ … #endif` — `#elif` after
   `#else` is invalid C and the generated file wouldn't compile. Fix: put the
   specific platform (`__APPLE__`) before the generic `#else` (Linux).
   Lesson: **specific-first, generic-last ordering for preprocessor branches.**
4. **macOS ≠ Linux.** We're developing on a Mac; `/proc` doesn't exist there, so
   the process list came back `[]`. Rather than wait for the Ubuntu VM, we added
   a macOS branch (sysctl/proc_listallpids + netstat). Now we can demo live on
   the dev machine, and the cross-platform story is 3 OSes. When we demo on the
   Ubuntu VM, the `/proc` branch kicks in automatically — no code change.
5. **One source, many targets, unique hashes still hold** — re-verified 3 seeds
   → 3 hashes on the bigger forensics program.

**Try it**
```bash
./build/jocky --build scripts/forensics.jk && ./scripts/forensics
./build/jocky --seed 3 --target mingw --build scripts/forensics.jk   # Windows exe
```

**Where this leaves us / next session**
The forensics stdlib is a *story-maker*: we can already collect processes,
sockets, registry keys, and memory from three platforms and emit JSON. Next
up is **WP4 — the CI/CD mutation pipeline** (GitHub Actions matrix producing a
fresh-mutated artifact + build report on every run), which is the "continuous
delivery of unique binaries" pillar the problem statement is really about.

---

### Session 2.5 — 2026-09-02: Docker multi-perspective testing (DONE)

**What we did**
- Built `docker/Dockerfile` (Debian bookworm-slim + gcc, cmake, MinGW-w64,
  valgrind, ClamAV) and `docker/test.sh` — a 9-perspective harness whose output
  lands in `docker/results/` and is summarized in `report.md`.
- Ran it in a clean Linux/arm64 container and recorded:
  - build clean (0 warnings), tests 5/5, **10/10 unique hashes**
  - Windows PE cross-compile OK
  - Linux `/proc` forensics verified live (container namespace)
  - **ClamAV (3.6M sigs): 0 detections** on ELF, PE, and generated C
  - valgrind 0 errors, ms-level performance

**What we learned**
1. **`test.sh` had a bug in its forensics grep**: it counted *lines* containing
   `"pid"`, but the process list is one big JSON line, so it printed "1" instead
   of the real count. Lesson: **when you write a test, verify the test's
   interpretation of output**, not just the code under test. We re-checked by
   counting `"pid"` occurrences, which correctly gave 2 (the container's own
   processes — PID namespaces isolate `/proc`).
2. **Containers are isolated forensics targets.** A container only shows its own
   processes/sockets, so the demo saw 2 processes and `[]` sockets — expected
   sandbox behavior, not a bug. This is itself a useful fact for the report.
3. **ClamAV in `debian:*-slim` silently fails without `ca-certificates`** —
   `freshclam` failed with "SSL CA cert" until we added the package. Lesson:
   slim images strip TLS trust stores; install `ca-certificates` before any
   network tool.
4. **The whole Docker Desktop VM wedged** (container *start* hung for any image,
   even `alpine echo hi`; `docker create` worked, `docker start` didn't). A
   clean app restart fixed it, and the user's other containers came back thanks
   to their restart policies. Lesson: **`docker ps`/`docker stats` responding
   doesn't mean containerd can spawn tasks** — isolate the failure to
   create/start when diagnosing.
5. **Signature engines don't flag our artifacts** (in this lab test) — the
   polymorphism + custom-compiler claim now has ClamAV evidence in the report.

**Try it**
```bash
docker build -t jocky-test docker/
docker run --rm -v "$PWD":/workspace jocky-test bash /workspace/docker/test.sh
open report.md
```

**Where this leaves us / next session**
Evidence pack is growing (report.md). Next up is **WP4 — the CI/CD mutation
pipeline** (GitHub Actions) so the polymorphism story runs automatically per
commit — the "continuous delivery of unique binaries" pillar.

---

_(Next entry: WP4 CI/CD mutation pipeline.)_
