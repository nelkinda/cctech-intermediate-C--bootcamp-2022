SHELL:=bash

.PHONY: test
test: calculator
	diff <<<"6" - <(echo "2 * 3" | ./calculator)
