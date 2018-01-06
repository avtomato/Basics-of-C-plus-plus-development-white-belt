#include <iostream>

using namespace std;


void EnsureEqual(const string& left, const string& right) {
    if (left != right) {
        throw runtime_error(left + " != " + right);
    } else {
        cout << left << " " << right << endl;
    }
};

int main() {
    string first = "1";
    string second = "2";

    try {
        EnsureEqual(first, second);
    } catch (const exception& ex) {
        cout << "exception: " << ex.what() << endl;
    }

    return 0;
}
