#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    // считываем вектор
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v) {
        cin >> x;
    }

    // сортируем
    sort(begin(v), end(v),
            // функция, сравнивающая abs(l) и abs(r) — модули чисел l и r
         [](int l, int r) {
             return abs(l) < abs(r);
         }
    );

    // выводим отсорированный вектор
    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}
