.PHONY: all
all: test

.PHONY: test
test: isValidTime
	./isValidTime 00:00:00
	./isValidTime 23:59:59
	! ./isValidTime 23:59:60
	! ./isValidTime 23:60:00
	! ./isValidTime 23:60:59
	! ./isValidTime 24:00:00
	./isValidTime 00:00
	./isValidTime 23:59

.PHONY: clean
clean::
	$(RM) *.[adios] *.ii isValidDate
