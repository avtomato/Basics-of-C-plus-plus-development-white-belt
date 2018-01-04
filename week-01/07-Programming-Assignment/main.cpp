#include <iostream>
#include <string>

using namespace std;


int main() {
    int n = 0;
    int i = 0;
    string s;
    cin >> s;

    while (i < s.size()) {
        if (s[i] == 'f') {
            n += 1;
        }
        if (n == 2) {
            cout << i;
            break;
        }
        i += 1;
    }
    if (n == 1) {
        cout << "-1";
    } else if (n == 0) {
        cout << "-2";
    }

    return 0;
}
