#include <stdlib.h>

void func() {
    char *ptr = malloc(10); // Memory allocated and never freed
    free(ptr);
}

int main() {
    func();
    return 0;
}
