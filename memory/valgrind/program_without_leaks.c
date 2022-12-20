#include <stdlib.h>

int main(void) {
    char *buf = malloc(1000);
    free(buf);
    return EXIT_SUCCESS;
}
