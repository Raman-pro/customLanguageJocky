// ============================================================================
//  JOCKY — Core Language Tour
//
//  A guided, fully deterministic walkthrough of every feature of the JOCKY
//  language: values, variables, operators, control flow, functions, recursion,
//  scoping, and the `print` / `len` builtins.
//
//  Build & run:
//      ./build/jocky --build scripts/tour.jk && ./scripts/tour
//      ./build/jocky --seed 7 --obf-level 3 --build scripts/tour.jk && ./scripts/tour
//
//  Expected output is stored in scripts/tour.expect.
// ============================================================================

// -- 1. Comments --------------------------------------------------------------
// Everything after // to the end of the line is a comment.
/* Everything between slash-star and star-slash is a block comment. */

fn main() {
    // -- 2. Integers ----------------------------------------------------------
    print("== integers ==");
    print(0);
    print(42);
    print(-17);
    print(1000000);

    // -- 3. Booleans ----------------------------------------------------------
    print("== booleans ==");
    print(true);
    print(false);

    // -- 4. Strings -----------------------------------------------------------
    print("== strings ==");
    print("hello, world");
    print("");
    print("escaped: \\ backslash, \" quote");
    print("line1\nline2");

    // -- 5. Variables ---------------------------------------------------------
    print("== variables ==");
    let typed: int = 10;        // explicit type
    let inferred = 20;          // type inferred from the value
    print(typed);
    print(inferred);
    let msg: str = "jocky";
    let ok: bool = true;
    print(msg);
    print(ok);
    ok = false;                 // reassignment
    print(ok);

    // -- 6. Arithmetic & precedence ------------------------------------------
    print("== arithmetic ==");
    print(2 + 3 * 4);          // 14  (* binds tighter than +)
    print((2 + 3) * 4);        // 20  (parentheses override precedence)
    print(10 - 3 - 2);         // 5   (left associative)
    print(100 / 7);            // 14  (integer division truncates)
    print(100 % 7);            // 2   (modulo)
    print(-(3 + 4));           // -7  (unary minus)
    print(7 / 2 * 2);          // 6   ((7/2)*2, left to right)
    print(1 + 2 * 3 % 4);      // 3   (* and % bind tighter than +)

    // -- 7. Comparison & logic ------------------------------------------------
    print("== comparisons ==");
    print(1 == 1);             // true
    print(1 != 2);             // true
    print(3 < 5);              // true
    print(5 <= 5);             // true
    print(4 > 9);              // false
    print(9 >= 10);            // false

    print("== logic ==");
    print(true && true);       // true
    print(true && false);      // false
    print(false || true);      // true
    print(!true);              // false
    print(!!true);             // true

    // -- 8. String operations: len & comparison --------------------------------
    print("== string operations ==");
    let s: str = "JOCKY";
    print(len(s));             // 5
    print(len(""));            // 0
    print(s == "JOCKY");       // true
    print(s == "jocky");       // false (comparison is case-sensitive)
    print(s != "JOCKY");       // false

    // -- 9. if / else ----------------------------------------------------------
    print("== if / else ==");
    let n: int = 7;
    if (n % 2 == 0) {
        print("even");
    } else {
        print("odd");
    }
    if (n > 10) {
        print("big");
    }
    print("after if");

    // -- 10. while -------------------------------------------------------------
    print("== while ==");
    let i: int = 0;
    while (i < 3) {
        print(i);
        i = i + 1;
    }

    // -- 11. for ----------------------------------------------------------------
    print("== for ==");
    for (let j = 0; j < 4; j = j + 1) {
        print(j);
    }

    // -- 12. Assignment is an expression ---------------------------------------
    print("== assignment ==");
    let x: int = 0;
    let y: int = (x = 5);      // assignment evaluates to the assigned value
    print(x);                  // 5
    print(y);                  // 5

    // -- 13. Shadowing ---------------------------------------------------------
    print("== shadowing ==");
    let v: int = 1;
    if (true) {
        let v: int = 2;        // inner declaration shadows the outer one
        print(v);              // 2
    }
    print(v);                  // 1

    // -- 14. Functions & recursion ---------------------------------------------
    print("== functions ==");
    print(double(21));         // 42
    print(add(2, 3));          // 5
    announce("hello from a void function");
    print(factorial(5));       // 120
    print(fib(10));            // 55
    print(describe("Ada", 21));// "adult"

    // -- 15. Mutual recursion (forward references) ------------------------------
    print("== mutual recursion ==");
    print(is_even(10));        // true
    print(is_odd(10));         // false
    print(is_even(7));         // false

    // -- 16. Composition ---------------------------------------------------------
    print("== composition ==");
    print(double(double(2)));  // 8
    print(factorial(fib(5)));  // fib(5)=5, 5! = 120
}

// Functions may be declared in any order; the compiler collects every
// signature before checking bodies, so forward references work.
fn double(x: int) : int {
    return x * 2;
}

fn add(a: int, b: int) : int {
    return a + b;
}

fn announce(msg: str) {          // no return type -> void
    print(msg);
}

fn factorial(n: int) : int {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

fn fib(n: int) : int {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

fn is_even(n: int) : bool {
    if (n == 0) {
        return true;
    }
    return is_odd(n - 1);
}

fn is_odd(n: int) : bool {
    if (n == 0) {
        return false;
    }
    return is_even(n - 1);
}

fn describe(name: str, age: int) : str {
    if (age >= 18) {
        return "adult";
    }
    return "minor";
}