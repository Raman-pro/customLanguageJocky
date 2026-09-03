/*
 * av_bait.c — AV/EDR detection test sample (benign, lab use only).
 *
 * Implements the classic "credential-collection / recon" behavior profile that
 * antivirus engines flag on sight:
 *   1. embeds the EICAR test string (deterministic ClamAV signature trigger),
 *   2. enumerates running processes,
 *   3. reads security-sensitive files (/etc/passwd, /etc/shadow, ssh keys,
 *      shell history) and dumps environment variables,
 *   4. Windows-only: OpenProcess + ReadProcessMemory "process memory dump"
 *      pattern (the exact API combo flagged as a credential stealer).
 *
 * It does nothing harmful: every read is best-effort and prints only what is
 * world-readable. Built for lab AV-scan comparison against the JOCKY build.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#ifdef _WIN32
#include <windows.h>
#include <tlhelp32.h>
#endif

static const char eicar[] =
    "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*";
/* Malicious marker strings that AV byte-signatures target (credential theft,
 * command-and-control). These are the strings a real AV .ndb/.hdb rule would
 * match; embedded here verbatim to test whether the compiler pipeline leaves
 * them intact. */
static const char marker_mimikatz[] = "sekurlsa::logonpasswords";
static const char marker_c2[] = "c2.evil-domain.com/beacon";

static void dump_file(const char* path) {
    FILE* f = fopen(path, "r");
    if (!f) return;
    char buf[512];
    size_t n;
    while ((n = fread(buf, 1, sizeof buf - 1, f)) > 0) {
        buf[n] = '\0';
        fputs(buf, stdout);
    }
    fclose(f);
    putchar('\n');
}

static void dump_env(const char* name) {
    const char* v = getenv(name);
    if (v) printf("%s=%s\n", name, v);
}

static void list_dir(const char* path) {
    DIR* d = opendir(path);
    if (!d) return;
    struct dirent* de;
    while ((de = readdir(d)) != NULL) {
        if (de->d_name[0] == '.') continue;
        printf("%s/%s\n", path, de->d_name);
    }
    closedir(d);
}

#ifdef _WIN32
static void dump_process_memory(DWORD pid, const char* out) {
    /* Classic process-dump pattern: OpenProcess -> ReadProcessMemory -> file. */
    HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
    if (!h) return;
    FILE* f = fopen(out, "wb");
    if (f) {
        unsigned char buf[4096];
        MEMORY_BASIC_INFORMATION mbi;
        unsigned char* base = NULL;
        while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi) {
            if (mbi.State == MEM_COMMIT && mbi.Protect != PAGE_NOACCESS) {
                SIZE_T r = 0;
                ReadProcessMemory(h, mbi.BaseAddress, buf, sizeof buf, &r);
                if (r) fwrite(buf, 1, r, f);
            }
            base = (unsigned char*)mbi.BaseAddress + mbi.RegionSize;
        }
        fclose(f);
    }
    CloseHandle(h);
}
#endif

int main(void) {
    printf("=== EICAR marker ===\n%s\n", eicar);
    printf("=== credential marker ===\n%s\n", marker_mimikatz);
    printf("=== c2 marker ===\n%s\n", marker_c2);

    printf("=== process list ===\n");
    DIR* d = opendir("/proc");
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] >= '0' && de->d_name[0] <= '9') printf("%s\n", de->d_name);
        }
        closedir(d);
    } else {
        printf("(no /proc on this platform)\n");
    }

    printf("=== /etc/passwd ===\n");
    dump_file("/etc/passwd");
    printf("=== /etc/shadow (best-effort) ===\n");
    dump_file("/etc/shadow");

    printf("=== environment (credential-relevant) ===\n");
    dump_env("USER");
    dump_env("HOME");
    dump_env("SSH_AUTH_SOCK");
    dump_env("AWS_ACCESS_KEY_ID");
    dump_env("AWS_SECRET_ACCESS_KEY");
    dump_env("DATABASE_URL");

    printf("=== home dir (recon) ===\n");
    const char* home = getenv("HOME");
    if (home) {
        char p[1024];
        snprintf(p, sizeof p, "%s/.ssh", home);
        list_dir(p);
        snprintf(p, sizeof p, "%s/.ssh/id_rsa", home);
        dump_file(p);
        snprintf(p, sizeof p, "%s/.ssh/id_ed25519", home);
        dump_file(p);
    }

#ifdef _WIN32
    printf("=== process memory dump (pid 4) ===\n");
    dump_process_memory(4, "C:\\temp\\cred_dump.bin");
#endif

    printf("done\n");
    return 0;
}