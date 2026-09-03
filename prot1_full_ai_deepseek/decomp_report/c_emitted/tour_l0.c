// JOCKY build 6C17147E0965930B seed=12345 date=2026-09-03 04:59:59
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <tlhelp32.h>
#include <direct.h>
#elif defined(__APPLE__)
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <libproc.h>
#else
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#endif

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == 0; }

static char j_buf[65536];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = 0;
    for (const char* p = s; *p && o + 8 < cap; ++p) {
        unsigned char c = (unsigned char)*p;
        switch (c) {
            case '"': out[o++] = '\\'; out[o++] = '"'; break;
            case '\\': out[o++] = '\\'; out[o++] = '\\'; break;
            case '\n': out[o++] = '\\'; out[o++] = 'n'; break;
            case '\r': out[o++] = '\\'; out[o++] = 'r'; break;
            case '\t': out[o++] = '\\'; out[o++] = 't'; break;
            default:
                if (c < 0x20) {
                    out[o++] = '\\'; out[o++] = 'u'; out[o++] = '0'; out[o++] = '0';
                    out[o++] = "0123456789abcdef"[c >> 4];
                    out[o++] = "0123456789abcdef"[c & 15];
                } else out[o++] = (char)c;
        }
    }
    out[o] = '\0';
}

static const char* j_sys_now(void) {
    time_t t = time(NULL);
#if defined(_WIN32)
    struct tm* tmv = localtime(&t);
    strftime(j_buf, J_BUF_CAP, "%Y-%m-%dT%H:%M:%S", tmv);
#else
    struct tm tmv;
    localtime_r(&t, &tmv);
    strftime(j_buf, J_BUF_CAP, "%Y-%m-%dT%H:%M:%S", &tmv);
#endif
    return j_buf;
}

static void j_sys_sleep(int32_t ms) {
#if defined(_WIN32)
    Sleep((DWORD)ms);
#else
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (long)(ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
#endif
}

static const char* j_sys_cwd(void) {
#if defined(_WIN32)
    _getcwd(j_buf, (int)J_BUF_CAP);
#else
    getcwd(j_buf, J_BUF_CAP);
#endif
    return j_buf;
}

static const char* j_env_get(const char* name) {
    const char* v = getenv(name);
    return v ? v : "";
}

static bool j_fs_exists(const char* path) {
#if defined(_WIN32)
    return GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES;
#else
    return access(path, F_OK) == 0;
#endif
}

static const char* j_fs_read(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) return "";
    size_t n = fread(j_buf, 1, J_BUF_CAP - 1, f);
    fclose(f);
    j_buf[n] = '\0';
    return j_buf;
}

static void j_fs_write(const char* path, const char* data) {
    FILE* f = fopen(path, "wb");
    if (f) { fputs(data, f); fclose(f); }
}

static const char* j_fs_list(const char* dir) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    char pattern[1024];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[0] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[1024];
            j_json_escape(esc, sizeof esc, fd.cFileName);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : 0);
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
#else
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[1024];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : 0);
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_sys_process_list(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - 400) break;
                char name[1024];
                size_t k = 0;
                for (size_t i = 0; pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[2048];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > 0 ? n : 0);
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[8192];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = 0; i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - 400) break;
        char name[256];
        int len = proc_name(pid, name, sizeof name);
        if (len <= 0) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = 0;
        char esc[512];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > 0 ? n : 0);
    }
#else
    DIR* d = opendir("/proc");
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[0] > '9') continue;
            int pid = atoi(de->d_name);
            char p[64], name[256];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, "r");
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, "\n")] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - 400) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[512];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static void j_net_proc_parse(const char* path, size_t* off, int* first) {
    FILE* f = fopen(path, "r");
    if (!f) return;
    char line[512];
    int skip = 1;
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = 0; continue; }
        char laddr[64], raddr[64], st[16];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != 3) continue;
        if (*off > J_BUF_CAP - 300) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = 0;
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > 0 ? n : 0);
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    ULONG sz = 0;
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);
    char* t = (char*)malloc(sz ? sz : 1);
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0) == NO_ERROR) {
            for (DWORD i = 0; i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[64], ri[64];
                snprintf(li, sizeof li, "%s:%u", inet_ntoa(*(struct in_addr*)&r->dwLocalAddr), (unsigned)ntohs((u_short)r->dwLocalPort));
                snprintf(ri, sizeof ri, "%s:%u", inet_ntoa(*(struct in_addr*)&r->dwRemoteAddr), (unsigned)ntohs((u_short)r->dwRemotePort));
                const char* state = "?";
                switch (r->dwState) {
                    case 2:  state = "LISTEN"; break;
                    case 5:  state = "ESTABLISHED"; break;
                    case 8:  state = "CLOSE_WAIT"; break;
                    case 11: state = "TIME_WAIT"; break;
                    default: state = "OTHER"; break;
                }
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen("netstat -an -p tcp 2>/dev/null", "r");
    if (ns) {
        char line[512];
        while (fgets(line, sizeof line, ns)) {
            char proto[8], laddr[64], raddr[64], st[32];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == 4) {
                if (strncmp(proto, "tcp", 3) != 0) continue;
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        pclose(ns);
    }
#else
    j_net_proc_parse("/proc/net/tcp", &off, &first);
    j_net_proc_parse("/proc/net/tcp6", &off, &first);
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_reg_list(const char* key) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, "HKLM\\", 5) == 0) { root = HKEY_LOCAL_MACHINE; sub = key + 5; }
    else if (strncmp(key, "HKCU\\", 5) == 0) { root = HKEY_CURRENT_USER; sub = key + 5; }
    else if (strncmp(key, "HKCR\\", 5) == 0) { root = HKEY_CLASSES_ROOT; sub = key + 5; }
    else if (strncmp(key, "HKU\\", 4) == 0) { root = HKEY_USERS; sub = key + 4; }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, 0, KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = 0; ; ++i) {
            char s[256];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - 400) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[512];
            j_json_escape(esc, sizeof esc, s);
            int n2 = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n2 > 0 ? n2 : 0);
        }
        RegCloseKey(hk);
    }
#else
    (void)key;
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static void j_mem_dump(int32_t pid, const char* path) {
#if defined(_WIN32)
    HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, (DWORD)pid);
    if (!h) return;
    FILE* out = fopen(path, "wb");
    if (!out) { CloseHandle(h); return; }
    unsigned char* base = NULL;
    MEMORY_BASIC_INFORMATION mbi;
    unsigned long regions = 0;
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < 100000) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : 1);
            SIZE_T read = 0;
            if (chunk && ReadProcessMemory(h, mbi.BaseAddress, chunk, mbi.RegionSize, &read) && read) {
                fwrite(chunk, 1, read, out);
            }
            free(chunk);
        }
        base = (unsigned char*)mbi.BaseAddress + mbi.RegionSize;
    }
    fclose(out);
    CloseHandle(h);
#else
    (void)pid; (void)path;
#endif
}

static volatile int32_t j_052rhh3g = 12438;
static volatile int32_t j_utsi31nd = 24323;

static int32_t j_4f7g6fui(int32_t j_zjsufqwi);
static int32_t j_t2hghb9f(int32_t j_oiwo6t0n, int32_t j_vls2wrj8);
static void j_m2p7e3pa(const char* j_doqql8pa);
static int32_t j_t8lvogp4(int32_t j_vxxehlw0);
static int32_t j_m3tuz7o1(int32_t j_vxxehlw0);
static bool j_dwwcl9v0(int32_t j_vxxehlw0);
static bool j_u1jd8trj(int32_t j_vxxehlw0);
static const char* j_gcfgd3i4(const char* j_eu3wz7tw, int32_t j_w6mesi0m);

static int32_t j_4f7g6fui(int32_t j_zjsufqwi)
{
    static volatile int64_t j_63tox7hg = 56872;
    if ((j_63tox7hg * j_63tox7hg) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_qpdmt0c8 = 37349;
    if ((j_qpdmt0c8 * j_qpdmt0c8) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    return (j_zjsufqwi * 2);
    return 0;
}

static int32_t j_t2hghb9f(int32_t j_oiwo6t0n, int32_t j_vls2wrj8)
{
    static volatile int64_t j_wur5468t = 51868;
    if ((j_wur5468t * j_wur5468t) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_zoaqo32b = 93053;
    if ((j_zoaqo32b * j_zoaqo32b) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    return (j_oiwo6t0n + j_vls2wrj8);
    return 0;
}

static void j_m2p7e3pa(const char* j_doqql8pa)
{
    static volatile int64_t j_qifxsxp8 = 35611;
    if ((j_qifxsxp8 * j_qifxsxp8) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_l9dl9lcd = 80149;
    if ((j_l9dl9lcd * j_l9dl9lcd) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    (void)printf("%s\n", j_doqql8pa);
}

static int32_t j_t8lvogp4(int32_t j_vxxehlw0)
{
    static volatile int64_t j_5fgot7yn = 66749;
    if ((j_5fgot7yn * j_5fgot7yn) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if ((j_vxxehlw0 <= 1))
    {
        return 1;
    }
    return (j_vxxehlw0 * j_t8lvogp4((j_vxxehlw0 - 1)));
    return 0;
}

static int32_t j_m3tuz7o1(int32_t j_vxxehlw0)
{
    static volatile int64_t j_xwb1kiie = 51467;
    if ((j_xwb1kiie * j_xwb1kiie) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_xmav3huv = 53861;
    if ((j_xmav3huv * j_xmav3huv) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_2vqb8n9r = 36626;
    if ((j_2vqb8n9r * j_2vqb8n9r) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if ((j_vxxehlw0 < 2))
    {
        return j_vxxehlw0;
    }
    return (j_m3tuz7o1((j_vxxehlw0 - 1)) + j_m3tuz7o1((j_vxxehlw0 - 2)));
    return 0;
}

static bool j_dwwcl9v0(int32_t j_vxxehlw0)
{
    static volatile int64_t j_fy0gpnl9 = 11042;
    if ((j_fy0gpnl9 * j_fy0gpnl9) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_1wchsa4l = 37584;
    if ((j_1wchsa4l * j_1wchsa4l) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_d9q6x2xs = 53318;
    if ((j_d9q6x2xs * j_d9q6x2xs) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if ((j_vxxehlw0 == 0))
    {
        return true;
    }
    return j_u1jd8trj((j_vxxehlw0 - 1));
    return 0;
}

static bool j_u1jd8trj(int32_t j_vxxehlw0)
{
    static volatile int64_t j_1o4pney0 = 32972;
    if ((j_1o4pney0 * j_1o4pney0) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if ((j_vxxehlw0 == 0))
    {
        return false;
    }
    return j_dwwcl9v0((j_vxxehlw0 - 1));
    return 0;
}

static const char* j_gcfgd3i4(const char* j_eu3wz7tw, int32_t j_w6mesi0m)
{
    static volatile int64_t j_9fdj8cfj = 12462;
    if ((j_9fdj8cfj * j_9fdj8cfj) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_nmbs50pn = 70862;
    if ((j_nmbs50pn * j_nmbs50pn) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_gzdn22af = 73420;
    if ((j_gzdn22af * j_gzdn22af) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if ((j_w6mesi0m >= 18))
    {
        return "adult";
    }
    return "minor";
    return 0;
}

int32_t main(void)
{
    static volatile int64_t j_t6q877f1 = 57815;
    if ((j_t6q877f1 * j_t6q877f1) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_bv9t4v19 = 53041;
    if ((j_bv9t4v19 * j_bv9t4v19) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_zg9kkwyq = 41007;
    if ((j_zg9kkwyq * j_zg9kkwyq) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    (void)printf("%s\n", "== integers ==");
    (void)printf("%d\n", 0);
    (void)printf("%d\n", 42);
    (void)printf("%d\n", -(17));
    (void)printf("%d\n", 1000000);
    (void)printf("%s\n", "== booleans ==");
    (void)printf("%s\n", true ? "true" : "false");
    (void)printf("%s\n", false ? "true" : "false");
    (void)printf("%s\n", "== strings ==");
    (void)printf("%s\n", "hello, world");
    (void)printf("%s\n", "");
    (void)printf("%s\n", "escaped: \\ backslash, \" quote");
    (void)printf("%s\n", "line1\nline2");
    (void)printf("%s\n", "== variables ==");
    int32_t j_ptuv0z66 = 10;
    int32_t j_4x027a2q = 20;
    (void)printf("%d\n", j_ptuv0z66);
    (void)printf("%d\n", j_4x027a2q);
    const char* j_doqql8pa = "jocky";
    bool j_is4zhoek = true;
    (void)printf("%s\n", j_doqql8pa);
    (void)printf("%s\n", j_is4zhoek ? "true" : "false");
    j_is4zhoek = false;
    (void)printf("%s\n", j_is4zhoek ? "true" : "false");
    (void)printf("%s\n", "== arithmetic ==");
    (void)printf("%d\n", (2 + (3 * 4)));
    (void)printf("%d\n", ((2 + 3) * 4));
    (void)printf("%d\n", ((10 - 3) - 2));
    (void)printf("%d\n", (100 / 7));
    (void)printf("%d\n", (100 % 7));
    (void)printf("%d\n", -((3 + 4)));
    (void)printf("%d\n", ((7 / 2) * 2));
    (void)printf("%d\n", (1 + ((2 * 3) % 4)));
    (void)printf("%s\n", "== comparisons ==");
    (void)printf("%s\n", (1 == 1) ? "true" : "false");
    (void)printf("%s\n", (1 != 2) ? "true" : "false");
    (void)printf("%s\n", (3 < 5) ? "true" : "false");
    (void)printf("%s\n", (5 <= 5) ? "true" : "false");
    (void)printf("%s\n", (4 > 9) ? "true" : "false");
    (void)printf("%s\n", (9 >= 10) ? "true" : "false");
    (void)printf("%s\n", "== logic ==");
    (void)printf("%s\n", (true && true) ? "true" : "false");
    (void)printf("%s\n", (true && false) ? "true" : "false");
    (void)printf("%s\n", (false || true) ? "true" : "false");
    (void)printf("%s\n", !(true) ? "true" : "false");
    (void)printf("%s\n", !(!(true)) ? "true" : "false");
    (void)printf("%s\n", "== string operations ==");
    const char* j_mdowkye3 = "JOCKY";
    (void)printf("%d\n", j_str_len(j_mdowkye3));
    (void)printf("%d\n", j_str_len(""));
    (void)printf("%s\n", j_str_eq(j_mdowkye3, "JOCKY") ? "true" : "false");
    (void)printf("%s\n", j_str_eq(j_mdowkye3, "jocky") ? "true" : "false");
    (void)printf("%s\n", !j_str_eq(j_mdowkye3, "JOCKY") ? "true" : "false");
    (void)printf("%s\n", "== if / else ==");
    int32_t j_vxxehlw0 = 7;
    if (((j_vxxehlw0 % 2) == 0))
    {
        (void)printf("%s\n", "even");
    }
    else
    {
        (void)printf("%s\n", "odd");
    }
    if ((j_vxxehlw0 > 10))
    {
        (void)printf("%s\n", "big");
    }
    (void)printf("%s\n", "after if");
    (void)printf("%s\n", "== while ==");
    int32_t j_5n7vyo8e = 0;
    while ((j_5n7vyo8e < 3))
    {
        (void)printf("%d\n", j_5n7vyo8e);
        j_5n7vyo8e = (j_5n7vyo8e + 1);
    }
    (void)printf("%s\n", "== for ==");
    for (int32_t j_zrtnywn7 = 0; (j_zrtnywn7 < 4); j_zrtnywn7 = (j_zrtnywn7 + 1))
    {
        (void)printf("%d\n", j_zrtnywn7);
    }
    (void)printf("%s\n", "== assignment ==");
    int32_t j_zjsufqwi = 0;
    int32_t j_7f500zpd = j_zjsufqwi = 5;
    (void)printf("%d\n", j_zjsufqwi);
    (void)printf("%d\n", j_7f500zpd);
    (void)printf("%s\n", "== shadowing ==");
    int32_t j_4o146wox = 1;
    if (true)
    {
        int32_t j_4o146wox = 2;
        (void)printf("%d\n", j_4o146wox);
    }
    (void)printf("%d\n", j_4o146wox);
    (void)printf("%s\n", "== functions ==");
    (void)printf("%d\n", j_4f7g6fui(21));
    (void)printf("%d\n", j_t2hghb9f(2, 3));
    (void)j_m2p7e3pa("hello from a void function");
    (void)printf("%d\n", j_t8lvogp4(5));
    (void)printf("%d\n", j_m3tuz7o1(10));
    (void)printf("%s\n", j_gcfgd3i4("Ada", 21));
    (void)printf("%s\n", "== mutual recursion ==");
    (void)printf("%s\n", j_dwwcl9v0(10) ? "true" : "false");
    (void)printf("%s\n", j_u1jd8trj(10) ? "true" : "false");
    (void)printf("%s\n", j_dwwcl9v0(7) ? "true" : "false");
    (void)printf("%s\n", "== composition ==");
    (void)printf("%d\n", j_4f7g6fui(j_4f7g6fui(2)));
    (void)printf("%d\n", j_t8lvogp4(j_m3tuz7o1(5)));
    return 0;
}
