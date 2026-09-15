import { useEffect, useState } from "react";
import { Binary, ChevronRight, DatabaseZap, FileCode2, Info, ShieldCheck } from "lucide-react";
import { Link } from "react-router-dom";
import { useDemo } from "../../app/DemoProvider";
import { ROUTES } from "../../app/routes";
import { Badge } from "../../components/Badge";
import { CodePanel } from "../../components/CodePanel";
import { EmptyState } from "../../components/EmptyState";
import type { BuildArtifact } from "../../domain/types";
import { forensicsSource } from "../../mocks/buildProof";
import { ArtifactCompare } from "./ArtifactCompare";
import { Pipeline } from "./Pipeline";

export function BuildProofPage() {
  const { repository } = useDemo();
  const [artifacts, setArtifacts] = useState<BuildArtifact[]>([]);
  const [error, setError] = useState(false);

  useEffect(() => {
    repository.getBuildArtifacts().then(setArtifacts).catch(() => setError(true));
  }, [repository]);

  if (error) return <EmptyState title="Build evidence could not be loaded" description="The checked-in evaluation sample is unavailable." />;

  return (
    <div className="page build-proof-page">
      <nav className="breadcrumb" aria-label="Breadcrumb"><Link to={ROUTES.fleet}>Fleet</Link><ChevronRight size={13} /><span>Build proof</span></nav>
      <header className="build-proof-heading entrance entrance--one">
        <div><p className="page-context"><Binary size={14} /> The JOCKY language / Build record</p><h1>JOCKY build proof</h1><p>Follow a JOCKY script through the compiler and compare its recorded outputs.</p></div>
        <div className="sample-label"><DatabaseZap size={17} /><span><strong>Checked-in evaluation sample</strong><small>Local, reproducible evidence</small></span></div>
      </header>

      <section className="pipeline-section entrance entrance--two" aria-labelledby="pipeline-heading">
        <div className="section-heading"><div><h2 id="pipeline-heading">Compiler path</h2><p>Five stages from the source script to the compiled output.</p></div><Badge tone="success"><ShieldCheck size={12} /> Read-only view</Badge></div>
        <Pipeline />
      </section>

      <div className="build-proof-grid entrance entrance--three">
        <section className="source-proof" aria-labelledby="source-heading">
          <div className="source-proof__header"><div><FileCode2 size={16} /><span><strong id="source-heading">forensics.rd</strong><small>Read-only source excerpt</small></span></div><code>JOCKY / .rd</code></div>
          <CodePanel value={forensicsSource} language="jocky" label="JOCKY source" />
          <div className="source-builtins"><span>sys.process_list</span><span>net.sockets</span><span>fs.list</span><span>reg.list</span></div>
        </section>

        <section className="comparison-section" aria-labelledby="comparison-heading">
          <div className="section-heading"><div><h2 id="comparison-heading">Build comparison</h2><p>Compare two recorded builds of the same script.</p></div><span className="section-count">Level 0 / Level 3</span></div>
          <ArtifactCompare artifacts={artifacts} />
        </section>
      </div>

      <div className="measurement-note entrance entrance--four"><Info aria-hidden="true" size={16} /><p><strong>Measurement boundary</strong>Measurements are loaded from <code>evaluation/decomp_report/metrics/hashes.txt</code>; this screen does not execute the compiler or claim detection efficacy.</p></div>
    </div>
  );
}
