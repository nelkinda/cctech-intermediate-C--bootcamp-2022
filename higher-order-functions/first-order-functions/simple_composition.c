#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// isLeapYear1 is a first-order function using statement composition
bool isLeapYear1(int year) {
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

// isLeapYear is a first-order function using expression composition
bool isLeapYear2(int year) {
    return
        ((year % 4 == 0) && (year % 100 != 0))
        || (year % 400 == 0);
}

// Can you add two numbers as expression composition?
// Yes, of course: 2 + 3
//
// Can you call a function in expression composition?
// Yes, of course: 2 + f(3)
//
// Can you split the path in expression composition?
// Yes, in C you can: ?:, &&, ||
// But not if, else, they can't be used in expressions.
//
// Can you repeat in expression composition?
// No, in C you can't.
//
// Can you try-catch in expression composition?
// No, in C++ you can't.

int main(void) {
    assert(!isLeapYear1(1999));
    assert(!isLeapYear2(1999));
    assert(isLeapYear1(2004));
    assert(isLeapYear2(2004));
    assert(!isLeapYear1(2100));
    assert(!isLeapYear2(2100));
    assert(isLeapYear1(2400));
    assert(isLeapYear2(2400));
    return EXIT_SUCCESS;
}
