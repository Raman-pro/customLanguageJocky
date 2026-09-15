import { CheckCircle2, ChevronRight } from "lucide-react";
import type { EvidenceRecord, Host, Severity } from "../../domain/types";
import { Badge } from "../../components/Badge";

const tones: Record<Severity, "danger" | "warning" | "info"> = { critical: "danger", high: "danger", medium: "warning", informational: "info" };

function shortTime(iso: string) {
  return new Intl.DateTimeFormat("en-GB", { hour: "2-digit", minute: "2-digit", second: "2-digit", timeZone: "UTC" }).format(new Date(iso));
}

export function EvidenceTable({ records, hosts, onSelect }: { records: EvidenceRecord[]; hosts: Host[]; onSelect(record: EvidenceRecord): void }) {
  const hostName = (id: string) => hosts.find(host => host.id === id)?.name ?? id;
  return (
    <div className="data-table-wrap evidence-table-wrap">
      <table className="data-table evidence-table">
        <caption className="sr-only">Evidence records for JKY-104</caption>
        <thead><tr><th>Severity</th><th>Summary</th><th>Host</th><th>Collector</th><th>Observed</th><th>Integrity</th><th><span className="sr-only">Open</span></th></tr></thead>
        <tbody>
          {records.map(record => (
            <tr key={record.id}>
              <td data-label="Severity"><Badge tone={tones[record.severity]}>{record.severity}</Badge></td>
              <td data-label="Summary"><button type="button" className="evidence-row-action" onClick={() => onSelect(record)}>{record.summary}<span className="sr-only"> on {hostName(record.hostId)}</span></button></td>
              <td data-label="Host"><code>{hostName(record.hostId)}</code></td>
              <td data-label="Collector"><code>{record.collector}</code></td>
              <td data-label="Observed"><span className="mono-muted">{shortTime(record.observedAt)}</span></td>
              <td data-label="Integrity"><span className="integrity-state"><CheckCircle2 aria-hidden="true" size={14} /> Verified</span></td>
              <td className="row-chevron"><ChevronRight aria-hidden="true" size={15} /></td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}
