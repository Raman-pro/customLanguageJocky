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
    static volatile int64_t j_468tmzoa = 4121;
    if ((((j_468tmzoa * (j_468tmzoa + 1)) % 2) == 1))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_qo32bb5q = 68996;
    if ((((j_qo32bb5q * j_qo32bb5q) + j_qo32bb5q) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((j_zjsufqwi < 2))
    {
        return j_zjsufqwi;
    }
    int32_t j_m2p7e3pa = 0;
    static volatile int64_t j_ifxsxp8l = 96421;
    if ((((j_ifxsxp8l * j_ifxsxp8l) + j_ifxsxp8l) < 0))
    {
        volatile int64_t j_l9dl9lcd = ((j_ifxsxp8l * 51) + 421);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    int32_t j_doqql8pa = 1;
    static volatile int64_t j_7m5fgot7 = 12415;
    static volatile int64_t j_yn30xwb1 = 1103;
    if ((((j_yn30xwb1 * j_yn30xwb1) + j_yn30xwb1) < 0))
    {
        volatile int64_t j_kiietxma = ((j_yn30xwb1 * 3) + 103);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_7m5fgot7 * j_7m5fgot7) + j_7m5fgot7) < 0))
    {
        volatile int64_t j_v3huvf2v = ((j_7m5fgot7 * 60) + 415);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    int32_t j_qb8n9rkr = 2;
    while ((j_qb8n9rkr <= j_zjsufqwi))
    {
        int32_t j_fy0gpnl9 = (j_m2p7e3pa + j_doqql8pa);
        j_m2p7e3pa = j_doqql8pa;
        j_doqql8pa = j_fy0gpnl9;
        j_qb8n9rkr = (j_qb8n9rkr + 1);
    }
    return j_doqql8pa;
    static volatile int64_t j_c1wchsa4 = 28527;
    if ((((j_c1wchsa4 * j_c1wchsa4) + j_c1wchsa4) < 0))
    {
        volatile int64_t j_lyd9q6x2 = ((j_c1wchsa4 * 79) + 527);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_xsop1o4p = 2944;
    if ((((j_xsop1o4p * j_xsop1o4p) % 4) < 2))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

static int32_t j_t2hghb9f(int32_t j_zjsufqwi)
{
    if ((j_zjsufqwi < 2))
    {
        return j_zjsufqwi;
    }
    static volatile int64_t j_ney0af9f = 51868;
    if ((((j_ney0af9f * j_ney0af9f) + j_ney0af9f) < 0))
    {
        volatile int64_t j_dj8cfjgn = ((j_ney0af9f * 66) + 868);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_mbs50pn8 = 12744;
    if ((((j_mbs50pn8 * j_mbs50pn8) + j_mbs50pn8) < 0))
    {
        volatile int64_t j_gzdn22af = ((j_mbs50pn8 * 92) + 744);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return (j_t2hghb9f((j_zjsufqwi - 1)) + j_t2hghb9f((j_zjsufqwi - 2)));
    static volatile int64_t j_2ct6q877 = 69910;
    if ((((j_2ct6q877 * j_2ct6q877) + j_2ct6q877) < 0))
    {
        volatile int64_t j_f1hbv9t4 = ((j_2ct6q877 * 28) + 910);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_v19rzg9k = 60293;
    static volatile int64_t j_kwyqhptu = 66990;
    if ((((j_kwyqhptu * j_kwyqhptu) + j_kwyqhptu) < 0))
    {
        volatile int64_t j_v0z664x0 = ((j_kwyqhptu * 92) + 990);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_v19rzg9k * j_v19rzg9k) + j_v19rzg9k) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

static int32_t j_oiwo6t0n(int32_t j_zjsufqwi)
{
    if ((j_zjsufqwi <= 1))
    {
        return 1;
    }
    static volatile int64_t j_27a2qis4 = 95933;
    if ((((j_27a2qis4 * j_27a2qis4) + j_27a2qis4) >= 0))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_zhoekmdo = 43089;
    if ((((j_zhoekmdo * (j_zhoekmdo + 1)) % 2) == 1))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_wkye35n7 = 68258;
    if ((((j_wkye35n7 * j_wkye35n7) + j_wkye35n7) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return (j_zjsufqwi * j_oiwo6t0n((j_zjsufqwi - 1)));
    static volatile int64_t j_vyo8ezrt = 13878;
    if ((((j_vyo8ezrt * j_vyo8ezrt) + j_vyo8ezrt) < 0))
    {
        volatile int64_t j_nywn77f5 = ((j_vyo8ezrt * 50) + 878);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

static int32_t j_vls2wrj8(int32_t j_m2p7e3pa, int32_t j_doqql8pa)
{
    static volatile int64_t j_00zpd4o1 = 60058;
    if ((((j_00zpd4o1 * j_00zpd4o1) + j_00zpd4o1) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((j_doqql8pa == 0))
    {
        return j_m2p7e3pa;
    }
    return j_vls2wrj8(j_doqql8pa, (j_m2p7e3pa % j_doqql8pa));
    static volatile int64_t j_46wox3cs = 58868;
    if ((((j_46wox3cs * j_46wox3cs) + j_46wox3cs) < 0))
    {
        volatile int64_t j_7yom7oru = ((j_46wox3cs * 84) + 868);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

static bool j_t8lvogp4(int32_t j_zjsufqwi)
{
    if ((j_zjsufqwi < 2))
    {
        return false;
    }
    static volatile int64_t j_c4i39azk = 29760;
    if ((((j_c4i39azk * j_c4i39azk) + j_c4i39azk) < 0))
    {
        volatile int64_t j_tr73225m = ((j_c4i39azk * 14) + 760);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_6lcv1ym4 = 78791;
    if ((((j_6lcv1ym4 * j_6lcv1ym4) % 4) == 3))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    int32_t j_qb8n9rkr = 2;
    static volatile int64_t j_s1u5c2bw = 66185;
    if ((((j_s1u5c2bw * j_s1u5c2bw) + j_s1u5c2bw) < 0))
    {
        volatile int64_t j_eexnkan3 = ((j_s1u5c2bw * 21) + 185);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    while (((j_qb8n9rkr * j_qb8n9rkr) <= j_zjsufqwi))
    {
        if (((j_zjsufqwi % j_qb8n9rkr) == 0))
        {
            return false;
        }
        j_qb8n9rkr = (j_qb8n9rkr + 1);
    }
    return true;
    return 0;
}

static int32_t j_vxxehlw0(int32_t j_zjsufqwi)
{
    int32_t j_r3lyvytq = 0;
    int32_t j_qv6uminn = j_zjsufqwi;
    static volatile int64_t j_2c53ign6 = 88627;
    if ((((j_2c53ign6 * j_2c53ign6) + j_2c53ign6) < 0))
    {
        volatile int64_t j_9kqju9v1 = ((j_2c53ign6 * 6) + 627);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_0dnkds5g = 39808;
    if ((((j_0dnkds5g * j_0dnkds5g) + j_0dnkds5g) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    while ((j_qv6uminn != 1))
    {
        if (((j_qv6uminn % 2) == 0))
        {
            j_qv6uminn = (j_qv6uminn / 2);
        }
        else
        {
            j_qv6uminn = ((j_qv6uminn * 3) + 1);
        }
        j_r3lyvytq = (j_r3lyvytq + 1);
    }
    static volatile int64_t j_6t4eaaox = 63932;
    if ((((j_6t4eaaox * j_6t4eaaox) + j_6t4eaaox) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_f8wwr90p = 94477;
    if ((((j_f8wwr90p * (j_f8wwr90p + 1)) % 2) == 1))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_andim2q7 = 91934;
    static volatile int64_t j_ybligual = 93141;
    if ((((j_ybligual * j_ybligual) + j_ybligual) < 0))
    {
        volatile int64_t j_r5oqef5n = ((j_ybligual * 34) + 141);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_andim2q7 * j_andim2q7) + j_andim2q7) < 0))
    {
        volatile int64_t j_2561o13g = ((j_andim2q7 * 83) + 934);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return j_r3lyvytq;
    return 0;
}

static int32_t j_m3tuz7o1(int32_t j_zjsufqwi)
{
    int32_t j_45k0m0xl = 0;
    int32_t j_3p7qt3hh = j_zjsufqwi;
    while ((j_3p7qt3hh > 0))
    {
        j_45k0m0xl = (j_45k0m0xl + (j_3p7qt3hh % 10));
        j_3p7qt3hh = (j_3p7qt3hh / 10);
    }
    static volatile int64_t j_ey467ne8 = 46539;
    if ((((j_ey467ne8 * j_ey467ne8) + j_ey467ne8) < 0))
    {
        volatile int64_t j_eymlwma1 = ((j_ey467ne8 * 73) + 539);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_5tphmacs = 49744;
    if ((((j_5tphmacs * j_5tphmacs) + j_5tphmacs) < 0))
    {
        volatile int64_t j_8o5fuudq = ((j_5tphmacs * 15) + 744);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return j_45k0m0xl;
    static volatile int64_t j_qana0zdj = 73005;
    if ((((j_qana0zdj * (j_qana0zdj + 1)) % 2) == 0))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

static int32_t j_dwwcl9v0(int32_t j_zjsufqwi)
{
    if ((j_zjsufqwi < 0))
    {
        return -(j_dwwcl9v0(-(j_zjsufqwi)));
    }
    static volatile int64_t j_htb3rgly = 19893;
    static volatile int64_t j_81x1jf3y = 60298;
    if ((((j_81x1jf3y * j_81x1jf3y) + j_81x1jf3y) < 0))
    {
        volatile int64_t j_qumacpti = ((j_81x1jf3y * 80) + 298);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_htb3rgly * j_htb3rgly) + j_htb3rgly) < 0))
    {
        volatile int64_t j_7n3fh0c0 = ((j_htb3rgly * 16) + 893);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    int32_t j_qwk265v2 = 0;
    int32_t j_3p7qt3hh = j_zjsufqwi;
    while ((j_3p7qt3hh > 0))
    {
        j_qwk265v2 = ((j_qwk265v2 * 10) + (j_3p7qt3hh % 10));
        j_3p7qt3hh = (j_3p7qt3hh / 10);
    }
    static volatile int64_t j_jhb16brr = 87191;
    if ((((j_jhb16brr * j_jhb16brr) + j_jhb16brr) < 0))
    {
        volatile int64_t j_kpt5jy74 = ((j_jhb16brr * 51) + 191);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_je3bxu1e = 89334;
    static volatile int64_t j_l17cumr5 = 95604;
    if ((((j_l17cumr5 * j_l17cumr5) + j_l17cumr5) < 0))
    {
        volatile int64_t j_vl90z625 = ((j_l17cumr5 * 3) + 604);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_je3bxu1e * j_je3bxu1e) % 4) < 2))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return j_qwk265v2;
    return 0;
}

static int32_t j_u1jd8trj(int32_t j_gcfgd3i4, int32_t j_eu3wz7tw)
{
    int32_t j_yackb9o9 = 1;
    int32_t j_qb8n9rkr = 0;
    static volatile int64_t j_obdh3w0k = 42410;
    if ((((j_obdh3w0k * j_obdh3w0k) + j_obdh3w0k) < 0))
    {
        volatile int64_t j_mt0qotjl = ((j_obdh3w0k * 68) + 410);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    while ((j_qb8n9rkr < j_eu3wz7tw))
    {
        j_yackb9o9 = (j_yackb9o9 * j_gcfgd3i4);
        j_qb8n9rkr = (j_qb8n9rkr + 1);
    }
    return j_yackb9o9;
    static volatile int64_t j_051xehyu = 18008;
    if ((((j_051xehyu * j_051xehyu) + j_051xehyu) < 0))
    {
        volatile int64_t j_pcrwneap = ((j_051xehyu * 72) + 8);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_1mi6kv9r = 80177;
    if ((((j_1mi6kv9r * j_1mi6kv9r) + j_1mi6kv9r) >= 0))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_lqdsll6a = 14539;
    if ((((j_lqdsll6a * j_lqdsll6a) + j_lqdsll6a) < 0))
    {
        volatile int64_t j_lhwxqj9r = ((j_lqdsll6a * 25) + 539);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_an62svr9 = 91683;
    if ((((j_an62svr9 * j_an62svr9) + j_an62svr9) < 0))
    {
        volatile int64_t j_x7von3v7 = ((j_an62svr9 * 3) + 683);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

static int32_t j_w6mesi0m(int32_t j_m2p7e3pa, int32_t j_doqql8pa, int32_t j_l052rhh3)
{
    static volatile int64_t j_l68dw28g = 45636;
    static volatile int64_t j_hoslr0at = 72996;
    if ((((j_hoslr0at * j_hoslr0at) + j_hoslr0at) < 0))
    {
        volatile int64_t j_jbb11t8c = ((j_hoslr0at * 21) + 996);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_l68dw28g * j_l68dw28g) % 4) < 2))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if (((j_m2p7e3pa >= j_doqql8pa) && (j_m2p7e3pa >= j_l052rhh3)))
    {
        return j_m2p7e3pa;
    }
    static volatile int64_t j_mhn3wxje = 47523;
    if ((((j_mhn3wxje * j_mhn3wxje) + j_mhn3wxje) < 0))
    {
        volatile int64_t j_3cdvb16f = ((j_mhn3wxje * 58) + 523);
        (void)printf("%s\n", 0 ? "true" : "false");
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
    static volatile int64_t j_n8l8nii7 = 13668;
    if ((((j_n8l8nii7 * j_n8l8nii7) + j_n8l8nii7) < 0))
    {
        volatile int64_t j_9q46v2mt = ((j_n8l8nii7 * 18) + 668);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_ddji0doq = 65474;
    static volatile int64_t j_y3ncgfwg = 46563;
    if ((((j_y3ncgfwg * (j_y3ncgfwg + 1)) % 2) == 0))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_ddji0doq * j_ddji0doq) + j_ddji0doq) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
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
    static volatile int64_t j_vo7u5hag = 91276;
    if ((((j_vo7u5hag * j_vo7u5hag) + j_vo7u5hag) < 0))
    {
        volatile int64_t j_7gvi8asa = ((j_vo7u5hag * 69) + 276);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

static bool j_dk9e63to(int32_t j_zjsufqwi)
{
    return (j_zjsufqwi == j_dwwcl9v0(j_zjsufqwi));
    static volatile int64_t j_2166sej3 = 52051;
    if ((((j_2166sej3 * (j_2166sej3 + 1)) % 2) == 0))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_07ikarzd = 61770;
    static volatile int64_t j_g6d1yvyy = 52186;
    if ((((j_g6d1yvyy * j_g6d1yvyy) + j_g6d1yvyy) < 0))
    {
        volatile int64_t j_vemeoo7a = ((j_g6d1yvyy * 6) + 186);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_07ikarzd * j_07ikarzd) + j_07ikarzd) >= 0))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_iw1z5vc6 = 33019;
    if ((((j_iw1z5vc6 * j_iw1z5vc6) + j_iw1z5vc6) >= 0))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

int32_t main(void)
{
    (void)printf("%s\n", "== fibonacci (iterative) ==");
    static volatile int64_t j_lrm1gehh = 81491;
    if ((((j_lrm1gehh * j_lrm1gehh) + j_lrm1gehh) < 0))
    {
        volatile int64_t j_vgpverpo = ((j_lrm1gehh * 27) + 491);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    (void)printf("%d\n", j_4f7g6fui(0));
    (void)printf("%d\n", j_4f7g6fui(1));
    static volatile int64_t j_uztk75r5 = 86933;
    if ((((j_uztk75r5 * (j_uztk75r5 + 1)) % 2) == 1))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
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
    for (int32_t j_qb8n9rkr = 2; (j_qb8n9rkr <= 30); j_qb8n9rkr = (j_qb8n9rkr + 1))
    {
        if (j_t8lvogp4(j_qb8n9rkr))
        {
            (void)printf("%d\n", j_qb8n9rkr);
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
