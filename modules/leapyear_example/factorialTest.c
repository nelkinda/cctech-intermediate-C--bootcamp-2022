#include "factorialTest.h"
#include "factorial.h"

#include <assert.h>

void testFactorial(void) {
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(2) == 2);
    assert(factorial(3) == 6);
    assert(factorial(6) == 720);
}
