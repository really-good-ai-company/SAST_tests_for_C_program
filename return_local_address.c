#include <stdio.h>

char* getLocalString() {
    static char localString[] = "Hello, World!";
    return localString; // static storage: valid after the function returns
}

int main() {
    char *str = getLocalString();
    printf("%s\n", str); // Undefined behavior: str points to deallocated stack memory
    return 0;
}
