#include <iostream>
#include <regex>
#include <string>

using namespace std;

string optionalFileSuffix = "(?:[.].*)?";
string partToBeRenamed = "([^.]*)";
regex pattern(partToBeRenamed + optionalFileSuffix);

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        smatch m;
        if (regex_match(arg, m, pattern))
            cout << "\"" << arg << "\": [" << m.position(1) << "," << (m.position(1) + m.length(1)) << "], " << endl;
    }
}
