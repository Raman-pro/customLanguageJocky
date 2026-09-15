#!/usr/bin/env bash
# String-obfuscation guardrail (LLVM backend).
#
# At obfuscation level >= 2 no sensitive literal may survive in the built
# binary -- neither a user `.rd` literal nor a literal baked into the C
# runtime (the lab webhook URL, the curl command, JSON keys, ...). The runtime
# used to be compiled separately and linked in, which bypassed the obfuscator
# and leaked the webhook through `strings`; this test locks that shut.
set -u
cd "$(dirname "$0")/.."
JOCKY=./build/jocky
pass=0; fail=0

# Substrings that must never appear in a level-2/3 binary. Kept long/specific
# so they cannot accidentally match unrelated data.
PATTERNS='requestcatcher|skjeks|https://|application/json|Content-Type|curl -sS|av_bait|EICAR-STANDARD|sekurlsa|evil-domain|JOCKY forensic language'

check() {
    local src="$1" lvl="$2"
    local bin="${src%.rd}"
    if ! $JOCKY --seed 424242 --obf-level "$lvl" --build "$src" >/dev/null 2>&1; then
        echo "FAIL(build) $src lvl=$lvl"; fail=$((fail+1)); return
    fi

    # The pre-obfuscation runtime IR must not be left behind either.
    if [ -f "${src%.rd}_rt.ll" ]; then
        echo "FAIL(intermediate IR left behind) ${src%.rd}_rt.ll"
        fail=$((fail+1))
    fi

    local hit
    hit="$(strings "$bin" | grep -iE "$PATTERNS" || true)"
    if [ -n "$hit" ]; then
        echo "FAIL(leak) $src lvl=$lvl"
        echo "$hit" | sed 's/^/    /' | head -5
        fail=$((fail+1))
    else
        echo "PASS(no-leak) $src lvl=$lvl"; pass=$((pass+1))
    fi
}

for lvl in 2 3; do
    for src in scripts/demo.rd scripts/test_strings.rd scripts/av_bait.rd; do
        [ -f "$src" ] && check "$src" "$lvl"
    done
done

echo "---"
echo "pass=$pass fail=$fail"
[ "$fail" -eq 0 ]
