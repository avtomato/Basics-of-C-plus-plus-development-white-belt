#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // считываем вектор строк
    int n;
    cin >> n;
    vector<string> v(n);
    for (string& s : v) {
        cin >> s;
    }

    // сортируем
    sort(begin(v), end(v),
            // компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
         [](const string& l, const string& r) {
             // сравниваем лексикографически...
             return lexicographical_compare(
                     // ... все символы строки l ...
                     begin(l), end(l),
                     // ... со всеми символами строки r ...
                     begin(r), end(r),
                     // ..., используя в качестве компаратора сравнение отдельных символов без учёта регистра
                     [](char cl, char cr) { return tolower(cl) < tolower(cr); }
             );
         }
    );

    // выводим отсортированный вектор
    for (const string& s : v) {
        cout << s << ' ';
    }

    return 0;
}
