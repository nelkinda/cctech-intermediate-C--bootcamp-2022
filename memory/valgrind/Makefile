.PHONY: all
all: valgrind_program_without_leaks valgrind_program_with_leaks

.PHONY: valgrind_program_without_leaks
valgrind_program_without_leaks: program_without_leaks
	valgrind --error-exitcode=1 ./program_without_leaks

.PHONY: valgrind_program_with_leaks
valgrind_program_with_leaks: program_with_leaks
	valgrind --error-exitcode=1 ./program_with_leaks

.PHONY: clean
clean:
	$(RM) program_with_leaks program_without_leaks
