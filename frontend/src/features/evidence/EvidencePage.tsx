import { useEffect, useMemo, useState, type KeyboardEvent } from "react";
import { ChevronRight, Database, Filter, Search, ShieldCheck } from "lucide-react";
import { Link, useSearchParams } from "react-router-dom";
import { useDemo } from "../../app/DemoProvider";
import { ROUTES } from "../../app/routes";
import { Button } from "../../components/Button";
import { EmptyState } from "../../components/EmptyState";
import { EvidenceInspector } from "../../components/EvidenceInspector";
import type { EvidenceCategory, EvidenceRecord, Finding, Host, Severity } from "../../domain/types";
import { EvidenceTable } from "./EvidenceTable";

type CategoryFilter = "all" | EvidenceCategory;
type SeverityFilter = "all" | Severity;

const categoryTabs: Array<{ id: CategoryFilter; label: string }> = [
  { id: "all", label: "All evidence" },
  { id: "process", label: "Processes" },
  { id: "network", label: "Network" },
  { id: "file", label: "Files" },
  { id: "persistence", label: "Persistence" },
  { id: "driver", label: "Drivers" },
];

export function EvidencePage() {
  const { repository } = useDemo();
  const [searchParams] = useSearchParams();
  const [records, setRecords] = useState<EvidenceRecord[]>([]);
  const [hosts, setHosts] = useState<Host[]>([]);
  const [findings, setFindings] = useState<Finding[]>([]);
  const [category, setCategory] = useState<CategoryFilter>("all");
  const [severity, setSeverity] = useState<SeverityFilter>("all");
  const [query, setQuery] = useState("");
  const [selected, setSelected] = useState<EvidenceRecord | null>(null);
  const [error, setError] = useState(false);

  useEffect(() => {
    let current = true;
    Promise.all([repository.getEvidence("JKY-104"), repository.getHosts(), repository.getFindings("JKY-104")])
      .then(([nextRecords, nextHosts, nextFindings]) => {
        if (!current) return;
        setRecords(nextRecords);
        setHosts(nextHosts);
        setFindings(nextFindings);
        const findingId = searchParams.get("finding");
        const targetFinding = nextFindings.find(item => item.id === findingId);
        const targetRecord = nextRecords.find(item => item.id === targetFinding?.evidenceIds[0]);
        if (targetRecord) setSelected(targetRecord);
      })
      .catch(() => current && setError(true));
    return () => { current = false; };
  }, [repository, searchParams]);

  const filtered = useMemo(() => records.filter(record => {
    if (category !== "all" && record.category !== category) return false;
    if (severity !== "all" && record.severity !== severity) return false;
    if (!query.trim()) return true;
    const host = hosts.find(item => item.id === record.hostId)?.name ?? record.hostId;
    const haystack = [record.summary, host, record.collector, record.sha256, JSON.stringify(record.attributes)].join(" ").toLowerCase();
    return haystack.includes(query.trim().toLowerCase());
  }), [records, hosts, category, severity, query]);

  const selectedFinding = selected ? findings.find(finding => finding.evidenceIds.includes(selected.id)) ?? null : null;
  const selectedHost = selected ? hosts.find(host => host.id === selected.hostId) ?? null : null;

  function handleTabKey(event: KeyboardEvent<HTMLDivElement>) {
    if (!['ArrowLeft', 'ArrowRight'].includes(event.key)) return;
    event.preventDefault();
    const index = categoryTabs.findIndex(tab => tab.id === category);
    const offset = event.key === "ArrowRight" ? 1 : -1;
    const next = categoryTabs[(index + offset + categoryTabs.length) % categoryTabs.length];
    setCategory(next.id);
    document.getElementById(`evidence-tab-${next.id}`)?.focus();
  }

  if (error) return <EmptyState title="Evidence could not be loaded" description="Reset the prepared dataset to restore the case manifest." />;

  return (
    <div className="page evidence-page">
      <nav className="breadcrumb" aria-label="Breadcrumb"><Link to={ROUTES.fleet}>Fleet</Link><ChevronRight size={13} /><Link to={ROUTES.case}>JKY-104</Link><ChevronRight size={13} /><span>Evidence</span></nav>
      <header className="evidence-heading entrance entrance--one">
        <div><p className="page-context"><Database size={14} /> Case JKY-104 / Evidence library</p><h1>Evidence explorer</h1><p>Search the case records and inspect where each piece of evidence came from.</p></div>
        <div className="manifest-proof"><span><ShieldCheck size={18} /></span><div><strong>Manifest verified</strong><code>24 / 24 records</code></div></div>
      </header>

      <section className="evidence-workspace entrance entrance--two" aria-labelledby="evidence-records-heading">
        <div className="evidence-toolbar">
          <div className="search-field"><Search aria-hidden="true" size={16} /><input type="search" aria-label="Search evidence" placeholder="Search host, address, process or hash" value={query} onChange={event => setQuery(event.target.value)} /></div>
          <label className="severity-filter"><Filter aria-hidden="true" size={15} /><span className="sr-only">Severity</span><select aria-label="Filter by severity" value={severity} onChange={event => setSeverity(event.target.value as SeverityFilter)}><option value="all">All severities</option><option value="high">High</option><option value="medium">Medium</option><option value="informational">Informational</option></select></label>
          <span className="record-count"><strong>{filtered.length.toString().padStart(2, "0")}</strong> records</span>
        </div>

        <div className="evidence-tabs" role="tablist" aria-label="Evidence category" onKeyDown={handleTabKey}>
          {categoryTabs.map(tab => <button key={tab.id} id={`evidence-tab-${tab.id}`} type="button" role="tab" aria-label={tab.label} aria-selected={category === tab.id} aria-controls="evidence-results" tabIndex={category === tab.id ? 0 : -1} onClick={() => setCategory(tab.id)}>{tab.label}<span aria-hidden="true">{tab.id === "all" ? records.length : records.filter(record => record.category === tab.id).length}</span></button>)}
        </div>

        <div id="evidence-results" role="tabpanel" aria-labelledby={`evidence-tab-${category}`}>
          <h2 id="evidence-records-heading" className="sr-only">Evidence records</h2>
          {filtered.length ? <EvidenceTable records={filtered} hosts={hosts} onSelect={setSelected} /> : <EmptyState title="No evidence matches these filters" description="Clear the search and severity filters to restore the case records." action={<Button onClick={() => { setQuery(""); setSeverity("all"); setCategory("all"); }}>Clear filters</Button>} />}
        </div>
      </section>

      <EvidenceInspector evidence={selected} host={selectedHost} finding={selectedFinding} onClose={() => setSelected(null)} />
    </div>
  );
}
