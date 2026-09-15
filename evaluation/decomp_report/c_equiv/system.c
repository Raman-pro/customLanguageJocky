// system.c — hand-written C equivalent of scripts/system.jk
// The forensic stdlib tour, implemented directly with OS APIs.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#if defined(__APPLE__)
#include <libproc.h>
#endif

static char g_buf[65536];

static void json_escape(char* out, size_t cap, const char* in) {
    size_t o = 0;
    for (const char* p = in; *p && o + 2 < cap; ++p) {
        if (*p == '"' || *p == '\\') out[o++] = '\\';
        out[o++] = *p;
    }
    out[o] = '\0';
}

static const char* now_str(void) {
    time_t t = time(NULL);
    struct tm tmv;
    localtime_r(&t, &tmv);
    strftime(g_buf, sizeof g_buf, "%Y-%m-%dT%H:%M:%S", &tmv);
    return g_buf;
}

static void sleep_ms(int ms) {
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (long)(ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}

static const char* process_list(void) {
    size_t off = 0;
    g_buf[off++] = '[';
    int first = 1;
#if defined(__APPLE__)
    int all_pids[8192];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = 0; i < np; ++i) {
        int pid = all_pids[i];
        char name[256];
        int len = proc_name(pid, name, sizeof name);
        if (len <= 0) snprintf(name, sizeof name, "pid_%d", pid);
        char esc[512];
        json_escape(esc, sizeof esc, name);
        if (!first) g_buf[off++] = ',';
        first = 0;
        int n = snprintf(g_buf + off, sizeof g_buf - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
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
                char esc[512];
                json_escape(esc, sizeof esc, name);
                if (!first) g_buf[off++] = ',';
                first = 0;
                int n = snprintf(g_buf + off, sizeof g_buf - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        closedir(d);
    }
#endif
    g_buf[off++] = ']';
    g_buf[off] = '\0';
    return g_buf;
}

static const char* sockets(void) {
    size_t off = 0;
    g_buf[off++] = '[';
    int first = 1;
    FILE* ns = popen("netstat -an -p tcp 2>/dev/null", "r");
    if (ns) {
        char line[512];
        while (fgets(line, sizeof line, ns)) {
            char proto[8], laddr[64], raddr[64], st[32];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == 4) {
                if (strncmp(proto, "tcp", 3) != 0) continue;
                if (!first) g_buf[off++] = ',';
                first = 0;
                int n = snprintf(g_buf + off, sizeof g_buf - off,
                                 "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        pclose(ns);
    }
    g_buf[off++] = ']';
    g_buf[off] = '\0';
    return g_buf;
}

static const char* fs_list(const char* dir) {
    size_t off = 0;
    g_buf[off++] = '[';
    int first = 1;
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] == '.') continue;
            if (!first) g_buf[off++] = ',';
            first = 0;
            char esc[1024];
            json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(g_buf + off, sizeof g_buf - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : 0);
        }
        closedir(d);
    }
    g_buf[off++] = ']';
    g_buf[off] = '\0';
    return g_buf;
}

int main(void) {
    printf("== sys.now() ==\n");
    printf("%s\n", now_str());

    printf("== sys.cwd() ==\n");
    char cwd[4096];
    printf("%s\n", getcwd(cwd, sizeof cwd));

    printf("== env.get() ==\n");
    const char* u = getenv("USER");
    printf("%s\n", u ? u : "");
    const char* x = getenv("NOT_A_REAL_VAR");
    printf("%s\n", x ? x : "");

    printf("== sys.sleep() ==\n");
    sleep_ms(200);
    printf("slept 200ms\n");

    printf("== sys.process_list() ==\n");
    printf("%s\n", process_list());

    printf("== net.sockets() ==\n");
    printf("%s\n", sockets());

    printf("== fs.write / fs.read ==\n");
    FILE* f = fopen("/tmp/jocky_system_tour.txt", "wb");
    if (f) { fputs("hello from system tour\n", f); fclose(f); }
    f = fopen("/tmp/jocky_system_tour.txt", "rb");
    if (f) {
        size_t n = fread(g_buf, 1, sizeof g_buf - 1, f);
        fclose(f);
        g_buf[n] = '\0';
        printf("%s\n", g_buf);
    }

    printf("== fs.exists ==\n");
    struct stat st;
    printf("%s\n", stat("/tmp/jocky_system_tour.txt", &st) == 0 ? "true" : "false");
    printf("%s\n", stat("/no/such/path", &st) == 0 ? "true" : "false");

    printf("== fs.list ==\n");
    printf("%s\n", fs_list("/tmp"));

    printf("== reg.list (Windows only) ==\n");
    printf("[]\n");

    printf("== mem.dump (Windows only) ==\n");
    printf("done\n");
    return 0;
}