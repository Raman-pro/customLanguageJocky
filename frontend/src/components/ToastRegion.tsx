export function ToastRegion({ message }: { message: string | null }) {
  return (
    <div className="toast-region" role="status" aria-live="polite" aria-atomic="true">
      {message ? <div className="toast">{message}</div> : null}
    </div>
  );
}
