CXXFLAGS:=-W -Wall -pedantic
SHELL:=bash

.PHONY: all
all: test

.PHONY: test
test: wordcount
	diff /dev/null <(./wordcount </dev/null)
	diff <(echo "bar: 2" ; echo "buzz: 1" ; echo "foo: 3") <(./wordcount <<< "foo bar foo buzz foo bar" -)

.PHONY: clean
clean::
	$(RM) *.[adios] *.ii wordcount
