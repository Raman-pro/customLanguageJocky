# JOCKY — Next-Gen Forensic Language Framework

A purpose-built programming language + compiler (written in C++) for writing
forensic-analysis scripts. Every build is automatically mutated (polymorphic),
so analysis tooling isn't pre-flagged by signature/reputation engines.
Cross-compiles to Linux and Windows from one source.

> **Authorized use only.** This is a dual-use project. Run it in your own lab
> (VMs with snapshots) for research/education/sanctioned testing. Never against
> systems you don't own or lack written permission to test.

## Build the compiler

```bash
cmake -S . -B build && cmake --build build
```

## Use it

```bash
# dump tokens / AST
./build/jocky --tokens scripts/demo.jk
./build/jocky --ast    scripts/demo.jk

# semantic check only
./build/jocky --check  scripts/demo.jk

# emit C
./build/jocky --emit-c scripts/demo.jk

# build + compile for Linux
./build/jocky --build scripts/demo.jk && ./scripts/demo

# build + cross-compile a Windows exe
./build/jocky --target mingw --build scripts/demo.jk

# polymorphism: same source, different seed -> different binary every time
./build/jocky --seed 42 --build scripts/demo.jk && shasum scripts/demo
./build/jocky --seed 7  --build scripts/demo.jk && shasum scripts/demo
```

## Test

```bash
./tests/run_tests.sh
```

## Docker test harness

`docker/Dockerfile` + `docker/test.sh` exercise JOCKY from 9 perspectives in a
clean Linux container (build, tests, polymorphism, cross-compile, forensics,
ClamAV scan, static analysis, valgrind, perf). Results land in
`docker/results/` and are summarized in `report.md`.

```bash
docker build -t jocky-test docker/
docker run --rm -v "$PWD":/workspace jocky-test bash /workspace/docker/test.sh
```

## Status

- [x] WP1 Lexer + parser + AST
- [x] WP2 Semantic analysis (symbol tables, type checking)
- [x] WP3 JOCKY → C transpiler + polymorphic seed (identifier renaming,
      build markers, opaque predicates) + Linux/Windows cross-compile
- [x] WP3b Forensics stdlib: `sys.process_list`, `sys.cwd`, `sys.now`,
      `sys.sleep`, `env.get`, `net.sockets`, `fs.read/write/list/exists`,
      `reg.list` (Windows), `mem.dump` (Windows). Runs on Linux, Windows,
      and macOS. Collectors emit JSON for console ingestion.
- [ ] WP4 CI/CD mutation pipeline (GitHub Actions)
- [ ] WP5 In-memory loader (lab)
- [ ] WP6 Transport (SOCKS5 / domain fronting)
- [ ] WP7 Management console
- [ ] WP8 BYOVD detection research

Try the forensics demo: `./build/jocky --build scripts/forensics.jk && ./scripts/forensics`

See `plan.md` for the full plan and `TEACHER.md` for the live learning journal.