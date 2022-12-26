#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    // In the chat, put a number for how readable you find this regular expression.
    // Put 0 for not readable at all, 10 for super-easy to read.
    string year = "[0-9]+";
    string month = "(0[1-9]|1[0-2])";
    string day = "(0[1-9]|[12][0-9]|3[01])";
    regex datePattern(year + "-" + month + "-" + day);
    //regex datePattern("[0-9]+-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])");
/*
    - "[0-9]+" ⇒ any number of digits
    - "-" ⇒ the dash character
    - "(0[1-9]|1[0-2])"
      - "(" Start of group
      - "0[1-9]" 0 followed by 1, 2, 3, 4, 5, 6, 7, 8, or 9, that is, 01, 02, 03, 04, 05, 06, 07, 08, or 09.
      - "|" or
      - "1[0-2]" 1 followed by 0, 1, or 2, that is, 10, 11, 12.
      - ")" End of group
    - "-" ⇒ the dash character
    - "(0[1-9]|[12][0-9]|3[01])"
      - "(" Start of group
      - "0[1-9]" 0 followed by 1, 2, 3, 4, 5, 6, 7, 8, or 9, that is, 01, 02, 03, 04, 05, 06, 07, 08, or 09.
      - "|" or
      - "[12][0-9]" 1 or 2 followed by 0, 1, 2, 3, 4, 5, 6, 7, 8, or 9, that is, 10, 11, 12, ..., 28, or 29.
      - "|" or
      - "3[01]" 3 followed by 0 or 1, that is, 30, or 31.
      - ")" End of group
*/
    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        smatch m;
        if (regex_match(arg, m, datePattern)) {
            cout << arg << " is a valid date." << endl;
        } else {
            cout << arg << " is not a valid date." << endl;
            return 1;
        }
    }
}
