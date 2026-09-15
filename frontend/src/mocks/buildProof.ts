import type { BuildArtifact } from "../domain/types";

export const forensicsSource = `// JOCKY forensics demo: collect digital-evidence artifacts from the host.
fn main() {
    print("=== SYSTEM ===");
    print(sys.now());
    print(sys.process_list());
    print(net.sockets());
    print(fs.list("/tmp"));
    print(reg.list("HKLM\\\\SOFTWARE\\\\Microsoft"));
}`;

export const buildArtifacts: BuildArtifact[] = [
  {
    id: "jk-forensics-l0",
    target: "linux-x86_64",
    seed: 42,
    level: 0,
    sha256: "31bc56ed1f21a9610155eedf2367036f40f590665bcb0c26b4001099ab3b1222",
    sizeBytes: 52136,
    entropy: 1.39,
    exportedFunctions: 18,
  },
  {
    id: "jk-forensics-l3",
    target: "linux-x86_64",
    seed: 7,
    level: 3,
    sha256: "ab6dad8d37d4eb82f82f754dcebf423d2d12bf3c72de7ca0b75acbd6c55abcf4",
    sizeBytes: 53368,
    entropy: 2.267,
    exportedFunctions: 19,
  },
];
