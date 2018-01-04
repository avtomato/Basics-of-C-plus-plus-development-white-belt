#include <iostream>

using namespace std;


int Factorial(int x){
    if (x < 1) {
        return 1;
    } else {
        x = x * (Factorial((x - 1)));
        return x;
    }
}

int main() {
    int y;
    cin >> y;
    
    cout << Factorial(y);

    return 0;
}
