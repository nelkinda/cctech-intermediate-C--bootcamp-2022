# STL

The STL is the Standard Template Library, the standard library for C++, part of the C++ standard.
Every standards-compliant C++ compiler provides the Standard Template Library.

## Container Classes
Container classes are classes that provide easy access to frequently used common data structures.

The container classes provided by the STL are:
- `vector`
- `list`
- `stack`
- `queue`
- `map`
- `set`
- `multimap`
- `multiset`
- `unordered_map`
- `unordered_set`
- `unordered_multimap`
- `unordered_multiset`
- `array`
- `deque`
- `priority_queue`

Attributes of containers:
- Performance (time-complexity) of operations
- Allow or disallow duplicates
- Sequence (insertion-order, natural order, internal order)

## Exercise
Write a C++ program that for a text on stdin displays how many different words are contained in that text.
Words in different case, like "Write" at the start of a sentence, and "write" in the middle of a sentence, should be counted only once.
Punctuation shall be ignored.

Example (empty file):
```
```
⇒ 0

Example:
```
Two roads diverged in a yellow wood,
And sorry I could not travel both
And be one traveler, long I stood
And looked down one as far as I could
To where it bent in the undergrowth;
```
⇒ 29
