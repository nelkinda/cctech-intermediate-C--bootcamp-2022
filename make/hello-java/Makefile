SHELL:=bash

.PHONY: all
## all:	Same as test.
all: test

.PHONY: test
## test:	Runs all tests.
test: .test-success
.test-success: Hello.class True.class False.class
	diff <<<"Hello, world!" - <(java Hello)
	java True
	! java False
	touch $@

%.class: %.java
	javac $^

.PHONY: clean
## clean:	Removes generated files.
clean:
	$(RM) Hello.class True.class False.class .test-success

.PHONY: help
## help:	Prints this help text.
help:
	@echo "Super-cool Makefile for Hello, world!"
	@echo "The following targets are supported:"
	@echo
	@sed -n 's/^## \?//p' $(MAKEFILE_LIST)
	@echo
	@echo "Have fun!"
