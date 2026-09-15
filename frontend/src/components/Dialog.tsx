import { useEffect, useRef, type KeyboardEvent, type ReactNode } from "react";
import { createPortal } from "react-dom";
import { X } from "lucide-react";

interface DialogProps {
  open: boolean;
  title: string;
  description: string;
  onClose(): void;
  children: ReactNode;
}

export function Dialog({ open, title, description, onClose, children }: DialogProps) {
  const containerRef = useRef<HTMLDivElement>(null);

  useEffect(() => {
    if (open) containerRef.current?.querySelector<HTMLElement>("button, [href], input")?.focus();
  }, [open]);

  if (!open) return null;

  function handleKeyDown(event: KeyboardEvent<HTMLDivElement>) {
    if (event.key === "Escape") onClose();
  }

  return createPortal(
    <div className="dialog-backdrop" onMouseDown={event => event.target === event.currentTarget && onClose()}>
      <div
        ref={containerRef}
        className="dialog-panel"
        role="dialog"
        aria-modal="true"
        aria-labelledby="dialog-title"
        aria-describedby="dialog-description"
        onKeyDown={handleKeyDown}
      >
        <button className="dialog-close" type="button" onClick={onClose} aria-label="Close review">
          <X aria-hidden="true" size={18} />
        </button>
        <div className="dialog-heading">
          <p className="page-context">Collection authorization</p>
          <h2 id="dialog-title">{title}</h2>
          <p id="dialog-description">{description}</p>
        </div>
        {children}
      </div>
    </div>,
    document.body,
  );
}
