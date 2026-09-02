# JOCKY — A Domain-Specific Language & Framework for Incident Response and Forensic System Analysis

**Hackathon plan (SIH 2026) — C++20, cross-platform (Windows & Ubuntu)**

---

## 1. One-line pitch

JOCKY is a custom programming language + compiler + distributed runtime that lets an incident-responder write **one short script** that simultaneously collects forensic artifacts and hunts for adversary activity across **hundreds of endpoints** (Windows and Linux), with every action logged, sandboxed, and attributable — something no existing tool lets you do in a single, purpose-built language.

---

## 2. Problem (the defensible framing of the problem statement)

IR / forensics teams today face three pain points:

1. **No purpose-built language.** Responders glue together PowerShell, Bash, Python, and Sysinternals. These are blocked, logged-as-noisy, or behave differently on every OS, and one wrong line on a live system can destroy evidence.
2. **No safe fleet-wide execution.** Running a custom collection script on 500 machines means hand-rolling deployment, error handling, and result aggregation every time.
3. **Adversary techniques are invisible to generic tooling.** Fileless execution, injection, and malicious driver loading require *targeted* hunts — and writing each hunt from scratch in a general-purpose language is slow.

**JOCKY solves all three:** a small, safe, auditable language for expressing forensic queries; a compiler that emits portable bytecode; and an agent+server architecture that fans scripts out across a fleet and aggregates results.

> **Scope note:** the original problem statement's evasion components (defeating AV signatures, process hollowing / reflective injection to hide inside trusted processes, BYOVD exploitation to disable EDR callbacks, domain fronting to hide command traffic) are **out of scope** — they describe building malware, not forensics. JOCKY instead includes a *detection* module for those exact techniques (§8), which is the legitimate way to "detect adversaries." A forensic tool must be transparent, attributable, and cooperative with the EDR already defending the machine — that is a feature, not a limitation.

---

## 3. Architecture overview

```
                       ┌────────────────────────────┐
                       │   JOCKY Central Manager     │
       ┌──────────┐    │  ┌──────────────────────┐  │
       │ Analyst   │───►│  │ Web Dashboard + CLI  │  │
       │ (browser/ │    │  ├──────────────────────┤  │
       │  terminal)│    │  │ Task Scheduler        │  │
       └──────────┘    │  │ Result Aggregator      │  │
                       │  │ Evidence Store (SQLite)│  │
                       │  │ mTLS Cert Authority    │  │
                       └───────────┬────────────────┘
                                   │  gRPC over mTLS
              ┌────────────────────┼────────────────────┐
              │                    │                    │
       ┌──────▼──────┐      ┌──────▼──────┐      ┌──────▼──────┐
       │ JOCKY Agent │      │ JOCKY Agent │      │ JOCKY Agent │
       │  (Windows)  │      │  (Ubuntu)   │      │  (Ubuntu)   │
       │             │      │             │      │             │
       │ • Bytecode  │      │ • Bytecode  │      │             │
       │   VM        │      │   VM        │      │             │
       │ • Capability│      │ • Capability│      │             │
       │   modules   │      │   modules   │      │             │
       │ • Full audit│      │ • Full audit│      │             │
       │   log       │      │   log       │      │             │
       └─────────────┘      └─────────────┘      └─────────────┘
```

**Four components:**

1. **`jockyc` — the compiler** (C++20, cross-platform): JOCKY source → JOCKY bytecode (`.jkb`). One script compiles once, runs on both OSes because the *agent runtime* implements the OS abstraction.
2. **`jocky-agent`** (C++20, one binary per OS): hosts the bytecode VM + capability modules; connects out to the manager; executes scheduled hunts; streams results + a full audit log.
3. **`jocky-server` — the central manager** (C++20): gRPC server with mTLS; fans out tasks, collects/aggregates results, exposes a web dashboard and REST API.
4. **Dashboard** (embedded web UI served by `jocky-server`; lightweight — no Node build required).

---

## 4. The JOCKY language

### 4.1 Design goals

- **Safe by construction:** no raw pointer access, no arbitrary command execution primitive, no implicit writes. Every mutating operation requires an explicit capability the deployment policy can deny. (This is what makes a "custom language for forensics" *genuinely* better than Python-on-endpoints — not signature games.)
- **Auditable:** every statement maps to a logged action; the compiler emits a human-readable action manifest alongside the bytecode, so an IR lead can review exactly what a script will do on 500 machines *before* deploying it.
- **Declarative-first, imperative-when-needed:** common hunts are queries; complex logic is real code.
- **Cross-platform by design:** the language has **no** OS-specific operations. OS differences live in the runtime, not the script.

### 4.2 Example (target syntax)

```jocky
// hunt.jk — hunt for suspicious driver activity across the fleet
hunt "BYOVD-check" {

    report severity = "high" when
        driver.loaded where driver.signed == false
        or driver.sha256 in feed("known-vulnerable-drivers")

    timeline "persistence-events" {
        source registry.run_keys          // Windows: Run keys; Linux: systemd units
        source scheduled_tasks            // Windows: schtasks; Linux: cron
        source startup_scripts
    }

    collect evidence when process.parent in ["winword.exe", "outlook.exe"]
        and process.image_path in user_download_dirs

    for each proc in process.list() {
        if proc.image_path in user_download_dirs
           and not proc.signed {
            log proc
        }
    }
}
```

### 4.3 Language features (milestone-friendly subset)

| Feature | Purpose |
|---|---|
| `let`, `for`, `if/else`, functions | Basic imperative core |
| Strong static typing (int, string, bool, time, path, list, map, record) | Catch script bugs **before** they touch a live machine |
| Built-in entity sets: `process`, `driver`, `service`, `registry`, `file`, `netconn`, `autorun` | The forensic vocabulary |
| Query blocks: `report … when`, `timeline`, `collect evidence` | Declarative hunting |
| Feeds: `feed("name")` | Match against intel feeds (vulnerable-driver lists, bad hashes) |
| `emit` for structured findings | Results are typed records, not strings |

### 4.4 Why a custom language is the right engineering call (judge-facing)

1. **Safety** — capability-gated, statically typed, no escape hatches. Python/PowerShell can't offer this without massive tooling.
2. **One script, both OSes** — the OS abstraction is in the runtime; scripts are written once.
3. **Pre-deployment review** — action manifests make fleet-wide execution reviewable, which enterprises legally require.
4. **Auditability** — bytecode + manifest + agent log = a defensible chain of what ran where.

---

## 5. Compiler pipeline (`jockyc`, C++20)

```
source.jk ─► Lexer ─► Parser (AST) ─► Semantic analysis / type checker
        ─► HIR (hunt/plan extraction) ─► Action-manifest emitter
        ─► Bytecode generator ─► .jkb (portable bytecode + manifest)
```

- **Hand-written lexer/parser** (recursive descent) — deliberately simple, fully achievable in a hackathon timeline, and a genuine CS-strong demo.
- **Type checker** before any codegen: script errors are caught on the analyst's machine, never on a production endpoint.
- **Action manifest**: human-readable summary ("this script reads: process list, run keys; writes: nothing") emitted beside the bytecode.
- **Bytecode**: compact stack-based VM format (~30 opcodes), trivially portable, cheap to verify on the agent before execution (bounds-checked, no jump-outside-segment).
- **Stretch goal:** LLVM backend instead of a VM (emit LLVM IR for AOT-compiled performance). Optional — the VM is the demo-critical path.

### 5.1 VM (`jocky-agent`)

- Stack machine interpreter, ~1.5k LOC.
- Sandboxed: bytecode can only call **registered capability functions** (`jocky.process_list()`, `jocky.file_hash(path)`, …). No memory access, no syscalls from bytecode.
- Instruction budget + watchdog: a runaway script is killed, not the endpoint.

---

## 6. Capability modules (agent side, the forensic engine room)

Each module is a C++ library exposing typed functions to the VM, implemented **per-OS** behind one interface:

| Module | Windows implementation | Linux implementation |
|---|---|---|
| `process` | Toolhelp32 snapshot, NtQuerySystemInformation | `/proc` walk, netlink connectors |
| `driver` | Enumerate device nodes (`SetupAPI`), driver signature status | `/proc/modules`, `/sys/module`, module signature |
| `service` | SCM enumeration | systemd unit enumeration |
| `persistence` | Run keys, services, scheduled tasks, WMI subscriptions (read-only) | systemd units, cron, shell rc files, udev rules |
| `filesystem` | MFT/USN journal reading (USN journal = live-system-safe), NTFS attribute parsing | ext4 directory walking, inode timestamps |
| `registry` | Registry API (read-only) | (maps to config-file scanning) |
| `net` | Get-NetTCPConnection equivalent (GetExtendedTcpTable) | `/proc/net/tcp*`, `ss`-equivalent parsing |
| `hash/evidence` | SHA-256, fuzzy hashing, SQLite-backed evidence store | same |

**Signature engineering point for judges:** the filesystem module includes a **live-system-safe USN journal / NTFS parser** and an **ext4 inode-timeline builder** — real digital-forensics technique (journal + timestamps → super-timeline), not just file-walking.

---

## 7. Fleet management (`jocky-server`)

- **Transport:** gRPC over **mutual TLS** — agent and server both certificate-authenticated (server runs its own internal CA). Forensic data is sensitive; comms security is a *requirement*, designed openly (the honest counterpart of the original statement's "trusted infrastructure" clause).
- **Task scheduler:** deploy `.jkb` to one / a tag-group / all agents; schedule recurring hunts; kill running tasks.
- **Result aggregator:** normalizes findings across OSes into one schema; dedupes identical hits across hosts; severity ranking.
- **Evidence store:** SQLite — findings, raw collected artifacts (hash + optional copy), full audit logs.
- **Dashboard:** web UI — fleet map, live findings feed, per-host timeline view, script deployment console. Served directly by the C++ server (embedded HTTP; simple HTML/JS, no Node toolchain).

---

## 8. Detection module — "detecting adversaries" (the crown jewel)

Implements detections **for** the adversary techniques named in the original statement. This is what makes the project honest *and* technically deep: you must understand each attack to detect it, and the detections are real, defensible engineering.

| Hunt | Detection logic (agent-side) |
|---|---|
| **Process hollowing artifacts** | Process image path vs. actual mapped-image mismatch; original-file-name ≠ process name; image checksum re-verification; hollowed-region RWX page scan via ReadProcessMemory on **our own agent's** visibility scope |
| **Reflective/injection anomalies** | Executable pages in processes with no backing file on disk; threads whose start address lies outside any mapped module |
| **Suspicious drivers (BYOVD *detection*)** | Loaded-driver enumeration cross-checked against a curated vulnerable-driver feed (e.g., the public Microsoft/LOLDrivers-style lists); signature status + signer reputation; out-of-tree driver loads |
| **EDR tampering attempts** | Audit ETW/Windows event-log for attempts to stop/weaken security services, protected-process failures, PPL violations |
| **Fileless persistence** | WMI event-subscription artifacts, suspicious scheduled-task command lines, LOLBin parent/child anomalies (office app → script interpreter) |
| **Anomalous egress** | Long-lived TLS connections to CDN ranges from non-browser processes (flags domain-fronting-style C2 *from the defender's side*) |
| **C2 infra indicators** | JA3-style fingerprint stubs on agent-visible TLS metadata, periodicity analysis of outbound beacons |

Each detection ships as a **JOCKY script in the standard library** — i.e., JOCKY eats its own dog food: the hunts are written in the language we built.

---

## 9. Tech stack

| Layer | Choice | Why |
|---|---|---|
| Language | C++20 | Problem statement requirement; performance for binary parsing |
| Build | CMake + vcpkg | Cross-platform, judge-recognizable |
| Compiler | hand-written (flex/bison optional) | Full control, demo-friendly |
| VM | custom stack bytecode | portable, small, verifiable |
| RPC | gRPC (protobuf) | Mature mTLS story, cross-platform |
| Storage | SQLite | zero-config, single-file evidence store |
| Crypto | OpenSSL/BoringSSL via vcpkg | mTLS, SHA-256 |
| Dashboard | embedded web UI (plain JS) | no Node toolchain at the hackathon |
| Testing | GoogleTest + JOCKY-language self-tests | compiler + VM test suite is a judging plus |

---

## 10. Milestones (12-week plan, hackathon-pace)

| # | Weeks | Deliverable | Demo value |
|---|---|---|---|
| 1 | 1–2 | Language spec doc + lexer + parser + AST printer | `jockyc parse hunt.jk` — show the AST |
| 2 | 3 | Type checker + first error messages | catch a bad script live |
| 3 | 4–5 | Bytecode generator + VM on Ubuntu | run a script computing over `/proc` |
| 4 | 6 | Windows agent: process + persistence modules | same script, same result, other OS |
| 5 | 7 | mTLS gRPC agent↔server + task fan-out | deploy to 5 VMs at once |
| 6 | 8 | Result aggregation + SQLite store + dashboard v1 | fleet findings on one screen |
| 7 | 9–10 | Detection module: BYOVD-driver feed check, injection anomaly hunts, persistence timeline | the headline demo |
| 8 | 11 | Super-timeline builder (USN/ext4) + evidence hashing | forensic depth |
| 9 | 12 | Hardening, docs, **rehearsed end-to-end demo** | polish |

**Hackathon-minimum viable demo (if time collapses):** one laptop + two VMs (Win + Ubuntu) + manager: write a 15-line JOCKY hunt → deploy to both → live dashboard shows a planted "suspicious" unsigned driver and a fake persistence run-key on both hosts, with audit logs.

---

## 11. What makes this novel for judges (unique points)

1. **The language itself** — a statically typed, capability-gated DSL for IR: no existing open tool has one (Velociraptor's VQL is the nearest cousin; JOCKY is a *full language* with a compiler pipeline, not a query dialect).
2. **Compiled-once, runs-on-both-OSes bytecode** — the OS abstraction lives in the agent, invisible to the script author.
3. **Action manifests** — pre-deployment review of exactly what a script will touch: a governance feature enterprises actually need.
4. **Real forensic engineering** — USN journal parsing, ext4 inode timelines, driver signature verification — not just "run some commands".
5. **Detection library written in JOCKY itself** — self-hosting proof of the language's value.
6. **Full audit chain** — script → manifest → bytecode → per-statement agent logs → aggregated findings: evidence-grade traceability.

---

## 12. Risks & mitigations

| Risk | Mitigation |
|---|---|
| Compiler scope creep | Freeze the spec at week 1: the grammar in §4.2 is the whole language for v1 |
| Windows API surface unfamiliar | Start Ubuntu agent first; Windows process/persistence modules are the minimum |
| gRPC setup time | Fallback: custom protobuf-length-prefixed framing over TLS sockets (already needed for the dashboard) |
| Two-OS demo logistics | 2 VMs suffice; "fleet" = 5 agents max on one host |
| Detection false positives | Every detection ships with a planted-artifact demo set — judges see true positives, controlled |

---

## 13. Out of scope (explicit)

- Any technique for evading or disabling security software (signature-evasion builds, process hollowing/injection *as an execution method*, BYOVD *exploitation*, hiding network traffic). JOCKY detects these; it does not perform them.
- Evasive packaging/persistence of the agent itself — the agent is a documented, openly installed, policy-gated service.

---

*Next artifact: `TEACHING.md` — the prerequisite curriculum (C++ beyond CP, OS internals, PE/ELF, compiler basics, how EDR/AV actually work) building up to this project, lesson by lesson.*
