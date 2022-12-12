.PHONY: all
all: test isLeapYear

.PHONY: test
test: testRunner
	./testRunner

testRunner: testRunner.o isLeapYearTest.o isLeapYear_impl.o
isLeapYear: isLeapYear.o isLeapYear_impl.o

.PHONY: clean
clean::
	$(RM) *.[adios] testRunner isLeapYear
