#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    //// Solution A
    //string hours = "([01][0-9]|2[0-3])";
    //string minutesOrSeconds = "([0-5][0-9])";
    //regex timePattern(hours + "(" + ":" + minutesOrSeconds + "){1,2}");

    // Solution B (preferred)
    string hours = "([01][0-9]|2[0-3])";
    string minutes = "([0-5][0-9])";
    string seconds = "([0-5][0-9])";
    regex timePattern(hours + ":" + minutes + "(" + ":" + seconds + ")?");

    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        smatch m;
        if (regex_match(arg, m, timePattern)) {
            cout << arg << " is a valid time." << endl;
        } else {
            cout << arg << " is not a valid time." << endl;
            return 1;
        }
    }
}
