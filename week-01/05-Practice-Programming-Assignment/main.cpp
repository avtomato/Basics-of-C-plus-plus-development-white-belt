#include <iostream>

using namespace std;


int main() {
    double N, A, B, X, Y, p;
    cin >> N >> A >> B >> X >> Y;
    
    if (N < A && N < B) {
        p = N;
        cout << p;
    } else if (N >= A && N < B) {
        p = N - N * X / 100;
        cout << p;
    } else {
        p = N - N * Y / 100;
        cout << p;
    }
    
    return 0;
}
