#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    regex pattern("([0-9a-zA-Z])\\1");
    smatch m;
    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        if (regex_search(arg, m, pattern)) {
            cout << argv[i] << " (" << m[1] << " in " << m[0] << ")" << endl;
        }
    }
}
