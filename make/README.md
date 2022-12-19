# Make and Makefiles

`make` is a tool for automating software builds.

Some of the key features include:
- Incremental building:
  Only (re-)build those things which need to be (re-)built because they are requested and don't exist or a timestamp comparison determined that they are out-of-date.
- Dependency tree:
  Request one file and build all dependent files incrementally as well.
- Declarative:
  The highest order of description is to tell make what is needed.
  How to do it, is only the second level of description.
- Make is a lot like a macro processor
  if, include (similar to the C preprocessor)
- Make does not do the actual work itself.
  Make is not a compiler and not a replacement for a compiler.
  Make is not a shell and not a replacement for a shell.
  Make uses a shell to execute commands, including compilation and linkage commands.
- Make can be used for all software construction.
  For some types of software, like Java programs, more specific and thus more suited tools exist.
  Make is particularly good at building C, C++, Objective-C, Assembler, and Fortran programs.
- Make is standardized through the Open Group (as part of POSIX/Linux).
  Multiple implementations exist.
  The most popular implementation is GNU make.
- Makefiles should be treated as executable documentation of software construction.

## Make Syntax

Given the following (bad!) `Makefile`:
```make
SHELL:=bash

compile:
	cc -o hello hello.c

test: compile
	diff <<<"Hello, world!" - <(./hello)

clean:
	rm hello
```

`compile`, `test`, and `clean` are _targets_ or _goals_.
Targets or goals are defined by specifying _rules_ for targets.
A rule for a target consists of two parts:
- A target declaration with an optional dependency list.
- A recipe of shell lines to execute when that target shall be made.
Unsatisfied dependencies will be built before the target.

Important: The shell lines of recipes MUST be indented with a TAB character. Spaces will not work here.

The order of targets in a Makefile is irrelevant with one exception.
The exception is for the very first target in the Makefile.
The very first target in the Makefile becomes the default goal.
The default goal is the goal that `make` will build when no other goal has been specified.

## Comments
Comments in `Makefile`s begin with the `#` symbol until the end of the line.
```make
# This is a comment.
```

## Variables
How to declare a variable?
```make
VAR=value
VAR:=value
```

How to reference variables?
- Use `$` plus the name in parentheses or braces.
```make
FOO=$(BAR)
FOO=${BAR}
```
- There is no difference between parentheses and braces, both work the same way.

## Predefined variables
Here are some useful predefined variables.
For a complete list, consult the `make` manual.
- `$(RM)` expands to the rm/del command of the underlying platform, plus the options to ignore errors.
- `$(SHELL)` expands to the command shell used by `make` to execute recipes. You can change this to a different, more powerful shell, if required, for example by declaring `SHELL:=bash`.
- `$(MAKEFILE_LIST)` expands to all `Makefile`s (including `include`d `Makefile`s). (Treat as read-only.)
- `$(CFLAGS)` expands to the command line options to be given to a C compiler.
- `$(CXXFLAGS)` expands to the command line options to be given to a C++ compiler.
- `$(CPPFLAGS)` expands to the command line options to be given to a C/C++ preprocessor.
- `$@` expands to the name of the current target.
- `$<` expands to the name of the first prerequisite.
- `$^` expands to the full list of prerequisites.
- `$*` expands to whatever `%` matched in a pattern rule.

`$^` and `$<` will expand to the same thing if the rule has only one prerequisite.

For example:
```make
# Use the bash shell instead of the sh shell.
SHELL:=bash

# Compile C++ files with -W -Wall -pedantic flags
CXXFLAGS:=-W -Wall -pedantic
```

Tip: Use `-W -Wall -pedantic` very early on! The sooner you enable additional feedback from the compiler, the sooner your source code quality improves.
Pro Tip: Add `-Werror` to stop at warnings and motivate yourself to write code completely free of warnings.

## Built-in rules
`make` has built-in rules for various purposes.
These bulit-in rules know how to build C, C++, Objective-C, Assembler, Fortran and several other programs.
All that we need to tell `make` is the dependencies.

## Command Echo
Per default, `make` will tell us what commands it is executing.
This is called "command echo".
Command echo can be suppressed for individual commands by prefixing them with `@`.
Command echo can be suppressed for the entire `make` run by calling `make` with option `-s` (the `-s` stands for "silent").

Warning: Only use `@` in special situations, like the `echo` commands of a `make help`.

## Non-file targets - `.PHONY` targets
Some targets in our `Makefile`s will be files, and some will not.
Example:
```make
SHELL:=bash

.PHONY: test
test: hello
	diff <<<"Hello, world!" - <(./hello)

.PHONY: clean
clean:
	$(RM) hello
```
In this `Makefile`, the targets `test` and `clean` represent steps but they do not represent files.
Such targets should be declared as `.PHONY`.
The `.PHONY` declaration suppresses the incremental build feature, that is, `make` will not check a `.PHONY` target for the presence and timestamp of a file of the same name.
Thus, even if a file named `test` or `clean` exists, the targets `test` and `clean` would still be executed in the above example.
If the `.PHONY` declaration were missing, the presence of a file named `test` or `clean` would suppress the execution of the `test` or `clean` targets.

## Timestamp files
Non-file targets cannot be incremental because there is no file with a timestamp on the filesystem representing the target.
We can change that by creating a timestamp file.
Example:
```make
.PHONY: test
## test:	Runs the tests. ⇐ Default
test: .test-success
.test-success: hello
	diff <<<"Hello, world!" - <(./hello)
	touch .test-success
```
`.test-success` is a so-called "timestamp file".
Timestamp files are normal files without any content.
All that matters is whether they exist and what their timestamp is.

In above example, the file `.test-success` makes the tests incremental, that is, if the tests passed successfully, and nothing changed, the tests will not be run again.

## Pattern rules
Pattern rules allow rules to be phrased for multiple files.

Example:
```make
%.class: %.java
	javac $^
```

## Including other Makefiles
A `Makefile` can include other `Makefile`s using the `include` directive.
Use `-include` if you need the `include` directive to work even in case the other `Makefile`s don't exist and cannot be made.

Example:
```make
CPPFLAGS:=-MMD

-include *.d
```

## Tips for good `Makefile`s
- Do not automatically clean before building.
- Try to create portable Makefiles, that is, Makefiles that work well on both, Windows and Unix (Linux/Mac OS).
  For example, use `$(RM)` instead of `rm -f` or `del`.
- Good `Makefile`s have a built-in help. See the `hello` subdirectory for an example.
- Good `Makefile`s follow the conventions.
  For example, the default goal should be named `all` and the goal that removes generated files should be named `clean`.
- [Makefile conventions](https://www.gnu.org/prep/standards/html_node/Makefile-Conventions.html)
