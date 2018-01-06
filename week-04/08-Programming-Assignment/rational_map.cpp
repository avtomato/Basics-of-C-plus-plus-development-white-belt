#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;



class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        int a = numerator, b = denominator, c = 0;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }
        if (denominator / a < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        p = numerator / a;
        q = denominator / a;
    }

    int Numerator() const {
        // Реализуйте этот метод
        return p;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return q;
    }

private:
    // Добавьте поля
    int p;
    int q;
};

bool operator == (const Rational& lhs, const Rational& rhs) {
    int a = lhs.Denominator(), b = rhs.Denominator(), c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    int n = (lhs.Denominator() * rhs.Denominator()) / a;
    int l = n / lhs.Denominator();
    int r = n / rhs.Denominator();
    return (lhs.Numerator() * l) == (rhs.Numerator() *r);
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    int a = lhs.Denominator(), b = rhs.Denominator(), c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    int n = (lhs.Denominator() * rhs.Denominator()) / a;
    int l = n / lhs.Denominator();
    int r = n / rhs.Denominator();
    return (lhs.Numerator() * l) < (rhs.Numerator() *r);
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    int a = lhs.Denominator(), b = rhs.Denominator(), c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    int n = (lhs.Denominator() * rhs.Denominator()) / a;
    int l = n / lhs.Denominator();
    int r = n / rhs.Denominator();
    return Rational((lhs.Numerator() * l) + (rhs.Numerator() *r), n);
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    int a = lhs.Denominator(), b = rhs.Denominator(), c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    int n = (lhs.Denominator() * rhs.Denominator()) / a;
    int l = n / lhs.Denominator();
    int r = n / rhs.Denominator();
    return Rational((lhs.Numerator() * l) - (rhs.Numerator() *r), n);
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

ostream& operator << (ostream& out, const Rational& rational) {
    out << rational.Numerator() << '/'  << rational.Denominator();
    return out;
}

istream& operator >> (istream& in, Rational& rational) {
    int p;
    in >> p;
    in.ignore(1);
    int q;
    in >> q;
    rational = Rational(p, q);
    return in;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
