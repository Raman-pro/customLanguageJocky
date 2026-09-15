import type { ReactNode } from "react";

export interface BadgeProps {
  tone: "neutral" | "info" | "success" | "warning" | "danger";
  children: ReactNode;
}

export function Badge({ tone, children }: BadgeProps) {
  return (
    <span className={`badge badge--${tone}`}>
      <span className="badge__dot" aria-hidden="true" />
      {children}
    </span>
  );
}
