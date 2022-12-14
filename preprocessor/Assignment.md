# Assignment

Create a macro named `verify` in a header file `verify.h` that works in the following way:
- Like the `assert` macro, it takes a condition and prints a message if that condition failed.
- Unlike the `assert` macro, it will _not_ `abort()`.

The message printed should have the following format (example):
```
    // In file foo.c, line 12, within function main()
    verify(1 == 2);
```
Output:
```
foo.c:12: error: In function main(), verification of condition "1 == 2" failed.
```
