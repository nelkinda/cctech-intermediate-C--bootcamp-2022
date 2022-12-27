#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string year = "[0-9]+";
    string month = "(0[1-9]|1[0-2])";
    string day = "(0[1-9]|[12][0-9]|3[01])";
    string date = year + "-" + month + "-" + day;

    string hours = "([01][0-9]|2[0-3])";
    string minutes = "([0-5][0-9])";
    string seconds = "([0-5][0-9])";
    string fractionSeconds = "([0-9]{3}){0,3}";
    string timezone = "(Z|[-+]" + hours + ":" + minutes + ")";
    string time = hours + ":" + minutes + "(" + ":" + seconds + "(" + "\\." + fractionSeconds + ")?" + ")?" + "(" + timezone + ")?";

    regex isoDateTimePattern("(" + date + "|" + time + "|" + date + "T" + time + ")");
    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        smatch m;
        if (regex_match(arg, m, isoDateTimePattern)) {
            cout << arg << " is a valid ISO 8601 date, time, or datetime." << endl;
        } else {
            cout << arg << " is not a valid ISO 8601 date, time, or datetime." << endl;
            return 1;
        }
    }
}
