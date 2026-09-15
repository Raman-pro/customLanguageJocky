import { BrowserRouter, Navigate, Route, Routes } from "react-router-dom";
import { CasePage } from "../features/case/CasePage";
import { EvidencePage } from "../features/evidence/EvidencePage";
import { BuildProofPage } from "../features/buildProof/BuildProofPage";
import { FleetPage } from "../features/fleet/FleetPage";
import { AppShell } from "./AppShell";
import { DemoProvider } from "./DemoProvider";
import { ROUTES } from "./routes";

export function App() {
  return (
    <BrowserRouter>
      <DemoProvider>
        <AppShell>
          <Routes>
            <Route path="/" element={<Navigate to={ROUTES.fleet} replace />} />
            <Route path={ROUTES.fleet} element={<FleetPage />} />
            <Route path={ROUTES.case} element={<CasePage />} />
            <Route path={ROUTES.evidence} element={<EvidencePage />} />
            <Route path={ROUTES.buildProof} element={<BuildProofPage />} />
            <Route path="*" element={<Navigate to={ROUTES.fleet} replace />} />
          </Routes>
        </AppShell>
      </DemoProvider>
    </BrowserRouter>
  );
}
