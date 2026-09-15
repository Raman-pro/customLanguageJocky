import { Check, Circle, LoaderCircle } from "lucide-react";
import type { CollectionRun, RunStage } from "../domain/types";

const stages: Array<{ stage: Exclude<RunStage, "idle">; label: string; detail: string }> = [
  { stage: "queued", label: "Queued", detail: "Scope accepted by three systems" },
  { stage: "prepared", label: "JOCKY artifact prepared", detail: "Target and read-only policy verified" },
  { stage: "collecting", label: "Collectors running", detail: "Processes, sockets and persistence" },
  { stage: "received", label: "Evidence received", detail: "Records normalized into JKY-104" },
  { stage: "verified", label: "Integrity verified", detail: "Manifest hashes complete" },
];

type StageState = "complete" | "active" | "pending";

function getStageState(index: number, currentIndex: number, runStage: RunStage): StageState {
  if (runStage === "verified" && index <= currentIndex) return "complete";
  if (index < currentIndex) return "complete";
  if (index === currentIndex) return "active";
  return "pending";
}

function StageMarker({ state }: { state: StageState }) {
  if (state === "complete") return <Check aria-hidden="true" size={14} />;
  if (state === "active") return <LoaderCircle aria-hidden="true" size={14} />;
  return <Circle aria-hidden="true" size={9} />;
}

export function StageTimeline({ run }: { run: CollectionRun }) {
  const currentIndex = stages.findIndex(item => item.stage === run.stage);
  const currentLabel = currentIndex < 0 ? "Collection is ready" : stages[currentIndex].label;

  return (
    <div className="stage-timeline">
      <div className="progress-track" aria-hidden="true"><span style={{ width: `${run.progress}%` }} /></div>
      <p className="sr-only" aria-live="polite">Current collection stage: {currentLabel}</p>
      <ol>
        {stages.map((item, index) => {
          const state = getStageState(index, currentIndex, run.stage);
          const status = { complete: "Complete", active: "In progress", pending: "Pending" }[state];
          return (
            <li key={item.stage} className={`is-${state}`}>
              <span className="stage-marker">
                <StageMarker state={state} />
              </span>
              <div><strong>{item.label}</strong><small>{item.detail}</small></div>
              <span className="stage-status">{status}</span>
            </li>
          );
        })}
      </ol>
    </div>
  );
}
