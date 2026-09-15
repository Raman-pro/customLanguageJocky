# JOCKY Framework — SIH 2026 (Problem Statement 26148)

> **Creation of scripts/functions with new programming language to commence Computer & Network forensic analysis without triggering security solutions**  
> *Smart India Hackathon 2026 | Theme: Blockchain & Cybersecurity*

---

## Executive Overview

**JOCKY** is a specialized, cross-platform programming language framework designed to conduct deep digital forensics, host recon, and network investigation without being thwarted by modern Antivirus (AV) and Endpoint Detection & Response (EDR) agents.

Traditional forensic scripts and utilities fail when deployed on compromised or monitored endpoints because heuristic scanners, signature matching, and reputation engines flag their toolchains or standard Windows/Linux API call signatures. JOCKY addresses this through:

1. **Custom LLVM IR Frontend:** Generates binaries with non-standard control-flow graphs, customized symbol surfaces, and proprietary token pipelines that evade static signatures.
2. **Built-in Continuous Polymorphism:** Compiler passes inject opaque predicates, mutate basic blocks, and generate dynamic trampoline entry points so every build produces a mathematically unique binary hash.
3. **Volatile In-Place String Encryption:** String encryption pass encrypts all user string literals and linked C-runtime literals (webhook endpoints, curl payloads, JSON headers) so zero plaintext survives into the binary at obfuscation levels $\ge 2$.
4. **Living-off-the-Land (LotL) Forensic Builtins:** Native modules (`fs`, `sys`, `net`, `env`, `mem`) gather vital system state and exfiltrate findings over trusted HTTPS channels.

---

## Directory Organization

```
SIH2026/
├── frontend/                       # Local forensic console with mock evidence
├── prot2_llvm_full_ai_deepseek/    # [PRIMARY] Final JOCKY compiler & runtime (LLVM backend)
│   ├── CMakeLists.txt              # Compiler build definition (LLVM 18+ required)
│   ├── src/                        # Lexer, AST, Parser, Sema, Obfuscator, LLVM Codegen
│   ├── runtime/                    # C runtime (HTTP/JSON exfil, process list, mem dump)
│   ├── scripts/                    # Test and forensic scripts (.rd files)
│   ├── tests/                      # Unit, obfuscation, and string-leak regression tests
│   ├── LANGUAGE.md                 # Language specification, grammar, and builtin API
│   └── README.md                   # Prot 2 compiler architecture details
│
├── evaluation/                     # Consolidated Evaluation & Benchmark Suites
│   ├── decomp_report/              # Headless Ghidra differential decompilation analysis
│   │   ├── report.md               # 480+ line forensic reverse-engineering comparison
│   │   ├── build.sh                # Test matrix compiler (obf levels 0..3 vs baseline C)
│   │   ├── decompile.sh            # Automated Ghidra headless decompiler runner
│   │   ├── metrics.py              # CFG block/edge count and complexity extractor
│   │   ├── ghidra_script/          # Ghidra post-analysis export scripts
│   │   └── metrics/                # Generated CFG metrics and binary hash tables
│   │
│   └── av_test/                    # Antivirus & EDR Evasion Test Suite
│       ├── Dockerfile.scan         # ClamAV isolated scanning harness
│       ├── custom.ndb              # Custom signature rules for recon/credential staging
│       ├── scan_results_*.txt      # Verifiable scan outputs demonstrating evasion
│       └── av_bait.rd              # Benign credential-recon bait script
│
├── presentations/                  # Presentation Decks & SIH Guidelines
│   ├── SIH_JOCKY_Complete.pptx     # Core presentation slide deck
│   ├── PPT_CONTENT_ORGANIZATION.md # Slide-by-slide technical talking points & script
│   ├── SIH2026-IDEA-Presentation-Format.pptx # Official SIH template
│   ├── ps.txt                      # Problem statement specifications
│   └── *.pdf                       # Reference pitch decks and formatting guidelines
│
├── research/                       # Malware Analysis References (Academic / Lab Use)
│   ├── Conti-RW-NEW/               # Leaked Conti ransomware source code
│   └── nekros/                     # Python/web multi-stage ransomware sample
│
└── archive/                        # Legacy Prototype Archive
    ├── prot1_full_ai/              # Initial design specification
    └── prot1_full_ai_deepseek/     # Prototype 1 (C Transpiler implementation)
```

---

## Quick Start Guide

### Frontend demo

```bash
cd frontend
npm ci
npm run dev
```

Open `http://localhost:5173/fleet`. The frontend uses prepared demonstration data.
See [the frontend guide](frontend/README.md) for validation commands and details.

### 1. Building the Final JOCKY Compiler (Prot 2)
Prerequisites: CMake 3.20+, C++17 compiler, and LLVM 18/19 (e.g. `brew install llvm` on macOS).

```bash
cd prot2_llvm_full_ai_deepseek
mkdir -p build && cd build
cmake ..
cmake --build .
```

### 2. Running Compiler Regression & Obfuscation Tests
```bash
cd prot2_llvm_full_ai_deepseek
./tests/run_tests.sh
./tests/run_obf_tests.sh
```

### 3. Compiling a JOCKY Forensic Script
```bash
# Level 0 (debug build):
./build/jocky --build scripts/demo.rd

# Level 3 (high obfuscation: opaque predicates, string encryption, trampolines):
./build/jocky --seed 424242 --obf-level 3 --build scripts/av_bait.rd
```

### 4. Running the Evaluation Suites
- **Decompilation differential report:**
  ```bash
  cd evaluation/decomp_report
  ./build.sh
  python3 metrics.py
  ```
- **ClamAV evasion verification:**
  ```bash
  cd evaluation/av_test
  docker build -t clamav-scanner -f Dockerfile.scan .
  docker run --rm -v "$(pwd):/scan" clamav-scanner clamscan -d /scan/custom.ndb /scan/scan_set/
  ```
