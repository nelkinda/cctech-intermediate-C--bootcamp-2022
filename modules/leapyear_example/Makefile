CPPFLAGS:=-MMD
CFLAGS:=-O2

.PHONY: all
all: test isLeapYear

.PHONY: test
test: testRunner
	./testRunner

testRunner: testRunner.o test_cases.a core_functions.a
isLeapYear: isLeapYear.o core_functions.a

test_cases.a: test_cases.a(isLeapYearTest.o)
test_cases.a: test_cases.a(factorialTest.o)
core_functions.a: core_functions.a(isLeapYear_impl.o)
core_functions.a: core_functions.a(factorial_impl.o)

-include *.d

.PHONY: clean
clean::
	$(RM) *.[adios] testRunner isLeapYear
