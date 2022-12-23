#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

string &toLowerCase(string &s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
    return s;
}

int main(void) {
    map<string, int> wordcount;
    for (string word; cin >> word;) {
        word = toLowerCase(word);
        if (!wordcount.count(word))
            wordcount.emplace(word, 0);
        wordcount[word]++;
    }

    for (auto entry : wordcount)
        cout << entry.first << ": " << entry.second << endl;
}
