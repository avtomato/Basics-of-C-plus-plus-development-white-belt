#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    vector<int> tmp;
    for (int i = v.size() - 1; i >= 0; --i) {
        tmp.push_back(v[i]);
    }
    v.clear();
    v = tmp;
}

int main() {

    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    // numbers должен оказаться равен {2, 4, 3, 5, 1}
    for (auto n : numbers) {
        cout << n << " ";
    }

    return 0;
}
