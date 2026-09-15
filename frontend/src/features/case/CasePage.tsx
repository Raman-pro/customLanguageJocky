import { useEffect, useMemo, useState } from "react";
import { ArrowRight, Box, CheckCircle2, ChevronRight, Clock3, Download, FileCheck2, Laptop, Radio, Server, ShieldCheck } from "lucide-react";
import { Link } from "react-router-dom";
import { useDemo } from "../../app/DemoProvider";
import { ROUTES } from "../../app/routes";
import { Badge } from "../../components/Badge";
import { Button } from "../../components/Button";
import { EmptyState } from "../../components/EmptyState";
import { StageTimeline } from "../../components/StageTimeline";
import { ToastRegion } from "../../components/ToastRegion";
import type { CollectionProfile, Finding, ForensicCase, Host } from "../../domain/types";
import { FindingsRail } from "./FindingsRail";
import { StartCollection } from "./StartCollection";
import { downloadCaseBundle } from "../export/exportCase";

export function CasePage() {
  const { repository, activeRun, startCollection } = useDemo();
  const [caseData, setCaseData] = useState<ForensicCase | null>(null);
  const [hosts, setHosts] = useState<Host[]>([]);
  const [profile, setProfile] = useState<CollectionProfile | null>(null);
  const [findings, setFindings] = useState<Finding[]>([]);
  const [error, setError] = useState(false);
  const [exporting, setExporting] = useState(false);
  const [message, setMessage] = useState<string | null>(null);

  useEffect(() => {
    let current = true;
    Promise.all([
      repository.getCase("JKY-104"),
      repository.getHosts(),
      repository.getProfile("network-process-triage"),
      repository.getFindings("JKY-104"),
    ]).then(([nextCase, nextHosts, nextProfile, nextFindings]) => {
      if (!current) return;
      setCaseData(nextCase);
      setHosts(nextHosts);
      setProfile(nextProfile);
      setFindings(nextFindings);
    }).catch(() => current && setError(true));
    return () => { current = false; };
  }, [repository]);

  const running = useMemo(() => !["idle", "verified"].includes(activeRun.stage), [activeRun.stage]);
  const verified = activeRun.stage === "verified";

  async function exportCase() {
    setExporting(true);
    try {
      downloadCaseBundle(await repository.getCaseBundle("JKY-104"));
      setMessage("Case bundle exported.");
    } catch {
      setMessage("Case bundle could not be exported.");
    } finally {
      setExporting(false);
      window.setTimeout(() => setMessage(null), 2200);
    }
  }

  if (error) return <EmptyState title="Case data could not be loaded" description="Reset the prepared dataset to restore JKY-104." />;

  return (
    <div className="page case-page">
      <nav className="breadcrumb" aria-label="Breadcrumb">
        <Link to={ROUTES.fleet}>Fleet</Link><ChevronRight aria-hidden="true" size={13} /><span>JKY-104</span>
      </nav>

      <header className="case-heading entrance entrance--one">
        <div>
          <div className="case-heading__state"><span className="case-code">JKY-104</span><Badge tone="warning">Active investigation</Badge></div>
          <h1>{caseData?.title ?? "Loading investigation"}</h1>
          <p>{caseData?.summary}</p>
        </div>
        <div className="case-heading__actions">
          <Button disabled={exporting} onClick={exportCase}><Download aria-hidden="true" size={15} /> Export case JSON</Button>
          {profile ? <StartCollection hosts={hosts} profile={profile} running={running} verified={verified} onStart={() => startCollection(profile.id, hosts.map(host => host.id))} /> : null}
        </div>
      </header>

      <section className="case-facts entrance entrance--two" aria-label="Case details">
        <div><span>Owner</span><strong>{caseData?.owner ?? "—"}</strong></div>
        <div><span>Opened</span><strong className="mono-value">15 Sep · 09:30 UTC</strong></div>
        <div><span>Systems</span><strong className="mono-value">03 in scope</strong></div>
        <div><span>Evidence</span><strong className="mono-value">{verified ? "24 verified" : "Prepared"}</strong></div>
        <div><span>Policy</span><strong className="policy-value"><ShieldCheck size={14} /> Read-only</strong></div>
      </section>

      <div className="case-workspace entrance entrance--three">
        <div className="case-workspace__main">
          <section className="collection-panel" aria-labelledby="collection-progress">
            <div className="collection-panel__header">
              <div>
                <p className="page-context"><Radio size={13} /> Evidence collection</p>
                <h2 id="collection-progress">Collection progress</h2>
              </div>
              <div className="run-identity"><span>{activeRun.stage === "idle" ? "Ready to run" : activeRun.stage}</span><code>RUN-104-A</code></div>
            </div>
            <StageTimeline run={activeRun} />
            {verified ? (
              <div className="verified-result">
                <span className="verified-result__icon"><CheckCircle2 aria-hidden="true" size={22} /></span>
                <div><strong>24 evidence records received</strong><p>Manifest signatures and record hashes are verified.</p></div>
                <Link className="button button--primary" to={ROUTES.evidence}>Explore evidence <ArrowRight aria-hidden="true" size={16} /></Link>
              </div>
            ) : (
              <div className="ready-message"><Box aria-hidden="true" size={18} /><span><strong>Prepared workflow</strong>Start collection to gather and review evidence from the three selected systems.</span></div>
            )}
          </section>

          <section className="scope-panel" aria-labelledby="scope-heading">
            <div className="section-heading"><div><h2 id="scope-heading">System scope</h2><p>Host status updates as the simulated collection progresses.</p></div><span className="section-count">03 selected</span></div>
            <div className="scope-hosts">
              {hosts.map(host => {
                const Icon = host.platform === "windows-server-2022" ? Server : Laptop;
                return (
                  <div className="scope-host" key={host.id}>
                    <span className="scope-host__icon"><Icon aria-hidden="true" size={17} /></span>
                    <div><strong>{host.name}</strong><code>{host.address}</code></div>
                    <Badge tone={running ? "info" : host.state === "attention" ? "warning" : "success"}>{running ? "Collecting" : host.state === "attention" ? "Attention" : "Online"}</Badge>
                  </div>
                );
              })}
            </div>
          </section>

          <section className="case-notes" aria-label="Acquisition notes">
            <div><Clock3 size={17} /><span><strong>Fixed demo clock</strong>Timestamps stay the same each time you replay this demo.</span></div>
            <div><FileCheck2 size={17} /><span><strong>Simulated collection</strong>This demo uses prepared records from three sample systems.</span></div>
          </section>
        </div>
        <FindingsRail findings={findings} />
      </div>
      <ToastRegion message={message} />
    </div>
  );
}
