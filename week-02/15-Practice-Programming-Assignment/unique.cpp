#include <iostream>
#include <set>

using namespace std;


int main() {

    int q;
    cin >> q;

    set<string> numbers;

    for (int i = 0; i < q; ++i) {
        string n;
        cin >> n;
        numbers.insert(n);
    }

    cout << numbers.size();

    return 0;
}