// JOCKY demo: a tiny forensics-style program exercising the language core.
// Sums integers, checks primality, prints results.

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

fn sum_up_to(limit: int) : int {
    let total: int = 0;
    for (let j = 0; j < limit; j = j + 1) {
        total = total + j;
    }
    return total;
}

fn main() {
    let greeting: str = "JOCKY forensic language v0.1";
    let answer: int = sum_up_to(10);
    print(greeting);
    print(answer);
    let s: str = "prime";
    if (is_prime(7) && len(s) == 5) {
        print(true);
    } else {
        print(false);
    }
    let count: int = 0;
    let n: int = 2;
    while (count < 3) {
        if (is_prime(n)) {
            print(n);
            count = count + 1;
        }
        n = n + 1;
    }
}