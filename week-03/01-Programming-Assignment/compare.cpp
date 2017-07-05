#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void PrintVector(const vector<int>& v) {
    for (const auto i : v) {
        cout << i << " ";
    }
}

bool Compare(int i, int j) {
    return abs(i) < abs(j);
}

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int& s : v) {
        cin >> s;
    }

    sort(begin(v), end(v), Compare);
    PrintVector(v);

    return 0;
}