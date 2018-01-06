#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class SortedStrings {
public:
    void AddString(const string& s) {
        // добавить строку s в набор
        v.push_back(s);
    }
    vector<string> GetSortedStrings() {
        // получить набор из всех добавленных строк в отсортированном порядке
        sort(begin(v), end(v));
        return v;
    }
private:
    // приватные поля
    vector<string> v;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
