#include <stdio.h>

int main() {
    char buf[100];
    scanf("%99s", buf);
    printf("%s", buf);
    return 0;
}
