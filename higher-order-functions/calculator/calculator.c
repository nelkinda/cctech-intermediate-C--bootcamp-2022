#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int op_add(int operand1, int operand2) {
    return operand1 + operand2;
}

int op_sub(int operand1, int operand2) {
    return operand1 - operand2;
}

int op_mul(int operand1, int operand2) {
    return operand1 * operand2;
}

int op_div(int operand1, int operand2) {
    return operand1 / operand2;
}

void testOperations() {
    assert(op_add(1, 2) == 3);
    assert(op_sub(5, 3) == 2);
    assert(op_mul(5, 8) == 40);
    assert(op_div(20, 4) == 5);
}

typedef int (*opt_t)(int, int);

//int (*getOpt(char *operator))(int, int) {
opt_t getOpt(char *operator) {
    opt_t op;
    if (strcmp("+", operator) == 0) {
        op = op_add;
    } else if (strcmp("-", operator) == 0) {
        op = op_sub;
    } else if (strcmp("*", operator) == 0) {
        op = op_mul;
    } else if (strcmp("/", operator) == 0) {
        op = op_div;
    } else {
        op = NULL;
    }
    return op;
}

void testGetOpt() {
    assert(getOpt("unknown operator") == NULL);
    assert(getOpt("+") == op_add);
    assert(getOpt("-") == op_sub);
    assert(getOpt("*") == op_mul);
    assert(getOpt("/") == op_div);
}

int main(int argc, char *argv[]) {
    testOperations();
    testGetOpt();

    int operand1, operand2, result;
    char operator[10];
    scanf("%d", &operand1);
    scanf("%s", operator);
    scanf("%d", &operand2);

    opt_t op = getOpt(operator);
    if (op != NULL) {
        result = op(operand1, operand2);
        printf("%d\n", result);
    } else {
        fprintf(stderr, "%s: error: Unknown operator <%s>\n", argv[0], operator);
        return EXIT_FAILURE;
    }
}
