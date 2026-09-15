import { createContext, useContext, useEffect, useRef, useState, type ReactNode } from "react";
import type { ForensicsRepository } from "../domain/repository";
import type { CollectionRun } from "../domain/types";
import { initialRun } from "../mocks/fixtures";
import { MockForensicsRepository } from "../mocks/MockForensicsRepository";

export interface DemoContextValue {
  repository: ForensicsRepository;
  activeRun: CollectionRun;
  startCollection(profileId: string, hostIds: string[]): Promise<void>;
  resetDemo(): Promise<void>;
}

const DemoContext = createContext<DemoContextValue | null>(null);

export function DemoProvider({ children }: { children: ReactNode }) {
  const repositoryRef = useRef<ForensicsRepository>(new MockForensicsRepository());
  const [activeRun, setActiveRun] = useState<CollectionRun>(initialRun);

  useEffect(() => repositoryRef.current.subscribeToRun("JKY-104", setActiveRun), []);

  const value: DemoContextValue = {
    repository: repositoryRef.current,
    activeRun,
    async startCollection(profileId, hostIds) {
      await repositoryRef.current.startCollection("JKY-104", profileId, hostIds);
    },
    async resetDemo() {
      await repositoryRef.current.reset();
    },
  };

  return <DemoContext.Provider value={value}>{children}</DemoContext.Provider>;
}

export function useDemo(): DemoContextValue {
  const context = useContext(DemoContext);
  if (!context) throw new Error("useDemo must be used inside DemoProvider");
  return context;
}
