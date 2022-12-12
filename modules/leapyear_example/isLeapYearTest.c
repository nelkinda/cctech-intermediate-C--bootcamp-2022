#include <assert.h>

#include "isLeapYear.h"
#include "isLeapYearTest.h"

void testIsLeapYear(void) {
    assert(!isLeapYear(1999.0f));
    assert(isLeapYear(2004.0f));
    assert(!isLeapYear(2100));
    assert(isLeapYear(2400));
}
