CPPFLAGS:=-MMD
CXXFLAGS:=-W -Wall -pedantic -Werror -std=c++20
CC:=$(CXX)

.PHONY: all
all: test

.PHONY: test
test: ExpenseReportTest
	faketime '2022-12-30 11:10:20' ./ExpenseReportTest

ExpenseReportTest: ExpenseReportTest.o ExpenseReport.o

.PHONY: clean
clean::
	$(RM) *.[adios]

-include *.d
