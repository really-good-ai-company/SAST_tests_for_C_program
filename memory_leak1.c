#include <stdlib.h>

void func() {
    char *ptr = malloc(10);
    free(ptr);
}

int main() {
    func();
    return 0;
}
