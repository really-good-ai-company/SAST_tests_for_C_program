#include <stdio.h>

int main() {
    char buffer[50];

    printf("Enter a string: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        buffer[0] = '\0';
    }

    printf("You entered: %s\n", buffer);
    return 0;
}
