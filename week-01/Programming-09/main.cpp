#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, x;
    cin >> n;

    vector<int> v;

    while (n > 0) {
        x = n % 2;
        v.push_back(x);
        n  /= 2;
    }

    reverse(begin(v), end(v));

    for (auto i : v) {
        cout << i;
    }

    return 0;
}
