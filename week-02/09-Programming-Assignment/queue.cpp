#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int Q;
    cin >> Q;
    vector<int> v;

    int n = 0;
    while (n < Q){
        string s;
        cin >> s;
        if (s == "COME") {
            int k;
            cin >> k;
            int c = v.size() + k;
            v.resize(c, 0);
        } else if(s == "WORRY") {
            int i;
            cin >> i;
            v[i] = 1;
        } else if(s == "QUIET") {
            int i;
            cin >> i;
            v[i] = 0;
        } else if(s == "WORRY_COUNT") {
            int quanity = count(begin(v), end(v), 1);
            cout << quanity << endl;
        }
        n += 1;
    }

    return 0;
}
