// tour.c — hand-written C equivalent of scripts/tour.jk
// Same logic, same output; written as a normal C program (NOT JOCKY-emitted C).

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static bool is_even(int n);
static bool is_odd(int n);

static int dbl(int x) { return x * 2; }
static int add(int a, int b) { return a + b; }
static void announce(const char* msg) { printf("%s\n", msg); }
static int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
static int fib(int n) {
    if (n < 2) return n;
    return fib(n - 1) + fib(n - 2);
}
static bool is_even(int n) {
    if (n == 0) return true;
    return is_odd(n - 1);
}
static bool is_odd(int n) {
    if (n == 0) return false;
    return is_even(n - 1);
}
static const char* describe(const char* name, int age) {
    if (age >= 18) return "adult";
    return "minor";
}

int main(void) {
    printf("== integers ==\n");
    printf("%d\n", 0);
    printf("%d\n", 42);
    printf("%d\n", -17);
    printf("%d\n", 1000000);

    printf("== booleans ==\n");
    printf("%s\n", true ? "true" : "false");
    printf("%s\n", false ? "true" : "false");

    printf("== strings ==\n");
    printf("hello, world\n");
    printf("\n");
    printf("escaped: \\ backslash, \" quote\n");
    printf("line1\nline2\n");

    printf("== variables ==\n");
    int typed = 10;
    int inferred = 20;
    printf("%d\n", typed);
    printf("%d\n", inferred);
    const char* msg = "jocky";
    bool ok = true;
    printf("%s\n", msg);
    printf("%s\n", ok ? "true" : "false");
    ok = false;
    printf("%s\n", ok ? "true" : "false");

    printf("== arithmetic ==\n");
    printf("%d\n", 2 + 3 * 4);
    printf("%d\n", (2 + 3) * 4);
    printf("%d\n", 10 - 3 - 2);
    printf("%d\n", 100 / 7);
    printf("%d\n", 100 % 7);
    printf("%d\n", -(3 + 4));
    printf("%d\n", 7 / 2 * 2);
    printf("%d\n", 1 + 2 * 3 % 4);

    printf("== comparisons ==\n");
    printf("%s\n", 1 == 1 ? "true" : "false");
    printf("%s\n", 1 != 2 ? "true" : "false");
    printf("%s\n", 3 < 5 ? "true" : "false");
    printf("%s\n", 5 <= 5 ? "true" : "false");
    printf("%s\n", 4 > 9 ? "true" : "false");
    printf("%s\n", 9 >= 10 ? "true" : "false");

    printf("== logic ==\n");
    printf("%s\n", true && true ? "true" : "false");
    printf("%s\n", true && false ? "true" : "false");
    printf("%s\n", false || true ? "true" : "false");
    printf("%s\n", !true ? "true" : "false");
    printf("%s\n", !!true ? "true" : "false");

    printf("== string operations ==\n");
    const char* s = "JOCKY";
    printf("%d\n", (int)strlen(s));
    printf("%d\n", (int)strlen(""));
    printf("%s\n", strcmp(s, "JOCKY") == 0 ? "true" : "false");
    printf("%s\n", strcmp(s, "jocky") == 0 ? "true" : "false");
    printf("%s\n", strcmp(s, "JOCKY") != 0 ? "true" : "false");

    printf("== if / else ==\n");
    int n = 7;
    if (n % 2 == 0) {
        printf("even\n");
    } else {
        printf("odd\n");
    }
    if (n > 10) {
        printf("big\n");
    }
    printf("after if\n");

    printf("== while ==\n");
    int i = 0;
    while (i < 3) {
        printf("%d\n", i);
        i = i + 1;
    }

    printf("== for ==\n");
    for (int j = 0; j < 4; j = j + 1) {
        printf("%d\n", j);
    }

    printf("== assignment ==\n");
    int x = 0;
    int y = (x = 5);
    printf("%d\n", x);
    printf("%d\n", y);

    printf("== shadowing ==\n");
    int v = 1;
    if (true) {
        int v = 2;
        printf("%d\n", v);
    }
    printf("%d\n", v);

    printf("== functions ==\n");
    printf("%d\n", dbl(21));
    printf("%d\n", add(2, 3));
    announce("hello from a void function");
    printf("%d\n", factorial(5));
    printf("%d\n", fib(10));
    printf("%s\n", describe("Ada", 21));

    printf("== mutual recursion ==\n");
    printf("%s\n", is_even(10) ? "true" : "false");
    printf("%s\n", is_odd(10) ? "true" : "false");
    printf("%s\n", is_even(7) ? "true" : "false");

    printf("== composition ==\n");
    printf("%d\n", dbl(dbl(2)));
    printf("%d\n", factorial(fib(5)));

    return 0;
}