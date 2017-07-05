#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, set<string>> synonyms;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "ADD") {

            string first_word, second_word;
            cin >> first_word >> second_word;

            // второе слово добавляем в список синонимов первого...
            synonyms[first_word].insert(second_word);
            // и наоборот
            synonyms[second_word].insert(first_word);

        } else if (operation_code == "COUNT") {

            string word;
            cin >> word;
            cout << synonyms[word].size() << endl;

        } else if (operation_code == "CHECK") {

            string first_word, second_word;
            cin >> first_word >> second_word;

            // ищём второе слово во множестве синонимов первого
            // (можно было сделать и наоборот)
            if (synonyms[first_word].count(second_word) == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

        }
    }

    return 0;
}
