#include <stdio.h>
#include <limits.h>

int main() {
    int max_int = INT_MAX;
    long long result = (long long)max_int + 1; // widen so the addition cannot overflow

    printf("Max int: %d\n", max_int);
    printf("Max int + 1: %lld\n", result);

    return 0;
}