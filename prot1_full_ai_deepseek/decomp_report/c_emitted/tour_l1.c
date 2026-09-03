// JOCKY build 6C17147E0965930B seed=12345 date=2026-09-03 05:00:00
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
    static volatile int64_t j_e63tox7h = 4121;
    if ((((j_e63tox7h * (j_e63tox7h + 1)) % 2) == 1))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return (j_zjsufqwi * 2);
    static volatile int64_t j_gmqpdmt0 = 2944;
    static volatile int64_t j_c8jewur5 = 68996;
    static volatile int64_t j_468tmzoa = 12415;
    static volatile int64_t j_qo32bb5q = 96421;
    if ((((j_qo32bb5q * j_qo32bb5q) + j_qo32bb5q) < 0))
    {
        volatile int64_t j_ifxsxp8l = ((j_qo32bb5q * 51) + 421);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_468tmzoa * j_468tmzoa) + j_468tmzoa) < 0))
    {
        volatile int64_t j_l9dl9lcd = ((j_468tmzoa * 60) + 415);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_c8jewur5 * j_c8jewur5) + j_c8jewur5) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_7m5fgot7 = 28527;
    if ((((j_7m5fgot7 * j_7m5fgot7) + j_7m5fgot7) < 0))
    {
        volatile int64_t j_yn30xwb1 = ((j_7m5fgot7 * 79) + 527);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_kiietxma = 1103;
    if ((((j_kiietxma * j_kiietxma) + j_kiietxma) < 0))
    {
        volatile int64_t j_v3huvf2v = ((j_kiietxma * 3) + 103);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_gmqpdmt0 * j_gmqpdmt0) % 4) < 2))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

static int32_t j_t2hghb9f(int32_t j_oiwo6t0n, int32_t j_vls2wrj8)
{
    static volatile int64_t j_qb8n9rkr = 60293;
    static volatile int64_t j_fy0gpnl9 = 69910;
    static volatile int64_t j_c1wchsa4 = 12744;
    if ((((j_c1wchsa4 * j_c1wchsa4) + j_c1wchsa4) < 0))
    {
        volatile int64_t j_lyd9q6x2 = ((j_c1wchsa4 * 92) + 744);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_fy0gpnl9 * j_fy0gpnl9) + j_fy0gpnl9) < 0))
    {
        volatile int64_t j_xsop1o4p = ((j_fy0gpnl9 * 28) + 910);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_ney0af9f = 51868;
    if ((((j_ney0af9f * j_ney0af9f) + j_ney0af9f) < 0))
    {
        volatile int64_t j_dj8cfjgn = ((j_ney0af9f * 66) + 868);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_mbs50pn8 = 66990;
    if ((((j_mbs50pn8 * j_mbs50pn8) + j_mbs50pn8) < 0))
    {
        volatile int64_t j_gzdn22af = ((j_mbs50pn8 * 92) + 990);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_qb8n9rkr * j_qb8n9rkr) + j_qb8n9rkr) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return (j_oiwo6t0n + j_vls2wrj8);
    return 0;
}

static void j_m2p7e3pa(const char* j_doqql8pa)
{
    (void)printf("%s\n", j_doqql8pa);
    static volatile int64_t j_2ct6q877 = 95933;
    if ((((j_2ct6q877 * j_2ct6q877) + j_2ct6q877) >= 0))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_f1hbv9t4 = 68258;
    static volatile int64_t j_v19rzg9k = 43089;
    if ((((j_v19rzg9k * (j_v19rzg9k + 1)) % 2) == 1))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_kwyqhptu = 13878;
    if ((((j_kwyqhptu * j_kwyqhptu) + j_kwyqhptu) < 0))
    {
        volatile int64_t j_v0z664x0 = ((j_kwyqhptu * 50) + 878);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_f1hbv9t4 * j_f1hbv9t4) + j_f1hbv9t4) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
}

static int32_t j_t8lvogp4(int32_t j_vxxehlw0)
{
    static volatile int64_t j_27a2qis4 = 60058;
    if ((((j_27a2qis4 * j_27a2qis4) + j_27a2qis4) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((j_vxxehlw0 <= 1))
    {
        return 1;
    }
    return (j_vxxehlw0 * j_t8lvogp4((j_vxxehlw0 - 1)));
    static volatile int64_t j_zhoekmdo = 58868;
    if ((((j_zhoekmdo * j_zhoekmdo) + j_zhoekmdo) < 0))
    {
        volatile int64_t j_wkye35n7 = ((j_zhoekmdo * 84) + 868);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

static int32_t j_m3tuz7o1(int32_t j_vxxehlw0)
{
    static volatile int64_t j_vyo8ezrt = 66185;
    if ((((j_vyo8ezrt * j_vyo8ezrt) + j_vyo8ezrt) < 0))
    {
        volatile int64_t j_nywn77f5 = ((j_vyo8ezrt * 21) + 185);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_00zpd4o1 = 78791;
    if ((((j_00zpd4o1 * j_00zpd4o1) % 4) == 3))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_46wox3cs = 29760;
    if ((((j_46wox3cs * j_46wox3cs) + j_46wox3cs) < 0))
    {
        volatile int64_t j_7yom7oru = ((j_46wox3cs * 14) + 760);
        (void)printf("%s\n", 0 ? "true" : "false");
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
    if ((j_vxxehlw0 == 0))
    {
        return true;
    }
    return j_u1jd8trj((j_vxxehlw0 - 1));
    static volatile int64_t j_c4i39azk = 39808;
    static volatile int64_t j_tr73225m = 91934;
    if ((((j_tr73225m * j_tr73225m) + j_tr73225m) < 0))
    {
        volatile int64_t j_6lcv1ym4 = ((j_tr73225m * 83) + 934);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_c4i39azk * j_c4i39azk) + j_c4i39azk) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_s1u5c2bw = 94477;
    static volatile int64_t j_eexnkan3 = 93141;
    if ((((j_eexnkan3 * j_eexnkan3) + j_eexnkan3) < 0))
    {
        volatile int64_t j_r3lyvytq = ((j_eexnkan3 * 34) + 141);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_s1u5c2bw * (j_s1u5c2bw + 1)) % 2) == 1))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_qv6uminn = 88627;
    if ((((j_qv6uminn * j_qv6uminn) + j_qv6uminn) < 0))
    {
        volatile int64_t j_2c53ign6 = ((j_qv6uminn * 6) + 627);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_9kqju9v1 = 63932;
    if ((((j_9kqju9v1 * j_9kqju9v1) + j_9kqju9v1) < 0))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

static bool j_u1jd8trj(int32_t j_vxxehlw0)
{
    static volatile int64_t j_0dnkds5g = 46539;
    if ((((j_0dnkds5g * j_0dnkds5g) + j_0dnkds5g) < 0))
    {
        volatile int64_t j_6t4eaaox = ((j_0dnkds5g * 73) + 539);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_f8wwr90p = 73005;
    if ((((j_f8wwr90p * (j_f8wwr90p + 1)) % 2) == 0))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((j_vxxehlw0 == 0))
    {
        return false;
    }
    return j_dwwcl9v0((j_vxxehlw0 - 1));
    static volatile int64_t j_andim2q7 = 49744;
    if ((((j_andim2q7 * j_andim2q7) + j_andim2q7) < 0))
    {
        volatile int64_t j_ybligual = ((j_andim2q7 * 15) + 744);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

static const char* j_gcfgd3i4(const char* j_eu3wz7tw, int32_t j_w6mesi0m)
{
    if ((j_w6mesi0m >= 18))
    {
        return "adult";
    }
    static volatile int64_t j_r5oqef5n = 89334;
    if ((((j_r5oqef5n * j_r5oqef5n) % 4) < 2))
    {
    }
    else
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return "minor";
    static volatile int64_t j_2561o13g = 19893;
    if ((((j_2561o13g * j_2561o13g) + j_2561o13g) < 0))
    {
        volatile int64_t j_45k0m0xl = ((j_2561o13g * 16) + 893);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_3p7qt3hh = 87191;
    if ((((j_3p7qt3hh * j_3p7qt3hh) + j_3p7qt3hh) < 0))
    {
        volatile int64_t j_ey467ne8 = ((j_3p7qt3hh * 51) + 191);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_eymlwma1 = 95604;
    if ((((j_eymlwma1 * j_eymlwma1) + j_eymlwma1) < 0))
    {
        volatile int64_t j_5tphmacs = ((j_eymlwma1 * 3) + 604);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    static volatile int64_t j_8o5fuudq = 60298;
    if ((((j_8o5fuudq * j_8o5fuudq) + j_8o5fuudq) < 0))
    {
        volatile int64_t j_qana0zdj = ((j_8o5fuudq * 80) + 298);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    return 0;
}

int32_t main(void)
{
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
    int32_t j_htb3rgly = 10;
    int32_t j_81x1jf3y = 20;
    (void)printf("%d\n", j_htb3rgly);
    (void)printf("%d\n", j_81x1jf3y);
    const char* j_doqql8pa = "jocky";
    bool j_qumacpti = true;
    (void)printf("%s\n", j_doqql8pa);
    (void)printf("%s\n", j_qumacpti ? "true" : "false");
    j_qumacpti = false;
    (void)printf("%s\n", j_qumacpti ? "true" : "false");
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
    const char* j_7n3fh0c0 = "JOCKY";
    static volatile int64_t j_qwk265v2 = 86933;
    static volatile int64_t j_jhb16brr = 81491;
    if ((((j_jhb16brr * j_jhb16brr) + j_jhb16brr) < 0))
    {
        volatile int64_t j_kpt5jy74 = ((j_jhb16brr * 27) + 491);
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    if ((((j_qwk265v2 * (j_qwk265v2 + 1)) % 2) == 1))
    {
        (void)printf("%s\n", 0 ? "true" : "false");
    }
    (void)printf("%d\n", j_str_len(j_7n3fh0c0));
    (void)printf("%d\n", j_str_len(""));
    (void)printf("%s\n", j_str_eq(j_7n3fh0c0, "JOCKY") ? "true" : "false");
    (void)printf("%s\n", j_str_eq(j_7n3fh0c0, "jocky") ? "true" : "false");
    (void)printf("%s\n", !j_str_eq(j_7n3fh0c0, "JOCKY") ? "true" : "false");
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
    int32_t j_je3bxu1e = 0;
    while ((j_je3bxu1e < 3))
    {
        (void)printf("%d\n", j_je3bxu1e);
        j_je3bxu1e = (j_je3bxu1e + 1);
    }
    (void)printf("%s\n", "== for ==");
    for (int32_t j_l17cumr5 = 0; (j_l17cumr5 < 4); j_l17cumr5 = (j_l17cumr5 + 1))
    {
        (void)printf("%d\n", j_l17cumr5);
    }
    (void)printf("%s\n", "== assignment ==");
    int32_t j_zjsufqwi = 0;
    int32_t j_vl90z625 = j_zjsufqwi = 5;
    (void)printf("%d\n", j_zjsufqwi);
    (void)printf("%d\n", j_vl90z625);
    (void)printf("%s\n", "== shadowing ==");
    int32_t j_yackb9o9 = 1;
    if (true)
    {
        int32_t j_yackb9o9 = 2;
        (void)printf("%d\n", j_yackb9o9);
    }
    (void)printf("%d\n", j_yackb9o9);
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
