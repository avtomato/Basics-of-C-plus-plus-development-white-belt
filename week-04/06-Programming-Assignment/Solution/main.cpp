#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");

    int n, m;
    input >> n >> m;

    // перебираем строки
    for (int i = 0; i < n; ++i) {
        // перебираем столбцы
        for (int j = 0; j < m; ++j) {
            // считываем очередное число
            int x;
            input >> x;
            // пропускаем следующий символ
            input.ignore(1);
            // выводим число в поле ширины 10
            cout << setw(10) << x;
            // выводим пробел, если только этот столбец не последний
            if (j != m - 1) {
                cout << " ";
            }
        }
        // выводим перевод строки, если только эта строка не последняя
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
