import { useState, type ReactNode } from "react";
import { Activity, Binary, Database, Fingerprint, Network, RotateCcw, ShieldCheck } from "lucide-react";
import { NavLink, useNavigate } from "react-router-dom";
import { ROUTES } from "./routes";
import { useDemo } from "./DemoProvider";
import { Button } from "../components/Button";
import { ToastRegion } from "../components/ToastRegion";

interface AppShellProps { children: ReactNode; }

const navItems = [
  { to: ROUTES.fleet, label: "Fleet", description: "Systems & activity", icon: Network },
  { to: ROUTES.case, label: "Investigation", description: "Collect & review", icon: Activity },
  { to: ROUTES.evidence, label: "Evidence", description: "Records & origins", icon: Database },
  { to: ROUTES.buildProof, label: "Build proof", description: "Source & builds", icon: Binary },
];

export function AppShell({ children }: AppShellProps) {
  const { resetDemo } = useDemo();
  const navigate = useNavigate();
  const [message, setMessage] = useState<string | null>(null);

  async function reset() {
    await resetDemo();
    navigate(ROUTES.fleet);
    setMessage("Demo restored to its starting state.");
    window.setTimeout(() => setMessage(null), 2200);
  }

  return (
    <div className="app-shell">
      <a className="skip-link" href="#main-content">Skip to content</a>
      <aside className="workspace-sidebar">
        <NavLink to={ROUTES.fleet} className="workspace-brand" aria-label="JOCKY home">
          <Fingerprint size={30} strokeWidth={1.6} aria-hidden="true" />
          <span><strong>JOCKY</strong><small>Forensic console</small></span>
        </NavLink>
        <div className="nav-section-label">Workspace</div>
        <nav className="primary-nav" aria-label="Primary navigation">
          {navItems.map(({ to, label, description, icon: Icon }, index) => (
            <NavLink key={to} to={to} end aria-label={label} className={({ isActive }) => `nav-link${isActive ? " is-active" : ""}`}>
              <Icon aria-hidden="true" size={20} strokeWidth={1.8} />
              <span><strong>{label}</strong><small>{description}</small></span>
              <span className="nav-index" aria-hidden="true">0{index + 1}</span>
            </NavLink>
          ))}
        </nav>
        <div className="sidebar-case"><span>Case in focus</span><strong>JKY-104</strong><p>Suspected lateral movement</p><div><span /> Investigation open</div></div>
        <div className="sidebar-policy"><ShieldCheck aria-hidden="true" size={18} /><span>Read-only analysis<small>Local demonstration</small></span></div>
      </aside>
      <div className="workspace-body">
        <header className="workspace-topbar">
          <div className="workspace-location"><strong>Forensic operations</strong><span>Investigation lab</span></div>
          <div className="context-actions"><span className="demo-boundary"><span aria-hidden="true" />Demo dataset</span><Button variant="quiet" onClick={reset} className="reset-demo"><RotateCcw size={16} aria-hidden="true" />Reset demo</Button></div>
        </header>
        <main id="main-content" className="app-content">{children}</main>
        <footer className="workspace-footer"><span>JOCKY · Computer & network forensics</span><span>All records in this workspace are demonstration data.</span></footer>
      </div>
      <ToastRegion message={message} />
    </div>
  );
}
