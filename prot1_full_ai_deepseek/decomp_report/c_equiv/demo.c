// demo.c — hand-written C equivalent of scripts/demo.jk
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static bool is_prime(int n) {
    if (n < 2) return false;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) return false;
        i = i + 1;
    }
    return true;
}

static int sum_up_to(int limit) {
    int total = 0;
    for (int j = 0; j < limit; j = j + 1) {
        total = total + j;
    }
    return total;
}

int main(void) {
    const char* greeting = "JOCKY forensic language v0.1";
    int answer = sum_up_to(10);
    printf("%s\n", greeting);
    printf("%d\n", answer);
    const char* s = "prime";
    if (is_prime(7) && (int)strlen(s) == 5) {
        printf("%s\n", "true");
    } else {
        printf("%s\n", "false");
    }
    int count = 0;
    int n = 2;
    while (count < 3) {
        if (is_prime(n)) {
            printf("%d\n", n);
            count = count + 1;
        }
        n = n + 1;
    }
    return 0;
}