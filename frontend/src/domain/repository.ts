import type {
  AuditEvent,
  BuildArtifact,
  CollectionProfile,
  CollectionRun,
  EvidenceRecord,
  Finding,
  ForensicCase,
  Host,
} from "./types";

export interface CaseBundle {
  case: ForensicCase;
  hosts: Host[];
  findings: Finding[];
  evidence: EvidenceRecord[];
  audit: AuditEvent[];
}

export interface ForensicsRepository {
  getHosts(): Promise<Host[]>;
  getCase(caseId: string): Promise<ForensicCase>;
  getProfile(profileId: string): Promise<CollectionProfile>;
  getRun(caseId: string): Promise<CollectionRun>;
  getEvidence(caseId: string): Promise<EvidenceRecord[]>;
  getFindings(caseId: string): Promise<Finding[]>;
  getBuildArtifacts(): Promise<BuildArtifact[]>;
  getAudit(caseId: string): Promise<AuditEvent[]>;
  getCaseBundle(caseId: string): Promise<CaseBundle>;
  startCollection(caseId: string, profileId: string, hostIds: string[]): Promise<CollectionRun>;
  subscribeToRun(caseId: string, listener: (run: CollectionRun) => void): () => void;
  reset(): Promise<void>;
}
