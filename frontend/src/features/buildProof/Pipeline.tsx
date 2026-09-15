import { Binary, Braces, Boxes, CheckCircle2, FileCode2 } from "lucide-react";

const stages = [
  { id: "source", label: "JOCKY source", detail: "forensics.rd", icon: FileCode2 },
  { id: "frontend", label: "Lexer + parser", detail: "Typed AST", icon: Braces },
  { id: "sema", label: "Semantic analysis", detail: "Collector policy checked", icon: CheckCircle2 },
  { id: "llvm", label: "LLVM IR", detail: "Target lowering", icon: Boxes },
  { id: "artifact", label: "Collector artifact", detail: "Measured output", icon: Binary },
] as const;

export function Pipeline() {
  return (
    <ol className="compiler-pipeline" aria-label="JOCKY compiler pipeline">
      {stages.map((stage, index) => {
        const Icon = stage.icon;
        return (
          <li key={stage.id}>
            <span className="pipeline-number">{String(index + 1).padStart(2, "0")}</span>
            <span className="pipeline-icon"><Icon aria-hidden="true" size={18} /></span>
            <div><strong>{stage.label}</strong><small>{stage.detail}</small></div>
          </li>
        );
      })}
    </ol>
  );
}
