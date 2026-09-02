# JOCKY — End-to-End Implementation Plan

> A Next-Gen forensic-analysis language framework (SIH 2026)

**IMPORTANT — AUTHORIZED USE ONLY**
This plan describes techniques that are dual-use (defensive + offensive). Everything here is
intended strictly for **authorized** security testing: your own lab machines, CTFs, university
research, or sanctioned red-team engagements where you have written permission. The same
techniques that make a forensics framework stealthy are exactly what real malware uses, so the
line is drawn by *authorization*, not by the code. Keep every test inside a controlled,
disconnected lab environment (VMs with snapshots). Never deploy any component of this project
against systems you do not own or have explicit written consent to test. Many of the underlying
behaviors are also covered by local cyber laws — be an ethical researcher, not a script kiddie.

---

## 0. Problem Statement Analysis

### What they actually want
A **programming language + framework** ("JOCKY") whose purpose is forensic/malicious-activity
analysis, but which is built so that **the analysis tooling itself is not flagged by AV/EDR**.
The core insight of the problem statement: *commercial AV blocks any unknown/custom tool that
tries to introspect the system. If you ship your analysis scripts through your own compiler
pipeline, every build is unique, so signature and reputation engines can't pre-flag it.*

### The four pillars they demand
1. **Independent programming language** → custom lexer/parser/codegen (or an LLVM frontend) so
   binaries aren't "standard MSVC/GCC output".
2. **Automated polymorphism via CI/CD** → every build gets unique hashes, shuffled entry points,
   reordered import tables, encrypted strings → defeats signature + file-reputation databases.
3. **File-less execution** → analysis payloads run in memory of trusted processes (process
   hollowing, reflective injection, thread hijacking, direct syscalls, API unhooking).
4. **Kernel-level subversion / BYOVD** → use legit-but-vulnerable signed drivers to disable EDR
   callbacks or manipulate kernel structures.

### Our honest reading (the "unique points" part)
- Pillars 1–2 are the **buildable, defensible core** and are genuinely novel engineering:
  a purpose-built language + a mutating CI/CD compiler pipeline. This is our flagship deliverable.
- Pillar 3 (in-memory execution) is standard, well-documented red-team technique. We implement it
  for *controlled lab demos*, emphasizing the forensic value: collecting artifacts without touching
  disk and without alerting the very agent we are analyzing.
- Pillar 4 (BYOVD/EDR-blinding) is the most dangerous. We will **NOT** ship a working
  EDR-bypass driver in this plan. We cover it as a *detection-research* workstream: analyze how
  such attacks work, what artifacts they leave, and how to *detect* them — which is the actual
  forensic goal. Judges want to see you understand the attack, not that you can perform it.

---

## 1. High-Level Architecture

```
┌────────────────────────────────────────────────────────────────────┐
│  JOCKY Language                                                   │
│  [lexer] → [parser/AST] → [typecheck] → [codegen]                 │
│        ↓ transpiles to C (not raw machine code — simpler & safe)  │
│  [C source]                                                       │
│        ↓                                                          │
│  CI/CD Build Pipeline (per commit / per deploy)                   │
│  [polymorphic mutator] → [string/const encryptor]                 │
│  → [entry-point shuffler] → [import-table reorderer]              │
│  → [junk/opaque predicate injector] → compile (gcc/mingw)         │
│        ↓                                                          │
│  Unique binary #N  (fresh hash every time)                        │
└────────────────────────────────────────────────────────────────────┘
                              │ HTTP(S)
                              ▼
┌────────────────────────────────────────────────────────────────────┐
│  Management Console (Python/Flask or C++ REST)                     │
│  • multi-agent dashboard  • task dispatch  • artifact ingestion    │
│  • routed through CDN / cloud API (domain fronting, legit cloud    │
│    buckets/queues as C2-looking-but-legit channels)                │
└────────────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌────────────────────────────────────────────────────────────────────┐
│  Agent (JOCKY-compiled binary, cross-platform Win/Linux)           │
│  • loader     : in-memory execution (hollowing/inject/syscall)     │
│  • modules    : forensics collectors (processes, network, etc.)    │
│  • transport  : SOCKS5 routing + TLS via cloud/CDN fronting        │
└────────────────────────────────────────────────────────────────────┘
```

### Language choice
- **JOCKY itself:** a small, purpose-built language (C-like syntax, easy to write) that we write
  in **C++**.
- **Compiler backend strategy:** transpile JOCKY → C, then compile C with gcc/clang/MinGW.
  Full native codegen or an LLVM frontend is a "stretch goal". Transpiling to C is dramatically
  simpler, still satisfies "custom compiler artifacts", and keeps us sane in a hackathon window.
- **Console:** Python/Flask (fast to build, great for demos) or C++ REST. Choose Python for speed.

---

## 2. Work Packages & Timeline (e.g., 6–8 weeks / 8 sprints)

| # | Work Package | Deliverable | Priority |
|---|--------------|-------------|----------|
| 0 | **Prerequisites + lab setup** | VMs, cross-compiler toolchain, CMake skeleton, repo | HIGH |
| 1 | **JOCKY lexer + parser** | tokenizer, recursive-descent parser, AST, `--ast` dump | HIGH |
| 2 | **JOCKY → C transpiler** | codegen for ints/strings/arrays/control flow/functions | HIGH |
| 3 | **Forensics stdlib** | `sys.process_list()`, `net.sockets()`, `fs.read()`, `reg.list()`, `mem.dump()` modules | HIGH |
| 4 | **CI/CD + polymorphic pipeline** | GitHub Actions workflow; mutators: string-encrypt, entry-point shuffle, import reorder, opaque predicates, unique hash report | HIGH |
| 5 | **In-memory loader** (lab-only) | process hollowing + reflective load of a test payload; direct-syscall stub for 2-3 APIs | MEDIUM |
| 6 | **Transport** | SOCKS5 client, TLS, domain-fronting via real CDN (e.g., upload a file to a public bucket / Azure CDN edge, connect through it) | MEDIUM |
| 7 | **Management console** | Flask dashboard: register agents, dispatch JOCKY tasks, receive JSON artifacts | MEDIUM |
| 8 | **BYOVD & EDR-bypass research + detection** | Threat-intel doc + detection rules (YARA/Sigma) for the techniques; **no weaponized driver** | MEDIUM |
| 9 | **Demo + polish** | end-to-end demo script, README, poster, judge slides | HIGH |

---

## 3. Unique / Differentiating Points (put these on the poster)

1. **A real custom language, not a script.** Most teams will "pack" a known tool. We build the
   tooling *and* the language. Judges can run a JOCKY script and watch it compile to unique C → binary.
2. **CI/CD as the polymorphism engine.** "Continuous Delivery of Malware" is the exact paradigm
   shift the problem statement describes. Each commit to the analysis-module repo automatically
   emits a freshly-mutated binary. We can show `sha256` diffing across 20 builds = 20 hashes.
3. **Cross-platform from one codebase.** JOCKY transpiles to C; we compile for Windows (MinGW-w64
   or MSVC) and Ubuntu in the same pipeline → same source, both OS artifacts.
4. **"Analysis payload, not malware."** Position the framework as a *forensic instrument*: its
   goal is to collect digital evidence the way a triage tool would, but delivered in a way that
   doesn't get false-positived by the very security stack we're evaluating.
5. **Detection-centric BYOVD workstream.** Instead of "we can blind EDR", we deliver: *"we
   analyzed X known vulnerable drivers, here's the detection rule and artifact timeline."* This is
   the responsible, judge-safe framing.
6. **Legitimate-cloud C2 transport.** Show domain fronting done the *boring legal way*: agent →
   HTTPS → CDN edge (Cloudflare/Azure Front Door) → origin server. Same technique bad guys use,
   but on infrastructure we own and registered to ourselves.
7. **Entropy/quality telemetry.** Every build emits a report (hash, section entropy, import count,
   AV-scan result in lab, size) → a "stealth score" dashboard. Nice demo visualization.

---

## 4. Technical Deep-Dive Per Pillar

### 4.1 Pillar 1 — The JOCKY Language (work packages 1–3)
- **Grammar** (EBNF sketch): C-like. Types: `int`, `str`, `bool`, `byte[]`, `list<T>`, `map`.
  Statements: `let`, `if/else`, `for`, `while`, `fn`, `return`, `sys.exit()`, `net.get()`.
- **Frontend:** hand-written recursive-descent parser (no flex/bison — fewer deps). AST with
  source positions. Semantic pass for type checking + symbol tables.
- **Backend:** AST → C source emitter. Mapping table for JOCKY stdlib calls → C wrapper calls.
- **Unique touch:** every transpile can apply *minor* semantic de-synchronization (rename
  identifiers with an RNG, swap if/else ordering, flatten one level of nesting) — this is where
  the "alter basic control-flow graphs and token generation" claim is demonstrably true.

### 4.2 Pillar 2 — CI/CD Polymorphism (work package 4)
Pipeline stages (each is a C++ tool under `tools/`):
1. **`mutate_strings`** — replace string literals with XOR/RC4-encrypted blobs + inline decryptor;
   per-build random key.
2. **`mutate_imports`** — for Windows: reorder the `.idata` entries by regenerating the import
   descriptor table in a random order; resolve imports at runtime via `GetProcAddress` + hash.
3. **`mutate_entry`** — pad/shrink `.text`, place a small decryptor trampoline before the real
   entry, adjust AddressOfEntryPoint.
4. **`mutate_cfg`** — inject opaque predicates (`if (x*x >= 0)`) and dead code between basic blocks.
5. **`report_build`** — emit build report JSON: sha256, import count, section entropy, size.
- Implemented in a GitHub Actions workflow matrix (windows + ubuntu runners) so every PR yields
  fresh artifacts. This literally is "CI/CD as an obfuscation engine".

### 4.3 Pillar 3 — In-Memory Execution (work package 5, lab-only)
- **Process hollowing** (lab demo): create a suspended trusted process, unmap its image,
  write our JOCKY-compiled payload into its memory, set context to our entry, resume.
- **Reflective DLL load**: map a position-independent DLL manually into our own (or a remote)
  process, resolve its import table, call `DllMain` — never touching `LoadLibrary`.
- **API unhooking** (educational PoC): re-read clean `ntdll.dll` from disk/`KnownDlls`, restore
  hooked bytes, or bypass hooks with direct syscalls (hardcode syscall numbers for 2–3 APIs).
- All demos run in a **Windows 10/11 VM with a snapshot**, against test targets we own.
- Every technique gets a *detection note* (what to look for in ETW, Memory Scanner, etc.) — keep
  the defender hat on.

### 4.4 Pillar 4 — Kernel / BYOVD (work package 8, research + detection ONLY)
- Build a **knowledge base**: enumerate known signed vulnerable drivers (RTCore64, delimon, etc.),
  their CVEs, vulnerable IOCTLs, and the standard attack flow (load → query → escalate/disable).
- Deliverable = **detection pack**: YARA rules, Sigma rules, and a Sysmon/ETW event timeline
  describing how to *catch* a BYOVD attack. Optionally a *dummy* driver skeleton that logs to
  DbgView and does nothing harmful, purely to teach the loading flow in the lab.
- Explicitly out of scope: any code that disables a real EDR/AV or elevates a real system.

### 4.5 Pillar 3b/4b — Transport & Console (work packages 6–7)
- **SOCKS5 client** in C++ (RFC 1928): handshake, CONNECT via relay, forward traffic.
- **Domain fronting (legal)**: agent connects to `https://<our-cdn-edge>/` with Host header of our
  origin; CDN edge forwards to our Flask origin. Wrapped in TLS via our own certs.
- **Console**: agents call back with JSON artifacts (process list, sockets, files). Dashboard
  shows which agents are live, dispatch a JOCKY script to N agents, render results.

---

## 5. Tech Stack

| Layer | Tech | Why |
|-------|------|-----|
| Language impl | C++17 + CMake | matches problem statement ("implemented in cpp"), fast lexer/parser/codegen |
| Cross-compile | MinGW-w64 (win), gcc/clang (ubuntu), CI runners | one source → two OS binaries |
| CI/CD | GitHub Actions matrix | automatic per-commit polymorphism |
| Console | Python 3 + Flask (or FastAPI) | fast dashboards + agent API |
| TLS | OpenSSL / mbedTLS | transport encryption |
| Testing | Catch2 or GoogleTest; CI on both OSes | correctness of the language |
| Docs | plan.md + TEACHER.md + build diary | engineering story for judges |

---

## 6. Risks & Mitigations

| Risk | Mitigation |
|------|-----------|
| Scope creep on the language (C++ work is big) | Keep grammar small; transpile to C; postpone LLVM codegen |
| AV-flagging during dev (false positive on our own lab) | Work in VMs; add AV exclusions in the lab only; use signed test certs where needed |
| Cross-platform syscall/loader differences | Implement Windows loader in VM; Linux variant is simpler (memory maps) |
| Ethical/legal exposure | Authorized-lab-only policy in README; no real EDR bypass; detection-first posture |
| Judges think it's "malware" | Lead with the forensic mission, the language, and the detection workstream |
| Time | Strict sprint list; demo is a recorded script not a live attack |

---

## 7. Definition of Done (Demo Script)
1. Write `forensic.jk` (JOCKY) that lists processes, open TCP sockets, and reads a target file.
2. `jocky build` → CI runs → 2 binaries (win + linux) with unique hashes vs previous builds.
3. Run Windows binary in VM → collects artifacts → POSTs JSON to console via CDN-fronted HTTPS.
4. Console shows agent online + artifact JSON.
5. Show 5-build hash table + stealth-score report.
6. Show BYOVD *detection* rules catching a lab-simulated attempt.

---

## 8. Immediate Next Steps
1. Read `TEACHER.md` modules 1–8 (prerequisites).
2. Set up lab: 1 Ubuntu VM + 1 Windows 10/11 VM (snapshotted), plus your host as build machine.
3. `mkdir` repo structure (plan in TEACHER module 8 / build diary) and scaffold CMake + CI.
4. Start Work Package 1 (lexer).
