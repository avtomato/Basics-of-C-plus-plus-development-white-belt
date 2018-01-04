#include <iostream>
#include <string>

using namespace std;


bool IsPalindrom(string s) {
    string r = "";
    for (int i = s.size() - 1; i >= 0; --i) {
        r += s[i];
    }
    if (s == r) {
        return true;
    } else {
        return false;
    }
}


int main() {
    string s2;
    cin >> s2;
    
    cout << IsPalindrom(s2);

    return 0;
}
