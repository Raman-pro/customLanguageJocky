import type { CaseBundle } from "../../domain/repository";

export function serializeCaseBundle(
  bundle: CaseBundle,
  exportedAt = new Date().toISOString(),
): string {
  return JSON.stringify({
    schema: "jocky.case-bundle/v1",
    demoData: true,
    exportedAt,
    case: bundle.case,
    hosts: bundle.hosts,
    findings: bundle.findings,
    evidence: bundle.evidence,
    audit: bundle.audit,
  }, null, 2);
}

export function downloadCaseBundle(bundle: CaseBundle): void {
  const blob = new Blob([serializeCaseBundle(bundle)], { type: "application/json" });
  const url = URL.createObjectURL(blob);
  const anchor = document.createElement("a");
  anchor.href = url;
  anchor.download = `${bundle.case.id}-case-bundle.json`;
  document.body.append(anchor);
  anchor.click();
  anchor.remove();
  URL.revokeObjectURL(url);
}
