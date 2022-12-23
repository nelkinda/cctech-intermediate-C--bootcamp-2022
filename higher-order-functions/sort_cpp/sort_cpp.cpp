#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Exercise:
// - The first argument now shall be a string "--length" or "--alphabet"
// - If the first argument is "--length", the remaining strings shall be sorted by their length.
// - If the first argument is "--alphabet", the remaining strings shall be sorted alphabetically.
// - If the first argument does not start with "--", the strings shall be sorted alphabetically.

//bool by_alphabet(const string &w1, const string &w2) { return w1 < w2; };
//bool by_length(const string &w1, const string &w2) { return w1.length() < w2.length(); };

// The variable by_comparator is the strategy design pattern.
// It allows switching between different algorithms ("strategies") at runtime.
// The two strategies available in this program for the by_comparator are by_alphabet and by_length.

int main(int argc, char *argv[]) {
    auto by_alphabet = [](const string &w1, const string &w2) { return w1 < w2; };
    auto by_length =   [](const string &w1, const string &w2) { return w1.length() < w2.length(); };

    bool (*comparator)(const string &, const string &) = by_alphabet;
    vector<string> words;
    if (argc > 1 && string(argv[1]).rfind("--", 0) == 0) {
        if (string(argv[1]) == "--length")
            comparator = by_length;
        ++argv;
    }
    while (*++argv)
        words.push_back(*argv);
    sort(words.begin(), words.end(), comparator);
    for (auto word : words)
        cout << word << endl;
}
