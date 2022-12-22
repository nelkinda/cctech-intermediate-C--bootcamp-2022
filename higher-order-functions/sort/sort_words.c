#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// comp_str implements the compar function pointer (interface) for the qsort function(stdlib module).
// This is depdency inversion through a higher-order function.
int comp_str(const void *s1, const void *s2) {
    const char **p1 = (const char **)s1;
    const char **p2 = (const char **)s2;
    return strcmp(*p1, *p2);
}

int main(int argc, char *argv[]) {
    qsort(argv + 1, argc - 1, sizeof(argv[0]), comp_str);
    for (int i = 1; i < argc; i++)
        puts(argv[i]);
}
