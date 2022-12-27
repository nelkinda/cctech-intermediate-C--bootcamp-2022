# Regular Expressions

What are regular expressions?
They are simple grammars for strings.
Isn't this cool!

## Examples
"What's your idea of a perfect date?"
"YYYY-MM-dd, everything else would be just confusing."
2022-12-26: Valid date in ISO-8601 / RFC 3339
10351-10-30: Valid date as well

Regular expression for date: `"[0-9]+-[0-9]{2}-[0-9]{2}"`
Similar regular expression for date: `"\d+-\d{2}-\d{2}"`
Similar regular expression for date: `"\d+(-\d{2}){2}"`

`.*`: Matches everything.
`\.$`: Full stop at the end of the line.
`[^.]$`: All lines that do not end with full stop.
`^#`: Hash symbol at the start of the line.
`^[^#]`: First symbol at the start of the line, when that symbol is not a hash symbol.
`^(?![#]|(  )*[-]).*[^.?!:]$`: Lines/strings that do not start with `#` and do not end with full stop or question mark.

`M[ae][ijy]e?r` The German name "Meier" in all its possible spellings.

## Components
- Atom: `a` matches the lowercase character `a`
- Sequence: Chaining atoms together. `at` matches the lowercase character `a` followed by the lowercase character `t`.
- Quantifier: Repeating the previous atom a specified number of times.
  - `*`: 0-n
  - `+`: 1-n
  - `?`: 0-1
  - `{n}`: Exactly n times
  - `{m,}`: At least m times
  - `{,n}`: At max n times
  - `{m,n}`: At least m, at max n times
- Wildcard: `.` matches any character
- Character class: `[abc]` Matches any of the characters in the character class.
  - `[shfjka]`: List of characters
  - `[a-k]`: Range of characters
  - `[^a-k]`: Negated range, matches all except `a-k`
  - `\d`: Shorthand for digits, same as `[0-9]`
  - `\w`: Shorthand for word characters, usually the same as `[a-zA-Z0-9]`
- Escape: Toggle the special meaning of a symbol. `\.` matches `.`.
- Group: `(X)` Groups a regular expression so that it can be used like an atom, plus it can be backreferenced.
- Group without number: `(?:X)` Groups a regular expression so that it can be used like an atom, but without number, so no backreference possible.
- Group modifier: (?!a) matches not a (in this case like `[^a]` but could be used for bigger things than atoms).
- Alternative: `(a|b)` matches a or b
- Anchor: Matches zero characters but a specified position
  - `^`: Start of line or string
  - `$`: End of line or string
  - `\<`: Start of word
  - `\>`: End of word
  - `\b`: Word boundary
- Backreference: `\\n` with n being a number of a previous group matches that previous group again.

## Flavors
There are different implementations of regular expressions.
They differ in syntax and capabilities.
They share a common base set of funcionality.
But extended functionality may differ or be unavailable depending on the engine.

Examples:
- POSIX regular expressions
- JavaScript regular expressions
- Perl regular expressions
- Java regular expressions (based on Perl)

## Use Cases
- Finding string (find/matching)
- Replacing strings (replace)

Use Case examples:
- grep (finding strings in files)
- sed (replacing strings in files)
- text editors (every powerful text editor supports find and replace with regular expressions)
- in programming for data validation and data parsing

## Exercise
- Write a program `isValidTime` that checks whether a given string is a valid time according to ISO 8601 / RFC 3339.
  The time could be 12:10:30 (including seconds) or 12:10 (without seconds).

## DISCLAIMER
- Time and date are nice examples for learning regular expressions.
  BUT: Time and date should never be checked for validity with regular expressions.
- Also, do not use regular expressions to check email addresses for validity (unless you have read the RFCs for email addresses and believe you can adhere to their specification - and if you're unsure about the answer, the answer is no).

## Homework / Assignment
- Write a program that uses a regular expression for validating an ISO 8601 date, time, or datetime string.
  - deal with leap seconds.
  - make the seconds optional.
  - if seconds are specified, make milliseconds, microseconds, and nanoseconds optional.
  - Allow for an optional time zone specifier, either as offset `+05:30` or as `Z` to denote UTC.
The following are examples for valid strings:
- `2022-12-26T06:55:30.741374147`
- `2022-12-26T06:55:30.741374147Z`
- `2022-12-26T12:25:30.741374147+05:30`
- `2022-12-26T06:55:30.741374`
- `2022-12-26T06:55:30.741374Z`
- `2022-12-26T12:25:30.741374+05:30`
- `2022-12-26T06:55:30.741`
- `2022-12-26T06:55:30.741Z`
- `2022-12-26T12:25:30.741+05:30`
- `2022-12-26T06:55:30`
- `2022-12-26T06:55:30Z`
- `2022-12-26T12:25+05:30`
- `2022-12-26T06:55`
- `2022-12-26T06:55Z`
- `2022-12-26T12:25:30+05:30`
