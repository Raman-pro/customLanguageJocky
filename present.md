# JOCKY — PRESENTATION PLAYBOOK
### Smart India Hackathon 2026 — Problem Statement 26148
### "Creation of scripts/functions with a new programming language to do computer & network forensic analysis without triggering security solutions"

This file has everything you need to present the PPT:
1. What we actually built (ground truth)
2. Slide-by-slide content in simple English
3. Five different ways (styles) to tell the story
4. Ready-made scripts for 3, 5, 10 and 15 minutes
5. Demo plan with backup steps
6. A big question bank: easy, medium, tough, very very very hard
7. Ethics and legal answers (very important for this problem statement)

Everything is written in easy English so a judge with **no cyber-security background** can follow and even ask questions.

---

## 0. HOW TO USE THIS FILE

| If you have... | Read... |
|---|---|
| 5 minutes to prepare | Section 2 (one-line pitch) + Section 12 (cheat sheet) |
| 30 minutes | Section 1, 2, 3, 8, 12 |
| A full day | The whole file |
| To answer a judge's question | Section 9 (Q&A bank) |
| To choose how to present | Section 4 (five styles) |

Golden rule while reading: **never say "we made a virus". Say "we made a forensic instrument that is allowed to work in a hostile, monitored environment."** Same tool, different permission. That is the whole project in one sentence.

---

## 1. GROUND TRUTH — WHAT WE ACTUALLY BUILT

Judges respect honesty. Know exactly what is done, what is proven, and what is roadmap.

### 1.1 One-line summary of the prototype
We built a **real compiler** for our own small forensic language called **Read** (files end in `.rd`). The compiler uses **LLVM** to produce real machine code, links in a forensic runtime, and can **change the binary a little every time it is built** so that antivirus signature databases do not recognise it.

### 1.2 What is BUILT and DEMONSTRATED today

| Item | Status | Detail |
|---|---|---|
| Own language "Read" (.rd) | Built | int, str, bool; variables; if/else; while; for; functions; recursion; comments; type checking with clear error messages |
| Real LLVM compiler | Built | C++17, LLVM 15+/23. Pipeline: lexer -> parser/AST -> semantic check -> LLVM IR -> link runtime IR -> obfuscation -> O2 -> object -> binary |
| Cross-platform | Built | One source builds for Linux, macOS, and Windows (`--target mingw` gives a real PE32+ .exe) |
| Forensic standard library | Built | `sys.now`, `sys.cwd`, `sys.sleep`, `sys.process_list`, `env.get`, `net.sockets`, `net.post`, `net.send`, `fs.read/write/list/exists`, `reg.list` (Windows), `mem.dump` (Windows) |
| Output for a management console | Built | Collectors return JSON strings, so a dashboard can read them directly |
| Polymorphic builds (4 levels) | Built | Level 0 rename+markers; Level 1 + opaque predicates; Level 2 + string encryption + junk functions; Level 3 + entry-point trampoline |
| Unique binary every build | Proven | Different seed -> different SHA-256. Same seed -> same emitted code (deterministic). 24 JOCKY binaries across 6 programs x 4 levels = all different hashes |
| Reverse-engineering proof | Proven | 30 binaries decompiled with Ghidra 12.1.2, compared against hand-written C with the same logic |
| Antivirus proof | Proven | ClamAV (3.28M+ signatures) plus a custom signature file. Plain C version flagged; JOCKY level 2/3 clean for the tested markers |
| Test suite | Built | `run_tests.sh`, `run_obf_tests.sh`, `run_string_leak_tests.sh`. Every program gives the same output at every obfuscation level |
| Lab exfiltration demo | Built | `net.post` / `net.send` do a single HTTPS POST (lab webhook) - shown only in the controlled lab |

### 1.3 What is ROADMAP (say it clearly, do not fake it)

| Item | Status | Our honest line |
|---|---|---|
| Central management console | Roadmap / partial | "The collectors already speak JSON, which is exactly what a console needs. The dashboard is Phase 2." |
| Multi-agent orchestration across many machines | Roadmap | "The single-agent path is proven; scaling is a networking and storage problem, not a language problem." |
| In-memory execution (process hollowing, reflective DLL, API unhooking, direct syscalls) | Roadmap / research | "We studied and documented them; the safe lab demos are the next phase. We will not ship a weapon." |
| BYOVD (Bring Your Own Vulnerable Driver) | Research / detection only | "We produce a research document and detection rules. We do not build an EDR-killer." |
| Domain fronting / CDN routing | Roadmap | "The protocol path is designed; the lab webhook demo shows the shape of it." |
| SOCKS5 routing | Roadmap | "Planned network module." |

### 1.4 Numbers you can quote (from our own evidence files)

- CFA/Ghidra comparison: `evaluation/decomp_report/report.md`
- Hash + entropy table: `evaluation/decomp_report/metrics/hashes.txt`
- CFG size table: `evaluation/decomp_report/metrics/cfg_metrics.txt`
- AV scan logs: `evaluation/av_test/scan_results_custom_sig.txt`
- Real AV DB log: `evaluation/av_test/scan_results_real_db.txt`

Example talking numbers:
- Program "demo": hand-written C main = 10 blocks / 14 edges. JOCKY level 0 = 28 / 41. Level 1 = 40 / 59. Level 2 and 3 = 70 / 113.
- Program "algorithms": C = 22 / 32. JOCKY level 0 = 188 / 281.
- Strings visible in binary: level 0 = 7 of 7. Level 2 and 3 = 0 of 7.
- Entropy stays below about 3.1 (packed malware is near 7.9), so we look like normal compiler output, not a packer.
- Size overhead of full obfuscation vs level 0: about 1.0x to 1.4x.
- Exported function symbols: 2 (a deliberately tiny surface).

---

## 2. THE PITCH

### 2.1 One line
"JOCKY is a small forensic programming language and compiler that lets investigators collect evidence on a compromised, monitored machine - and because every build looks different, the security tools do not block our own forensic tool."

### 2.2 30-second version
"When an incident happens, the attacker's own antivirus or EDR can block the investigator's tools. It is like the police being stopped at the door by the thief's own security system. We built a compiler that produces a fresh, unique forensic agent on every build, so signature-based security cannot recognise and block it. It is one language, it runs on Windows, Linux and macOS, and it already collects processes, network sockets and files as JSON. We proved it with Ghidra decompilation and a ClamAV test: the plain version gets flagged, our protected version does not."

### 2.3 The 10-second version (if the judge is walking away)
"We wrote a tiny language and compiler for forensic tools, and every build gets a new fingerprint so antivirus signatures cannot stop it."

---

## 3. SLIDE-BY-SLIDE CONTENT AND TALKING POINTS

This follows the official SIH 6-slide idea format. Each slide has: what to show, what to say, and the "one sentence that lands".

---

### SLIDE 1 — TITLE

**Show**
- SIH 2026 logo, team name, team ID
- Problem Statement ID: 26148
- Title (copy exactly): "Creation of scripts/functions with new programming language to commence Computer & Network forensic analysis without triggering security solutions"
- Theme: Blockchain & Cybersecurity. Category: Software.
- Optional tagline: "A new language for digital forensics that works even when the attacker's security is watching."

**Say**
"Good morning. We are Team [name]. Our problem statement is number 26148. In simple words: investigators today are blocked by antivirus while doing their own job. We built a language and compiler called JOCKY to fix that."

**The one sentence that lands**
"Today the investigator's tools are the ones getting blocked - we fixed that."

---

### SLIDE 2 — PROPOSED SOLUTION

**Show (six boxes or a grid)**
1. Own language + compiler ("Read", `.rd`)
2. Polymorphic builds (a fresh binary each time)
3. Cross-platform (Windows, Linux, macOS from one source)
4. Forensic standard library (processes, sockets, files, registry, memory)
5. JSON output for a management console
6. Safe, lab-only, authorized-use design

**Say**
"Normal forensic scripts are written in PowerShell or Python. Antivirus already knows those tools, so it blocks them. We made our own language and our own compiler. The compiler adds a little controlled randomness every time it builds, so every agent has a different fingerprint. Yet the program's behaviour is exactly the same. On top, we ship built-in forensic functions that collect process lists, network sockets and files, and hand them over as JSON."

**The line that lands**
"Same job, new face, every single build."

**If a judge asks "is this not just obfuscation?"**
"Obfuscation hides code. We changed the whole delivery process: our compiler itself produces the variation, at the intermediate-representation level, before optimisation. That is a language and compiler project, not a packer."

---

### SLIDE 3 — TECHNICAL APPROACH

**Show: Diagram 1 — Compilation pipeline**
```
.rd source
  -> lexer -> parser -> AST -> semantic check
       -> LLVM IR code generation
            -> link the forensic runtime into the same module
                 -> obfuscation passes (markers, opaque predicates, string encryption, junk, trampoline)
                      -> LLVM O2 optimisation
                           -> object file -> link -> binary (or Windows .exe)
```

**Show: Diagram 2 — The four obfuscation levels**

| Level | What it adds | Effect on the binary |
|---|---|---|
| 0 | Seeded renaming + volatile build markers | Different bytes, same shape |
| 1 | Opaque predicates (`g*g >= 0` on a volatile value) | Extra always-true branches that survive O2 |
| 2 | Per-string XOR encryption + junk functions | No readable text left; dead code added |
| 3 | Entry-point trampoline chain (1-3 hops) | Real main function is hidden behind callers |

**Show: Diagram 3 — The forensic library**
`sys.*`, `env.get`, `net.sockets`, `net.post/send`, `fs.*`, `reg.list`, `mem.dump` - all cross-platform, returning JSON.

**Show: Diagram 4 — Evidence slide (small table)**
- Ghidra: 30 binaries decompiled
- Level 2/3: entry point cannot be resolved by the decompiler
- Level 2/3: zero literal strings visible (`strings` finds none)
- 24 unique hashes across builds
- Entropy stays low (not a packer)

**Say**
"Here is the pipeline. Source goes through a normal compiler front-end, produces LLVM intermediate representation, we link our runtime into the same module, then we run our obfuscation passes before optimisation, and finally emit a real object file and binary. The important part: our randomness is baked into the intermediate representation, so it survives the optimiser. That is why the binary really is different every time, not just in the source text."

**The line that lands**
"We proved it, not just claimed it: a decompiler cannot follow our level-3 entry point, and the string table is empty."

---

### SLIDE 4 — FEASIBILITY AND VIABILITY

**Show (three columns)**
- Technical: mature LLVM foundation, proven cross-compilation, working prototype today
- Economic: open-source, no licence cost, runs on normal developer machines
- Operational: one source for three operating systems, JSON output ready for a console

**Show a small "what we tested" table**
| Test | Tool | Result |
|---|---|---|
| Reverse engineering | Ghidra 12.1.2 | Level 3 entry point unresolved; algorithm obscured |
| Antivirus signatures | ClamAV + custom rules | Plain C flagged; JOCKY level 2/3 clean for tested markers |
| Correctness | Own test suite | Same output at every level |
| Memory safety | valgrind | 0 errors |
| Cross-compile | LLVM + MinGW | Valid Windows PE32+ produced |

**Say**
"This is not a slide-only idea. We built it, tested it, and measured it. LLVM is industry standard, so we are standing on a strong base. The cost is near zero because it is open source. And the same source runs on all three major operating systems."

**The line that lands**
"It is feasible enough that it already exists - today."

---

### SLIDE 5 — IMPACT AND BENEFITS

**Show (three user groups)**
- Digital forensic investigators: collect evidence on machines that would otherwise block them
- Law enforcement / CERT teams: covert, careful investigation of hostile networks
- Enterprise red teams: test whether their own security can stop a modern, changing threat

**Show (impact areas)**
- Social: faster cybercrime investigation, better protection of citizens
- Economic: no licence cost, less manual work, shorter incident response
- Strategic: home-grown forensic capability and skill building

**Show (one honest use case)**
"Ransomware case: the infected server's security tries to block our tool. Instead of disabling security (which would alert the attacker), we deploy a JOCKY agent that blends in, collects process and socket evidence, and reports back."

**Say**
"The people who benefit most are the people who investigate attacks. Right now they are fighting with one hand tied behind their back because the victim's own security blocks their tools. We give them a tool that keeps working inside a hostile environment. It also lets companies test their own defences honestly."

**The line that lands**
"Faster, safer investigations - and a stronger red team for everyone."

**Caution:** Do not promise "we will catch all hackers". Promise "a faster, more reliable path to evidence".

---

### SLIDE 6 — RESEARCH AND REFERENCES

**Show**
- LLVM Language Reference and Writing an LLVM Pass
- Microsoft docs on PE format; Linux ELF docs
- MITRE ATT&CK; "Evading EDR" (Matt Hand); "The Art of Memory Forensics"
- BYOVD research: Microsoft MSRC blog; LOLDrivers project
- Domain fronting: "Hiding in the Cloud" research
- Tools we used for testing: Ghidra, ClamAV, valgrind, MinGW-w64

**Say**
"Our work sits on well-known, public research. We read the same papers as the defenders, and we also wrote down how our own tool could be detected - because a good security project knows its own weaknesses."

**The line that lands**
"We know exactly how we would be caught, and we say it out loud."

---

## 4. FIVE WAYS TO PRESENT THE SAME PPT

Pick the style that fits the room. You can also mix them.

### STYLE 1 — THE DETECTIVE STORY (recommended for emotional impact)

**Idea:** The audience is the investigator. Walk them through a real case step by step.

**Opening line**
"Imagine a cyber-crime case. The suspect's server is sitting in front of you, still running. The evidence you need is inside it. You plug in your forensic tool - and the machine's own security refuses to let you work. That is the scene our problem statement starts with."

**Flow**
1. The case (ransomware / data theft). The clock is ticking.
2. The obstacle: antivirus and EDR block the investigator's tools because they recognise them.
3. The old fix (turn security off) is dangerous - it alerts the suspect and may destroy evidence.
4. Our idea: a forensic language whose tools never look the same twice.
5. Demo: show one source file, build it three times, show three different hashes; run it; show the JSON evidence.
6. Proof: the decompiler cannot follow the entry point; antivirus signatures do not match.
7. Close on the human result: the investigator gets the evidence without tipping off the criminal.

**Closing line**
"JOCKY does not break security. It lets the investigator work quietly, so the truth can be found safely."

**Best for:** non-technical judges, impact-focused panels, a room that likes a human story.

---

### STYLE 2 — THE STRAIGHT LINE (recommended for technical panels)

**Idea:** Problem -> root cause -> our solution -> evidence -> future. No drama, maximum clarity.

**Opening line**
"Our problem statement has three technical needs: a new language, automatic variation of every build, and forensic collection under monitoring. We built all three. Let me show you the pipeline and the proof."

**Flow**
1. Requirement 1: independent language / LLVM frontend -> show pipeline.
2. Requirement 2: polymorphism -> show the four levels and the hash table.
3. Requirement 3: forensic functions -> show the JSON output.
4. Requirement 4: cross-platform -> show Windows .exe from the same source.
5. Proof table (Ghidra + ClamAV + tests).
6. Honest limits and next steps (console, in-memory, BYOVD research).

**Closing line**
"Every requirement in the problem statement maps to a working part of the prototype."

**Best for:** technical judges, evaluation-heavy panels, short time slots.

---

### STYLE 3 — SHOW, DON'T TELL (recommended if the projector and laptop behave)

**Idea:** Run the demo in the first minute. Explain afterwards.

**Opening line**
"Before I explain anything, let me build the same program twice and look at the fingerprints."

**Flow**
1. Live: `jocky --seed 42 --obf-level 3 --build scripts/tour.rd`, run `shasum`.
2. Live: `jocky --seed 7 --obf-level 3 --build scripts/tour.rd`, run `shasum`. Two different hashes.
3. Live: run `strings` on the level-2 binary - nothing readable.
4. Live: run the forensics script - JSON process and socket list appears.
5. Now explain the compiler pipeline and the four levels.
6. Close with the proof tables and the honest roadmap.

**Closing line**
"You just saw the same program become a different, unrecognisable binary twice - and still do its job."

**Best for:** demo day, a technically curious audience, judges who value a working prototype.

**Backup:** if the live build fails, keep screenshots and the pre-built binaries ready. Never debug on stage - switch to the prepared video or screenshots immediately.

---

### STYLE 4 — THE EVERYDAY ANALOGY (recommended for mixed / non-tech panels)

**Idea:** Compare the whole thing to things everyone knows.

**Analogy set**
- The investigator's problem = "the police are stopped by the thief's own door lock."
- The antivirus signature = "a wanted poster with your face on it. Same face, always caught."
- Polymorphism = "the investigator changes appearance for every mission, but does the same job."
- LLVM = "the engine factory everyone trusts; we built our own car body on top of it."
- String encryption = "writing the instructions in a secret code."
- Opaque predicate = "a locked door that is actually always open, to waste the intruder's time."
- Trampoline = "the front door leads you to another door, and then another, before the real room."
- Domain fronting (roadmap) = "sending your letter in an ordinary, trusted courier envelope."

**Flow**
1. Tell the wanted-poster analogy.
2. Explain that we rebuild the "face" every time.
3. Show that the tool still collects evidence.
4. Mention the proof in one line.

**Closing line**
"Same mission, new face every time. That is JOCKY in one sentence."

**Best for:** non-cyber judges, business/policy panels, a mixed audience.

---

### STYLE 5 — THE INVESTIGATION / COURT CASE (recommended for law-enforcement flavoured panels)

**Idea:** Frame it as a legal investigation, not a hacking demo.

**Opening line**
"In a court case, evidence is only useful if it is collected legally and safely. Our problem is that modern security can block legal evidence collection. We solve the collection problem while keeping the rules."

**Flow**
1. The legal need: covert, authorized evidence collection.
2. The conflict: security blocks the collector.
3. Our approach: an authorized, fresh-per-build forensic instrument.
4. Chain of custody: how we keep the process auditable (collect, tag, send as JSON, keep logs).
5. The limits: only authorized use; we do not disable security; we do not alter the suspect's data without control.
6. Proof and roadmap.

**Closing line**
"We did not build a weapon. We built a legal, careful instrument for people who already have permission."

**Best for:** panels with a governance, policy, or law-enforcement angle.

---

### BONUS STYLE 6 — THE STARTUP PITCH (if the panel asks about business)

**Opening line**
"Every security company needs to test its own defences. Every CERT team needs tools that work in a hostile network. That is our market."

**Flow**
1. Who pays: enterprises, CERTs, red-team consultancies, defence and law enforcement.
2. What they buy: a language, a compiler, and a managed agent console.
3. Why now: attackers already use these ideas; defenders are behind.
4. Revenue: support contracts, training, enterprise console licence (compiler stays open source).
5. Roadmap: console, multi-agent, in-memory research module.

**Closing line**
"We sell the ability to see an attack that cannot be seen with normal tools."

---

## 5. READY-MADE SCRIPTS (JUST READ IF NERVOUS)

### 5.1 Three-minute script (fast, high level)
"Investigators are blocked by the victim's own security. That is problem 26148. We built a small forensic language and a real LLVM compiler. Every time it builds, the binary changes, but the behaviour stays the same, so signature-based security cannot recognise it. It runs on Windows, Linux and macOS from one source and collects processes, sockets and files as JSON. We proved it: a decompiler cannot follow our level-3 entry point, and in a ClamAV test the plain version was flagged while our protected version was clean. The next phase is a management console and, in lab research only, in-memory execution. Thank you."

### 5.2 Five-minute script (recommended default)
Use Section 3, but say only the "Say" lines for Slide 1, 2, 3, 5, 6 and add one line of proof for Slide 3. Show one diagram (the four levels) and one proof table.

### 5.3 Ten-minute script
Section 3 fully, plus:
- The Ghidra comparison numbers (demo: 10 blocks vs 70 blocks).
- The AV table (plain C flagged, level 2/3 clean, EICAR caveat).
- The honest roadmap from Section 1.3.
- One use case from Slide 5.

### 5.4 Fifteen-minute script
Everything above plus:
- Live demo or a 60-second screen recording.
- The ethics and legal section (Section 8).
- Three questions from the "tough" bank answered proactively so judges do not have to ask.
- Team roles and the division of work.

---

## 6. DEMO PLAYBOOK

### 6.1 Safe demo order (do not improvise)

```bash
# 1. Show the source is tiny and readable
cat prot2_llvm_full_ai_deepseek/scripts/tour.rd

# 2. Build twice with different seeds
./prot2_llvm_full_ai_deepseek/build/jocky --seed 42 --obf-level 3 \
  --build prot2_llvm_full_ai_deepseek/scripts/tour.rd
shasum prot2_llvm_full_ai_deepseek/scripts/tour

./prot2_llvm_full_ai_deepseek/build/jocky --seed 7 --obf-level 3 \
  --build prot2_llvm_full_ai_deepseek/scripts/tour.rd
shasum prot2_llvm_full_ai_deepseek/scripts/tour

# 3. Show no readable strings at level 2
strings prot2_llvm_full_ai_deepseek/scripts/tour | grep -c "hello"

# 4. Run the forensic collector
./prot2_llvm_full_ai_deepseek/build/jocky --build \
  prot2_llvm_full_ai_deepseek/scripts/forensics.rd
./prot2_llvm_full_ai_deepseek/scripts/forensics
```

### 6.2 What to say while it runs
"Watch the hash change between the two builds, even though the source is identical. Then notice that `strings` cannot find our text at level 2. Finally, the same tool quietly lists the processes and network sockets."

### 6.3 Backup plan (mandatory)
- Pre-build all binaries before the event and keep them in a folder.
- Keep PNG screenshots of every result.
- Keep a 60-90 second screen recording.
- If the laptop fails, present from the screenshots and the tables - never debug on stage.

### 6.4 Never do on stage
- Never run anything against a real network or a machine you do not own.
- Never use the words "malware", "attack", "steal", "hack a victim".
- Never claim you disabled a real antivirus. You did not. You evaded a signature test in your lab.

---

## 7. SIMPLE-LANGUAGE GLOSSARY (so nobody gets lost)

| Term | Simple meaning |
|---|---|
| Compiler | A program that turns human-written code into a program the computer can run |
| LLVM | A well-known, free engine used by many languages to generate fast machine code |
| Intermediate representation (IR) | A middle step inside a compiler, between source code and machine code |
| Antivirus / AV | Software that looks for known bad files |
| EDR | A stronger security tool that watches what programs do, not just their files |
| Signature | A known fingerprint (bytes or hash) that security tools search for |
| Hash | A short fingerprint of a file; change one byte, the hash changes completely |
| Polymorphism | The same program changing its appearance every build while behaving the same |
| Obfuscation | Making code harder for a stranger to read |
| Opaque predicate | A condition that is always true or always false, used to confuse analysis |
| Control-flow graph (CFG) | A map of how a program's code branches and loops |
| Trampoline | An extra jump in front of the real start, hiding the real entry point |
| Forensic | Related to collecting and preserving digital evidence |
| Living off the land | Using tools already on the machine instead of bringing new ones |
| In-memory execution | Running code without writing it to disk |
| BYOVD | Loading an already-signed but flawed driver to reach the kernel (research only here) |
| Domain fronting | Hiding the real destination behind a trusted cloud/CDN address |
| JSON | A simple, standard text format for data; easy for dashboards to read |
| Entropy | A measure of randomness; packed malware looks very random |
| Ghidra | A free reverse-engineering tool made by the NSA, used to decompile binaries |

---

## 8. ETHICS, LEGAL AND SAFETY (DO NOT SKIP THIS)

This problem statement is "dual-use": the same idea can help defenders and attackers. Judges will test your character. Have these answers ready.

### 8.1 The must-say paragraph
"This is a dual-use technology. The only difference between a forensic tool and malware is permission. We only build and test in our own lab, on machines we own, in virtual machines with snapshots. We do not disable real security products, we do not attack real systems, and we do not publish anything that could be used to harm someone. Our goal is to help the people who investigate crimes."

### 8.2 Ready answers

**Q: Is this not just creating malware?**
No. Malware is software that acts without permission. Our tool is designed for authorized investigations, in a lab, with the owner's consent. We even refuse to build the harmful parts (real EDR-disabling).

**Q: What is the difference from a hacking tool?**
Intent and permission. A locksmith's tools and a burglar's tools are similar; the locksmith is invited. We are the locksmith for digital crime scenes.

**Q: Does this violate Indian law (IT Act) or other laws?**
Only if used without authorization. Authorized security testing, incident response and research are legitimate. We will ship a clear licence, an authorization checklist, and audit logs. We do not deploy outside a lab.

**Q: Why should we trust you with this?**
Because we published our own weaknesses. Our report lists how our tool can be detected and where it fails. Honest self-criticism is the strongest proof of good intent.

**Q: What will you NOT build?**
- A real EDR-disabling driver.
- Anything that escalates privileges on a real system.
- A fully automatic attack chain.
- Code that destroys or alters evidence.

---

## 9. Q&A BANK

Answers are written in simple English. Start with the short answer, then add the "extra detail" only if the judge wants more.

---

### EASY QUESTIONS

**E1. What problem are you solving?**
Investigators' own forensic tools get blocked by the antivirus or EDR on the victim's machine. We built a tool that does not get blocked by simple signature checks.

**E2. What is JOCKY?**
It is our framework: a small programming language, a compiler, and a forensic library. The language is called "Read" and files end in `.rd`.

**E3. Why do you need a new programming language at all?**
Because existing tools are already known to antivirus. A new compiler lets us produce a fresh, unfamiliar result every time, which old signatures cannot match.

**E4. What is a compiler?**
A program that translates human-friendly code into a program the computer can run. We wrote one in C++.

**E5. What is antivirus and how does it catch things?**
It compares files against fingerprints (signatures) of known bad software, and it also watches behaviour. We focus on defeating the fingerprint part.

**E6. What is a hash?**
A fingerprint of a file. If one byte changes, the hash changes completely. We make every build produce a new hash.

**E7. What is polymorphism in your project?**
The same program changes its appearance on every build, but does exactly the same job.

**E8. Which operating systems does it support?**
Windows, Linux and macOS from a single source file.

**E9. Did you actually build it, or just design it?**
It is built and working. We can compile and run it right now.

**E10. Can I see a demo?**
Yes. Let me build the same program twice and show you the two different fingerprints.

**E11. What does the tool output?**
Clean JSON text: process list, network sockets, files, environment data. A dashboard can read it directly.

**E12. How long did you work on this?**
[Answer with your real timeline.] The compiler, the four obfuscation levels, the runtime and the tests are all done.

**E13. What is LLVM?**
A free, widely trusted engine that turns intermediate code into fast machine code. Many big languages use it.

**E14. Is this a finished product?**
The compiler and language are finished and tested. The management console and some advanced modules are next.

**E15. What happens if you use a different seed number?**
You get a different binary with a different hash. Same source, new fingerprint.

---

### MEDIUM QUESTIONS

**M1. How is your language different from Python or PowerShell?**
Python and PowerShell are known to security tools and are often blocked. Our language is unknown, small, and compiled to native code with a changing fingerprint. Also, our forensic functions are built in.

**M2. Why LLVM instead of just translating to C?**
Our first prototype translated to C. But renaming variables is erased by the optimiser, so the binary stays the same. LLVM lets us change things at the intermediate level that survive optimisation, like control flow and strings.

**M3. What exactly does "obfuscation level 2 and 3" do?**
Level 2 encrypts every string and adds fake functions, so no readable text remains. Level 3 also hides the real start of the program behind one to three extra jumps.

**M4. How does string encryption work?**
Each text string is mixed (XOR) with a random key before it goes into the binary. At runtime the program quietly decrypts it in memory before using it. So `strings` cannot find it.

**M5. What is an opaque predicate?**
A condition that is always true, like "a square of a number is never negative". We add it to create extra fake branches that survive the optimiser and confuse analysis.

**M6. What is a control-flow graph and why change it?**
It is the map of how code jumps and branches. Changing the map makes the decompiled output look completely different and breaks recognisable patterns.

**M7. How do you guarantee every build is unique?**
A random seed drives renaming, markers, predicates, keys and trampolines. Change the seed, change the binary. We showed 24 different hashes across our test programs.

**M8. Is the same build reproducible if I reuse the seed?**
The generated code is identical for the same seed. On Linux the binary is identical too. On macOS the linker adds a random ID, so the file hash differs. We documented this honestly.

**M9. How did you test that it evades antivirus?**
We used ClamAV with its full signature database plus our own custom signature rules that match our test markers. The plain C version was flagged; our level 2/3 versions were not.

**M10. Why ClamAV and not a commercial antivirus?**
ClamAV is free, reproducible and works in a container, and our custom rules imitate exactly how a commercial signature engine would match strings. We are honest that a commercial engine may have extra behavioural detection.

**M11. Did the antivirus catch anything at all?**
Yes, two things. Level 0 of our build was flagged just like plain C. And any string containing the "%" character is never encrypted, so it stays visible. We reported this bug ourselves.

**M12. How does the forensic library collect data?**
On Linux it reads `/proc`; on Windows it uses system APIs like Toolhelp32 and the TCP table; on macOS it uses library calls and `netstat`. All results become JSON.

**M13. What is the management console?**
A dashboard that receives the JSON from many agents and shows the evidence. The collectors already speak JSON; the dashboard itself is the next phase.

**M14. How do you build a Windows program on a Mac?**
Using cross-compilation: LLVM plus MinGW-w64 produce a real Windows `.exe` from the same source. We verified it is a valid PE32+ executable.

**M15. What stops someone using this for crime?**
The same thing that stops someone using a kitchen knife as a weapon: law, intent and controls. We add clear licensing, an authorization checklist, and we do not ship the dangerous parts.

**M16. Why is your tool small in features (no arrays)?**
That is deliberate. A small language is easier to protect and audit. We return JSON strings instead of complex types, which is exactly what a dashboard needs.

**M17. How do you know the obfuscation did not break the program?**
We have a test suite that runs every program at all four levels and compares the output. It is identical every time.

**M18. What is entropy and why does it matter?**
It measures randomness. Packed malware looks very random and is suspicious. Our binaries stay below about 3.1, so we look like normal compiled software, not a packer.

---

### TOUGH QUESTIONS

**T1. Your XOR encryption is easy to reverse. Is it really evasion?**
For signature scanning, yes: the plain text simply is not in the file, so the signature cannot match. But we admit a human with a decompiler can recover the key. We say this openly in our report. Our goal is to defeat automated signatures and reputation, not to be unbreakable.

**T2. Ghidra can still recover your state machine. Why claim success?**
Because our claim is specific: the entry point is not automatically resolvable, the strings are gone, and the code shape is heavily altered. Perfect secrecy is impossible. We measure the increase in analysis effort, not absolute invisibility.

**T3. If AV vendors add a signature for LLVM output, are you dead?**
No single signature covers all builds, because the marker values, keys, predicates and trampolines change every time. But we admit that if they detect our tool's general pattern, we must keep evolving. That is why continuous rebuilding is part of the design.

**T4. The forensic API calls like process listing are visible at every level. A behavioural EDR can still catch you. What do you say?**
Correct, and we say it in our report. Obfuscation defeats file and signature detection. Behavioural detection is beaten by in-memory execution and direct system calls, which are our next lab phase. We do not pretend one layer solves everything.

**T5. The EICAR test string survives at every level because of the "%" rule. Does that not break your "zero plaintext" claim?**
It is a real limitation. Strings containing "%" are skipped to protect formatting. We found it, reported it, and it is on our fix list. This is exactly the kind of honesty judges should expect.

**T6. Is this security, or security theatre?**
It is a real, measurable improvement against a specific threat: automatic signature and reputation detection. We measured it with a decompiler and an antivirus engine. We never claim it defeats every product.

**T7. Why should a real investigator trust a student-built tool?**
They should not trust blindly. That is why we publish our test method, our evidence and our failures. Trust should come from verification, not from our confidence.

**T8. How do you avoid alerting the attacker while collecting evidence?**
Several ways: the tool is exempted or trusted through authorization, we do not disable their security loudly, we minimise our footprint, and we keep collection quiet and targeted. But we are honest: a kernel-level attacker can see a lot.

**T9. What if the machine blocks driver loading (HVCI, WDAC)?**
Then BYOVD-style approaches fail, which is why we treat BYOVD as research and detection, not our selling point. Our main strength is the compiler and the language, which do not depend on driver loading.

**T10. Your language has no arrays or lists. How do you handle large data?**
We return JSON strings and let the console process them. This keeps the language small and safe. For very large data we would stream to the console instead of holding it in memory.

**T11. What about modern protections like Control Flow Guard, CET, ASLR?**
Our generated code is normal compiled code, so it works with these protections. Our obfuscation does not rely on disabling them.

**T12. How is this different from existing obfuscators like VMProtect or packers?**
Those hide an existing program after it is built. We change how the program is generated in the first place, inside the compiler, so there is no recognisable "packing" layer and entropy stays low.

**T13. How is this different from Cobalt Strike or other red-team frameworks?**
Those are command-and-control platforms. We are a language and compiler for evidence collection. The overlap is only in the delivery idea, not the purpose.

**T14. Are you not worried this helps attackers more than defenders?**
The techniques already exist publicly. Our contribution is a defensive, controlled, honest implementation with detection notes. Attackers do not need our permission to learn; defenders do need better tools.

**T15. What is your false-positive story? Who decides what is "evidence"?**
The tool collects data; humans decide meaning. We tag output with source, time and context so an analyst can judge. We do not claim automatic truth.

**T16. What is the cost to run this across a large company?**
The compiler is free and light. The cost is the console, storage and trained people. Because output is JSON, standard logging pipelines can be reused.

**T17. What is your biggest risk?**
Two: first, AV vendors adapting to our general pattern; second, legal misuse. We reduce the first by continuous mutation, and the second by strict authorized-use controls.

**T18. How do you ensure the encrypted strings do not crash the program?**
We decrypt all strings once at startup, before any use, and our test suite verifies identical output at every level.

---

### VERY VERY VERY HARD QUESTIONS

**H1. In a real APT investigation, the attacker may own the kernel. How can you guarantee your agent is not seen?**
We cannot guarantee it, and no honest tool can. If the attacker controls the kernel, every user-space tool is visible in principle. Our realistic goal is to raise the cost and reduce obvious signatures, and to operate in the grey zone where many attackers do not deploy full kernel monitoring. We document this limit clearly.

**H2. Prove formally that your opaque predicates survive modern optimisers across LLVM versions.**
We do not have a formal proof. Our evidence is empirical: we compile at O2 and inspect the result with Ghidra, and we see the injected branches and increased control-flow graph size. The reason they survive is the `volatile` load, which the optimiser is not allowed to treat as a constant. A formal model would be valuable future work.

**H3. Fuzzy hashing, import hashing and machine-learning classifiers can cluster your variants. How do you defeat those?**
Signature hashes are the easy target and we beat them. Fuzzy and ML detectors are a harder, active research problem. We already vary structure, strings and entry points, which hurts similarity hashing, but we admit a determined ML classifier could still group us. Our answer is continuous, larger mutation, not a single trick.

**H4. Your binaries have unusually large control-flow graphs and low entropy - could that "weirdness" itself be a detection signal?**
Yes, that is a real concern and it is why we deliberately avoid looking packed: entropy stays low and the file looks like normal compiler output. The trade-off is that heavy control-flow changes are visible to a sophisticated analyst. We discuss this balance in our report.

**H5. Domain fronting has been largely blocked by major cloud providers. What is your fallback?**
We treat domain fronting as one option, not the only one. Alternatives include legitimate cloud APIs, encrypted standard protocols, and domain hiding. Because the console is ours, we can also use mutual TLS to a private endpoint. The problem statement asks for trusted infrastructure routing, and we design for "trusted, replaceable channel", not one provider.

**H6. String keys are in the binary and plaintext exists in memory after decryption. How do you protect runtime plaintext?**
You cannot fully, once the program runs. We reduce exposure by decrypting late, using each string briefly, and keeping sensitive data in memory only. Real protection would need hardware support or secure enclaves, which we list as future work.

**H7. How would you build detection for JOCKY, as a blue team?**
We would watch for the forensic API pattern (process enumeration, socket tables), unusual control-flow shapes, and the specific decryptor pattern, and we would use behavioural rules rather than file signatures. We actually wrote detection notes like this, because a good security project knows both sides.

**H8. Is your threat model even valid? Forensics is usually done offline on a disk image with a write blocker. Why evade AV at all?**
That is a fair challenge. Offline forensics is the gold standard and we support it. But live incident response and covert investigation on a running hostile system are real, common situations where tools must run on the machine without alerting the adversary or being blocked. Our tool targets that specific, harder scenario.

**H9. What is the chain-of-custody and evidentiary risk if an obfuscated binary runs on a live system?**
Obfuscation does not change what we collect, but it can look suspicious in court if not documented. Our answer is full logging, hashed evidence, timestamps and a documented, authorized process. The tool must be explainable in court, and our report is the start of that documentation.

**H10. How do you prevent dual-use misuse, technically, not just legally?**
Ideas: signed and licensed builds tied to an organization, an authorization token required to run an agent, time-limited builds, and removing the dangerous modules from the public release. None of these is perfect; that is why law, audit and intent matter too.

**H11. What is the performance cost of full obfuscation across thousands of endpoints?**
File size grows only about 1.0 to 1.4 times, and the work is at build time, not run time, so runtime cost is low. The real scale cost is network and storage for the JSON evidence, which standard pipelines can handle.

**H12. Under ETW-TI and kernel callbacks, direct syscalls may not help. How do you respond?**
Kernel telemetry is very strong. Our honest position: we defeat file and signature detection with confidence, and we treat kernel-level evasion as an unsolved research area. We will keep publishing what works and what does not.

**H13. How do you avoid an arms race where you must rebuild faster than vendors can sign?**
That is exactly the design. Because the variation happens automatically inside the build, a CI/CD pipeline can produce a fresh artifact on every delivery, so the defender is always signing yesterday's build. This is the "continuous delivery as a polymorphic engine" idea from the problem statement.

**H14. What is your statistical evidence that evasion works? We tested one engine.**
We have mechanism-level evidence, not population-level statistics. One antivirus engine plus custom rules is a proof of concept, not a benchmark. A stronger study would test many engines, many builds and many behavioural sensors. We present our result as a demonstration, not a guarantee.

**H15. If I give you a real EDR, what would you change first in the prototype?**
We would first reduce our behavioural footprint: change how we call forensic APIs and add in-memory execution and direct system calls, then test against the EDR's telemetry. This is Phase 3 on our roadmap.

**H16. Why not use an existing language with an existing obfuscator?**
Because then the toolchain itself is a known quantity and the optimiser removes the variation. Owning the compiler lets us change the intermediate representation in ways no external obfuscator can, and it lets us build a purpose-made forensic library.

**H17. Your compiler is a front-end only. Is that a real compiler?**
Yes. It does lexing, parsing, type checking and generates LLVM IR, which is exactly what a compiler front-end does. LLVM handles the back-end. That is the same architecture used by Clang and Rust.

**H18. What would make you abandon this approach?**
If we found that vendors could reliably cluster our variants cheaply, or if the legal and ethical controls could not be enforced in practice. We would then pivot to detection research and defensive tooling.

**H19. What is the single most important thing you want the judges to remember?**
That we did not just talk about a hard problem - we built a working compiler, proved our claim with a decompiler and an antivirus, and were honest about every limitation.

**H20. What is the biggest unsolved problem in your own project?**
Closing the gap between defeating signatures and defeating behaviour. File-level evasion is solved; behavioural and kernel-level visibility is the frontier, and it is genuinely hard.

---

### SIH / JUDGING-CRITERIA QUESTIONS

**J1. What is novel here?**
The combination: our own language, our own compiler, IR-level polymorphism, and a forensic library - integrated into one system, with published evidence.

**J2. What is the social impact?**
Faster and safer investigation of cybercrime, which protects citizens and critical services.

**J3. What is the business model?**
Open-source compiler; paid support, training and an enterprise console for organizations.

**J4. How will you scale?**
The compiler is light and the output is JSON. Scaling is a standard distributed-systems problem: many agents, one console, normal storage.

**J5. What is your technology readiness level?**
The core language, compiler and forensic library are working and tested. The console and advanced evasion modules are prototype or roadmap. We would place it around early-to-mid prototype level, and we are honest about that.

**J6. What are the team roles?**
[Fill in your real roles: compiler, runtime, testing/evaluation, presentation, security research.]

**J7. How did you validate with real users?**
[Fill in any mentor, investigator or faculty feedback you have. If none yet, say the next step is a guided pilot.]

**J8. What is your plan for the next 6 months?**
1. Management console and multi-agent support. 2. In-memory execution lab module with detection notes. 3. Broader antivirus and behavioural testing. 4. Legal and authorization framework.

**J9. Why should you win?**
Because we built a real compiler, we proved our central claim with evidence, we know our limits, and our idea directly answers every part of problem statement 26148.

---

## 10. DELIVERY TIPS

- Open with the human problem, not the technology.
- Say "we built" and "we tested" more than "we plan to".
- Use one number to make a point: "the decompiler cannot follow the entry point" or "24 different fingerprints".
- When you do not know something, say: "That is a real limitation. Here is how we would test it." Never bluff.
- Keep the ethics paragraph ready. It wins trust.
- Do not read the slides. Slides carry proof; your voice carries the story.
- Pace: one idea per sentence. Pause after numbers.
- End on impact, not on features.

### Judging-criteria mapping (mention these naturally)
| Criterion | Your strongest point |
|---|---|
| Innovation | Own language + IR-level polymorphism, not a wrapper |
| Feasibility | Working prototype, mature LLVM base, low cost |
| Impact | Direct help to forensic and CERT teams |
| Technical depth | Real compiler, four obfuscation levels, Ghidra evidence |
| Scalability | One source, many targets, JSON output to a console |
| Presentation | Honest, evidence-based, clear limits |
| Ethics | Authorized-use-only design and self-reported weaknesses |

---

## 11. THINGS YOU MUST NOT CLAIM (RED FLAGS)

- Do not claim you disabled or killed a real antivirus or EDR.
- Do not claim your tool is undetectable. Say "harder to detect by signatures".
- Do not claim you tested against many commercial products when you tested one.
- Do not claim the management console, BYOVD or in-memory execution are finished.
- Do not claim zero plaintext, because strings with "%" survive.
- Do not claim reproducibility on all platforms; macOS differs.
- Do not call it a "virus", "weapon" or "malware".
- Do not run anything against a live network on stage.

---

## 12. ONE-PAGE CHEAT SHEET (PRINT THIS)

**Problem:** Investigator's tools get blocked by the victim's own security.

**Solution:** Our own tiny language "Read" + real LLVM compiler + built-in forensic library. Every build has a new fingerprint; behaviour stays identical.

**Pipeline:** source -> lexer -> parser -> type check -> LLVM IR -> link runtime -> obfuscate (4 levels) -> O2 -> object -> binary.

**Four levels:** 0 rename+markers; 1 + opaque predicates; 2 + string encryption + junk; 3 + entry trampoline.

**Proof:**
- 30 binaries decompiled with Ghidra.
- Level 3 entry point cannot be resolved.
- Level 2/3: zero readable strings.
- 24 unique hashes.
- ClamAV: plain C flagged, JOCKY level 2/3 clean (our custom rules).
- Same output at every level (test suite passes).

**Honest limits:** behavioural/kernel detection not solved; "%" strings unencrypted; macOS hash not reproducible; console and in-memory are roadmap.

**Ethics line:** "Dual-use. Permission is the only difference. Lab only, authorized only, never a real EDR-killer."

**Closing line:** "Same mission, new face every time - and we proved it."

---

*End of playbook. Update Section 1 whenever the prototype changes.*
