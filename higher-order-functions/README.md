# Higher-order Functions

First-order functions are functions that only deal with data.
```C
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    puts("Hello, world!");
    return EXIT_SUCCESS;
}
```
Both functions in this program, `main()` and `puts()`, are first-order functions.
Both functions deal only with data.

First-order functions only pass data around, that is, they use data as argument values and return data.

## Composition
Programming languages offer various different means of composition.
Composition combines elements of modularization to form bigger modules.

Examples of composition:
- Structure programming (sequence, selection, iteration)
  that is statement composition within functions.
- Expression compositions: Terms combined to bigger terms following rules of term and expression evaluation.

