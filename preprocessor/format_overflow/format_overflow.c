#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is active sabotage and should be regarded a serious crime.
#if  !defined(__ISO_C_VERSION__) || __ISO_C_VERSION__ < 199900L
#define snprintf(buf, length, ...) \
    sprintf(buf, __VA_ARGS__)
#endif

//C89: sprintf()
//C99: sprintf() + snprintf()

char buf[100] = "folks";
char test[] = "Foo Bar!";

int main(int argc, char *argv[]) {
#if  !defined(__ISO_C_VERSION__) || __ISO_C_VERSION__ < 199900L
    sprintf(buf, "Hello, %s\n", argv[1]);
#else
    snprintf(buf, 100, "Hello, %s\n", argv[1]);
#endif
    puts(buf);
    puts(test);
}
