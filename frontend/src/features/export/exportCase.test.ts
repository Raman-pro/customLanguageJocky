import { expect, it } from "vitest";
import type { CaseBundle } from "../../domain/repository";
import { activeCase, evidence, findings, hosts, initialAudit } from "../../mocks/fixtures";
import { serializeCaseBundle } from "./exportCase";

const caseBundleFixture: CaseBundle = {
  case: activeCase,
  hosts,
  findings,
  evidence,
  audit: initialAudit,
};

it("serializes a stable case manifest with provenance", () => {
  const json = serializeCaseBundle(caseBundleFixture, "2026-09-15T09:40:00.000Z");
  const manifest = JSON.parse(json);

  expect(manifest.schema).toBe("jocky.case-bundle/v1");
  expect(manifest.demoData).toBe(true);
  expect(manifest.case.id).toBe("JKY-104");
  expect(manifest.hosts).toHaveLength(3);
  expect(manifest.evidence[0].sha256).toMatch(/^[a-f0-9]{64}$/);
  expect(manifest.exportedAt).toBe("2026-09-15T09:40:00.000Z");
});
