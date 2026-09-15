import { Check, Copy } from "lucide-react";
import { useState } from "react";

export function CodePanel({ value, language = "json", label = "Raw evidence" }: { value: string | Record<string, unknown>; language?: "json" | "jocky"; label?: string }) {
  const [copied, setCopied] = useState(false);
  const text = typeof value === "string" ? value : JSON.stringify(value, null, 2);

  async function copy() {
    await navigator.clipboard?.writeText(text);
    setCopied(true);
    window.setTimeout(() => setCopied(false), 1200);
  }

  return (
    <div className={`code-panel code-panel--${language}`}>
      <div className="code-panel__bar"><span>{label}</span><button type="button" onClick={copy} aria-label={`Copy ${label.toLowerCase()}`}>{copied ? <Check size={14} /> : <Copy size={14} />} {copied ? "Copied" : "Copy"}</button></div>
      <pre><code>{text}</code></pre>
    </div>
  );
}
