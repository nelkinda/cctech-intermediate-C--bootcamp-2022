# The C/C++ Preprocessor

C compilation works in multiple steps:
- Preprocessor
- Compiler
- Assembler
- Optional: Archiver (Librarian)
- Linker

<dl>
<dt>Preprocessor</dt><dd>Translates unprocessed source code into processed source code.</dd>
<dt>Compiler</dt><dd>Parses processed source code into a syntax tree and compiles it, that is, emits assembler code that is an executable representation of the syntax tree.</dd>
<dt>Assembler</dt><dd>Translates assembler code into machine code.</dd>
<dt>Archiver (Librarian)</dt><dd>Collects multiple object files (machine code) into a single easy-to-handle archive (library) file.</dd>
<dt>Linker</dt><dd>Binds multiple object files (directly or from archives) together into a single executable binary.</dd>
</dl>

- `*.c` / `*.cpp` [preprocessor]⇒ `*.i` / `*.ii`
- `*.i` / `*.ii` [compiler]⇒ `*.s`
- `*.s` [assembler]⇒ `*.o`
- `*.o` [archiver]⇒ `*.a` (Optional, explicit)
- `*.o` `*.a` [linker]⇒ binary executable

You can see the intermediate files by adding `-save-temps` to the command line arguments of GCC or clang.
You can automate this by adding the following line to your `Makefile`:
```make
CPPFLAGS:=-save-temps
```

## What is the C Preprocessor?
It's a powerful text-replacement engine.
Engines which are geared towards text-replacement and automation are often also called macro-processors.

### Line markers
The C Preprocessor emits line markers to the compiler so that the compiler understands where the text that it sees was originally coming from.

### Comments
The C Preprocessor removes comments.

### File Inclusion
The C Preprocessor replaces an include statement with the contents of the included file, emitting line markers to keep track.
The replaced text will then be processed by the preprocessor.

There are two syntaxes for `#include` statements:
- `#include <file.h>` to include a system header file from the OS or compiler.
- `#include "file.h"` to include a project header file from the developer.

Important: Using `\` inside an inlude path is undefined behavior!

#### Include Shields

To prevent a file from being included multiple times unnecessarily, wrap header file contents in an include shield.

```c
#ifndef MYINCLUDE_H
#define MYINCLUDE_H 1

// Regular contents of the header file

#endif
```

## Macros and Macro Replacement
Tip: Do not put `;` at the end of macro definitions!
Important Tip: Always surround macro argument replacement with () to prevent operator precedence confusion!
Important Tip: Always surround the entire macro expression replacement with () to prevent operator precedence confusion!
Tip: Use the backslash to spread a long macro definition across multiple lines.

To define a simple macro:
```
#define NAME value
```

To define an expression macro aka function-like macro:
```
#define NAME(ARG1, ARG2) replacement-using-ARG1-and-ARG2
```

To define an expression macro with a variable number of arguments:
```
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
```

Good practice: Enclose statement-like macros in `do { ... } while (0)` (without the semicolon) to force the user of the macro to put the semicolon.

For replacement:
```
// Simple replacement:
#define NAME(ARG) ARG

// Stringification:
#define NAME(ARG) #ARG

// Token concatenation:
#define NAME(ARG) PREFIX ## ARG
```

### Conditional Compilation

This is like a comment:
```
#if 0
...
#endif
```

```
#if cond
...
#else
...
#endif
```

Test if a macro is defined:
```
#if defined(macro)
#endif
```

```
#ifdef N
```
is just a shorthand for
```
#if defined(N)
```

```
#ifndef N
```
is just a shorthand for
```
#if !defined(N)
```

```
#if cond1
...
#elif cond2
...
#else
...
#endif
```

## Why and when to use conditional compilation?
- To switch something like assertions off.
- To switch debug code that is only for development off.
- To support optional features of the target platform.
- For configuration.
  (Nowadays we prefer runtime configuration _IF_ we have the resources.)
  Examples: Linux Kernel, SIM card OS, smart card OS
- For migration between old and new, or just different, library dependencies.
- To have multiple versions with different configurations.
- To build a new feature and be able to switch it off as long as it's not finished.

## Naming conventions for macros
- Follow the lead of the specification.
- Simple expression macros are in uppercase, like `INT_MAX` or `UINT8_MAX`.
- Function-like macros that behave correctly with their surroundings (`if`-safe and semicolon-demanding through `do-while`, arguments evaluated only once, no precedence confusion) are in lowercase, like `assert()`.
- All other macros in uppercase, like `MY_MACRO`.
- Projects might have their own conventions, follow them.

# Misellaneous
- NEVER use the `_` prefix for your own symbol names.
