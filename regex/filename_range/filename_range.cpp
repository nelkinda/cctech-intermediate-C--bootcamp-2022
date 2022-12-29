#include <cassert>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

string optionalParentDirectories = "(?:.*/)?";
string optionalTestPrefixOrSuffixSeparator = "[-_]?";
string testPrefixOrSuffix = "(?:[Tt]est|[Ss]pec|[Ss]tep)s?";
string optionalTestPrefix = "(?:" + testPrefixOrSuffix + optionalTestPrefixOrSuffixSeparator + ")?";
string partToBeRenamed = "(.*?)";
string optionalTestSuffix = "(?:" + optionalTestPrefixOrSuffixSeparator + testPrefixOrSuffix + ")?";
string optionalFileSuffix = "(?:[.].*)?";
regex pattern(optionalParentDirectories + optionalTestPrefix + partToBeRenamed + optionalTestSuffix + optionalFileSuffix);
//regex pattern2("(?:.*/)?(?:(?:[Tt]est|[Ss]pec|[Ss]tep)s?[-_]?)?(.*?)(?:[-_]?(?:[Tt]est|[Ss]pec|[Ss]tep)s?)?(?:[.].*)?");

void assertMatch(string sample, string expectedGroup1) {
    smatch m;
    if (regex_match(sample, m, pattern)) {
        assert(m[1] == expectedGroup1);
    } else {
        assert(false);
    }
}

void testOptionalParentDirectories() {
    assertMatch("foo", "foo");
    assertMatch("src/with/directories/foo", "foo");
}

int main(int argc, char *argv[]) {
    testOptionalParentDirectories();
    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        smatch m;
        if (regex_match(arg, m, pattern))
            cout << "\"" << arg << "\": [" << m.position(1) << "," << (m.position(1) + m.length(1)) << "]," << endl;
    }
}
