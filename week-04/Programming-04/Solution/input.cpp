#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");

    string line;
    while (getline(input, line)) {
        cout << line << endl;
    }

    return 0;
}
