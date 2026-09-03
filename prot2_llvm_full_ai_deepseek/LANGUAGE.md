# READ — Language Reference

> A complete guide to the Read forensic-scripting language and its LLVM
> compiler: values, types, operators, control flow, functions, builtins,
> toolchain flags, and the built-in polymorphism/obfuscation engine.
>
> **Authorized use only.** Read is a dual-use forensic-analysis framework.
> Use it only in your own lab, on systems you own or have written permission to
> test. See `README.md` and `plan.md`.

**Quick links:** [Types](#types) · [Operators](#operators--precedence) ·
[Control flow](#control-flow) · [Functions](#functions) ·
[Builtins](#builtins--standard-library) ·
[Obfuscation](#polymorphism--obfuscation) · [CLI](#command-line-interface) ·
[Grammar](#grammar-ebnf)

---

## 1. Getting started

```bash
# build the compiler (LLVM backend)
cmake -S . -B build && cmake --build build

# compile and run the language tour
./build/jocky --build scripts/tour.rd && ./scripts/tour

# compile with full obfuscation
./build/jocky --seed 7 --obf-level 3 --build scripts/tour.rd && ./scripts/tour

# cross-compile a Windows exe
./build/jocky --target mingw --build scripts/system.rd
```

The compiler pipeline is: **lexer → parser → AST → semantic analysis → LLVM IR
codegen → (IR obfuscation) → O2 optimization → object file → link → binary**.

Demonstration scripts shipped in `scripts/`:

| Script | Shows |
|---|---|
| `tour.rd` | the complete core language (deterministic, `.expect` provided) |
| `algorithms.rd` | recursion, iteration, math / number-theory in pure Read |
| `system.rd` | every forensic stdlib builtin against the live host |
| `demo.rd` | functions, loops, primes |
| `forensics.rd` | end-to-end evidence collection (processes, sockets, files, JSON) |

---

## 2. Hello world

```js
fn main() {
    print("hello, world");
}
```

There is no top-level statement list — every program is a set of functions,
and execution begins at `main()`. `print(...)` is the builtin output function.

---

## 3. Comments

```js
// line comment — everything to the end of the line is ignored

/* block comment
   spanning multiple lines */
```

---

## Types

| Type | Meaning | LLVM mapping | Default value |
|---|---|---|---|
| `int` | 32-bit signed integer | `i32` | — (see note) |
| `str` | string (immutable sequence of bytes) | `ptr` (i8*) | `""` |
| `bool` | boolean (`true` / `false`) | `i1` | `false` |
| `void` | no value — functions only | `void` | — |

> **Note:** every `let` must be given either an explicit type **and** an
> initializer, or just an initializer (the type is inferred). A declaration
> with a type but no initializer is a **semantic error**; the default values
> above apply to the internal generated code but cannot be requested from Read
> source.

### Integer bounds

`int` is 32-bit (range ≈ −2,147,483,648 … 2,147,483,647). Arithmetic that
overflows wraps like C `int32_t`.

---

## Variables & assignment

```js
let typed: int = 10;     // explicit type
let inferred = 20;       // type inferred from the value
let msg: str = "read";
let ok: bool = true;

ok = false;              // reassignment — type must match
let x: int = 0;
let y: int = (x = 5);    // assignment is an expression: y becomes 5
```

- `let name [: type] = value;` declares a variable.
- `name = value;` assigns — the assigned type must match exactly.
- Assignment is **right-associative** and evaluates to the assigned value.
- A variable cannot be redeclared in the same scope (see
  [Scoping](#scoping--shadowing)).

---

## Literals

### Integers

```js
0    42    -17    1000000
```

Decimal only, optional leading minus via the unary operator.

### Strings

```js
"double quoted"
""                       // empty string
"escaped: \"quote\" \\ backslash"
"line1\nline2"
```

Supported escape sequences: `\n`, `\t`, `\r`, `\\`, `\"`, `\0`.

Strings support `==` / `!=` comparison (case-sensitive) and `len()`, but there
is **no concatenation, indexing, or substring** operator.

### Booleans

```js
true    false
```

---

## Operators & precedence

From highest to lowest precedence:

| Precedence | Operators | Associativity | Operand types | Result |
|---|---|---|---|---|
| 1 (highest) | `-x` (unary), `!x` (logical not) | right | `-`: int, `!`: bool | int / bool |
| 2 | `*` `/` `%` | left | int | int |
| 3 | `+` `-` | left | int | int |
| 4 | `<` `<=` `>` `>=` | left | int | bool |
| 5 | `==` `!=` | left | int–int **or** str–str | bool |
| 6 | `&&` | left | bool | bool |
| 7 | `\|\|` | left | bool | bool |
| 8 (lowest) | `=` (assignment) | **right** | matching | the assigned type |

- `/` truncates toward zero; `%` is C-style remainder.
- `&&` / `||` are short-circuiting (implemented with LLVM basic blocks + phi).
- No ternary operator, no bitwise operators, no floats.

---

## Control flow

### `if` / `else`

```js
let n: int = 7;
if (n % 2 == 0) {
    print("even");
} else {
    print("odd");
}
```

- The condition must be a `bool`.
- `else` must be followed by `{` — there is **no `else if` chain**.

### `while`

```js
let i: int = 0;
while (i < 3) {
    print(i);
    i = i + 1;
}
```

### `for`

```js
for (let j = 0; j < 4; j = j + 1) {
    print(j);
}
```

- Header **must** begin with a `let` declaration.
- The loop variable is scoped to the loop.

### `return`

```js
fn is_prime(n: int) : bool {
    if (n < 2) {
        return false;
    }
    return true;
}
```

- `return expr;` returns a value; `return;` returns from a `void` function.
- A typed function must return a value on every path (checked semantically).

There are no `break` / `continue` statements.

---

## Functions

```js
fn name(param: type, ...) : retType {
    body
}
```

- Parameter types are required; the return type defaults to `void`.
- Recursion and forward references work — the compiler collects every
  signature before checking bodies, and codegen creates all LLVM functions
  before emitting any bodies, so mutual recursion just works.
- Nested function declarations are not allowed; functions are not values.

---

## Scoping & shadowing

Scopes are the **global** scope (function names) and each **block**. A `let`
is visible from its declaration to the end of its enclosing block; an inner
block may shadow an outer name:

```js
let v: int = 1;
if (true) {
    let v: int = 2;    // shadows the outer v inside this block
    print(v);          // 2
}
print(v);              // 1
```

Redeclaring a name in the **same** scope is an error.

---

## Builtins & standard library

### Core builtins

| Call | Signature | Description |
|---|---|---|
| `print(x)` | `(int\|str\|bool) → void` | prints the value followed by a newline |
| `len(s)` | `(str) → int` | length of a string |

### Forensic stdlib

All collectors are cross-platform unless marked. The JSON-producing ones emit a
single string of JSON.

| Call | Signature | Description |
|---|---|---|
| `sys.now()` | `() → str` | current timestamp `YYYY-MM-DDTHH:MM:SS` |
| `sys.cwd()` | `() → str` | current working directory |
| `sys.sleep(ms)` | `(int) → void` | pause for `ms` milliseconds |
| `sys.process_list()` | `() → str` | JSON array `[{"pid":…,"name":"…"}, …]` — Linux `/proc`, Windows Toolhelp32, macOS `libproc` |
| `env.get(name)` | `(str) → str` | value of an environment variable (`""` if unset) |
| `net.sockets()` | `() → str` | JSON array of TCP sockets — Linux `/proc/net/tcp`, Windows `GetExtendedTcpTable`, macOS `netstat` |
| `fs.read(path)` | `(str) → str` | file contents (`""` if unreadable) |
| `fs.write(path, data)` | `(str, str) → void` | write `data` to `path` |
| `fs.list(dir)` | `(str) → str` | JSON array of directory entry names |
| `fs.exists(path)` | `(str) → bool` | does the path exist |
| `reg.list(key)` | `(str) → str` | **Windows only** — JSON array of subkeys; `[]` elsewhere |
| `mem.dump(pid, path)` | `(int, str) → void` | **Windows only** — dump readable committed memory; no-op elsewhere |

> Windows-only collectors degrade gracefully so one source runs on all three
> platforms. These are implemented in `runtime/runtime.c`, compiled and linked
> by the driver at `--build` time.

---

## Polymorphism & obfuscation

Every build is a **unique artifact** even for identical source:

```bash
./build/jocky --seed 42 --obf-level 3 --build scripts/tour.rd   # deterministic per seed
./build/jocky --seed 7  --obf-level 3 --build scripts/tour.rd   # different binary
```

- Same source + same seed → byte-identical object and binary.
- Different seeds → different identifiers, marker values, opaque predicates,
  encrypted strings, junk functions, trampolines — and therefore different
  SHA-256 hashes.
- `--seed -1` disables identifier renaming.

### Obfuscation levels

`--obf-level <0-3>` (default: **2** when `--seed` is given, else **0**):

| Level | Active passes | Effect |
|---|---|---|
| 0 | seeded renaming + volatile build markers | different bytes, same structure |
| 1 | + IR opaque predicates (`g*g >= 0` on a volatile global) | extra always-true branches that survive -O2 |
| 2 | + XOR string encryption (per-string decryptors) + junk functions | plaintext gone from the binary, dead code |
| 3 | + entry-point trampoline chain | real `main` is buried behind 1..3 callers |

Obfuscation never changes program semantics — every script produces the same
output at every level (verified by `tests/run_tests.sh`).

---

## Command-line interface

```
usage: jocky [options] <file.rd>
  --tokens          dump token stream
  --ast             dump AST
  --check           semantic check only (no output)
  --emit-ir         print generated LLVM IR to stdout
  -o <file.ll>      write generated LLVM IR to a file
  --build           optimize + emit object + link against the runtime
  --target <t>      for --build: native (default) | mingw (Windows exe)
  --seed <n>        polymorphism seed (-1 = no renaming, default = random)
  --obf-level <0-3> obfuscation level (default: 2 when --seed used, else 0)
```

Typical workflow:

```bash
./build/jocky --check scripts/tour.rd          # fast error check
./build/jocky --emit-ir scripts/tour.rd        # inspect the generated IR
./build/jocky --build scripts/tour.rd          # native binary
./build/jocky --target mingw --build scripts/tour.rd   # Windows exe
./build/jocky --seed 42 --obf-level 3 --build scripts/tour.rd   # obfuscated
```

---

## Compilation targets

| Target | Toolchain | Artifact |
|---|---|---|
| `native` (default) | LLVM host target + `cc` | host binary |
| `mingw` | LLVM `x86_64-pc-windows-gnu` + `x86_64-w64-mingw32-gcc` | PE32+ `.exe` (links `ws2_32`, `iphlpapi`, `advapi32`) |

The runtime auto-selects platform collectors via preprocessor branches, so one
`.rd` source yields working binaries on Linux, macOS, and Windows.

---

## Errors & diagnostics

Compiler errors are reported with file position and exit code 1:

```
semantic error at line 2, col 5: type mismatch: cannot assign str to variable 'x' of type int
parse error at line 4, col 12: expected '{', got 'if'
lex error at line 1, col 8: unexpected character '@'
```

---

## Limitations (by design)

- No arrays, lists, or maps — the language is intentionally small.
- No string concatenation, indexing, or formatting.
- No `else if`, `break`, or `continue`.
- No ternary operator, bitwise operators, or floats.
- No global/static variables; no closures; functions are not values.
- Integers are 32-bit.

---

## Grammar (EBNF)

```
program        ::= { topLevel }
topLevel       ::= fnDecl | letDecl | exprStmt

fnDecl         ::= "fn" IDENT "(" [ param { "," param } ] ")"
                  [ ":" typeName ] "{" { stmt } "}"
param          ::= IDENT ":" typeName
typeName       ::= "int" | "str" | "bool" | "void"

stmt           ::= letDecl | ifStmt | whileStmt | forStmt | returnStmt | exprStmt
letDecl        ::= "let" IDENT [ ":" typeName ] [ "=" expr ] ";"
ifStmt         ::= "if" "(" expr ")" "{" { stmt } "}"
                  [ "else" "{" { stmt } "}" ]
whileStmt      ::= "while" "(" expr ")" "{" { stmt } "}"
forStmt        ::= "for" "(" "let" letDecl expr ";" expr ")" "{" { stmt } "}"
returnStmt     ::= "return" [ expr ] ";"
exprStmt       ::= expr ";"

expr           ::= assign
assign         ::= logicalOr [ "=" assign ]
logicalOr      ::= logicalAnd { "||" logicalAnd }
logicalAnd     ::= equality { "&&" equality }
equality       ::= relational { ( "==" | "!=" ) relational }
relational     ::= additive { ( "<" | "<=" | ">" | ">=" ) additive }
additive       ::= multiplicative { ( "+" | "-" ) multiplicative }
multiplicative ::= unary { ( "*" | "/" | "%" ) unary }
unary          ::= ( "!" | "-" ) unary | call
call           ::= primary { "(" [ expr { "," expr } ] ")" }
primary        ::= INT | STR | "true" | "false"
                | IDENT { "." IDENT } | "(" expr ")"
```