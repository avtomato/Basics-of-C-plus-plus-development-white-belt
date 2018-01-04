#include <iostream>
#include <string>
#include <map>

using namespace std;


map<char, int> BuildCharCounters(string& s) {
    map<char, int> counters;
    for (const char& c : s) {
        ++counters[c];
    }
    return counters;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        string s1, s2;
        cin >> s1 >> s2;

        map<char, int> t = BuildCharCounters(s1);
        map<char, int> t2 = BuildCharCounters(s2);
        if (t == t2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
