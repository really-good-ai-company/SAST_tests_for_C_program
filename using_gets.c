#include <stdio.h>
#include <string.h>

int main() {
    char buffer[50];

    printf("Enter a string: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        buffer[0] = '\0';
    }
    buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline character

    printf("You entered: %s\n", buffer);
    return 0;
}
