#!/usr/bin/env bash
# decomp_report/decompile.sh
# Runs Ghidra headless on every built artifact and stores decompiled C in decomp/.
set -u
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DR="$ROOT/decomp_report"
GHIDRA="/opt/homebrew/Cellar/ghidra/12.1.2/libexec/support/analyzeHeadless"
BUILDS="$DR/builds"
DECOMP="$DR/decomp"
PROJ="$DR/ghidra_projects"
SCRIPT="$DR/ghidra_script"
mkdir -p "$DECOMP"

for bin in "$BUILDS"/jk_* "$BUILDS"/c_*; do
    name=$(basename "$bin")
    out="$DECOMP/${name}.c"
    if [ -s "$out" ]; then echo "skip $name"; continue; fi
    echo "== decompile $name =="
    rm -rf "$PROJ"
    mkdir -p "$PROJ"
    "$GHIDRA" "$PROJ" proj \
        -import "$bin" \
        -scriptPath "$SCRIPT" \
        -postScript ExportDecomp.java "$out" \
        > /dev/null 2>&1
    if [ -s "$out" ]; then
        echo "ok $name ($(wc -l < "$out") lines)"
    else
        echo "FAILED $name"
    fi
done
echo "done"