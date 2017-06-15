#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> bits;

    cin >> n;
    while (n > 0) {
        bits.push_back(n % 2);
        n /= 2;
    }

    for (int i = bits.size() - 1; i >= 0; --i) {
        cout << bits[i];
    }
    return 0;
}
