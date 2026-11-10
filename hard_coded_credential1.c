/*
    This program demonstrates the use of a hardcoded password to access a 
    system-critical file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inputPassword[50] = {0};
    const char *hardcodedPassword = getenv("CRITICAL_FILE_PASSWORD");  // Password comes from the deployment

    if (hardcodedPassword == NULL || hardcodedPassword[0] == '\0') {
        fprintf(stderr, "CRITICAL_FILE_PASSWORD is not set.\n");
        return 1;
    }

    printf("Enter password to access the system file: ");
    if (fgets(inputPassword, sizeof(inputPassword), stdin) == NULL) {
        fprintf(stderr, "Error reading password.\n");
        return 1;
    }
    inputPassword[strcspn(inputPassword, "\n")] = 0; // Remove newline character

    if (strcmp(inputPassword, hardcodedPassword) == 0) {
        printf("Access granted. Reading system file...\n");

        // Attempting to read a system-critical file (with a fake filename)
        const char *criticalFilePath = "/etc/fake_critical_file.conf";
        FILE *file = fopen(criticalFilePath, "r");

        if (file == NULL) {
            perror("Error opening file");
        } else {
            // Read and print the contents of the file (hypothetical)
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                printf("%s", buffer);
            }
            fclose(file);
        }
    } else {
        printf("Access denied.\n");
    }

    return 0;
}
