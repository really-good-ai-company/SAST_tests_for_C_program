#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer = (char*)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Use the buffer for some operation
    sprintf(buffer, "Sample text for buffer.");

    // Print the buffer content while it is still allocated
    printf("Buffer content: %s\n", buffer);

    // Free the buffer
    free(buffer);

    return 0;
}