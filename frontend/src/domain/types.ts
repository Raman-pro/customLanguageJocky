export type HostPlatform = "windows-11" | "windows-server-2022" | "ubuntu-24.04";
export type HostState = "online" | "collecting" | "attention";
export type Severity = "critical" | "high" | "medium" | "informational";
export type EvidenceCategory = "process" | "network" | "file" | "persistence" | "driver";
export type RunStage = "idle" | "queued" | "prepared" | "collecting" | "received" | "verified";

export interface Host {
  id: string;
  name: string;
  platform: HostPlatform;
  address: string;
  state: HostState;
  lastSeen: string;
  caseId: string;
  findings: number;
}

export interface ForensicCase {
  id: string;
  title: string;
  status: "active" | "contained";
  summary: string;
  owner: string;
  openedAt: string;
  hostIds: string[];
  tags: string[];
}

export interface CollectionProfile {
  id: string;
  name: string;
  description: string;
  collectorIds: string[];
  categories: EvidenceCategory[];
  estimatedSeconds: number;
}

export interface StageEvent {
  stage: Exclude<RunStage, "idle">;
  label: string;
  at: string;
  status: "pending" | "active" | "complete" | "skipped";
  detail: string;
}

export interface CollectionRun {
  id: string;
  caseId: string;
  profileId: string;
  hostIds: string[];
  stage: RunStage;
  progress: number;
  startedAt: string | null;
  events: StageEvent[];
}

export interface EvidenceRecord {
  id: string;
  caseId: string;
  hostId: string;
  category: EvidenceCategory;
  severity: Severity;
  observedAt: string;
  collector: string;
  summary: string;
  attributes: Record<string, string | number | boolean>;
  raw: Record<string, unknown>;
  sha256: string;
}

export interface Finding {
  id: string;
  caseId: string;
  title: string;
  severity: Severity;
  status: "open" | "reviewed";
  rationale: string;
  evidenceIds: string[];
  technique?: string;
}

export interface BuildArtifact {
  id: string;
  target: "windows-x86_64" | "linux-x86_64";
  seed: number;
  level: 0 | 3;
  sha256: string;
  sizeBytes: number;
  entropy: number;
  exportedFunctions: number;
}

export interface AuditEvent {
  id: string;
  caseId: string;
  actor: string;
  action: string;
  object: string;
  at: string;
  outcome: "success" | "informational";
}
