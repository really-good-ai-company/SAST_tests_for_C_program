#include <stdio.h>

int main() {
    int *ptr = NULL;
    if (ptr == NULL) {
        printf("Pointer is NULL, cannot dereference\n");
        return 1;
    }
    printf("%d", *ptr); // Dereferencing a NULL pointer
    return 0;
}
