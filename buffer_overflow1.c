#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char buffer2[10];
    // This line deliberately causes a buffer overflow
    strcpy(buffer, "This string is way too long for the buffer");
    snprintf(buffer2, sizeof(buffer2), "%s", "This string is way too long for the buffer");
    printf("%s\n", buffer);
    printf("%s\n", buffer2);
    return 0;
}
