#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    int m = 0;
    vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int q;
    cin >> q;

    vector<vector<string>> v(31, vector<string>());

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;
        if (operation_code == "ADD") {
            string s;
            int i;
            cin >> i;
            cin >> s;
            v[i-1].push_back(s);
        } else if (operation_code == "DUMP") {
            int i;
            cin >> i;
            cout << v[i-1].size();
            for (string s: v[i-1]) {
                cout << " " << s;
            }
            cout << endl;
        } else if (operation_code == "NEXT") {
            m += 1;
            if (m == 12) {
                m = 0;
            }
            if (m == 0) {
            } else {
                if (days_in_months[m] == 28) {
                    v[27].insert(end(v[27]), begin(v[28]), end(v[28]));
                    v[28].clear();
                    v[27].insert(end(v[27]), begin(v[29]), end(v[29]));
                    v[29].clear();
                    v[27].insert(end(v[27]), begin(v[30]), end(v[30]));
                    v[30].clear();
                } else if (days_in_months[m] == 30) {
                    v[29].insert(end(v[29]), begin(v[30]), end(v[30]));
                    v[30].clear();
                }
            }
        }
    }

    return 0;
}
