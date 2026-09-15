#!/usr/bin/env bash
# JOCKY test runner: compiles each *.jk in scripts/ against expected output
# stored next to it as *.expect, plus checks a few semantic-error programs.
set -u
cd "$(dirname "$0")/.."
JOCKY=./build/jocky
pass=0; fail=0

for src in scripts/test_*.jk scripts/demo.jk; do
    exp="${src%.jk}.expect"
    [ -f "$exp" ] || continue
    if ! $JOCKY --build "$src" >/dev/null 2>&1; then
        echo "FAIL(build) $src"; fail=$((fail+1)); continue
    fi
    bin="${src%.jk}"
    got="$("$bin")"
    want="$(cat "$exp")"
    if [ "$got" = "$want" ]; then
        echo "PASS $src"; pass=$((pass+1))
    else
        echo "FAIL $src"
        echo "  expected: $(echo "$want" | head -1) ..."
        echo "  got:      $(echo "$got" | head -1) ..."
        fail=$((fail+1))
    fi
done

# semantic-error cases must fail with rc=1
for bad in scripts/errors_*.jk; do
    [ -f "$bad" ] || continue
    if $JOCKY --check "$bad" >/dev/null 2>&1; then
        echo "FAIL(error not caught) $bad"; fail=$((fail+1))
    else
        echo "PASS(error) $bad"; pass=$((pass+1))
    fi
done

echo "---"
echo "pass=$pass fail=$fail"
[ "$fail" -eq 0 ]