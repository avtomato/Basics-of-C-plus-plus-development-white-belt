#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> palindrom;
    for (auto w : words) {
        string r = "";
        for (int i = w.size() - 1; i >= 0; --i) {
            r += w[i];
        }
        if (w == r and w.size() >= minLength){
            palindrom.push_back(w);
        }
    } return palindrom;
}

int main() {

    vector<string> v;
    int n;
    cin >> n;
    vector<string> total;
    total = PalindromFilter(v, n);
    for (auto t : total) {
        cout << t << " ";
    }

    return 0;
}