#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    int q;
    cin >> q;
    map<int, vector<string>> buses;
    int m = 1;

    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (string& s : v) {
            cin >> s;
        }
        int c = 0;
        int j;
        for (const auto& item : buses) {
            if (item.second == v) {
                c = 1;
                j = item.first;
            }
        }
        if (c == 1) {
            cout << "Already exists for " << j << endl;
        } else if (c == 0) {
            buses[m] = v;
            cout << "New bus " << m << endl;
            m += 1;
        }
    }

    return 0;
}
