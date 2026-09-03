// ============================================================================
//  JOCKY — Forensic System Tour
//
//  Demonstrates every forensic stdlib builtin on the host it runs on
//  (Linux, macOS, or Windows). The output is host-dependent: timestamps,
//  process lists, sockets, and files all reflect the live system.
//
//  Build & run:
//      ./build/jocky --build scripts/system.jk && ./scripts/system
//      ./build/jocky --seed 5 --obf-level 3 --build scripts/system.jk && ./scripts/system
//      ./build/jocky --target mingw --build scripts/system.jk && ./scripts/system.exe
//
//  Windows-only collectors (reg.list, mem.dump) are no-ops on Linux/macOS.
// ============================================================================

fn main() {
    print("== sys.now() ==");
    print(sys.now());

    print("== sys.cwd() ==");
    print(sys.cwd());

    print("== env.get() ==");
    print(env.get("USER"));
    print(env.get("NOT_A_REAL_VAR"));

    print("== sys.sleep() ==");
    sys.sleep(200);
    print("slept 200ms");

    print("== sys.process_list() ==");
    print(sys.process_list());

    print("== net.sockets() ==");
    print(net.sockets());

    print("== fs.write / fs.read ==");
    fs.write("/tmp/jocky_system_tour.txt", "hello from system tour\n");
    print(fs.read("/tmp/jocky_system_tour.txt"));

    print("== fs.exists ==");
    print(fs.exists("/tmp/jocky_system_tour.txt"));
    print(fs.exists("/no/such/path"));

    print("== fs.list ==");
    print(fs.list("/tmp"));

    print("== reg.list (Windows only) ==");
    print(reg.list("HKLM\\SOFTWARE\\Microsoft"));

    print("== mem.dump (Windows only) ==");
    mem.dump(1, "/tmp/jocky_mem.bin");
    print("done");
}