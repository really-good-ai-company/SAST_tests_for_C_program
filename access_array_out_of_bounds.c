#include <stdio.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};

    // Correctly accessing the array
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print the last element instead of reading one past the end of the array
    printf("Accessing last element: %d\n", array[4]);

    return 0;
}
