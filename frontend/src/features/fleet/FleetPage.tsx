import { useEffect, useState } from "react";
import { ArrowUpRight, CheckCircle2, Clock3, FileCheck2, Radar, RotateCcw, ShieldAlert } from "lucide-react";
import { Link } from "react-router-dom";
import { useDemo } from "../../app/DemoProvider";
import { ROUTES } from "../../app/routes";
import { Badge } from "../../components/Badge";
import { Button } from "../../components/Button";
import { EmptyState } from "../../components/EmptyState";
import type { ForensicCase, Host } from "../../domain/types";
import { HostTable } from "./HostTable";

export function FleetPage() {
  const { repository } = useDemo();
  const [hosts, setHosts] = useState<Host[]>([]);
  const [activeCase, setActiveCase] = useState<ForensicCase | null>(null);
  const [error, setError] = useState(false);

  useEffect(() => {
    let current = true;
    Promise.all([repository.getHosts(), repository.getCase("JKY-104")])
      .then(([nextHosts, nextCase]) => {
        if (!current) return;
        setHosts(nextHosts);
        setActiveCase(nextCase);
      })
      .catch(() => current && setError(true));
    return () => { current = false; };
  }, [repository]);

  if (error) {
    return <EmptyState title="Demo data could not be loaded" description="Restore the prepared dataset to continue the presentation." action={<Button onClick={() => window.location.reload()}><RotateCcw size={16} /> Reload dataset</Button>} />;
  }

  return (
    <div className="page fleet-page">
      <header className="page-heading entrance entrance--one">
        <div>
          <p className="page-context"><Radar aria-hidden="true" size={14} /> Computer & network forensics</p>
          <h1>Fleet overview</h1>
          <p>Monitor three systems. Investigate findings. Follow the evidence.</p>
        </div>
        <div className="sync-note"><span /> Last synchronized <code>09:39:52 UTC</code></div>
      </header>

      <section className="case-strip entrance entrance--two" aria-labelledby="active-case-title">
        <div className="case-strip__body">
          <div className="case-strip__title-row">
            <span className="case-code">Current investigation / JKY-104</span>
            <Badge tone="warning">Active case</Badge>
          </div>
          <h2 id="active-case-title">{activeCase?.title ?? "Loading case"}</h2>
          <p>{activeCase?.summary}</p>
        </div>
        <dl className="case-strip__meta">
          <div><dt>Owner</dt><dd>{activeCase?.owner ?? "—"}</dd></div>
          <div><dt>Opened</dt><dd>09:30 UTC</dd></div>
        </dl>
        <Link className="button button--primary" to={ROUTES.case}>Open investigation <ArrowUpRight aria-hidden="true" size={17} /></Link>
      </section>

      <section className="metric-band entrance entrance--three" aria-label="Fleet health summary">
        <div className="metric-cell"><span className="metric-icon metric-icon--mint"><CheckCircle2 aria-hidden="true" size={18} /></span><div><strong>3</strong><span>systems online</span></div></div>
        <div className="metric-cell"><span className="metric-icon metric-icon--coral"><ShieldAlert aria-hidden="true" size={18} /></span><div><strong>4</strong><span>open findings</span></div></div>
        <div className="metric-cell"><span className="metric-icon metric-icon--amber"><Radar aria-hidden="true" size={18} /></span><div><strong>1</strong><span>active case</span></div></div>
        <div className="metric-cell"><span className="metric-icon metric-icon--cyan"><FileCheck2 aria-hidden="true" size={18} /></span><div><strong>24</strong><span>verified records</span></div></div>
      </section>

      <section className="section-block entrance entrance--four" aria-labelledby="systems-heading">
        <div className="section-heading">
          <div><h2 id="systems-heading">Systems in scope</h2><p>Windows and Ubuntu systems included in this investigation.</p></div>
          <span className="section-count">03 systems</span>
        </div>
        <HostTable hosts={hosts} />
      </section>

      <div className="fleet-lower-grid entrance entrance--five">
        <section className="section-block compact-panel" aria-labelledby="activity-heading">
          <div className="section-heading"><div><h2 id="activity-heading">Recent activity</h2><p>A record of activity in this investigation.</p></div></div>
          <ol className="activity-list">
            <li><span className="activity-glyph"><ShieldAlert size={15} /></span><div><strong>Collection scope approved</strong><small>JOCKY policy · 09:30:18 UTC</small></div><time>9m</time></li>
            <li><span className="activity-glyph"><Radar size={15} /></span><div><strong>Three hosts confirmed online</strong><small>Fleet monitor · 09:31:02 UTC</small></div><time>8m</time></li>
            <li><span className="activity-glyph"><FileCheck2 size={15} /></span><div><strong>Evidence manifest prepared</strong><small>Case workspace · 09:32:10 UTC</small></div><time>7m</time></li>
          </ol>
        </section>

        <section className="readiness-panel" aria-labelledby="readiness-heading">
          <div className="readiness-panel__top"><span className="radar-orbit"><Radar aria-hidden="true" size={26} /></span><Badge tone="success">Ready</Badge></div>
          <div><h2 id="readiness-heading">Collection readiness</h2><p>Three systems are ready for a simulated evidence collection.</p></div>
          <div className="readiness-rule"><span style={{ width: "100%" }} /></div>
          <div className="readiness-meta"><span><Clock3 size={14} /> Estimated run</span><code>00:06</code></div>
        </section>
      </div>
    </div>
  );
}
