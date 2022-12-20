# CCTech C++ Intermediate Bootcamp 2022

## Miscellaneous

### Procedures vs Functions and CQS

- Procedure: A function that does not return a value.
  Example:
```
char *prefix = "myprefix";
void printWithPrefix(char *text) {
    printf("%s%s\n", prefix, test);
}
```
- Function: A function that returns a value.
  Example:
```
int factorial(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
```

Functions should either be commands (procedures), that is, they have side-effects and return nothing, or they should be queries (real functions), that is, they return information but have no side-effects.

