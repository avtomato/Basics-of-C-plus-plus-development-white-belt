#include <iostream>
#include <string>
#include <vector>

using namespace std;


void MoveStrings(vector<string>& source , vector<string>& destination) {
    for (auto w : source) {
        destination.push_back(w);
    }
    source.clear();
}

int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    // source должен оказаться пустым
    // destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
    cout << source.size() << endl;
    cout << destination.size() << endl;
    for (auto c : destination) {
        cout << c;
    }

    return 0;
}
