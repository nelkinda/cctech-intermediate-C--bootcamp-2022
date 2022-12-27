.PHONY: all
all: test

.PHONY: test
test: isValidDateTime
	./isValidDateTime 2022-12-26
	! ./isValidDateTime faksdfaksjdhf
	./isValidDateTime 12022-12-26
	! ./isValidDateTime 2022-12-32
	! ./isValidDateTime 2022-12-00
	./isValidDateTime 2022-12-01
	./isValidDateTime 2022-12-29
	./isValidDateTime 2022-12-30
	./isValidDateTime 2022-12-31
	! ./isValidDateTime 2022-00-01
	./isValidDateTime 2022-01-01
	./isValidDateTime 2022-09-01
	./isValidDateTime 2022-10-01
	./isValidDateTime 2022-12-01
	! ./isValidDateTime 2022-13-01
	./isValidDateTime 00:00:00
	./isValidDateTime 23:59:59
	! ./isValidDateTime 23:59:60
	! ./isValidDateTime 23:60:00
	! ./isValidDateTime 23:60:59
	! ./isValidDateTime 24:00:00
	./isValidDateTime 00:00
	./isValidDateTime 23:59
	./isValidDateTime 2022-12-26T06:55:30.741374147
	./isValidDateTime 2022-12-26T06:55:30.741374147Z
	./isValidDateTime 2022-12-26T12:25:30.741374147+05:30
	./isValidDateTime 2022-12-26T06:55:30.741374
	./isValidDateTime 2022-12-26T06:55:30.741374Z
	./isValidDateTime 2022-12-26T12:25:30.741374+05:30
	./isValidDateTime 2022-12-26T06:55:30.741
	./isValidDateTime 2022-12-26T06:55:30.741Z
	./isValidDateTime 2022-12-26T12:25:30.741+05:30
	./isValidDateTime 2022-12-26T06:55:30
	./isValidDateTime 2022-12-26T06:55:30Z
	./isValidDateTime 2022-12-26T12:25+05:30
	./isValidDateTime 2022-12-26T06:55
	./isValidDateTime 2022-12-26T06:55Z
	./isValidDateTime 2022-12-26T12:25:30+05:30
	./isValidDateTime 2022-12-26T12:25:30-05:30

.PHONY: clean
clean::
	$(RM) *.[adios] *.ii isValidDateTime
