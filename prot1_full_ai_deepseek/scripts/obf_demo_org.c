#include <stdio.h>

const char* describe(int n) {
    if (n < 0) {
        return "negative";
    }
    if (n == 0) {
        return "zero";
    }
    if (n % 2 == 0) {
        return "even";
    }
    return "odd";
}

// One Collatz step: n -> n/2 (even) or 3n+1 (odd).
int step(int n) {
    if (n % 2 == 0) {
        return n / 2;
    }
    return n * 3 + 1;
}

// Number of Collatz steps needed to reach 1 from n.
int collatz_count(int n) {
    int count = 0;
    int x = n;
    while (x != 1) {
        x = step(x);
        count = count + 1;
    }
    return count;
}

int main(void) {
    printf("=== COLLATZ STEPS ===\n");
    int i = 1;
    while (i <= 8) {
        printf("%d\n", collatz_count(i));
        i = i + 1;
    }

    printf("=== CLASSIFICATION ===\n");
    for (int j = -3; j <= 6; j = j + 1) {
        printf("%s\n", describe(j));
    }

    printf("=== AGGREGATE ===\n");
    int total = 0;
    int n = 1;
    while (n <= 10) {
        total = total + collatz_count(n);
        n = n + 1;
    }
    printf("%d\n", total);

    printf("=== RESULT ===\n");
    printf("all builds produce identical output\n");

    return 0;
}