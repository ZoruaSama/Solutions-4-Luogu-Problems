#include <iostream>

using namespace std;
string s1, s2;  //NOLINT

string divide(const string &s, int i) {
    if (s.empty()) return "";
    if (i == s2.length() + 1) return "";
    char ch = s2[s2.length() - i];
    if (s.find(ch) == -1) return divide(s, i + 1);
    string l = s.substr(0, s.find(ch));
    string r;
    if (s.find(ch) + 1 != s.length()) {
        r = s.substr(s.find(ch) + 1, s.length());
    }
    return ch + divide(l, i + 1) + divide(r, i + 1);
}

int main() {
    cin >> s1 >> s2;
    cout << divide(s1, 1);
    return 0;
}
