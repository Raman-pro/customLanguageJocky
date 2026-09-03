#!/usr/bin/env bash
# decomp_report/build.sh
# Builds every JOCKY test at obf-levels 0..3 (fixed seed) and every hand-written
# C equivalent, records hashes/sizes/entropy/strings/symbols, and keeps the
# emitted C for reference.
set -u
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DR="$ROOT/decomp_report"
JOCKY="$ROOT/build/jocky"
SCRIPTS="$ROOT/scripts"
BUILDS="$DR/builds"
METRICS="$DR/metrics"
EMIT="$DR/c_emitted"
mkdir -p "$BUILDS" "$METRICS" "$EMIT"
SEED=12345

# ---------- build JOCKY artifacts ----------
for name in tour algorithms demo obfuscation_demo forensics system; do
    src="$SCRIPTS/$name.jk"
    [ -f "$src" ] || continue
    for lvl in 0 1 2 3; do
        if ! "$JOCKY" --seed "$SEED" --obf-level "$lvl" --emit-c "$src" > "$EMIT/${name}_l${lvl}.c" 2>/dev/null; then
            echo "FAIL emit jk_${name}_l${lvl}"; continue
        fi
        if cc -O2 -o "$BUILDS/jk_${name}_l${lvl}" "$EMIT/${name}_l${lvl}.c" 2>/dev/null; then
            echo "built jk_${name}_l${lvl}"
        else
            echo "FAIL cc jk_${name}_l${lvl}"
        fi
    done
done

# ---------- build hand-written C equivalents ----------
for name in tour algorithms demo obfuscation_demo forensics system; do
    src="$DR/c_equiv/$name.c"
    [ -f "$src" ] || continue
    if cc -O2 -o "$BUILDS/c_${name}" "$src"; then
        echo "built c_${name}"
    else
        echo "FAIL cc c_${name}"
    fi
done

# ---------- metrics ----------
cd "$BUILDS"
{
    echo "# artifact sha256 size entropy exported_functions"
    for f in jk_* c_*; do
        [ -f "$f" ] || continue
        sha=$(shasum -a 256 "$f" | cut -d' ' -f1)
        size=$(stat -f%z "$f")
        ent=$(python3 - "$f" <<'PY'
import sys, math
data = open(sys.argv[1], 'rb').read()
freq = [0]*256
for b in data: freq[b] += 1
n = len(data)
ent = -sum(c/n * math.log2(c/n) for c in freq if c) if n else 0.0
print(f"{ent:.3f}")
PY
)
        fc=$(nm -g "$f" 2>/dev/null | grep -c ' T ' || echo 0)
        echo "$f $sha $size $ent $fc"
    done
} > "$METRICS/hashes.txt"
echo "====="
cat "$METRICS/hashes.txt"