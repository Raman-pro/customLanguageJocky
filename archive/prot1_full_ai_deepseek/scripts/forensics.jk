// JOCKY forensics demo: collect digital-evidence artifacts from the host.
// Runs on Linux and Windows; Windows-only collectors (reg, mem) are no-ops
// on Linux. Output is JSON so a management console can ingest it later.

fn main() {
    print("=== SYSTEM ===");
    print(sys.now());
    print(sys.cwd());
    print(env.get("USER"));
    print("=== PROCESSES (JSON) ===");
    print(sys.process_list());
    print("=== TCP SOCKETS (JSON) ===");
    print(net.sockets());
    print("=== FS /tmp (JSON) ===");
    print(fs.list("/tmp"));
    print(fs.exists("/tmp"));
    fs.write("/tmp/jocky_test.txt", "hello from jocky\n");
    print(fs.read("/tmp/jocky_test.txt"));
    print("=== REGISTRY (Windows only) ===");
    print(reg.list("HKLM\\SOFTWARE\\Microsoft"));
    print("=== MEM DUMP (Windows only, pid=1) ===");
    mem.dump(1, "/tmp/jocky_mem.bin");
    print("done");
}