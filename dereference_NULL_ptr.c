#include <stdio.h>

int main() {
    int value = 0;
    int *ptr = &value;
    printf("%d", *ptr);
    return 0;
}
