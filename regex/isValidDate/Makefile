.PHONY: all
all: test

.PHONY: test
test: isValidDate
	./isValidDate 2022-12-26
	! ./isValidDate faksdfaksjdhf
	./isValidDate 12022-12-26
	! ./isValidDate 2022-12-32
	! ./isValidDate 2022-12-00
	./isValidDate 2022-12-01
	./isValidDate 2022-12-29
	./isValidDate 2022-12-30
	./isValidDate 2022-12-31
	! ./isValidDate 2022-00-01
	./isValidDate 2022-01-01
	./isValidDate 2022-09-01
	./isValidDate 2022-10-01
	./isValidDate 2022-12-01
	! ./isValidDate 2022-13-01

.PHONY: clean
clean::
	$(RM) *.[adios] *.ii isValidDate
