# Regular Expressions

What are regular expressions?
They are simple grammars for strings.
Isn't this cool!

## Example
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
- Escape: Toggle the special meaning of a symbol. `\.` matches `.`.
- Group: `()` Groups a regular expression so that it can be used like an atom, plus it can be backreferenced.
- Group modifier: (?!a) matches not a.
- Alternative: `(a|b)` matches a or b
- Anchor: Matches zero characters but a specified position
  - `^`: Start of line or string
  - `$`: End of line or string
  - `\<`: Start of word
  - `\>`: End of word
  - `\b`: Word boundary

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
