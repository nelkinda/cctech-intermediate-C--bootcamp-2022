CFLAGS:=-W -Wall -pedantic -Werror
CPPFLAGS:=-MMD

.PHONY: all
## all:	Runs the tests and builds the main program.
all: test isLeapYear

.PHONY: test
## test:	Runs the tests.
test: .test-success
.test-success: runTests
	./runTests
	touch $@

runTests: runTests.o isLeapYear_test.o isLeapYear.o
isLeapYear: isLeapYear_main.o isLeapYear.o

-include *.d

.PHONY: clean
## clean:	Removes all generated files.
clean:
	$(RM) *.[adios] *.ii runTests .test-success

.PHONY: help
## help:	Prints this help text.
help:
	@echo "Super-cool Makefile for Hello, world!"
	@echo "The following targets are supported:"
	@echo
	@sed -n 's/^## \?//p' $(MAKEFILE_LIST)
	@echo
	@echo "Have fun!"
