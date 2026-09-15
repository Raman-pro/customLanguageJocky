// ============================================================================
//  JOCKY — Algorithm Showcase
//
//  Classic algorithms written in pure JOCKY: recursion, iteration, math,
//  and number-theory helpers. Fully deterministic output.
//
//  Build & run:
//      ./build/jocky --build scripts/algorithms.jk && ./scripts/algorithms
//      ./build/jocky --seed 3 --obf-level 3 --build scripts/algorithms.jk && ./scripts/algorithms
//
//  Expected output is stored in scripts/algorithms.expect.
// ============================================================================

fn main() {
    print("== fibonacci (iterative) ==");
    print(fib_iter(0));    // 0
    print(fib_iter(1));    // 1
    print(fib_iter(10));   // 55
    print(fib_iter(20));   // 6765

    print("== fibonacci (recursive) ==");
    print(fib_rec(0));     // 0
    print(fib_rec(1));     // 1
    print(fib_rec(10));    // 55

    print("== factorial ==");
    print(fact(0));        // 1
    print(fact(5));        // 120
    print(fact(8));        // 40320

    print("== greatest common divisor ==");
    print(gcd(48, 36));    // 12
    print(gcd(17, 5));     // 1
    print(gcd(100, 10));   // 10

    print("== primality ==");
    print(is_prime(2));    // true
    print(is_prime(17));   // true
    print(is_prime(18));   // false
    print(is_prime(97));   // true

    print("== primes up to 30 ==");
    for (let i = 2; i <= 30; i = i + 1) {
        if (is_prime(i)) {
            print(i);
        }
    }

    print("== collatz steps ==");
    print(collatz_steps(1));    // 0
    print(collatz_steps(27));   // 111
    print(collatz_steps(6));    // 8

    print("== sum of digits ==");
    print(sum_digits(0));       // 0
    print(sum_digits(12345));   // 15
    print(sum_digits(999));     // 27

    print("== reverse digits ==");
    print(reverse_int(12345));  // 54321
    print(reverse_int(-123));   // -321
    print(reverse_int(7));      // 7

    print("== power ==");
    print(pow(2, 10));          // 1024
    print(pow(3, 3));           // 27
    print(pow(5, 0));           // 1

    print("== min / max of three ==");
    print(max3(3, 9, 6));       // 9
    print(min3(3, 9, 6));       // 3
    print(max3(-5, -1, -3));    // -1

    print("== palindrome number ==");
    print(is_pal(121));         // true
    print(is_pal(12321));       // true
    print(is_pal(123));         // false
}

fn fib_iter(n: int) : int {
    if (n < 2) {
        return n;
    }
    let a: int = 0;
    let b: int = 1;
    let i: int = 2;
    while (i <= n) {
        let t: int = a + b;
        a = b;
        b = t;
        i = i + 1;
    }
    return b;
}

fn fib_rec(n: int) : int {
    if (n < 2) {
        return n;
    }
    return fib_rec(n - 1) + fib_rec(n - 2);
}

fn fact(n: int) : int {
    if (n <= 1) {
        return 1;
    }
    return n * fact(n - 1);
}

fn gcd(a: int, b: int) : int {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

fn is_prime(n: int) : bool {
    if (n < 2) {
        return false;
    }
    let i: int = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return false;
        }
        i = i + 1;
    }
    return true;
}

fn collatz_steps(n: int) : int {
    let steps: int = 0;
    let x: int = n;
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

fn sum_digits(n: int) : int {
    let total: int = 0;
    let m: int = n;
    while (m > 0) {
        total = total + m % 10;
        m = m / 10;
    }
    return total;
}

fn reverse_int(n: int) : int {
    if (n < 0) {
        return -reverse_int(-n);
    }
    let r: int = 0;
    let m: int = n;
    while (m > 0) {
        r = r * 10 + m % 10;
        m = m / 10;
    }
    return r;
}

fn pow(base: int, exp: int) : int {
    let result: int = 1;
    let i: int = 0;
    while (i < exp) {
        result = result * base;
        i = i + 1;
    }
    return result;
}

fn max3(a: int, b: int, c: int) : int {
    if (a >= b && a >= c) {
        return a;
    }
    if (b >= a && b >= c) {
        return b;
    }
    return c;
}

fn min3(a: int, b: int, c: int) : int {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}

fn is_pal(n: int) : bool {
    return n == reverse_int(n);
}