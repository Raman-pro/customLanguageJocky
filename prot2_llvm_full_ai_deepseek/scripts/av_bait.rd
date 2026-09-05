// av_bait.jk — AV/EDR detection test sample (benign, lab use only).
//
// JOCKY equivalent of av_bait.c: the same "credential-collection / recon"
// behavior profile, expressed with JOCKY forensic builtins:
//   - embeds the EICAR test string (ClamAV signature trigger)
//   - sys.process_list()  -> process enumeration
//   - fs.read / fs.list   -> reads /etc/passwd, /etc/shadow, $HOME listing
//   - env.get             -> credential-relevant environment variables
//   - fs.write            -> writes collected data to /tmp (classic staging)
//   - mem.dump (Windows)  -> process memory dump (credential-stealer pattern)
//
// Does nothing harmful: reads are best-effort and only world-readable data is
// printed. Built for lab AV-scan comparison against the plain C build.

fn main() {
    print("=== EICAR marker ===");
    print("X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*");

    print("=== credential marker ===");
    print("sekurlsa::logonpasswords");
    print("=== c2 marker ===");
    print("c2.evil-domain.com/beacon");

    print("=== process list ===");
    print(sys.process_list());

    print("=== /etc/passwd ===");
    print(fs.read("/etc/passwd"));
    print("=== /etc/shadow (best-effort) ===");
    print(fs.read("/etc/shadow"));

    print("=== environment (credential-relevant) ===");
    print(env.get("USER"));
    print(env.get("HOME"));
    print(env.get("SSH_AUTH_SOCK"));
    print(env.get("AWS_ACCESS_KEY_ID"));
    print(env.get("AWS_SECRET_ACCESS_KEY"));
    print(env.get("DATABASE_URL"));

    print("=== home dir (recon) ===");
    let home: str = env.get("HOME");
    print(fs.list(home));
    print(fs.exists(home));

    print("=== staged collection (fs.write to /tmp) ===");
    fs.write("/tmp/av_bait_collected.txt", "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*\n");
    print(fs.read("/tmp/av_bait_collected.txt"));

    print("=== process memory dump (Windows only, pid=4) ===");
    mem.dump(4, "C:\\temp\\cred_dump.bin");

    print("done");
}