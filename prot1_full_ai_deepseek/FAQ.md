# JOCKY — Frequently Asked Questions

**Audience:** hackathon judges, reviewers, and the team.
**Honest framing up front:** JOCKY does **not** make binaries invisible to antivirus or
EDR. It defeats the *cheap, automated* detection layers (byte/string signatures, hashes,
reputation) and **raises analysis friction** — it is not a guarantee of stealth. Every
claim below points to verifiable evidence in `decomp_report/`.

---

## 1. "Both my C and JK files got 3/63 on VirusTotal with the same detections — is the language useless?"

No. You uploaded the **source files**, and both contain the same malware-marker strings in
plaintext (`sekurlsa::logonpasswords`, `c2.evil-domain.com/beacon`). The same static-string
engines flagged the same strings in both — that measures the *content*, not the toolchain.
Source is never the deployed artifact; the **binary** is. The correct comparison is
`c_av_bait` (plain C binary) vs `jk_av_bait_l2` / `jk_av_bait_l3` (JOCKY binaries):
the C binary and the level-0 JOCKY binary carry the markers in clear, the level-2/3
binaries do **not** (verified: `strings` finds 0 mimikatz/C2 hits).
Evidence: `decomp_report/av_test/scan_results_custom_sig.txt`.

## 2. "Is JOCKY really undetectable by antivirus?"

**No, and nothing is.** What JOCKY actually does at obfuscation level 2+:
- defeats **byte/string signatures** (marker strings are XOR-encrypted out of the binary),
- defeats **hash/reputation engines** (every build is a unique SHA-256),
- resists casual **strings/`strings`** triage.

What it does **not** do: hide OS API calls, hide decrypted runtime strings in memory, or
change behavioral patterns. The defensible claim is *friction, not invisibility*.
Evidence: `decomp_report/metrics/hashes.txt` (6 seeds → 6 unique hashes).

## 3. "Would an EDR have trouble scanning JOCKY binaries?"

Its static engine — yes. Its behavioral/ML engine — no. The binary still calls the same
OS APIs (`proc_listallpids`, `OpenProcess`, `netstat`, `ReadProcessMemory`), and string
decryption happens in RAM at runtime. An EDR watching behavior sees the same forensic/
credential pattern regardless of what compiled the agent.
Evidence: report §7 (forensic API surface is identical between JOCKY and hand-written C).

## 4. "What does a custom language actually achieve vs just obfuscating C?"

Owning the toolchain is the only clean way to inject **per-build mutation at every layer**
— AST (CFG flattening, opaque predicates, dead code), emitted C (string XOR keys,
constant noise, trampolines, junk functions), and identifiers. Generic obfuscators mutate
bytes or add a packer; JOCKY mutates the *program structure* and ships a different,
unrecognizable artifact every build. Evidence: `decomp_report/c_emitted/` (l0 vs l3 C).

## 5. "Why not just use a packer / obfuscator (UPX, ConfuserEx, ...)?"

Because packed artifacts are *themselves* a well-known signature and heuristic trigger
(high entropy ~7.9, packed-section markers, toolchain fingerprints). JOCKY stays unpacked
(entropy ≤ 3.1), so it doesn't trip "packed" heuristics, and it mutates logic structure
rather than just compressing bytes. Evidence: entropy column in
`decomp_report/metrics/hashes.txt`.

## 6. "How is this different from tooling written in Nim / Golang / Rust?"

Same API-surface reality — an EDR sees the same calls. JOCKY's differentiators are:
(1) a small forensic **DSL** (one `.jk` source → evidence-collection agent), (2)
**deterministic polymorphism** (same seed → reproducible C; different seeds → different
artifacts), and (3) **one source → Linux + Windows + macOS** via `#ifdef`-based
collectors. It is about delivery + ops hygiene, not magical evasion.

## 7. "Why compile to C instead of LLVM IR / machine code?"

C gives us:
- portability to `gcc`/`clang`/MinGW with zero backend work,
- cross-platform collectors via simple `#if defined(_WIN32/__APPLE__/__linux__)` branches,
- **text-level post-processing passes** (string encryption, constant noise, trampolines)
  that are trivial to write, inspect, and debug on the emitted C string.

The pipeline `lexer → parser → sema → obfuscate → codegen → postprocess → cc` keeps every
layer inspectable — which is exactly how we found and fixed the two real bugs below.

## 8. "What does a blue team still see that we can't hide?"

- the **JOCKY runtime footprint**: volatile build markers, the 64 KB `j_buf` global,
  the JSON schema strings of the collectors (encrypted at l2+ but the *shape* remains),
- the **forensic API calls** (`proc_listallpids`, `popen("netstat …")`, JSON building),
- **decrypted strings in memory** while the agent runs,
- behavioral patterns (process + socket + file enumeration in one process).

None of this is erasable by any language/compiler. Evidence: report §11 finding #4.

## 9. "Can ML-based AV detect a custom compiler?"

Eventually, yes. Artifact profiling (entropy, structure, symbol surface, import patterns)
is learnable — the project's own report already characterizes JOCKY output as "custom,
unpacked compiler output." Polymorphism makes it a **moving target**, not a permanent
blind spot. The honest expectation is that detection requires custom tooling/ML — which
is exactly the "friction" JOCKY claims to add.

## 10. "Why did my level-2/3 binaries still get flagged (EICAR)?"

Two reasons, both documented:
1. The string-encryption pass **skips any literal containing `%`** (to protect `printf`
   format strings, `src/postprocess.cpp:164`). The EICAR string contains `%`, so it stays
   plaintext at every level.
2. A real compiler bug we found: level-3 emitted invalid C when a string literal contained
   `{`/`}` (the EICAR `}` broke `trampolineMain`'s naive brace counter). **Fixed** in
   `src/postprocess.cpp` (`findMatchingBrace`); all 16 existing tests still pass.
Evidence: report §P2.4, §P2.5 finding #5.

## 11. "What's the honest success metric for this project?"

Measurable friction, all verified in `decomp_report/`:
- 0 plaintext marker strings in l2/l3 binaries (`strings`),
- unique SHA-256 per build; same seed → byte-identical C,
- ClamAV-clean for non-`%` signatures,
- Ghidra **fails** to recover the level-3 entry point (1-block indirect jump),
- one source cross-compiles to Linux ELF + Windows PE, forensics output correct.

## 12. "What are the known failure modes of the evasion?"

- EDR **behavioral/ML** detection (unchanged API surface),
- **memory scanning** (strings decrypt at runtime),
- YARA rules written against the **JOCKY runtime fingerprint** (markers, `j_buf`, JSON
  shape),
- signature strings containing `%` (never encrypted),
- **source-code leakage** (the `.jk` source still contains the markers — never ship it).

## 13. "Is this legal / ethical?"

This is a **dual-use** project. It is a forensic-analysis framework intended for
authorized lab testing on systems you own or have written permission to test — exactly as
stated in `README.md` ("Authorized use only") and `plan.md`. The polymorphism goal is
operational hygiene for legitimate agents (not being pre-flagged by reputation engines),
and the collectors are evidence-collection tools. All testing here was performed in a
local lab environment with a benign bait program. Use responsibly.

## 14. "What should we actually demo to win the judges?"

Four parts, in order:
1. **The DSL** — one ~20-line `.jk` source builds working Linux + Windows + macOS agents
   that collect processes/sockets/files as JSON. This is the concrete, provable language
   value.
2. **Polymorphism** — same source, 6 seeds → 6 different hashes/sizes; same seed →
   identical C. Show `shasum` side by side.
3. **Static-detection defeat** — `strings` diff l0 vs l3; ClamAV/custom-signature scan
   shows the C binary flagged and the l2/l3 binaries clean (markers gone).
4. **CFG destruction** — Ghidra decompilation: readable structured loop at l0 vs flattened
   state machine + unrecoverable entry at l3.

Close with the honest conclusion: *"we raise the cost of detection, we don't make
anything invisible — and that measurable friction is the product."*

---

*All evidence lives in `decomp_report/` (builds, hashes, ClamAV logs, Ghidra output). See
`decomp_report/report.md` for the full differential analysis.*