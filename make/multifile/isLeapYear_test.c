#include "isLeapYear.h"
#include "isLeapYear_test.h"
#include <assert.h>

void testIsLeapYear() {
    assert(!isLeapYear(1999));
    assert(isLeapYear(2004));
    assert(!isLeapYear(2100));
    assert(isLeapYear(2400));
}
