# Modules


## Reasons for modules
- Independent developability of parts of a software system
- Reuse
- Ease of change

## Levels of modules

Construction-level modularization
- Source modules (`*.c` / `*.cpp`)
- Header files (`*.h`)
  provide reuse through the preprocessor
- Object files (`*.o`)
  provide reuse of single object files through the linker
- (static) Library files (`*.a`, `*.lib`)
  provide reuse of multiple object files through the linker

Deployment-level modularization
- Dynamic link libraries (`*.so`, `*.dll`)

Phrasing modularization
- Classes
- Functions
- Templates
- Macros
- Global Variables (avoid!)

Plus something that automates your process!

## Philosophy
- Divide and Conquer
- Modularization is the physical mechanisms
- Software design is the rationale and reasoning of decisions about modularization
- Elementary particles of modularization: individual instructions of the Turing machine or individual terms of the Lambda calculus -> statements and expressions, can only be reused through copy-paste (or goto)
- Atoms and molecules of modularization: functions and classes, can be reused through name
- Colocation of cohesion into a named element
- Names are crucial for reuse
  - Name categories: technical domain and business domain
  - Names need to communicate intent
  - Intent often is the glue and transition between technical domain and business domain
- Cohesion is the nature of things to change together
  - We call things "cohesive" when it is natural for them to change together
- Unix philosophy: "Everything should do one thing, it should do it well, and it should do it only."
  aka SRP: Single Responsibility Principle
  "Every class should have only one reason for change." ― Robert C. Martin
  "Every entity in a software system should, on its level of abstraction and granularity, have only one reason for change." ― Christian Hujer
- Colocation is a measure of the proximity of elements
- We want colocation to mirror cohesion:
  Things that change together should be placed closely together.
  Things that do not change together should be placed further apart from each other.
- Repetition (Duplication) is an indicator for a lack of colocation for cohesion.
- Beware: Not every apparent duplication is a cohesion!
  Ask yourself: If one duplicate changes, would the other have to change as well?
  Yes ⇒ accidental duplication, cohesion, remove duplication
  No ⇒ apparent (coincidental) justified duplication, keep
  Removing duplication often requires the introduction of an abstraction.
  Beware: The wrong abstraction can be worse than duplication.
  Martin Fowler: "Rule of Three" - find (or wait for) 3 duplicates to understand the abstraction.
  "3" is a wild card: Wait for a number of duplicates that gives you high confidence in your abstraction.
- Duplication: Duplication is more than "looks similar".
  Real duplication is cohesion: "changes for the same reasons".
- Software design is about giving maintainable structure to behavior.
- Users care about behavior.
- Structure is for us, developers, to enable us to deliver behavior with less risk, less effort, and higher confidence.
- Coupling: A dependency that propagates change.
- 5 Design smells
  - Rigidity: Code is hard (high effort) to change, caused by coupling and lack of cohesion
  - Fragility: Code is risky to change, caused by coupling and lack of cohesion
  - Inseparability: Code is not reusable, caused by coupling and lack of cohesion
  - Opacity: Code is difficult to understand
  - Viscosity: It is slow and difficult to get feedback on code (and change)
  ⇒ Caused by coupling and lack of (colocation for) cohesion
- Abstraction and Modularization
  - To decouple and colocate
  - Decouple: Prevent (negative effects like effort and risk of) change propagation through abstraction
  - Colocate: Reduce effort and risk of change by reducing motion across structure when performing change on cohesive elements through modularization by responsibility

- A fundamental question: Does it scale?
  What if the volume increases? What if we have more of this?



Question: What do you think is easier to understand:
- A: A single function with 100 lines
- B: 10 functions with 10 lines each
Answer: B (and we imply that the functions have good names that inform, communicate intent, and do not misinform.)




map<item,int> itemMap; // bad, does not communicate intent
map<item,int> shoppingCartContent; // good, does communicate intent



## Modularization in C
- Use #include <> syntax for system includes.
- Use #include "" syntax for project includes.
- Protect header files from unnecessary duplicate inclusion using include shields. Pattern:
```c
// File header.h
#ifndef HEADER_H
#define HEADER_H

// Actual contents go here.

#endif
```
- Header files should be self-contained. If a declaration in a header file needs another header file, it is the responsibility of this header file to include the other header file.
