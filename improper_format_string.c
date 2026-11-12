#include <stdio.h>

int main() {
    char buf[100];
    scanf("%s", buf);
    printf("%s", buf); // Format string vulnerability
    return 0;
}
