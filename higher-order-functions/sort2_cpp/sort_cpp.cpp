#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

auto by_alphabet = [](const string &s1, const string &s2) { return s1 < s2; };
auto by_length =   [](const string &s1, const string &s2) { return s1.length() < s2.length(); };

bool (*comparator)(const string &, const string &) = by_alphabet;

vector<string> readLines() {
    vector<string> lines;
    for (string line; getline(cin, line);)
        lines.push_back(line);
    return lines;
}

void sortLines(vector<string> &lines) {
    sort(lines.begin(), lines.end(), comparator);
}

void printLines(vector<string> &lines) {
    for (auto word : lines)
        cout << word << endl;
}

void parseCommandLineArguments(int argc, char *argv[]) {
    if (argc > 1 && string(argv[1]).rfind("--", 0) == 0) {
        if (string(argv[1]) == "--length")
            comparator = by_length;
        ++argv;
    }
}

int main(int argc, char *argv[]) {
    parseCommandLineArguments(argc, argv);

    vector<string> lines = readLines();
    sortLines(lines);
    printLines(lines);
}
