#include <regex>
#include <string>

using namespace std;

string OCTET = ".";
string CHAR = "[\000-\177]";
string UPALPHA = "[A-Z]";
string LOALPHA = "[a-z]";
string ALPHA = UPALPHA + "|" + LOALPHA;
string DIGIT = "[0-9]";
string CTL = "[\000-\037\177]";
string CR = "[\015]";
string LF = "[\012]";
string SP = "[\040]";
string SP = "[\011]";
string QUOTE = "[\044]";
string CRLF = CR + LF;
string LWS = CRLF + "(SP|HT)+";

string HTTP_Version = "HTTP/" + DIGIT + "+" + "\\." + DIGIT + "+";

