#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class ReversibleString {
public:
    ReversibleString () {
        word = "";
    }
    ReversibleString (const string& w) {
        word = w;
    }

    void Reverse() {
        vector<char> v;
        
        for (int i = 0; i < word.size(); ++i) {
            v.push_back(word[i]);
        }
        
        reverse(begin(v), end(v));
        
        word = "";
            
        for (auto i : v) {
            word += i;
        }
    }

    string ToString() const {
        return word;
    }

private:
    string word;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
