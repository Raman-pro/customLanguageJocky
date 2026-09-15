import { ExternalLink, FileCheck2, Hash, Server, X } from "lucide-react";
import { useEffect, useRef } from "react";
import type { EvidenceRecord, Finding, Host } from "../domain/types";
import { Badge } from "./Badge";
import { CodePanel } from "./CodePanel";

const tones = { critical: "danger", high: "danger", medium: "warning", informational: "info" } as const;

interface EvidenceInspectorProps {
  evidence: EvidenceRecord | null;
  host: Host | null;
  finding: Finding | null;
  onClose(): void;
}

export function EvidenceInspector({ evidence, host, finding, onClose }: EvidenceInspectorProps) {
  const closeRef = useRef<HTMLButtonElement>(null);

  useEffect(() => {
    if (evidence) closeRef.current?.focus();
  }, [evidence]);

  if (!evidence) return null;

  const observed = new Intl.DateTimeFormat("en-GB", { dateStyle: "medium", timeStyle: "medium", timeZone: "UTC" }).format(new Date(evidence.observedAt));

  return (
    <div className="evidence-scrim" onMouseDown={event => event.target === event.currentTarget && onClose()}>
      <aside className="evidence-inspector" role="dialog" aria-modal="true" aria-label="Evidence record" onKeyDown={event => event.key === "Escape" && onClose()}>
        <header className="evidence-inspector__header">
          <div><span>Evidence record</span><strong>{evidence.id}</strong></div>
          <button ref={closeRef} type="button" onClick={onClose} aria-label="Close evidence"><X aria-hidden="true" size={19} /></button>
        </header>

        <div className="evidence-inspector__body">
          <div className="mock-stamp"><span>Mock evidence for presentation</span><small>No live endpoint data</small></div>
          <div className="evidence-classification"><Badge tone={tones[evidence.severity]}>{evidence.severity}</Badge><span>{evidence.category}</span></div>
          <h2>{evidence.summary}</h2>
          <p className="evidence-interpretation">{finding?.rationale ?? "This normalized record is retained as supporting context for the current investigation."}</p>

          <dl className="provenance-list">
            <div><dt><Server size={14} /> Source host</dt><dd>{host?.name ?? evidence.hostId}<small>{host?.address}</small></dd></div>
            <div><dt><ExternalLink size={14} /> Collector</dt><dd><code>{evidence.collector}</code></dd></div>
            <div><dt><FileCheck2 size={14} /> Observed</dt><dd><time>{observed} UTC</time></dd></div>
            <div className="provenance-hash"><dt><Hash size={14} /> SHA-256</dt><dd><code>{evidence.sha256}</code><small>Integrity verified</small></dd></div>
          </dl>

          <section className="attribute-section" aria-labelledby="attributes-heading">
            <h3 id="attributes-heading">Normalized attributes</h3>
            <dl className="attribute-grid">
              {Object.entries(evidence.attributes).map(([key, value]) => <div key={key}><dt>{key.replaceAll(/([A-Z_])/g, " $1").trim()}</dt><dd>{String(value)}</dd></div>)}
            </dl>
          </section>

          <CodePanel value={evidence.raw} />
        </div>
      </aside>
    </div>
  );
}
