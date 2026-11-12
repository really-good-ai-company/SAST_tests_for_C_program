#include <stdio.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};

    // Correctly accessing the array
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Bounds-checked access - index 5 is out of range and is skipped
    int index = 5;
    if (index >= 0 && index < 5) {
        printf("Accessing out of bounds: %d\n", array[index]);
    }

    return 0;
}
