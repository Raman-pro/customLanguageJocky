import { Check, Copy, FileDigit, GitCompareArrows } from "lucide-react";
import { useState } from "react";
import type { BuildArtifact } from "../../domain/types";
import { Badge } from "../../components/Badge";

function formatBytes(value: number) {
  return new Intl.NumberFormat("en-IN").format(value);
}

function ArtifactColumn({ artifact, label }: { artifact: BuildArtifact; label: string }) {
  const [copied, setCopied] = useState(false);
  async function copyHash() {
    await navigator.clipboard?.writeText(artifact.sha256);
    setCopied(true);
    window.setTimeout(() => setCopied(false), 1200);
  }
  return (
    <article className="artifact-column">
      <div className="artifact-column__header"><div><span>{label}</span><strong>Level {artifact.level}</strong></div><Badge tone="neutral">{artifact.target}</Badge></div>
      <dl className="artifact-metrics">
        <div><dt>Seed</dt><dd><code>{artifact.seed}</code></dd></div>
        <div><dt>Size</dt><dd><code>{formatBytes(artifact.sizeBytes)} B</code></dd></div>
        <div><dt>Entropy</dt><dd><code>{artifact.entropy.toFixed(3)}</code></dd></div>
        <div><dt>Exported functions</dt><dd><code>{artifact.exportedFunctions}</code></dd></div>
      </dl>
      <div className="artifact-hash"><span>SHA-256</span><code>{artifact.sha256}</code><button type="button" onClick={copyHash} aria-label={`Copy level ${artifact.level} hash`}>{copied ? <Check size={14} /> : <Copy size={14} />}</button></div>
    </article>
  );
}

export function ArtifactCompare({ artifacts }: { artifacts: BuildArtifact[] }) {
  const baseline = artifacts.find(artifact => artifact.level === 0);
  const varied = artifacts.find(artifact => artifact.level === 3);
  if (!baseline || !varied) return null;
  const delta = varied.sizeBytes - baseline.sizeBytes;

  return (
    <div className="artifact-compare">
      <ArtifactColumn artifact={baseline} label="Baseline artifact" />
      <ArtifactColumn artifact={varied} label="Varied artifact" />
      <div className="same-source-spine"><span><GitCompareArrows size={16} /></span><strong>Same source</strong><small>Different measured artifacts</small><code>+{formatBytes(delta)} B</code></div>
      <div className="comparison-proof"><FileDigit aria-hidden="true" size={16} /><span><strong>Artifact hashes differ</strong>Both values are loaded from the checked-in evaluation set.</span></div>
    </div>
  );
}
