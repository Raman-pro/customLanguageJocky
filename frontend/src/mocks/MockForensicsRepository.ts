import type { CaseBundle, ForensicsRepository } from "../domain/repository";
import type {
  AuditEvent,
  BuildArtifact,
  CollectionProfile,
  CollectionRun,
  EvidenceRecord,
  Finding,
  ForensicCase,
  Host,
  RunStage,
  StageEvent,
} from "../domain/types";
import { buildArtifacts } from "./buildProof";
import { activeCase, evidence, findings, hosts, initialAudit, initialRun, triageProfile } from "./fixtures";

const clone = <T,>(value: T): T => structuredClone(value);

const stageDefinitions: Array<{
  stage: Exclude<RunStage, "idle">;
  progress: number;
  delay: number;
  label: string;
  detail: string;
  at: string;
}> = [
  { stage: "queued", progress: 8, delay: 0, label: "Queued", detail: "Three systems accepted the collection scope.", at: "2026-09-15T09:40:00.000Z" },
  { stage: "prepared", progress: 28, delay: 1200, label: "JOCKY artifact prepared", detail: "Read-only collector policy and target were verified.", at: "2026-09-15T09:40:01.200Z" },
  { stage: "collecting", progress: 58, delay: 2800, label: "Collectors running", detail: "Process, socket, file, persistence, and driver inventories are active.", at: "2026-09-15T09:40:02.800Z" },
  { stage: "received", progress: 84, delay: 4400, label: "Evidence received", detail: "Twenty-four normalized records reached the local case workspace.", at: "2026-09-15T09:40:04.400Z" },
  { stage: "verified", progress: 100, delay: 6000, label: "Integrity verified", detail: "Evidence hashes and acquisition manifest are complete.", at: "2026-09-15T09:40:06.000Z" },
];

function eventsAt(stage: Exclude<RunStage, "idle">): StageEvent[] {
  const currentIndex = stageDefinitions.findIndex(item => item.stage === stage);
  return stageDefinitions.map((item, index) => ({
    stage: item.stage,
    label: item.label,
    at: item.at,
    detail: item.detail,
    status: getEventStatus(index, currentIndex, stage),
  }));
}

function getEventStatus(
  index: number,
  currentIndex: number,
  stage: Exclude<RunStage, "idle">,
): StageEvent["status"] {
  if (index < currentIndex || stage === "verified") return "complete";
  if (index === currentIndex) return "active";
  return "pending";
}

export class MockForensicsRepository implements ForensicsRepository {
  private currentHosts = clone(hosts);
  private currentRun = clone(initialRun);
  private currentAudit = clone(initialAudit);
  private readonly listeners = new Set<(run: CollectionRun) => void>();
  private timers: Array<ReturnType<typeof setTimeout>> = [];

  async getHosts(): Promise<Host[]> { return clone(this.currentHosts); }

  async getCase(caseId: string): Promise<ForensicCase> {
    if (caseId !== activeCase.id) throw new Error(`Case ${caseId} was not found`);
    return clone(activeCase);
  }

  async getProfile(profileId: string): Promise<CollectionProfile> {
    if (profileId !== triageProfile.id) throw new Error(`Profile ${profileId} was not found`);
    return clone(triageProfile);
  }

  async getRun(caseId: string): Promise<CollectionRun> {
    if (caseId !== activeCase.id) throw new Error(`Run for ${caseId} was not found`);
    return clone(this.currentRun);
  }

  async getEvidence(caseId: string): Promise<EvidenceRecord[]> {
    return clone(evidence.filter(record => record.caseId === caseId));
  }

  async getFindings(caseId: string): Promise<Finding[]> {
    return clone(findings.filter(finding => finding.caseId === caseId));
  }

  async getBuildArtifacts(): Promise<BuildArtifact[]> { return clone(buildArtifacts); }

  async getAudit(caseId: string): Promise<AuditEvent[]> {
    return clone(this.currentAudit.filter(event => event.caseId === caseId));
  }

  async getCaseBundle(caseId: string): Promise<CaseBundle> {
    return {
      case: await this.getCase(caseId),
      hosts: (await this.getHosts()).filter(host => host.caseId === caseId),
      findings: await this.getFindings(caseId),
      evidence: await this.getEvidence(caseId),
      audit: await this.getAudit(caseId),
    };
  }

  async startCollection(caseId: string, profileId: string, hostIds: string[]): Promise<CollectionRun> {
    await this.getCase(caseId);
    await this.getProfile(profileId);
    this.clearTimers();
    this.currentHosts = this.currentHosts.map(host => hostIds.includes(host.id) ? { ...host, state: "collecting" } : host);

    stageDefinitions.forEach(definition => {
      const transition = () => this.transition(definition, caseId, profileId, hostIds);
      if (definition.delay === 0) transition();
      else this.timers.push(setTimeout(transition, definition.delay));
    });

    return clone(this.currentRun);
  }

  subscribeToRun(caseId: string, listener: (run: CollectionRun) => void): () => void {
    if (caseId !== activeCase.id) return () => undefined;
    this.listeners.add(listener);
    return () => this.listeners.delete(listener);
  }

  async reset(): Promise<void> {
    this.clearTimers();
    this.currentHosts = clone(hosts);
    this.currentRun = clone(initialRun);
    this.currentAudit = clone(initialAudit);
    this.emit();
  }

  private transition(
    definition: (typeof stageDefinitions)[number],
    caseId: string,
    profileId: string,
    hostIds: string[],
  ) {
    this.currentRun = {
      id: initialRun.id,
      caseId,
      profileId,
      hostIds: [...hostIds],
      stage: definition.stage,
      progress: definition.progress,
      startedAt: stageDefinitions[0].at,
      events: eventsAt(definition.stage),
    };

    if (definition.stage === "verified") {
      this.currentHosts = this.currentHosts.map(host => {
        if (!hostIds.includes(host.id)) return host;
        return { ...host, state: host.id === "FIN-WS-07" ? "attention" : "online" };
      });
      if (!this.currentAudit.some(event => event.id === "AUD-003")) {
        this.currentAudit.push({
          id: "AUD-003",
          caseId,
          actor: "JOCKY verifier",
          action: "Integrity verified",
          object: initialRun.id,
          at: definition.at,
          outcome: "success",
        });
      }
    }
    this.emit();
  }

  private emit() {
    const snapshot = clone(this.currentRun);
    this.listeners.forEach(listener => listener(snapshot));
  }

  private clearTimers() {
    this.timers.forEach(timer => clearTimeout(timer));
    this.timers = [];
  }
}
