#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate memory for the string and its terminator
    const char *source = "This string is too long for the buffer";
    char *buffer = (char*)malloc(strlen(source) + 1);

    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Copy the string into the buffer sized for it
    strcpy(buffer, source);

    printf("%s\n", buffer);

    free(buffer);
    return 0;
}
