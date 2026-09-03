// algorithms.c — hand-written C equivalent of scripts/algorithms.jk
#include <stdio.h>
#include <stdbool.h>

static int fib_iter(int n) {
    if (n < 2) return n;
    int a = 0, b = 1, i = 2;
    while (i <= n) {
        int t = a + b;
        a = b;
        b = t;
        i = i + 1;
    }
    return b;
}

static int fib_rec(int n) {
    if (n < 2) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

static int fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

static int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

static bool is_prime(int n) {
    if (n < 2) return false;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) return false;
        i = i + 1;
    }
    return true;
}

static int collatz_steps(int n) {
    int steps = 0;
    int x = n;
    while (x != 1) {
        if (x % 2 == 0) {
            x = x / 2;
        } else {
            x = x * 3 + 1;
        }
        steps = steps + 1;
    }
    return steps;
}

static int sum_digits(int n) {
    int total = 0;
    int m = n;
    while (m > 0) {
        total = total + m % 10;
        m = m / 10;
    }
    return total;
}

static int reverse_int(int n) {
    if (n < 0) return -reverse_int(-n);
    int r = 0;
    int m = n;
    while (m > 0) {
        r = r * 10 + m % 10;
        m = m / 10;
    }
    return r;
}

static int pow_int(int base, int exp) {
    int result = 1;
    int i = 0;
    while (i < exp) {
        result = result * base;
        i = i + 1;
    }
    return result;
}

static int max3(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

static int min3(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

static bool is_pal(int n) {
    return n == reverse_int(n);
}

static void putb(bool v) { printf("%s\n", v ? "true" : "false"); }

int main(void) {
    printf("== fibonacci (iterative) ==\n");
    printf("%d\n", fib_iter(0));
    printf("%d\n", fib_iter(1));
    printf("%d\n", fib_iter(10));
    printf("%d\n", fib_iter(20));

    printf("== fibonacci (recursive) ==\n");
    printf("%d\n", fib_rec(0));
    printf("%d\n", fib_rec(1));
    printf("%d\n", fib_rec(10));

    printf("== factorial ==\n");
    printf("%d\n", fact(0));
    printf("%d\n", fact(5));
    printf("%d\n", fact(8));

    printf("== greatest common divisor ==\n");
    printf("%d\n", gcd(48, 36));
    printf("%d\n", gcd(17, 5));
    printf("%d\n", gcd(100, 10));

    printf("== primality ==\n");
    putb(is_prime(2));
    putb(is_prime(17));
    putb(is_prime(18));
    putb(is_prime(97));

    printf("== primes up to 30 ==\n");
    for (int i = 2; i <= 30; i = i + 1) {
        if (is_prime(i)) printf("%d\n", i);
    }

    printf("== collatz steps ==\n");
    printf("%d\n", collatz_steps(1));
    printf("%d\n", collatz_steps(27));
    printf("%d\n", collatz_steps(6));

    printf("== sum of digits ==\n");
    printf("%d\n", sum_digits(0));
    printf("%d\n", sum_digits(12345));
    printf("%d\n", sum_digits(999));

    printf("== reverse digits ==\n");
    printf("%d\n", reverse_int(12345));
    printf("%d\n", reverse_int(-123));
    printf("%d\n", reverse_int(7));

    printf("== power ==\n");
    printf("%d\n", pow_int(2, 10));
    printf("%d\n", pow_int(3, 3));
    printf("%d\n", pow_int(5, 0));

    printf("== min / max of three ==\n");
    printf("%d\n", max3(3, 9, 6));
    printf("%d\n", min3(3, 9, 6));
    printf("%d\n", max3(-5, -1, -3));

    printf("== palindrome number ==\n");
    putb(is_pal(121));
    putb(is_pal(12321));
    putb(is_pal(123));

    return 0;
}