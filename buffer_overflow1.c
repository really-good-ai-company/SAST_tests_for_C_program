#include <stdio.h>
#include <string.h>

int main() {
    char buffer[64];
    // Copy with the destination size so the literal cannot overflow the buffer
    snprintf(buffer, sizeof(buffer), "%s", "This string is way too long for the buffer");
    printf("%s\n", buffer);
    return 0;
}
