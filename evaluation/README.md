# Evaluation & Benchmarking Suite

This directory contains empirical verification, decompilation analysis, and antivirus evasion benchmarks for the **JOCKY** language framework.

---

## Directory Structure

```
evaluation/
├── decomp_report/              # Ghidra differential decompilation analysis & metrics
│   ├── report.md               # Full 480+ line reverse-engineering report
│   ├── build.sh                # Test matrix builder across obfuscation levels 0..3
│   ├── decompile.sh            # Headless Ghidra automated decompilation runner
│   ├── metrics.py              # CFG block/edge & opaque predicate metric extractor
│   ├── ghidra_script/          # Ghidra post-analysis export scripts (Java & Python)
│   ├── c_equiv/                # Hand-written baseline C implementations
│   ├── c_emitted/              # Emitted C intermediate source code
│   ├── decomp/                 # Ghidra decompiled C reconstruction files
│   ├── builds/                 # Compiled benchmark binaries (jk_* and c_*)
│   └── metrics/                # Extracted CFG complexity & hash tables
│
└── av_test/                    # Antivirus and EDR evasion testing suite
    ├── Dockerfile.scan         # ClamAV isolated scanning container (Debian arm64/amd64)
    ├── custom.ndb              # Custom ClamAV signature database (recon & credential markers)
    ├── scan_results_custom_sig.txt # Scan logs proving evasion at obf-levels >= 2
    ├── scan_results_real_db.txt    # Scan logs against upstream ClamAV database
    ├── scan_set/               # Automated test sample bundle
    ├── av_bait.rd              # Prot2 (LLVM frontend) benign recon test script
    ├── av_bait.jk              # Prot1 (C transpiler) benign recon test script
    ├── av_bait.c               # Baseline C equivalent
    └── av_bait.exe             # Windows PE test binary
```

---

## 1. Decompilation Analysis (`decomp_report/`)

Compares decompiled outputs of identical logic across:
- Hand-written C (`c_*`) compiled with `clang -O2`
- JOCKY binaries across obfuscation levels `l0`, `l1`, `l2`, `l3`

### Key Findings (from [`report.md`](./decomp_report/report.md)):
1. **Opaque Predicates:** Defeat compiler dead-code elimination and constant-folding, expanding CFG blocks by **2.5x to 8x** over baseline C.
2. **Control-Flow Flattening:** Level 2/3 transforms linear execution into complex state-machine dispatchers.
3. **String Concealment:** String encryption strips plaintext strings from the binary; at level 2+, zero sensitive literals survive.
4. **Entry-Point Concealment:** Main entry point is hidden behind dynamic multi-stage trampoline chains.

To re-run metrics extraction:
```bash
python3 decomp_report/metrics.py
```

---

## 2. Antivirus Evasion (`av_test/`)

Tests whether JOCKY binaries evade signature and heuristic detection compared to baseline C programs with identical behavioral profiles (process listing, environment harvesting, credential staging, and webhook exfiltration).

### Execution:
1. Build the isolated ClamAV scanning container:
   ```bash
   cd evaluation/av_test
   docker build -t clamav-scanner -f Dockerfile.scan .
   ```
2. Scan the test binaries:
   ```bash
   docker run --rm -v "$(pwd):/scan" clamav-scanner clamscan -d /scan/custom.ndb /scan/jk_av_bait_l0 /scan/jk_av_bait_l2 /scan/jk_av_bait_l3 /scan/c_av_bait
   ```
3. Results:
   - `c_av_bait`: **FOUND** (Detected via static signatures)
   - `jk_av_bait_l0`: **FOUND** (Detected via unencrypted string markers)
   - `jk_av_bait_l2`: **OK** (Evaded detection)
   - `jk_av_bait_l3`: **OK** (Evaded detection)
