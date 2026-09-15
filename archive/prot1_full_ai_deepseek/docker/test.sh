#!/usr/bin/env bash
# JOCKY multi-perspective test harness (run inside the Docker container).
# Each perspective writes results to docker/results/<name>.txt
set -u
R=/workspace/docker/results
mkdir -p "$R"
cd /workspace
rm -rf build

say() { echo; echo "===== $1 ====="; }

# ---------------------------------------------------------------- 0. system
say "SYSTEM"
{
  uname -a
  gcc --version | head -1
  cmake --version | head -1
  nproc
} | tee "$R/00_system.txt"

# ---------------------------------------------------------------- 1. build
say "BUILD"
{
  time cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
  time cmake --build build
  ls -la build/jocky
} 2>&1 | tee "$R/01_build.txt"

# ---------------------------------------------------------------- 2. tests
say "TESTS"
./tests/run_tests.sh 2>&1 | tee "$R/02_tests.txt"

# ---------------------------------------------------------------- 3. polymorphism
say "POLYMORPHISM"
{
  echo "Building the same source 10 times with different seeds:"
  echo "seed | sha256 | size"
  for s in 1 2 3 4 5 6 7 8 9 10; do
    ./build/jocky --seed "$s" --build scripts/demo.jk >/dev/null 2>&1
    h=$(sha256sum scripts/demo | cut -d' ' -f1)
    sz=$(stat -c %s scripts/demo)
    echo "$s | $h | $sz"
  done
  echo
  u=$(for s in 1 2 3 4 5 6 7 8 9 10; do ./build/jocky --seed "$s" --build scripts/demo.jk >/dev/null 2>&1; sha256sum scripts/demo; done | cut -d' ' -f1 | sort -u | wc -l)
  echo "unique hashes out of 10 builds: $u"
} 2>&1 | tee "$R/03_polymorphism.txt"

# ---------------------------------------------------------------- 4. cross-compile
say "CROSS-COMPILE (Windows PE)"
{
  ./build/jocky --seed 5 --target mingw --build scripts/demo.jk
  file scripts/demo.exe
  echo
  ./build/jocky --seed 5 --target mingw --build scripts/forensics.jk
  file scripts/forensics.exe
} 2>&1 | tee "$R/04_crosscompile.txt"

# ---------------------------------------------------------------- 5. forensics on Linux
say "FORENSICS (Linux /proc)"
{
  ./build/jocky --build scripts/forensics.jk >/dev/null 2>&1
  out=$(./scripts/forensics)
  echo "$out" | head -5
  echo
  procs=$(echo "$out" | sed -n 's/^.*PROCESSES.*$//p' >/dev/null; echo "$out" | grep -c '"pid"')
  socks=$(echo "$out" | grep -c '"local"')
  echo "process entries in JSON: $procs"
  echo "socket entries in JSON: $socks"
  echo "fs.read(\"/etc/hostname\") ->"
  echo "$out" | grep -i hostname || true
} 2>&1 | tee "$R/05_forensics.txt"

# ---------------------------------------------------------------- 6. AV scan (lab, defensive research)
say "ANTIVIRUS SCAN (ClamAV, defensive-lab)"
{
  freshclam --no-warnings 2>&1 | tail -2 || echo "freshclam update failed"
  echo
  ./build/jocky --seed 9 --build scripts/demo.jk >/dev/null 2>&1
  clamscan --stdout scripts/demo 2>/dev/null || true
  clamscan --stdout scripts/demo.exe 2>/dev/null || true
  clamscan --stdout scripts/demo.c 2>/dev/null || true
} 2>&1 | tee "$R/06_avscan.txt"

# ---------------------------------------------------------------- 7. static analysis
say "STATIC ANALYSIS"
{
  ./build/jocky --seed 9 --build scripts/demo.jk >/dev/null 2>&1
  echo "--- file ---"; file scripts/demo scripts/demo.exe
  echo
  echo "--- dynamic imports (Linux) ---"
  readelf -d scripts/demo 2>/dev/null | grep -E "NEEDED" || true
  echo
  echo "--- section entropy (python) ---"
  python3 - <<'PY'
import math
data=open('/workspace/scripts/demo','rb').read()
# crude: whole-file Shannon entropy
def ent(b):
    if not b: return 0.0
    from collections import Counter
    c=Counter(b); n=len(b)
    return -sum((v/n)*math.log2(v/n) for v in c.values())
print("whole-file entropy: %.4f bits/byte" % ent(data))
# entropy of first 3 sections via PE? just report size
print("file size: %d bytes" % len(data))
PY
  echo
  echo "--- compiler fingerprint strings ---"
  strings -n 6 scripts/demo | grep -iE "clang|gcc|GCC|GLIBC" | sort -u | head -5 || true
} 2>&1 | tee "$R/07_static.txt"

# ---------------------------------------------------------------- 8. memory safety
say "VALGRIND (memory safety)"
{
  ./build/jocky --build scripts/demo.jk >/dev/null 2>&1
  valgrind --leak-check=summary --error-exitcode=99 ./scripts/demo >/dev/null 2> /tmp/vg.txt
  rc=$?
  grep -E "ERROR SUMMARY|definitely lost|indirectly lost|possibly lost" /tmp/vg.txt
  echo "valgrind exit code: $rc (0=clean)"
} 2>&1 | tee "$R/08_valgrind.txt"

# ---------------------------------------------------------------- 9. performance
say "PERFORMANCE"
{
  echo "compiler build time:"
  time ./build/jocky --build scripts/demo.jk >/dev/null 2>&1
  echo
  echo "demo runtime:"
  time ./scripts/demo >/dev/null
  echo
  echo "forensics runtime (proc+net+fs):"
  time ./scripts/forensics >/dev/null 2>&1
} 2>&1 | tee "$R/09_perf.txt"

echo
echo "ALL PERSPECTIVES DONE -> docker/results/"