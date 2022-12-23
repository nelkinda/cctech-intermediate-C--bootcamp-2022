#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Sorter {
private:
    static bool by_alphabet(const string &s1, const string &s2) { return s1 < s2; };
    static bool by_length  (const string &s1, const string &s2) { return s1.length() < s2.length(); };

    vector<string> lines;
    bool (*comparator)(const string &, const string &) = by_alphabet;

public:
    void parseCommandLineArguments(int argc, char *argv[]) {
        if (argc > 1 && string(argv[1]).rfind("--", 0) == 0) {
            if (string(argv[1]) == "--length")
                comparator = by_length;
            ++argv;
        }
    }

    void readLines() {
        for (string line; getline(cin, line);)
            lines.push_back(line);
    }

    void sortLines() {
        sort(lines.begin(), lines.end(), comparator);
    }

    void printLines() {
        for (auto word : lines)
            cout << word << endl;
    }
};

int main(int argc, char *argv[]) {
    Sorter sorter;
    sorter.parseCommandLineArguments(argc, argv);

    sorter.readLines();
    sorter.sortLines();
    sorter.printLines();
}
