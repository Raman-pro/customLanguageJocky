#!/usr/bin/env bash
# Extended obfuscation test runner (LLVM backend).
# Builds every test script at every obfuscation level with a fixed seed and
# verifies output still matches the *.expect files. Forensics gets a
# structural check (must contain the JSON artifacts and "done").
set -u
cd "$(dirname "$0")/.."
JOCKY=./build/jocky
pass=0; fail=0

for lvl in 0 1 2 3; do
    for src in scripts/test_*.rd scripts/demo.rd; do
        exp="${src%.rd}.expect"
        [ -f "$exp" ] || continue
        if ! $JOCKY --seed 424242 --obf-level "$lvl" --build "$src" >/dev/null 2>&1; then
            echo "FAIL(build) lvl=$lvl $src"; fail=$((fail+1)); continue
        fi
        bin="${src%.rd}"
        got="$("$bin")"
        want="$(cat "$exp")"
        if [ "$got" = "$want" ]; then
            echo "PASS lvl=$lvl $src"; pass=$((pass+1))
        else
            echo "FAIL lvl=$lvl $src"
            echo "  expected: $(echo "$want" | head -1)"
            echo "  got:      $(echo "$got" | head -1)"
            fail=$((fail+1))
        fi
    done
done

# forensics structural checks at every level
for lvl in 0 1 2 3; do
    if ! $JOCKY --seed 424242 --obf-level "$lvl" --build scripts/forensics.rd >/dev/null 2>&1; then
        echo "FAIL(build forensics) lvl=$lvl"; fail=$((fail+1)); continue
    fi
    out="$(./scripts/forensics 2>&1)"
    ok=1
    echo "$out" | grep -q "=== SYSTEM ===" || { echo "missing SYSTEM @lvl$lvl"; ok=0; }
    echo "$out" | grep -q "=== PROCESSES (JSON) ===" || { echo "missing PROCESSES @lvl$lvl"; ok=0; }
    echo "$out" | grep -q "=== FS /tmp (JSON) ===" || { echo "missing FS @lvl$lvl"; ok=0; }
    echo "$out" | grep -q "hello from jocky" || { echo "missing fs.write/read roundtrip @lvl$lvl"; ok=0; }
    echo "$out" | grep -q "done" || { echo "missing done @lvl$lvl"; ok=0; }
    if [ "$ok" -eq 1 ]; then
        echo "PASS forensics lvl=$lvl"; pass=$((pass+1))
    else
        fail=$((fail+1))
    fi
done

echo "---"
echo "pass=$pass fail=$fail"
[ "$fail" -eq 0 ]