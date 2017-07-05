#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    vector<bool> is_nervous;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "WORRY_COUNT") {

            // подсчитываем количество элементов в векторе is_nervous, равных true
            cout << count(begin(is_nervous), end(is_nervous), true) << endl;

        } else {
            if (operation_code == "WORRY" || operation_code == "QUIET") {

                int person_index;
                cin >> person_index;

                // выражение в скобках имеет тип bool и равно true для запроса WORRY,
                // поэтому is_nervous[person_index] станет равным false или true
                // в зависимости от operation_code
                is_nervous[person_index] = (operation_code == "WORRY");

            } else if (operation_code == "COME") {

                int person_count;
                cin >> person_count;

                // метод resize может как уменьшать размер вектора, так и увеличивать,
                // поэтому специально рассматривать случаи с положительным
                // и отрицательным person_count не нужно
                is_nervous.resize(is_nervous.size() + person_count, false);

            }
        }
    }

    return 0;
}
