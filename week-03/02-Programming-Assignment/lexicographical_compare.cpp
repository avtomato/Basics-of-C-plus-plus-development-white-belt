#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void PrintVector(const vector<string>& v) {
    for (const auto i : v) {
        cout << i << " ";
    }
}

string Transform(string& s) {
    string temp = "";
    for (int i = 0; i < s.size(); ++i) {
        temp += tolower(s[i]);
    }
    return temp;
}

bool Compare(string i, string j) {
    return Transform(i) < Transform(j);
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    
    for (string& w : v) {
        cin >> w;
    }

    sort(begin(v), end(v), Compare);
    PrintVector(v);

    return 0;
}
