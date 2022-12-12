#include <stdio.h>
#include <stdlib.h>

#include "isLeapYear.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "%s: error: wrong number of arguments.\n", argv[0]);
        fprintf(stderr, "Usage: %s YEAR\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int year = atoi(argv[1]);
    bool wasLeapYear = isLeapYear(year);
    if (wasLeapYear)
        printf("%d is a leap year.\n", year);
    else
        printf("%d is not a leap year.\n", year);
}
