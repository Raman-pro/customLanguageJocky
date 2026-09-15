import { afterEach, beforeEach, expect, it, vi } from "vitest";
import { MockForensicsRepository } from "./MockForensicsRepository";

beforeEach(() => vi.useFakeTimers());
afterEach(() => vi.useRealTimers());

it("progresses a collection through the presentation stages", async () => {
  const repository = new MockForensicsRepository();
  const stages: string[] = [];
  repository.subscribeToRun("JKY-104", run => stages.push(run.stage));

  await repository.startCollection(
    "JKY-104",
    "network-process-triage",
    ["FIN-WS-07", "DC-WIN-01", "ENG-UBU-02"],
  );
  await vi.advanceTimersByTimeAsync(6500);

  expect(stages).toEqual(["queued", "prepared", "collecting", "received", "verified"]);
  expect((await repository.getRun("JKY-104")).progress).toBe(100);
  expect((await repository.getAudit("JKY-104")).at(-1)?.action).toBe("Integrity verified");
});

it("reset restores the idle run and initial audit trail", async () => {
  const repository = new MockForensicsRepository();
  await repository.startCollection("JKY-104", "network-process-triage", ["FIN-WS-07"]);
  await repository.reset();

  expect((await repository.getRun("JKY-104")).stage).toBe("idle");
  expect(await repository.getAudit("JKY-104")).toHaveLength(2);
});
