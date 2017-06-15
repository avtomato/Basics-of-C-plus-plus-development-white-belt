#include <iostream>

using namespace std;

void UpdateIfGreater(const int& first, int& second) {
    int tmp = first;
    if (first > second) {
        second = tmp;
    }
}

int main() {

    int a = 4;
    int b = 2;
    UpdateIfGreater(a, b);
    cout << b;

    return 0;
}
