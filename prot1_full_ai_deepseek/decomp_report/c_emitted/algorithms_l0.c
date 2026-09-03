// JOCKY build 2AA95D66ECF0C36B seed=12345 date=2026-09-03 05:00:01
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

static volatile int32_t j_7hgmqpdm = 42673;
static volatile int32_t j_t0c8jewu = 25683;

static int32_t j_4f7g6fui(int32_t j_zjsufqwi);
static int32_t j_t2hghb9f(int32_t j_zjsufqwi);
static int32_t j_oiwo6t0n(int32_t j_zjsufqwi);
static int32_t j_vls2wrj8(int32_t j_m2p7e3pa, int32_t j_doqql8pa);
static bool j_t8lvogp4(int32_t j_zjsufqwi);
static int32_t j_vxxehlw0(int32_t j_zjsufqwi);
static int32_t j_m3tuz7o1(int32_t j_zjsufqwi);
static int32_t j_dwwcl9v0(int32_t j_zjsufqwi);
static int32_t j_u1jd8trj(int32_t j_gcfgd3i4, int32_t j_eu3wz7tw);
static int32_t j_w6mesi0m(int32_t j_m2p7e3pa, int32_t j_doqql8pa, int32_t j_l052rhh3);
static int32_t j_gutsi31n(int32_t j_m2p7e3pa, int32_t j_doqql8pa, int32_t j_l052rhh3);
static bool j_dk9e63to(int32_t j_zjsufqwi);

static int32_t j_4f7g6fui(int32_t j_zjsufqwi)
{
    static volatile int64_t j_68tmzoaq = 2698;
    if ((j_68tmzoaq * j_68tmzoaq) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if ((j_zjsufqwi < 2))
    {
        return j_zjsufqwi;
    }
    int32_t j_m2p7e3pa = 0;
    int32_t j_doqql8pa = 1;
    int32_t j_32bb5qif = 2;
    while ((j_32bb5qif <= j_zjsufqwi))
    {
        int32_t j_xsxp8ll9 = (j_m2p7e3pa + j_doqql8pa);
        j_m2p7e3pa = j_doqql8pa;
        j_doqql8pa = j_xsxp8ll9;
        j_32bb5qif = (j_32bb5qif + 1);
    }
    return j_doqql8pa;
    return 0;
}

static int32_t j_t2hghb9f(int32_t j_zjsufqwi)
{
    static volatile int64_t j_l9lcd7m5 = 38077;
    if ((j_l9lcd7m5 * j_l9lcd7m5) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if ((j_zjsufqwi < 2))
    {
        return j_zjsufqwi;
    }
    return (j_t2hghb9f((j_zjsufqwi - 1)) + j_t2hghb9f((j_zjsufqwi - 2)));
    return 0;
}

static int32_t j_oiwo6t0n(int32_t j_zjsufqwi)
{
    static volatile int64_t j_ot7yn30x = 53282;
    if ((j_ot7yn30x * j_ot7yn30x) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if ((j_zjsufqwi <= 1))
    {
        return 1;
    }
    return (j_zjsufqwi * j_oiwo6t0n((j_zjsufqwi - 1)));
    return 0;
}

static int32_t j_vls2wrj8(int32_t j_m2p7e3pa, int32_t j_doqql8pa)
{
    static volatile int64_t j_1kiietxm = 72828;
    if ((j_1kiietxm * j_1kiietxm) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_v3huvf2v = 96432;
    if ((j_v3huvf2v * j_v3huvf2v) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if ((j_doqql8pa == 0))
    {
        return j_m2p7e3pa;
    }
    return j_vls2wrj8(j_doqql8pa, (j_m2p7e3pa % j_doqql8pa));
    return 0;
}

static bool j_t8lvogp4(int32_t j_zjsufqwi)
{
    static volatile int64_t j_8n9rkrfy = 38382;
    if ((j_8n9rkrfy * j_8n9rkrfy) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_gpnl9c1w = 60058;
    if ((j_gpnl9c1w * j_gpnl9c1w) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if ((j_zjsufqwi < 2))
    {
        return false;
    }
    int32_t j_32bb5qif = 2;
    while (((j_32bb5qif * j_32bb5qif) <= j_zjsufqwi))
    {
        if (((j_zjsufqwi % j_32bb5qif) == 0))
        {
            return false;
        }
        j_32bb5qif = (j_32bb5qif + 1);
    }
    return true;
    return 0;
}

static int32_t j_vxxehlw0(int32_t j_zjsufqwi)
{
    static volatile int64_t j_sa4lyd9q = 58868;
    if ((j_sa4lyd9q * j_sa4lyd9q) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_x2xsop1o = 80182;
    if ((j_x2xsop1o * j_x2xsop1o) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    int32_t j_pney0af9 = 0;
    int32_t j_fdj8cfjg = j_zjsufqwi;
    while ((j_fdj8cfjg != 1))
    {
        if (((j_fdj8cfjg % 2) == 0))
        {
            j_fdj8cfjg = (j_fdj8cfjg / 2);
        }
        else
        {
            j_fdj8cfjg = ((j_fdj8cfjg * 3) + 1);
        }
        j_pney0af9 = (j_pney0af9 + 1);
    }
    return j_pney0af9;
    return 0;
}

static int32_t j_m3tuz7o1(int32_t j_zjsufqwi)
{
    static volatile int64_t j_mbs50pn8 = 94022;
    if ((j_mbs50pn8 * j_mbs50pn8) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_zdn22af2 = 65934;
    if ((j_zdn22af2 * j_zdn22af2) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    int32_t j_t6q877f1 = 0;
    int32_t j_hbv9t4v1 = j_zjsufqwi;
    while ((j_hbv9t4v1 > 0))
    {
        j_t6q877f1 = (j_t6q877f1 + (j_hbv9t4v1 % 10));
        j_hbv9t4v1 = (j_hbv9t4v1 / 10);
    }
    return j_t6q877f1;
    return 0;
}

static int32_t j_dwwcl9v0(int32_t j_zjsufqwi)
{
    static volatile int64_t j_rzg9kkwy = 36260;
    if ((j_rzg9kkwy * j_rzg9kkwy) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_hptuv0z6 = 63932;
    if ((j_hptuv0z6 * j_hptuv0z6) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_4x027a2q = 23976;
    if ((j_4x027a2q * j_4x027a2q) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if ((j_zjsufqwi < 0))
    {
        return -(j_dwwcl9v0(-(j_zjsufqwi)));
    }
    int32_t j_s4zhoekm = 0;
    int32_t j_hbv9t4v1 = j_zjsufqwi;
    while ((j_hbv9t4v1 > 0))
    {
        j_s4zhoekm = ((j_s4zhoekm * 10) + (j_hbv9t4v1 % 10));
        j_hbv9t4v1 = (j_hbv9t4v1 / 10);
    }
    return j_s4zhoekm;
    return 0;
}

static int32_t j_u1jd8trj(int32_t j_gcfgd3i4, int32_t j_eu3wz7tw)
{
    static volatile int64_t j_owkye35n = 12757;
    if ((j_owkye35n * j_owkye35n) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    int32_t j_vyo8ezrt = 1;
    int32_t j_32bb5qif = 0;
    while ((j_32bb5qif < j_eu3wz7tw))
    {
        j_vyo8ezrt = (j_vyo8ezrt * j_gcfgd3i4);
        j_32bb5qif = (j_32bb5qif + 1);
    }
    return j_vyo8ezrt;
    return 0;
}

static int32_t j_w6mesi0m(int32_t j_m2p7e3pa, int32_t j_doqql8pa, int32_t j_l052rhh3)
{
    static volatile int64_t j_ywn77f50 = 8038;
    if ((j_ywn77f50 * j_ywn77f50) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_zpd4o146 = 25494;
    if ((j_zpd4o146 * j_zpd4o146) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if (((j_m2p7e3pa >= j_doqql8pa) && (j_m2p7e3pa >= j_l052rhh3)))
    {
        return j_m2p7e3pa;
    }
    if (((j_doqql8pa >= j_m2p7e3pa) && (j_doqql8pa >= j_l052rhh3)))
    {
        return j_doqql8pa;
    }
    return j_l052rhh3;
    return 0;
}

static int32_t j_gutsi31n(int32_t j_m2p7e3pa, int32_t j_doqql8pa, int32_t j_l052rhh3)
{
    static volatile int64_t j_x3cs7yom = 24781;
    if ((j_x3cs7yom * j_x3cs7yom) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_oruc4i39 = 15720;
    if ((j_oruc4i39 * j_oruc4i39) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    static volatile int64_t j_zktr7322 = 46539;
    if ((j_zktr7322 * j_zktr7322) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    if (((j_m2p7e3pa <= j_doqql8pa) && (j_m2p7e3pa <= j_l052rhh3)))
    {
        return j_m2p7e3pa;
    }
    if (((j_doqql8pa <= j_m2p7e3pa) && (j_doqql8pa <= j_l052rhh3)))
    {
        return j_doqql8pa;
    }
    return j_l052rhh3;
    return 0;
}

static bool j_dk9e63to(int32_t j_zjsufqwi)
{
    static volatile int64_t j_6lcv1ym4 = 52794;
    if ((j_6lcv1ym4 * j_6lcv1ym4) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    return (j_zjsufqwi == j_dwwcl9v0(j_zjsufqwi));
    return 0;
}

int32_t main(void)
{
    static volatile int64_t j_u5c2bwee = 26387;
    if ((j_u5c2bwee * j_u5c2bwee) >= 0)
    {
    }
    else
    {
        printf("%d\n", 0);
    }
    (void)printf("%s\n", "== fibonacci (iterative) ==");
    (void)printf("%d\n", j_4f7g6fui(0));
    (void)printf("%d\n", j_4f7g6fui(1));
    (void)printf("%d\n", j_4f7g6fui(10));
    (void)printf("%d\n", j_4f7g6fui(20));
    (void)printf("%s\n", "== fibonacci (recursive) ==");
    (void)printf("%d\n", j_t2hghb9f(0));
    (void)printf("%d\n", j_t2hghb9f(1));
    (void)printf("%d\n", j_t2hghb9f(10));
    (void)printf("%s\n", "== factorial ==");
    (void)printf("%d\n", j_oiwo6t0n(0));
    (void)printf("%d\n", j_oiwo6t0n(5));
    (void)printf("%d\n", j_oiwo6t0n(8));
    (void)printf("%s\n", "== greatest common divisor ==");
    (void)printf("%d\n", j_vls2wrj8(48, 36));
    (void)printf("%d\n", j_vls2wrj8(17, 5));
    (void)printf("%d\n", j_vls2wrj8(100, 10));
    (void)printf("%s\n", "== primality ==");
    (void)printf("%s\n", j_t8lvogp4(2) ? "true" : "false");
    (void)printf("%s\n", j_t8lvogp4(17) ? "true" : "false");
    (void)printf("%s\n", j_t8lvogp4(18) ? "true" : "false");
    (void)printf("%s\n", j_t8lvogp4(97) ? "true" : "false");
    (void)printf("%s\n", "== primes up to 30 ==");
    for (int32_t j_32bb5qif = 2; (j_32bb5qif <= 30); j_32bb5qif = (j_32bb5qif + 1))
    {
        if (j_t8lvogp4(j_32bb5qif))
        {
            (void)printf("%d\n", j_32bb5qif);
        }
    }
    (void)printf("%s\n", "== collatz steps ==");
    (void)printf("%d\n", j_vxxehlw0(1));
    (void)printf("%d\n", j_vxxehlw0(27));
    (void)printf("%d\n", j_vxxehlw0(6));
    (void)printf("%s\n", "== sum of digits ==");
    (void)printf("%d\n", j_m3tuz7o1(0));
    (void)printf("%d\n", j_m3tuz7o1(12345));
    (void)printf("%d\n", j_m3tuz7o1(999));
    (void)printf("%s\n", "== reverse digits ==");
    (void)printf("%d\n", j_dwwcl9v0(12345));
    (void)printf("%d\n", j_dwwcl9v0(-(123)));
    (void)printf("%d\n", j_dwwcl9v0(7));
    (void)printf("%s\n", "== power ==");
    (void)printf("%d\n", j_u1jd8trj(2, 10));
    (void)printf("%d\n", j_u1jd8trj(3, 3));
    (void)printf("%d\n", j_u1jd8trj(5, 0));
    (void)printf("%s\n", "== min / max of three ==");
    (void)printf("%d\n", j_w6mesi0m(3, 9, 6));
    (void)printf("%d\n", j_gutsi31n(3, 9, 6));
    (void)printf("%d\n", j_w6mesi0m(-(5), -(1), -(3)));
    (void)printf("%s\n", "== palindrome number ==");
    (void)printf("%s\n", j_dk9e63to(121) ? "true" : "false");
    (void)printf("%s\n", j_dk9e63to(12321) ? "true" : "false");
    (void)printf("%s\n", j_dk9e63to(123) ? "true" : "false");
    return 0;
}
