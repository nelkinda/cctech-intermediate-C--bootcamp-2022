SHELL:=bash

CXXFLAGS:=-W -Wall -pedantic -Werror -save-temps

.PHONY: all
## all:	Same as test.
all: test

.PHONY: test
## test:	Runs the tests. ⇐ Default
test: .test-success
.test-success: hello
	diff <<<"Hello, world!" - <(./hello)
	touch $@

.PHONY: clean
## clean:	Removes the generated files.
clean:
	$(RM) *.[adios] *.ii hello .test-success

.PHONY: help
## help:	Prints this help text.
help:
	@echo "Super-cool Makefile for Hello, world!"
	@echo "The following targets are supported:"
	@echo
	@sed -n 's/^## \?//p' $(MAKEFILE_LIST)
	@echo
	@echo "Have fun!"
