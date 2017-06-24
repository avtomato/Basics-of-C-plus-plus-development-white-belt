#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {

    ifstream input("input.txt");

    int row = 0;
    int column = 0;

    if (input.is_open()) {
        input >> row;
        input.ignore(1);
        input >> column;

        for (int i=0; i < row; ++i) {
            for (int j=0; j <= (column*2-1); ++j) {
                int n;
                cout << setw(10) << fixed;
                if (j % 2 == 0 && j < (column*2-2)) {
                    input >> n;
                    cout << n << " ";
                } else if (j % 2 == 0 && j == (column*2-2)) {
                    input >> n;
                    cout << n;
                } else {
                    input.ignore(1);
                }
            }
            cout << endl;
        }
    }

    return 0;
}
