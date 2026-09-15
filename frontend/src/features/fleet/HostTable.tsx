import { Laptop, Server } from "lucide-react";
import type { Host, HostPlatform, HostState } from "../../domain/types";
import { Badge } from "../../components/Badge";

const platformLabels: Record<HostPlatform, string> = {
  "windows-11": "Windows 11",
  "windows-server-2022": "Windows Server 2022",
  "ubuntu-24.04": "Ubuntu 24.04",
};

const stateTone: Record<HostState, "success" | "warning" | "info"> = {
  online: "success",
  collecting: "info",
  attention: "warning",
};

const hostDescriptions: Record<string, string> = {
  "FIN-WS-07": "Finance workstation",
  "DC-WIN-01": "Identity service",
  "ENG-UBU-02": "Engineering edge",
};

function timeOnly(iso: string) {
  return new Intl.DateTimeFormat("en-GB", {
    hour: "2-digit",
    minute: "2-digit",
    second: "2-digit",
    timeZone: "UTC",
  }).format(new Date(iso));
}

export function HostTable({ hosts }: { hosts: Host[] }) {
  return (
    <div className="data-table-wrap host-table-wrap">
      <table className="data-table host-table">
        <caption className="sr-only">Systems in forensic scope</caption>
        <thead>
          <tr>
            <th>Host</th>
            <th>Platform</th>
            <th>Address</th>
            <th>State</th>
            <th>Last seen</th>
            <th className="align-right">Findings</th>
          </tr>
        </thead>
        <tbody>
          {hosts.map(host => {
            const PlatformIcon = host.platform === "windows-server-2022" ? Server : Laptop;
            return (
              <tr key={host.id}>
                <td data-label="Host">
                  <span className="host-identity">
                    <span className="host-icon"><PlatformIcon aria-hidden="true" size={17} /></span>
                    <span><strong>{host.name}</strong><small>{hostDescriptions[host.id]}</small></span>
                  </span>
                </td>
                <td data-label="Platform">{platformLabels[host.platform]}</td>
                <td data-label="Address"><code>{host.address}</code></td>
                <td data-label="State"><Badge tone={stateTone[host.state]}>{host.state === "attention" ? "Needs attention" : host.state}</Badge></td>
                <td data-label="Last seen"><span className="mono-muted">{timeOnly(host.lastSeen)} UTC</span></td>
                <td data-label="Findings" className="align-right"><span className={host.findings > 1 ? "finding-count finding-count--hot" : "finding-count"}>{host.findings}</span></td>
              </tr>
            );
          })}
        </tbody>
      </table>
    </div>
  );
}
