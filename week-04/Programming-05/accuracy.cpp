#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    ifstream input("input.txt");

    double num;
    cout << setprecision(3) << fixed;
    if (input.is_open()) {
        while (input) {
            input >> num;
            if (input) {
                cout << num << endl;
            }
        }
    }
    return 0;
}
