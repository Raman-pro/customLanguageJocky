import { useRef, useState } from "react";
import { Check, Clock3, Cpu, HardDrive, Network, Play, ShieldCheck } from "lucide-react";
import { Button } from "../../components/Button";
import { Dialog } from "../../components/Dialog";
import type { CollectionProfile, Host } from "../../domain/types";

interface StartCollectionProps {
  hosts: Host[];
  profile: CollectionProfile;
  running: boolean;
  verified: boolean;
  onStart(): Promise<void>;
}

export function StartCollection({ hosts, profile, running, verified, onStart }: StartCollectionProps) {
  const [open, setOpen] = useState(false);
  const [submitting, setSubmitting] = useState(false);
  const triggerRef = useRef<HTMLButtonElement>(null);

  function close() {
    setOpen(false);
    requestAnimationFrame(() => triggerRef.current?.focus());
  }

  async function run() {
    setSubmitting(true);
    await onStart();
    setSubmitting(false);
    close();
  }

  return (
    <>
      <Button ref={triggerRef} variant="primary" disabled={running} onClick={() => setOpen(true)}>
        {running ? <><span className="spinner" /> Collection running</> : <><Play aria-hidden="true" size={16} fill="currentColor" /> {verified ? "Run again" : "Start collection"}</>}
      </Button>
      <Dialog open={open} title="Review collection" description="Confirm the prepared read-only profile and system scope." onClose={close}>
        <div className="review-profile">
          <div className="review-profile__icon"><ShieldCheck aria-hidden="true" size={23} /></div>
          <div><span>Approved profile</span><strong>{profile.name}</strong><p>{profile.description}</p></div>
        </div>
        <div className="review-scope-heading"><span>{hosts.length} selected hosts</span><code>~{profile.estimatedSeconds}s</code></div>
        <ul className="review-hosts">
          {hosts.map(host => <li key={host.id}><Check aria-hidden="true" size={14} /><span>{host.name}</span><code>{host.address}</code></li>)}
        </ul>
        <div className="review-collectors">
          <span><Cpu size={15} /> Processes</span><span><Network size={15} /> Network</span><span><HardDrive size={15} /> Files + persistence</span>
        </div>
        <div className="demo-notice"><Clock3 aria-hidden="true" size={16} /><p><strong>Presentation simulation</strong>Mock execution; no endpoint commands are sent.</p></div>
        <div className="dialog-actions">
          <Button variant="quiet" onClick={close}>Cancel</Button>
          <Button variant="primary" disabled={submitting} onClick={run}>Run collection <Play aria-hidden="true" size={15} /></Button>
        </div>
      </Dialog>
    </>
  );
}
