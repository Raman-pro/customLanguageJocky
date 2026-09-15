#!/usr/bin/env python3
"""Extract CFG metrics from Ghidra decompilation outputs in decomp/."""
import glob, re, os, sys

base = os.path.join(os.path.dirname(os.path.abspath(__file__)), "decomp")
libc = {
    "_printf","_puts","_strlen","_strcmp","_exit","_atexit","_snprintf",
    "_strncmp","_memset","_memcpy","_malloc","_free","_system","_popen",
    "_pclose","_fopen","_fread","_fclose","_fputs","_getcwd","_getenv",
    "_opendir","_readdir","_closedir","_access","_time","_localtime_r",
    "_strftime","_nanosleep","_stat","_proc_listallpids","_proc_name",
    "_getpid","_sprintf","_pthread_once","_objc_autoreleasePoolPush",
    "_objc_autoreleasePoolPop","_fflush","_fgets","_sscanf","_getpid",
}

rows = []
for f in sorted(glob.glob(base + "/jk_*.c") + glob.glob(base + "/c_*.c")):
    txt = open(f).read()
    funcs = re.findall(r"FUNCTION (\S+) @ (0x[0-9a-f]+) size=(\d+)", txt)
    entry = next((fn for fn in funcs if fn[0] in ("entry", "main")), None)
    if not entry and funcs:
        entry = max(funcs, key=lambda fn: int(fn[2]))
    if not entry:
        continue
    m = re.search(
        r"FUNCTION " + re.escape(entry[0]) + r" @ \S+ size=\d+[^\n]*\nCFG blocks=(\d+) edges=(\d+)",
        txt,
    )
    blk = int(m.group(1)) if m else -1
    edg = int(m.group(2)) if m else -1
    # largest non-libc function (the real logic body when main is trampolined)
    big = None
    for fn in funcs:
        if fn[0] in libc or fn[0] == entry[0]:
            continue
        if big is None or int(fn[2]) > int(big[2]):
            big = fn
    bblk = bblk2 = -1
    if big:
        m2 = re.search(
            r"FUNCTION " + re.escape(big[0]) + r" @ \S+ size=\d+[^\n]*\nCFG blocks=(\d+) edges=(\d+)",
            txt,
        )
        if m2:
            bblk = int(m2.group(1))
            bblk2 = int(m2.group(2))
    nfun = len([x for x in funcs if x[0] not in libc])
    # count opaque-predicate-looking conditions in the whole file
    opaque = len(re.findall(r"[<>]=\s*0|\*[^)]*< 0|% 4|== 1U|0x8000000000000001", txt))
    # count switch-state-machine-style nesting in entry
    rows.append((os.path.basename(f), nfun, blk, edg, int(entry[2]), big[0] if big else "-", bblk, bblk2, opaque))

print(f"{'artifact':22} {'funcs':>5} {'entry':>3}/{'>'}{'edg':>4} {'bigfn':>4} {'big':>3}/{'>'}{'edg':>4} {'size':>6} {'opaque':>6}")
for r in rows:
    print(f"{r[0]:22} {r[1]:>5} {r[2]:>4} {r[3]:>4} {r[5]:>12} {r[6]:>4} {r[7]:>4} {r[4]:>6} {r[8]:>6}")

out = os.path.join(os.path.dirname(os.path.abspath(__file__)), "metrics", "cfg_metrics.txt")
with open(out, "w") as fh:
    fh.write(f"{'artifact':22} {'funcs':>5} {'entryblk':>7} {'entryedg':>7} {'bigfn':>12} {'bigblk':>6} {'bigedg':>6} {'entrysize':>9} {'opaque':>6}\n")
    for r in rows:
        fh.write(f"{r[0]:22} {r[1]:>5} {r[2]:>7} {r[3]:>7} {r[5]:>12} {r[6]:>6} {r[7]:>6} {r[4]:>9} {r[8]:>6}\n")
print("\nwrote " + out)