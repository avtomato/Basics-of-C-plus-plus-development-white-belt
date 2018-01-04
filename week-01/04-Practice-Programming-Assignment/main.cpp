#include <iostream>

using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b;
    
    if (b != 0) {
        c = a / b;
        cout << c;
    } else {
        cout << "Impossible";
    }
    
    return 0;
}
