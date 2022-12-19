#include "isLeapYear.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        int year = atoi(argv[i]);
        if (!isLeapYear(year))
            printf("%d is not a leap year.\n", year);
        else
            printf("%d is a leap year.\n", year);
    }
    return EXIT_SUCCESS;
}
