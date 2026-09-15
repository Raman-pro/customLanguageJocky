#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return false;
        }
        i = i + 1;
    }
    return true;
}

int main(void) {
    int count = 0;
    int n = 2;
    while (count < 8) {
        if (is_prime(n)) {
            printf("%d\n", n);
            count = count + 1;
        }
        n = n + 1;
    }
    return 0;
}
