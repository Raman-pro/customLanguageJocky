import type {
  AuditEvent,
  CollectionProfile,
  CollectionRun,
  EvidenceCategory,
  EvidenceRecord,
  Finding,
  ForensicCase,
  Host,
} from "../domain/types";
import { rawEvidence } from "./rawEvidence";

export const hosts: Host[] = [
  {
    id: "FIN-WS-07",
    name: "FIN-WS-07",
    platform: "windows-11",
    address: "192.0.2.17",
    state: "attention",
    lastSeen: "2026-09-15T09:39:48.000Z",
    caseId: "JKY-104",
    findings: 2,
  },
  {
    id: "DC-WIN-01",
    name: "DC-WIN-01",
    platform: "windows-server-2022",
    address: "192.0.2.10",
    state: "online",
    lastSeen: "2026-09-15T09:39:52.000Z",
    caseId: "JKY-104",
    findings: 1,
  },
  {
    id: "ENG-UBU-02",
    name: "ENG-UBU-02",
    platform: "ubuntu-24.04",
    address: "203.0.113.24",
    state: "online",
    lastSeen: "2026-09-15T09:39:44.000Z",
    caseId: "JKY-104",
    findings: 1,
  },
];

export const activeCase: ForensicCase = {
  id: "JKY-104",
  title: "Suspected lateral movement",
  status: "active",
  summary: "Correlate an unusual PowerShell session with network and persistence evidence across three systems.",
  owner: "Priya Menon",
  openedAt: "2026-09-15T09:30:00.000Z",
  hostIds: hosts.map(host => host.id),
  tags: ["PowerShell", "Lateral movement", "Priority 1"],
};

export const triageProfile: CollectionProfile = {
  id: "network-process-triage",
  name: "Network + process triage",
  description: "Read-only process, socket, persistence, filesystem, and vulnerable-driver inventory.",
  collectorIds: ["sys.process_list", "net.sockets", "fs.list", "reg.list", "drv.audit"],
  categories: ["process", "network", "file", "persistence", "driver"],
  estimatedSeconds: 6,
};

const primaryEvidence: EvidenceRecord[] = [
  {
    id: "EV-001",
    caseId: activeCase.id,
    hostId: "FIN-WS-07",
    category: "network",
    severity: "high",
    observedAt: "2026-09-15T09:34:12.000Z",
    collector: "net.sockets",
    summary: "powershell.exe connected to 198.51.100.42:443",
    attributes: { pid: 6840, process: "powershell.exe", destination: "198.51.100.42:443", state: "ESTABLISHED" },
    raw: rawEvidence.unusualConnection,
    sha256: "a1d8bdb486a86b8c0d5a7c548c5152b3166449a61b0473b6d04a8e6abf86d102",
  },
  {
    id: "EV-002",
    caseId: activeCase.id,
    hostId: "FIN-WS-07",
    category: "process",
    severity: "high",
    observedAt: "2026-09-15T09:34:10.000Z",
    collector: "sys.process_list",
    summary: "PowerShell launched a script from ProgramData",
    attributes: { pid: 6840, parentPid: 4312, user: "CORP\\r.singh", signed: true },
    raw: rawEvidence.powershellProcess,
    sha256: "bf2c6bf4937402eaa43a5e163a83eb97f40d41b13aef7b0f335c5f4472f23631",
  },
  {
    id: "EV-003",
    caseId: activeCase.id,
    hostId: "DC-WIN-01",
    category: "driver",
    severity: "high",
    observedAt: "2026-09-15T09:35:16.000Z",
    collector: "drv.audit",
    summary: "Known vulnerable signed driver exposure detected",
    attributes: { driver: "dbutil_2_3.sys", signature: "Valid", disposition: "Review and remediate" },
    raw: rawEvidence.driverExposure,
    sha256: "c6426662a5de116a0d2d147356647aa8483a4097035b32ee12ef8da525187369",
  },
  {
    id: "EV-004",
    caseId: activeCase.id,
    hostId: "FIN-WS-07",
    category: "persistence",
    severity: "medium",
    observedAt: "2026-09-15T09:35:48.000Z",
    collector: "reg.list",
    summary: "Recently-created scheduled task runs as SYSTEM",
    attributes: { task: "UpdaterTelemetry", principal: "SYSTEM", ageMinutes: 37 },
    raw: rawEvidence.scheduledTask,
    sha256: "d55d1281cf4668426940cc53d67e4237452ebff84d5cc27cd74107b5d868e43c",
  },
  {
    id: "EV-005",
    caseId: activeCase.id,
    hostId: "ENG-UBU-02",
    category: "network",
    severity: "informational",
    observedAt: "2026-09-15T09:36:22.000Z",
    collector: "net.sockets",
    summary: "Unexpected Python listener exposed on port 8443",
    attributes: { pid: 2218, process: "python3", listener: "0.0.0.0:8443", user: "deploy" },
    raw: rawEvidence.ubuntuListener,
    sha256: "e7a028701c259d462f598a69cc5ff2f356645b64b1ad14cf9f12bc0677290aa7",
  },
  {
    id: "EV-006",
    caseId: activeCase.id,
    hostId: "FIN-WS-07",
    category: "file",
    severity: "medium",
    observedAt: "2026-09-15T09:36:41.000Z",
    collector: "fs.list",
    summary: "New diagnostic archive found in shared application data",
    attributes: { path: "C:\\ProgramData\\cache\\diag-0915.zip", sizeBytes: 1842304, owner: "CORP\\r.singh" },
    raw: rawEvidence.stagedArchive,
    sha256: "f0ab6a8c91c76eef397699f9c12c2bb287fcd531cb9f032e281f8cfc340ae58a",
  },
];

const routineCategories: EvidenceCategory[] = ["process", "network", "file", "persistence", "driver"];
const routineHosts = ["FIN-WS-07", "DC-WIN-01", "ENG-UBU-02"];
const routineCollectors: Record<EvidenceCategory, string> = {
  process: "sys.process_list",
  network: "net.sockets",
  file: "fs.list",
  persistence: "reg.list",
  driver: "drv.audit",
};
const routineEvidence: EvidenceRecord[] = Array.from({ length: 18 }, (_, index) => {
  const number = index + 7;
  const category = routineCategories[index % routineCategories.length];
  const hostId = routineHosts[index % routineHosts.length];
  return {
    id: `EV-${String(number).padStart(3, "0")}`,
    caseId: activeCase.id,
    hostId,
    category,
    severity: "informational",
    observedAt: `2026-09-15T09:${String(36 + Math.floor(index / 6)).padStart(2, "0")}:${String(10 + index).padStart(2, "0")}.000Z`,
    collector: routineCollectors[category],
    summary: `Baseline ${category} record verified on ${hostId}`,
    attributes: { baseline: true, sequence: number },
    raw: { baseline: true, sequence: number, host: hostId, category },
    sha256: number.toString(16).padStart(64, "0"),
  };
});

export const evidence: EvidenceRecord[] = [...primaryEvidence, ...routineEvidence];

export const findings: Finding[] = [
  {
    id: "F-001",
    caseId: activeCase.id,
    title: "PowerShell process reached an unusual external endpoint",
    severity: "high",
    status: "open",
    rationale: "Process and socket records align within two seconds on the finance workstation.",
    evidenceIds: ["EV-001", "EV-002"],
    technique: "T1059.001 · PowerShell",
  },
  {
    id: "F-002",
    caseId: activeCase.id,
    title: "Known vulnerable signed driver is present",
    severity: "high",
    status: "open",
    rationale: "The driver matches the defensive exposure catalog and should be remediated through approved controls.",
    evidenceIds: ["EV-003"],
    technique: "Driver exposure audit",
  },
  {
    id: "F-003",
    caseId: activeCase.id,
    title: "Scheduled task was created shortly before the alert",
    severity: "medium",
    status: "open",
    rationale: "The task runs as SYSTEM and was created 37 minutes before acquisition.",
    evidenceIds: ["EV-004"],
    technique: "T1053.005 · Scheduled Task",
  },
  {
    id: "F-004",
    caseId: activeCase.id,
    title: "Engineering host exposes an untracked listener",
    severity: "informational",
    status: "reviewed",
    rationale: "The listener is reachable on all interfaces and is not in the prepared service inventory.",
    evidenceIds: ["EV-005"],
  },
];

export const initialAudit: AuditEvent[] = [
  {
    id: "AUD-001",
    caseId: activeCase.id,
    actor: "Priya Menon",
    action: "Case opened",
    object: activeCase.id,
    at: "2026-09-15T09:30:00.000Z",
    outcome: "success",
  },
  {
    id: "AUD-002",
    caseId: activeCase.id,
    actor: "JOCKY policy",
    action: "Collection scope approved",
    object: triageProfile.id,
    at: "2026-09-15T09:30:18.000Z",
    outcome: "informational",
  },
];

export const initialRun: CollectionRun = {
  id: "RUN-104-A",
  caseId: activeCase.id,
  profileId: triageProfile.id,
  hostIds: activeCase.hostIds,
  stage: "idle",
  progress: 0,
  startedAt: null,
  events: [],
};
