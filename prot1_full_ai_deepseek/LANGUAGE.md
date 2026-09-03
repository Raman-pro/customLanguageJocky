# JOCKY — Language Reference

> A complete guide to the JOCKY forensic-scripting language: its values, types,
> operators, control flow, functions, builtins, toolchain flags, and the
> built-in polymorphism/obfuscation engine.
>
> **Authorized use only.** JOCKY is a dual-use forensic-analysis framework.
> Use it only in your own lab, on systems you own or have written permission to
> test. See `README.md` and `plan.md`.

**Quick links:** [Getting started](#1-getting-started) · [Types](#4-types) ·
[Operators](#7-operators--precedence) · [Control flow](#8-control-flow) ·
[Functions](#9-functions) · [Builtins](#11-builtins--standard-library) ·
[Obfuscation](#12-polymorphism--obfuscation) · [CLI](#13-command-line-interface) ·
[Grammar](#17-grammar-ebnf)

---

## 1. Getting started

```bash
# build the compiler
cmake -S . -B build && cmake --build build

# compile and run the language tour
./build/jocky --build scripts/tour.jk && ./scripts/tour

# compile and run a script with full obfuscation
./build/jocky --seed 7 --obf-level 3 --build scripts/tour.jk && ./scripts/tour

# cross-compile a Windows exe
./build/jocky --target mingw --build scripts/system.jk && ./scripts/system.exe
```

JOCKY compiles to C, which is then compiled by `cc`/`gcc`/MinGW. The compiler
pipeline is: **lexer → parser → semantic analysis → (obfuscation) → C codegen →
(post-processing) → C compiler → binary**.

Demonstration scripts shipped in `scripts/`:

| Script | Shows |
|---|---|
| `tour.jk` | the complete core language (deterministic, `.expect` provided) |
| `algorithms.jk` | recursion, iteration, math / number-theory in pure JOCKY (`.expect` provided) |
| `system.jk` | every forensic stdlib builtin against the live host |
| `obfuscation_demo.jk` | the polymorphism / obfuscation feature (see §12) |
| `demo.jk` | functions, loops, primes |
| `forensics.jk` | end-to-end evidence collection (processes, sockets, files, JSON) |

Run the guided obfuscation demonstration with:
`./scripts/demo_obfuscation.sh`

---

## 2. Hello world

```js
fn main() {
    print("hello, world");
}
```

There is no top-level statement list — every program is a set of functions, and
execution begins at `main()`. `print(...)` is the builtin output function.

---

## 3. Comments

```js
// line comment — everything to the end of the line is ignored

/* block comment
   spanning multiple lines */
```

---

## 4. Types

JOCKY has exactly three value types plus a return-type marker:

| Type | Meaning | C mapping | Default value |
|---|---|---|---|
| `int` | 32-bit signed integer | `int32_t` | — (see note) |
| `str` | string (immutable sequence of bytes) | `const char*` | `""` |
| `bool` | boolean (`true` / `false`) | `bool` | `false` |
| `void` | no value — functions only | `void` | — |

> **Note:** every `let` must be given either an explicit type **and** an
> initializer, or just an initializer (the type is inferred). A declaration
> with a type but no initializer (`let x: int;`) is a **semantic error**; the
> default values listed above apply to the internal generated C but cannot be
> requested from JOCKY source.

### 4.1 Integer bounds

`int` is 32-bit (range ≈ −2,147,483,648 … 2,147,483,647). Arithmetic that
overflows wraps like C `int32_t`.

---

## 5. Variables & assignment

```js
let typed: int = 10;     // explicit type
let inferred = 20;       // type inferred from the value
let msg: str = "jocky";
let ok: bool = true;

ok = false;              // reassignment — type must match
let x: int = 0;
let y: int = (x = 5);    // assignment is an expression: y becomes 5
```

- `let name [: type] = value;` declares a variable.
- `name = value;` (or any expression) assigns — the assigned type must match
  the declared type exactly (`int`, `str`, or `bool`).
- Assignment is **right-associative** and evaluates to the assigned value, so
  `a = b = c` is valid.
- A variable cannot be redeclared in the same scope (see
  [Scoping](#10-scoping--shadowing)).

---

## 6. Literals

### 6.1 Integers

```js
0    42    -17    1000000
```

Decimal only (no hex/octal/binary), optional leading minus via the unary
operator.

### 6.2 Strings

```js
"double quoted"
""                       // empty string
"escaped: \"quote\" \\ backslash"
"line1\nline2"           // real newline
```

Supported escape sequences:

| Sequence | Meaning |
|---|---|
| `\n` | newline (0x0A) |
| `\t` | tab (0x09) |
| `\r` | carriage return (0x0D) |
| `\\` | backslash |
| `\"` | double quote |
| `\0` | null byte (0x00) |

Strings support `==` / `!=` comparison (case-sensitive) and `len()`, but there
is **no concatenation, no indexing, and no substring** operator.

### 6.3 Booleans

```js
true    false
```

---

## 7. Operators & precedence

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

Examples:

```js
print(2 + 3 * 4);        // 14   (* binds tighter than +)
print((2 + 3) * 4);      // 20   (parentheses override)
print(100 / 7);          // 14   (integer division truncates)
print(100 % 7);          // 2    (modulo)
print(-(3 + 4));         // -7   (unary minus)
print(1 + 2 * 3 % 4);    // 3    ((2*3)%4, * and % are left-assoc)
print(1 == 1);           // true
print("abc" == "abc");   // true (string equality)
```

Notes:
- `/` on integers truncates toward zero (C semantics).
- `%` requires `int` operands.
- `&&` / `||` are short-circuiting like C.
- Comparison between `int` and `str` (e.g. `1 == "1"`) is a semantic error.
- There is no ternary `? :` operator and no bitwise operators.

---

## 8. Control flow

### 8.1 `if` / `else`

```js
let n: int = 7;
if (n % 2 == 0) {
    print("even");
} else {
    print("odd");
}
```

- The condition must be a `bool`.
- The `else` branch is optional.
- `else` must be followed by `{` — there is **no `else if` chain** (nest the
  `if` inside the `else` body instead).

### 8.2 `while`

```js
let i: int = 0;
while (i < 3) {
    print(i);
    i = i + 1;
}
```

Loop condition must be `bool`.

### 8.3 `for`

```js
for (let j = 0; j < 4; j = j + 1) {
    print(j);
}
```

- The header is `for (let init; condition; step)` — it **must** begin with a
  `let` declaration.
- The loop variable (`j`) is scoped to the loop and is not visible after it.
- The `step` is any expression (usually an assignment).

### 8.4 `return`

```js
fn is_prime(n: int) : bool {
    if (n < 2) {
        return false;   // early return
    }
    return true;
}
```

- `return expr;` returns a value; `return;` returns from a `void` function.
- A `void` function cannot return a value; a typed function must return a value
  of the declared type on every path.

There are no `break` / `continue` statements.

---

## 9. Functions

### 9.1 Declaration

```js
fn name(param: type, ...) : retType {
    body
}
```

- Parameter types are required.
- The return type is optional and defaults to `void`:
  `fn announce(msg: str) { print(msg); }`
- A function with a non-`void` return type **must** return on every path
  (checked semantically).

### 9.2 Calling

```js
print(add(2, 3));
print(factorial(5));
```

### 9.3 Recursion & forward references

Functions may call themselves (recursion) and may call functions declared
**later** in the file (mutual recursion / forward references). The compiler
collects every signature before checking bodies:

```js
fn is_even(n: int) : bool {
    if (n == 0) { return true; }
    return is_odd(n - 1);       // is_odd is declared below — fine
}

fn is_odd(n: int) : bool {
    if (n == 0) { return false; }
    return is_even(n - 1);
}
```

### 9.4 Restrictions

- Nested function declarations are **not** allowed.
- Functions are not values — you cannot pass or return a function.
- There are no default/optional parameters and no variadics.

---

## 10. Scoping & shadowing

Scopes are: the **global** scope (function names) and each **block** (a `{ ... }`
body: function body, `if`/`else`, `while`, `for`).

- A `let` is visible from its declaration to the end of its enclosing block.
- A block may declare a variable with the same name as one in an enclosing
  scope — this **shadows** it:

```js
let v: int = 1;
if (true) {
    let v: int = 2;    // shadows the outer v inside this block
    print(v);          // 2
}
print(v);              // 1
```

- Redeclaring a name in the **same** scope is an error.
- A `for` loop variable is scoped to the loop; it is not visible afterward.

---

## 11. Builtins & standard library

### 11.1 Core builtins

| Call | Signature | Description |
|---|---|---|
| `print(x)` | `(int\|str\|bool) → void` | prints the value followed by a newline (`int` as decimal, `str` as-is, `bool` as `true`/`false`) |
| `len(s)` | `(str) → int` | length of a string |

### 11.2 Forensic stdlib

All collectors are cross-platform unless marked. The JSON-producing ones emit a
single string of JSON so a management console can ingest it.

| Call | Signature | Description |
|---|---|---|
| `sys.now()` | `() → str` | current timestamp `YYYY-MM-DDTHH:MM:SS` |
| `sys.cwd()` | `() → str` | current working directory |
| `sys.sleep(ms)` | `(int) → void` | pause for `ms` milliseconds |
| `sys.process_list()` | `() → str` | JSON array `[{"pid":…,"name":"…"}, …]` — Linux `/proc`, Windows Toolhelp32, macOS `libproc` |
| `env.get(name)` | `(str) → str` | value of an environment variable (`""` if unset) |
| `net.sockets()` | `() → str` | JSON array of TCP sockets `{"local","remote","state"}` — Linux `/proc/net/tcp`, Windows `GetExtendedTcpTable`, macOS `netstat` |
| `fs.read(path)` | `(str) → str` | file contents (`""` if unreadable) |
| `fs.write(path, data)` | `(str, str) → void` | write `data` to `path` |
| `fs.list(dir)` | `(str) → str` | JSON array of directory entry names |
| `fs.exists(path)` | `(str) → bool` | does the path exist |
| `reg.list(key)` | `(str) → str` | **Windows only** — JSON array of subkeys under `HKLM\…` / `HKCU\…`; returns `[]` elsewhere |
| `mem.dump(pid, path)` | `(int, str) → void` | **Windows only** — dump readable committed memory of `pid` to `path`; no-op elsewhere |

> Windows-only collectors degrade gracefully on Linux/macOS (empty result /
> no-op) so one source runs on all three platforms.

Example (`scripts/system.jk`):

```js
fn main() {
    print(sys.now());
    print(sys.process_list());     // live /proc on Linux
    print(net.sockets());
    fs.write("/tmp/t.txt", "hello\n");
    print(fs.read("/tmp/t.txt"));
    print(fs.exists("/tmp/t.txt"));
}
```

---

## 12. Polymorphism & obfuscation

Every build is a **unique artifact** even for identical source: the compiler
renames every identifier with a seeded RNG, emits volatile build markers, and
can apply escalating levels of control-flow obfuscation.

### 12.1 The seed

```bash
./build/jocky --seed 42 --build scripts/tour.jk     # deterministic per seed
./build/jocky --seed 7  --build scripts/tour.jk     # different binary than seed 42
```

- Same source + same seed → byte-identical C and binary.
- Different seeds → different identifiers, markers, opaque predicates,
  structure — and therefore different SHA-256 hashes.
- `--seed -1` disables identifier renaming (still polymorphic via markers
  unless obfuscation is off).

### 12.2 Obfuscation levels

`--obf-level <0-3>` (default: **2** when `--seed` is given, else **0**):

| Level | Active passes | Effect |
|---|---|---|
| 0 | — | legacy behavior: rename + build markers + original opaque predicates |
| 1 | enhanced opaque predicates + dead code | different bytes, same structure |
| 2 | + CFG flattening + bogus control flow + string encryption | flattened state machine, strings encrypted |
| 3 | + constant-folding noise + trampolines + junk functions | maximum — CFG destroyed, encrypted strings, buried entry point |

```bash
./build/jocky --seed 9 --obf-level 3 --build scripts/forensics.jk
./scripts/forensics                      # output is identical to level 0
strings ./scripts/forensics | grep -i process   # -> nothing
```

Obfuscation never changes program semantics — every script produces the same
output at every level. Run the end-to-end demonstration to see all of this in
action:

```bash
./scripts/demo_obfuscation.sh
```

It builds `scripts/obfuscation_demo.jk` at multiple seeds/levels and shows the
unique hashes, reproducible same-seed builds, identical runtime output, the
flattened switch state machine, encrypted strings, the trampolined entry point,
and the injected junk functions.

---

## 13. Command-line interface

```
usage: jocky [options] <file.jk>
  --tokens          dump token stream
  --ast             dump AST
  --check           semantic check only (no output)
  --emit-c          print generated C to stdout
  -o <file.c>       write generated C to a file
  --build           write C and invoke a C compiler
  --target <t>      for --build: linux (default) | mingw (Windows exe)
  --seed <n>        polymorphism seed (-1 = no renaming, default = random)
  --obf-level <0-3> CFG obfuscation level (default: 2 when --seed used, else 0)
```

Typical workflow:

```bash
./build/jocky --check scripts/tour.jk             # fast error check
./build/jocky --emit-c scripts/tour.jk            # inspect generated C
./build/jocky --build scripts/tour.jk             # Linux binary
./build/jocky --target mingw --build scripts/tour.jk   # Windows exe
./build/jocky --seed 42 --obf-level 3 --build scripts/tour.jk  # obfuscated
```

---

## 14. Compilation targets

| Target | Compiler | Artifact |
|---|---|---|
| `linux` (default) | `cc`/`gcc` | ELF binary |
| `mingw` | `x86_64-w64-mingw32-gcc` | PE32+ `.exe` (links `ws2_32`, `iphlpapi`, `advapi32`) |

The runtime auto-selects platform collectors via preprocessor branches, so one
`.jk` source yields working binaries on Linux, macOS, and Windows.

---

## 15. Errors & diagnostics

Compiler errors are reported with file position and exit code 1:

```
semantic error at line 2, col 5: type mismatch: cannot assign str to variable 'x' of type int
parse error at line 4, col 12: expected '{', got 'if'
lex error at line 1, col 8: unexpected character '@'
```

| Error class | Example |
|---|---|
| lex | unexpected character, unterminated string, unknown escape |
| parse | missing `;`, `else` without `{`, bad type, `else if` |
| semantic | undefined variable/function, type mismatch, `if` on non-bool, `len` on non-str, wrong arg count, void misuse, return-type mismatch, redeclaration, nested function |

---

## 16. Limitations (by design)

- No arrays, lists, or maps — the language is intentionally small.
- No string concatenation, indexing, or formatting.
- No `else if`, `break`, or `continue`.
- No ternary operator, bitwise operators, or floats.
- No global/static variables; no closures; functions are not values.
- Integers are 32-bit.

These are deliberate: JOCKY is a domain-specific forensic-scripting language,
not a general-purpose one. Its power comes from the builtins and the
polymorphic toolchain, not a large grammar.

---

## 17. Grammar (EBNF)

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

---

## 18. Example programs

A recursive function with a forward reference and string logic:

```js
fn starts_with_abc(s: str) : bool {
    return len(s) >= 3 && s == "abc";
}

fn main() {
    print(starts_with_abc("abc"));   // true
    print(starts_with_abc("xy"));    // false
    print(fib(10));                  // 55
}

fn fib(n: int) : int {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
```

Run the full, annotated walkthrough: `scripts/tour.jk`.