import { ArrowUpRight, ShieldAlert } from "lucide-react";
import { Link } from "react-router-dom";
import type { Finding } from "../../domain/types";
import { Badge } from "../../components/Badge";
import { ROUTES } from "../../app/routes";

const severityOrder = { critical: 0, high: 1, medium: 2, informational: 3 };
const tone = { critical: "danger", high: "danger", medium: "warning", informational: "info" } as const;

export function FindingsRail({ findings }: { findings: Finding[] }) {
  const ordered = [...findings].sort((a, b) => severityOrder[a.severity] - severityOrder[b.severity]).slice(0, 4);
  return (
    <aside className="findings-rail" aria-labelledby="priority-findings">
      <div className="findings-rail__heading">
        <div><p className="page-context"><ShieldAlert size={13} /> Prepared analysis</p><h2 id="priority-findings">Priority findings</h2></div>
        <span>{ordered.length.toString().padStart(2, "0")}</span>
      </div>
      <div className="finding-cards">
        {ordered.map((finding, index) => (
          <Link key={finding.id} className="finding-card" to={`${ROUTES.evidence}?finding=${finding.id}`}>
            <div className="finding-card__top"><span>{String(index + 1).padStart(2, "0")}</span><Badge tone={tone[finding.severity]}>{finding.severity}</Badge></div>
            <strong>{finding.title}</strong>
            <p>{finding.rationale}</p>
            <span className="finding-card__action">Inspect evidence <ArrowUpRight aria-hidden="true" size={14} /></span>
          </Link>
        ))}
      </div>
    </aside>
  );
}
