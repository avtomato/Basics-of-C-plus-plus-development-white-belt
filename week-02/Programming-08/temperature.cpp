#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int n, sum = 0, average;
    cin >> n;
    vector<int> v(n);

    for (int & s : v) {
        cin >> s;
        sum += s;
    }

    average = sum / n;
    vector<int> temperature;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] > average) {
            temperature.push_back(i);
        }
    }

    cout << temperature.size() << endl;

    for (const auto& num : temperature) {
        cout << num << " ";
    }

    return 0;
}
