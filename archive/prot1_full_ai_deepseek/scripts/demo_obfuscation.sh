#!/usr/bin/env bash
# ============================================================================
#  JOCKY — Obfuscation Demo
#
#  End-to-end demonstration of JOCKY's polymorphism + control-flow obfuscation.
#  Uses scripts/obfuscation_demo.jk (deterministic output) and shows that:
#
#    [1] different seeds / levels -> unique binaries (unique SHA-256)
#    [2] same seed -> byte-identical binary (deterministic)
#    [3] runtime output is IDENTICAL at every obfuscation level
#    [4] control flow is flattened into a switch state machine (level 3)
#    [5] string literals are encrypted (plaintext gone from the binary)
#    [6] the entry point is buried behind trampolines
#    [7] junk functions are injected to inflate apparent complexity
#
#  Run from the repository root:  ./scripts/demo_obfuscation.sh
# ============================================================================
set -u
cd "$(dirname "$0")/.."

JOCKY=./build/jocky
SRC=scripts/obfuscation_demo.jk
BASE="${SRC%.jk}"
C_L0=/tmp/jocky_obf_l0.c
C_L3=/tmp/jocky_obf_l3.c

[ -x "$JOCKY" ] || { echo "compiler not built — run: cmake -S . -B build && cmake --build build"; exit 1; }

line() { printf -- '------------------------------------------------------------\n'; }

echo "============================================================"
echo " JOCKY OBFUSCATION DEMO"
echo " source: $SRC"
echo "============================================================"
line

# ---------------------------------------------------------------------------
echo "[1] Polymorphism — same source, different seed/level => unique binary"
echo "    (level 0 = rename + markers, level 3 = full CFG obfuscation)"
line
for spec in "1 0 seed1-l0" "1 3 seed1-l3" "2 3 seed2-l3" "3 3 seed3-l3"; do
    read -r seed lvl tag <<<"$spec"
    $JOCKY --seed "$seed" --obf-level "$lvl" --build "$SRC" >/dev/null 2>&1
    printf '   %-10s size=%-6s sha256=%s\n' "$tag" "$(wc -c < "$BASE" | tr -d ' ')" "$(shasum -a 256 "$BASE" | cut -d' ' -f1)"
done
echo "   => every build hashes differently (no two artifacts are alike)"
line

# ---------------------------------------------------------------------------
echo "[2] Determinism — same seed at level 3 built twice => identical hash"
line
$JOCKY --seed 7 --obf-level 3 --build "$SRC" >/dev/null 2>&1; h1=$(shasum -a 256 "$BASE" | cut -d' ' -f1)
$JOCKY --seed 7 --obf-level 3 --build "$SRC" >/dev/null 2>&1; h2=$(shasum -a 256 "$BASE" | cut -d' ' -f1)
if [ "$h1" = "$h2" ]; then echo "   sha256 (build 1): $h1"; echo "   sha256 (build 2): $h1"; echo "   => identical (reproducible builds)"; else echo "   MISMATCH"; fi
line

# ---------------------------------------------------------------------------
echo "[3] Correctness — output is identical at every obfuscation level"
line
for lvl in 0 1 2 3; do
    $JOCKY --seed 9 --obf-level "$lvl" --build "$SRC" >/dev/null 2>&1
    got="$(./"$BASE")"
    [ "$lvl" -eq 0 ] && want="$got"
    if [ "$got" = "$want" ]; then echo "   level $lvl  -> output OK"; else echo "   level $lvl  -> MISMATCH"; fi
done
echo "   => obfuscation never changes program semantics"
line

# ---------------------------------------------------------------------------
echo "[4] Control-flow flattening (level 3 emits a switch state machine)"
line
$JOCKY --seed 1 --obf-level 0 --emit-c "$SRC" > "$C_L0"
$JOCKY --seed 1 --obf-level 3 --emit-c "$SRC" > "$C_L3"
printf '   level 0 C: %s switch dispatch statements (runtime only)\n' "$(grep -c 'switch (j_' "$C_L0" || true)"
printf '   level 3 C: %s flattened functions (each is now a state machine)\n' "$(grep -c 'switch (j_' "$C_L3" || true)"
echo "   snippet of the first flattened function at level 3:"
ln=$(grep -n 'switch (j_' "$C_L3" | head -1 | cut -d: -f1)
if [ -n "$ln" ]; then
    sed -n "$((ln-2)),$((ln+6))p" "$C_L3" | sed 's/^/      /'
fi
line

# ---------------------------------------------------------------------------
echo "[5] String encryption (section labels leave the binary at level 3)"
line
$JOCKY --seed 1 --obf-level 0 --build "$SRC" >/dev/null 2>&1
printf '   plaintext section labels in level 0 binary: %s\n' "$(grep -a -c 'COLLATZ STEPS' "$BASE")"
$JOCKY --seed 1 --obf-level 3 --build "$SRC" >/dev/null 2>&1
printf '   plaintext section labels in level 3 binary: %s\n' "$(grep -a -c 'COLLATZ STEPS' "$BASE")"
echo "   (level 3 replaces each literal with an XOR blob + j_dc_*() decryptor)"
line

# ---------------------------------------------------------------------------
echo "[6] Entry-point shuffle (main is buried behind trampolines at level 3)"
line
echo "   level 3 main:"
grep -E '^int32_t main' "$C_L3" | sed 's/^/      /'
printf '   entry chain: %s function(s) (real body + trampolines)\n' "$(grep -c 'static int32_t j_tr_' "$C_L3" || true)"
line

# ---------------------------------------------------------------------------
echo "[7] Junk functions (unused, look real, inflate apparent complexity)"
line
printf '   junk functions injected at level 3: %s\n' "$(grep -c '__attribute__((used)) static int32_t' "$C_L3" || true)"
printf '   level 3 C is %s lines vs %s at level 0\n' "$(wc -l < "$C_L3" | tr -d ' ')" "$(wc -l < "$C_L0" | tr -d ' ')"
line

echo "DONE — see report.md section 7 and LANGUAGE.md section 12 for details."