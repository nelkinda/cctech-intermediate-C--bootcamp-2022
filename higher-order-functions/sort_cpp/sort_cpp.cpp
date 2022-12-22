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

int main(int argc, char *argv[]) {
    vector<string> words;
    while (*++argv)
        words.push_back(*argv);
    sort(words.begin(), words.end(), [](const string &w1, const string &w2) { return w1 < w2; } );
    for (auto word : words)
        cout << word << endl;
}
