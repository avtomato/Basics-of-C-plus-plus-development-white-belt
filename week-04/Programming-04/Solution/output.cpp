#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while (getline(input, line)) {
        output << line << endl;
    }

    return 0;
}
