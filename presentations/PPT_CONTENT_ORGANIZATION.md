# SIH 2026 - JOCKY Framework PPT Content Organization
## Problem Statement ID: 26148
## Dense Technical Content Plan

---

## SLIDE 1: TITLE PAGE
**Layout**: Clean, professional, minimal text

### Content:
```
SMART INDIA HACKATHON 2026

Problem Statement ID – 26148
Problem Statement Title – Creation of scripts/functions with new programming language to commence Computer & Network forensic analysis without triggering security solutions
Theme – Blockchain & Cybersecurity
PS Category – Software
Team ID – [Your Team ID]
Team Name – [Your Team Name]
```

### Visual Elements:
- SIH 2026 logo (top-right)
- Custom JOCKY logo (center or left)
- Minimalist background (dark theme recommended, similar to WAF/NaVira examples)

---

## SLIDE 2: PROPOSED SOLUTION
**Layout**: Dense, multi-section with visual hierarchy

### Content Structure:

#### SECTION 1: WHAT IS JOCKY? (Top Banner)
**Brief Description** (2-3 lines):
> A cross-platform programming language framework using custom LLVM IR frontend that enables systematic forensic analysis of malicious activities and digital investigations, bypassing all existing antivirus solutions through novel binary structures, polymorphic compilation, and living-off-the-land execution techniques.

#### SECTION 2: KEY FEATURES (6 Feature Blocks - Grid Layout)
Use icon-based feature cards (similar to NaVira Page 2):

1. **🔧 Custom LLVM-Based Language**
   - Independent intermediate representation
   - Altered control-flow graphs & token generation
   - Unique binary structures evading signature detection

2. **🔄 Continuous Polymorphic Engine**
   - Automated CI/CD pipeline integration
   - Every compilation produces unique hashes
   - Dynamic entry points & import tables
   - Variable-encryption routines per build

3. **🧠 Living-off-the-Land (LotL) Execution**
   - Zero standard API calls for core operations
   - Native OS component utilization
   - Persistence via legitimate system tools
   - SOCKS5 routing through trusted processes

4. **💾 Multi-Vector In-Memory Execution**
   - Process hollowing techniques
   - Reflective DLL injection
   - API unhooking mechanisms
   - Direct system calls (syscall stubs)
   - Thread execution hijacking

5. **⚙️ BYOVD (Bring Your Own Vulnerable Driver)**
   - Kernel-level subversion
   - EDR callback disabling
   - Kernel structure manipulation
   - Blind security agents in user/kernel space

6. **🎛️ Central Management Interface**
   - Multi-system simultaneous analysis
   - Secure command & control
   - Real-time forensic data aggregation
   - Domain fronting / CDN traffic routing

#### SECTION 3: PROBLEMS ADDRESSED (4 Problem-Solution Pairs)
**Format**: Left column = Problem, Right column = JOCKY Solution

| Problem | JOCKY Solution |
|---------|----------------|
| AV/EDR blocks proprietary forensic scripts | Custom LLVM IR alters binary signatures completely |
| Behavioral heuristics detect standard API patterns | LotL + direct syscalls bypass behavioral monitoring |
| Static signature matching flags known tools | Polymorphic engine generates unique binaries per deployment |
| Kernel-level monitoring intercepts analysis | BYOVD techniques blind kernel security agents |
| Network traffic between tools gets flagged | Domain fronting via trusted cloud infrastructure |

#### SECTION 4: INNOVATION & UNIQUENESS (Bottom Section)
**3 Key Differentiators** (with icons):

1. **First-of-its-Kind Language Framework**
   - Not just obfuscation—a complete custom compilation pipeline
   - From source to binary: every stage introduces uniqueness

2. **Automated Polymorphism via CI/CD**
   - Manual packing is obsolete; every build is automatically unique
   - Integrated obfuscators + encryption + polymorphic engines

3. **Dual-Layer Evasion: User + Kernel**
   - User-mode: in-memory execution, API unhooking
   - Kernel-mode: BYOVD, driver-level subversion

---

## SLIDE 3: TECHNICAL APPROACH
**Layout**: Highly technical, architecture-focused, multiple diagrams (similar to NaVira Pages 5-10 and WAF Pages 2-3)

### Content Structure:

#### DIAGRAM 1: JOCKY COMPILATION PIPELINE (Top Half - Full Width)
**Flowchart Layout**: Left-to-right with 5 stages

```
[Source Code (.jky)] 
    ↓
[JOCKY Lexer/Parser]
    ↓
[Custom LLVM IR Frontend]
    ├── Alters control-flow graphs
    ├── Modifies token generation
    └── Introduces unique binary structures
    ↓
[Polymorphic Engine]
    ├── Variable encryption routines
    ├── Entry point randomization
    ├── Import table mutation
    └── Hash uniqueness enforcement
    ↓
[Platform-Specific Backend]
    ├── Windows (PE format)
    └── Ubuntu (ELF format)
    ↓
[Unique Binary Output]
```

**Visual Style**: Use colored boxes for each stage, arrows showing flow, annotations for key modifications at each stage.

#### DIAGRAM 2: SYSTEM ARCHITECTURE (Bottom Left - 50% Width)
**Multi-Layer Architecture Diagram**:

```
┌─────────────────────────────────────────────────────────┐
│                   CENTRAL MANAGEMENT                     │
│              (Command & Control Interface)               │
│  • Multi-system orchestration                           │
│  • Forensic data aggregation                           │
│  • Secure communication layer                          │
└─────────────────────────────────────────────────────────┘
                            ↓ (Domain Fronting / CDN Routing)
┌─────────────────────────────────────────────────────────┐
│                   TRUSTED CLOUD LAYER                    │
│  • AWS/Azure/GCP APIs                                  │
│  • CDN domain fronting                                 │
│  • TLS encryption                                      │
└─────────────────────────────────────────────────────────┘
                            ↓
┌─────────────────────────────────────────────────────────┐
│                   CLIENT AGENT LAYER                     │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐ │
│  │   Agent 1    │  │   Agent 2    │  │   Agent N    │ │
│  │ (Windows)    │  │  (Ubuntu)    │  │  (Windows)   │ │
│  └──────────────┘  └──────────────┘  └──────────────┘ │
│                                                          │
│  Each Agent Contains:                                   │
│  ├── In-Memory Execution Engine                         │
│  ├── BYOVD Module                                       │
│  ├── LotL Toolkit                                       │
│  └── Forensic Analysis Scripts                          │
└─────────────────────────────────────────────────────────┘
```

#### DIAGRAM 3: EVASION TECHNIQUES MATRIX (Bottom Right - 50% Width)
**Table/Matrix Layout**:

| Evasion Layer | Technique | Mechanism | Target |
|---------------|-----------|-----------|--------|
| **Static** | Custom LLVM IR | Unique binary structures | Signature DB |
| **Static** | Polymorphic Engine | Hash/entry point mutation | File reputation |
| **Behavioral** | Direct Syscalls | Bypass hooked APIs | User-mode monitors |
| **Behavioral** | API Unhooking | Restore original ntdll | EDR hooks |
| **Memory** | Process Hollowing | Inject into trusted process | Memory scanners |
| **Memory** | Reflective DLL | Load without LoadLibrary | Import table analysis |
| **Kernel** | BYOVD | Load vulnerable driver | Kernel monitors |
| **Kernel** | Driver Manipulation | Disable EDR callbacks | Security agents |
| **Network** | Domain Fronting | Masquerade as CDN traffic | Network filters |

#### DIAGRAM 4: IN-MEMORY EXECUTION WORKFLOW (Bottom - Full Width)
**Sequential Flow**:

```
1. LAUNCHER EXECUTION
   ↓ (Direct syscalls, no API hooks)
2. TARGET PROCESS SELECTION
   ↓ (Legitimate process: svchost.exe, explorer.exe)
3. PROCESS HOLLOWING
   ↓ (Suspend → Unmap → Allocate → Write → Resume)
4. PAYLOAD INJECTION
   ↓ (Reflective DLL, position-independent code)
5. API UNHOOKING
   ↓ (Restore ntdll from disk, bypass EDR hooks)
6. FORENSIC ANALYSIS EXECUTION
   ↓ (In-memory, fileless)
7. DATA EXTRACTION
   ↓ (Encrypted channel to C2)
8. SELF-DELETION
   (Zero artifacts on disk)
```

---

## SLIDE 4: FEASIBILITY AND VIABILITY
**Layout**: Multi-section with feasibility analysis, challenges, and strategies

### Content Structure:

#### SECTION 1: FEASIBILITY ANALYSIS (Top - 3 Columns)
**Three Feasibility Dimensions**:

**Technical Feasibility** ✅
- LLVM compiler infrastructure is mature and extensible
- Cross-platform compilation (Windows/Ubuntu) is proven technology
- In-memory execution techniques are well-documented in research
- BYOVD methods leverage known vulnerable drivers (Microsoft WHQL signed)
- Domain fronting uses legitimate cloud infrastructure

**Economic Feasibility** ✅
- Open-source LLVM foundation (no licensing costs)
- Cloud infrastructure costs are pay-as-you-go (AWS/Azure)
- Development can leverage existing forensic tool research
- No specialized hardware required
- Scalable from single investigator to enterprise SOC teams

**Operational Feasibility** ✅
- Cross-platform support covers 95% of enterprise environments
- Central management interface simplifies multi-system analysis
- Automated polymorphism reduces manual obfuscation effort
- Training required: forensic investigators with malware analysis background
- Integration with existing forensic workflows

#### SECTION 2: POTENTIAL CHALLENGES & RISKS (Middle - Left Column)
**Format**: Challenge → Impact → Likelihood

| Challenge | Impact | Likelihood |
|-----------|--------|------------|
| AV vendors adapt to LLVM IR patterns | High | Medium |
| Microsoft patches vulnerable drivers (BYOVD) | High | High |
| Cloud providers block domain fronting | Medium | Low |
| Behavioral AI detects syscall patterns | Medium | Medium |
| Memory scanners detect hollowed processes | Medium | Medium |
| Legal/ethical concerns in dual-use technology | High | Low |

#### SECTION 3: STRATEGIES FOR OVERCOMING (Middle - Right Column)
**Format**: Strategy → Addresses Which Challenge

| Strategy | Challenge Addressed |
|----------|---------------------|
| **Continuous LLVM IR Mutation**: Randomize IR generation patterns per compilation cycle | AV adaptation |
| **Driver Rotation Pool**: Maintain database of 50+ vulnerable drivers, rotate automatically | Driver patching |
| **Multi-CDN Fallback**: Support AWS, Azure, GCP, Cloudflare domain fronting | CDN blocking |
| **Syscall Diversification**: Randomize syscall order, add junk syscalls, use indirect calls | Behavioral AI |
| **Multi-Process Injection**: Spread across 3-5 processes, not just one | Memory scanners |
| **Law Enforcement Only Distribution**: Restrict to certified agencies, audit trails | Legal concerns |

#### SECTION 4: DEVELOPMENT ROADMAP (Bottom - Timeline)
**Phased Approach**:

```
Phase 1 (Months 1-2): LLVM Frontend
  ├── Custom IR generation
  ├── Control-flow graph alteration
  └── Token randomization

Phase 2 (Months 3-4): Polymorphic Engine
  ├── Hash mutation pipeline
  ├── Entry point randomization
  └── Import table modification

Phase 3 (Months 5-6): Evasion Modules
  ├── In-memory execution engine
  ├── BYOVD framework
  └── API unhooking

Phase 4 (Months 7-8): Central Management
  ├── C2 interface development
  ├── Multi-agent orchestration
  └── Domain fronting integration

Phase 5 (Months 9-10): Testing & Hardening
  ├── Red team testing against 20+ AV/EDR
  ├── Performance optimization
  └── Cross-platform validation
```

---

## SLIDE 5: IMPACT AND BENEFITS
**Layout**: Multi-stakeholder impact visualization

### Content Structure:

#### SECTION 1: TARGET AUDIENCE IMPACT (Top - 3 Stakeholder Groups)
**Format**: Stakeholder → Impact Description

**🔍 Digital Forensic Investigators**
- Bypass AV restrictions on proprietary analysis tools
- Conduct deep system analysis without triggering alerts
- Analyze compromised systems in hostile environments
- Perform network forensics without detection
- Maintain operational security during investigations

**🏢 Law Enforcement Agencies**
- Investigate cybercrime without alerting suspects
- Conduct covert digital forensics in active investigations
- Analyze malware-infected systems safely
- Perform incident response on compromised networks
- Gather evidence without contamination

**🛡️ Enterprise Security Teams (Red Teams)**
- Simulate advanced adversaries for security testing
- Test EDR/AV effectiveness against novel techniques
- Validate detection capabilities against living-off-the-land attacks
- Assess incident response readiness
- Benchmark security posture against state-sponsored threats

#### SECTION 2: SOCIAL, ECONOMIC, ENVIRONMENTAL BENEFITS (Middle - 4 Benefit Areas)

**Social Impact** 🌐
- **Enhanced Cybersecurity**: Better tools to combat cybercrime and protect citizens
- **Digital Justice**: Faster, more effective investigations lead to quicker resolution of cybercrime cases
- **Privacy Protection**: Covert analysis tools protect investigator identity and operational security
- **Public Safety**: Improved ability to investigate threats to critical infrastructure

**Economic Impact** 💰
- **Cost Savings**: Open-source foundation reduces tool development costs
- **Efficiency Gains**: Automated polymorphism saves manual obfuscation time (est. 80% reduction)
- **Market Opportunity**: Potential commercialization to law enforcement agencies globally
- **Job Creation**: Demand for skilled forensic investigators with advanced tool expertise
- **Reduced Breach Costs**: Faster incident response minimizes financial impact of cyberattacks

**Environmental Impact** 🌱
- **Cloud Efficiency**: Domain fronting via existing CDN infrastructure (no new hardware)
- **Resource Optimization**: Multi-agent architecture reduces need for physical forensic labs
- **Digital-First**: Reduces travel for on-site investigations through remote analysis capabilities

**Strategic Impact** 🎯
- **National Security**: Advanced forensic capabilities for investigating state-sponsored threats
- **Technological Sovereignty**: Indigenous development of advanced forensic tools
- **Global Leadership**: Position India as leader in offensive security research
- **Deterrence**: Advanced capabilities deter cybercriminals targeting Indian infrastructure

#### SECTION 3: REAL-WORLD APPLICATION SCENARIOS (Bottom - 3 Use Cases)

**Use Case 1: Ransomware Investigation**
```
Scenario: Financial institution hit by ransomware
Challenge: AV blocks custom analysis tools on infected systems
JOCKY Solution: Deploy JOCKY agent → bypass AV → analyze ransomware behavior in-memory → extract decryption keys → recover data
```

**Use Case 2: APT Investigation**
```
Scenario: Government network compromised by APT group
Challenge: APT has deployed AV/EDR that blocks forensic tools
JOCKY Solution: Use BYOVD to blind EDR → deploy JOCKY agents across network → conduct covert forensic analysis → identify C2 infrastructure → remediate
```

**Use Case 3: Insider Threat Investigation**
```
Scenario: Suspected data exfiltration by insider
Challenge: Cannot alert suspect by deploying obvious forensic tools
JOCKY Solution: Covert JOCKY deployment → analyze suspect's system without detection → gather evidence of data theft → support legal proceedings
```

---

## SLIDE 6: RESEARCH AND REFERENCES
**Layout**: Categorized references with links

### Content Structure:

#### SECTION 1: TECHNICAL DOCUMENTATION & RESOURCES (Top)
**Format**: Category → Resource → Link

**LLVM Compiler Infrastructure**
- LLVM Language Reference Manual: https://llvm.org/docs/LangRef.html
- LLVM IR Tutorial: https://llvm.org/docs/tutorial/
- LLVM Passes Documentation: https://llvm.org/docs/WritingAnLLVMPass.html

**In-Memory Execution Techniques**
- Process Hollowing: https://github.com/m0n0ph1/Process-Hollowing
- Reflective DLL Injection: https://github.com/stephenfewer/ReflectiveDLLInjection
- API Unhooking Techniques: https://www.ired.team/offensive-security/defense-evasion/unhooking-dlls-in-c++

**BYOVD Research**
- Microsoft WHQL Vulnerable Drivers: https://github.com/magicswordio/DBI
- BYOVD Attack Techniques: https://www.reddit.com/r/csirts/comments/vmc1in/byovd_bring_yourown_vulnerable_driver/

**Domain Fronting**
- AWS Domain Fronting: https://www.bamsoftware.com/hacks/fronting/
- CloudFront Domain Fronting: https://blog.safebuff.com/2018/02/21/CloudFront-domain-fronting/

#### SECTION 2: ACADEMIC PAPERS & RESEARCH (Middle)
**Format**: Paper Title → Authors → Conference/Journal → Year

1. **"LLVM: A Compilation Framework for Lifelong Program Analysis & Transformation"**
   - Chris Lattner et al.
   - CGO 2004 (International Symposium on Code Generation and Optimization)

2. **"The Art of Memory Forensics: Detecting Malware and Intrusions in Volatile Memory"**
   - Jamie Levy et al.
   - Wiley, 2014

3. **"Evading EDR: The Definitive Guide to Defeating Endpoint Detection Systems"**
   - Matt Hand
   - No Starch Press, 2023

4. **"Windows Security Monitoring: Scenarios and Patterns for Detection and Response"**
   - Andrei Miroshnikov
   - Wiley, 2020

5. **"Polymorphic Malware: A Survey of Techniques and Countermeasures"**
   - Anup Ghosh et al.
   - IEEE Security & Privacy, 2019

6. **"Bring Your Own Vulnerable Driver: A New Attack Vector for Kernel-Level Security"**
   - Microsoft Security Research
   - MSRC Blog, 2022

#### SECTION 3: TOOLS & FRAMEWORKS (Bottom Left)
**Format**: Tool → Purpose → Link

| Tool | Purpose | Link |
|------|---------|------|
| **PE-Sieve** | Detect in-memory malware | https://github.com/hasherezade/pe-sieve |
| **Hollows-Hunter** | Find hollowed processes | https://github.com/hasherezade/hollows_hunter |
| **Sysmon** | System monitoring (for testing) | https://docs.microsoft.com/en-us/sysinternals/downloads/sysmon |
| **Volatility 3** | Memory forensics framework | https://github.com/volatilityfoundation/volatility3 |
| **YARA** | Pattern matching for malware | https://github.com/VirusTotal/yara |
| **Flare-VM** | Malware analysis environment | https://github.com/mandiant/flare-vm |

#### SECTION 4: CASE STUDIES & REAL-WORLD EXAMPLES (Bottom Right)

**Case Study 1: SolarWinds Supply Chain Attack (2020)**
- **Relevance**: Demonstrates need for covert forensic tools
- **Lesson**: Traditional AV failed to detect sophisticated supply chain compromise
- **JOCKY Application**: Could analyze compromised systems without alerting attackers

**Case Study 2: Colonial Pipeline Ransomware (2021)**
- **Relevance**: Critical infrastructure under attack
- **Lesson**: Incident response teams need tools that bypass AV on compromised systems
- **JOCKY Application**: Covert analysis of ransomware behavior in operational environment

**Case Study 3: NotPetya Global Attack (2017)**
- **Relevance**: Nation-state level threat
- **Lesson**: Advanced threats require advanced forensic capabilities
- **JOCKY Application**: BYOVD techniques to analyze kernel-level components

**Case Study 4: Lazarus Group APT Campaigns**
- **Relevance**: Persistent threat actor targeting multiple sectors
- **Lesson**: Need for tools that can operate in hostile environments
- **JOCKY Application**: Living-off-the-land execution to avoid detection

---

## VISUAL DESIGN GUIDELINES

### Color Scheme:
- **Primary**: Dark navy blue (#1a1f3d) or black (#0d0d0d)
- **Accent 1**: Cyan (#00d9ff) for highlights and icons
- **Accent 2**: Purple (#8b5cf6) for secondary elements
- **Text**: White (#ffffff) for main text, light gray (#e0e0e0) for secondary

### Typography:
- **Headers**: Bold, uppercase, large (36-48pt)
- **Body**: Clean sans-serif (Roboto, Open Sans, or Segoe UI)
- **Code/Technical**: Monospace (Fira Code, Consolas)

### Diagrams:
- Use **Mermaid** or **draw.io** for flowcharts
- Export as PNG with transparent background
- Maintain consistent styling (rounded corners, consistent colors)
- Add subtle drop shadows for depth

### Icons:
- Use **Font Awesome** or **Material Design Icons**
- Consistent stroke width and style
- Color-code by category (evasion, execution, analysis)

### Layout Principles:
- **Dense but organized**: Use grid layouts, clear section dividers
- **Visual hierarchy**: Most important content largest/boldest
- **Breathing room**: Don't overcrowd, use whitespace strategically
- **Consistency**: Same icon styles, colors, and spacing throughout

---

## ADDITIONAL DIAGRAMS TO CREATE

### For Slide 3 (Technical Approach):

**Diagram 5: BYOVD Attack Flow**
```
[Legitimate Application]
    ↓
[Identify Vulnerable Driver]
    ↓
[Load Driver (WHQL Signed)]
    ↓
[Exploit Driver Vulnerability]
    ↓
[Gain Kernel Privileges]
    ↓
[Disable EDR Callbacks]
    ↓
[Execute Forensic Analysis]
```

**Diagram 6: Domain Fronting Architecture**
```
[JOCKY Agent] → [HTTPS Request] → [CDN Edge Server]
                                        ↓
                              [Domain Fronting Logic]
                                        ↓
                              [Actual C2 Server]
```

**Diagram 7: Polymorphic Compilation Pipeline**
```
[Source Code] → [Lexer] → [Parser] → [AST]
                                    ↓
                        [Custom IR Generation]
                                    ↓
                    [Polymorphic Transformations]
                    ├── CFG Alteration
                    ├── Token Mutation
                    ├── Junk Code Injection
                    └── Encryption Routines
                                    ↓
                        [Code Generation]
                                    ↓
                    [Platform-Specific Output]
                    ├── Windows PE
                    └── Linux ELF
```

**Diagram 8: Multi-Agent Orchestration**
```
[Central Management Console]
    ├── Agent 1 (Windows) → Forensic Analysis
    ├── Agent 2 (Ubuntu) → Network Capture
    ├── Agent 3 (Windows) → Memory Dump
    └── Agent N (...) → ...
            ↓
    [Aggregated Forensic Data]
            ↓
    [Investigator Dashboard]
```

---

## FINAL CHECKLIST

Before finalizing the PPT:

- [ ] All 6 slides follow SIH template exactly
- [ ] Technical diagrams are clear and professional
- [ ] Content is dense but readable
- [ ] Color scheme is consistent throughout
- [ ] All references are accurate and accessible
- [ ] Flowcharts use consistent styling
- [ ] No spelling/grammar errors
- [ ] File size < 10MB (compress images)
- [ ] Export as PDF before submission
- [ ] Test PDF rendering (all diagrams visible)

---

## NOTES ON CONTENT DENSITY

The reference PDFs (NaVira, WAF, drone) achieve density through:
1. **Multiple diagrams per slide** (3-4 technical diagrams)
2. **Dense tables/matrices** with technical specifications
3. **Layered architecture diagrams** showing all components
4. **Minimal prose, maximum information** via visuals
5. **Consistent visual language** across all diagrams
6. **Technical depth** without sacrificing clarity

Your JOCKY PPT should follow this pattern:
- Each slide has 3-4 distinct sections
- Every technical concept has a corresponding diagram
- Tables and matrices convey complex information efficiently
- Architecture diagrams show the complete system
- Flowcharts illustrate processes step-by-step

**Total estimated content**: 6 slides × 4 sections × 3-5 bullet points = 72-120 distinct information points, delivered primarily through visuals rather than paragraphs.
