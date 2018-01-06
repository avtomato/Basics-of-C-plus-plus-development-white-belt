#include <iostream>

using namespace std;


int GreatestCommonDivisor(int a, int b) {
    int n = a, m = b, c = 0;
    while (m != 0) {
        c = n % m;
        n = m;
        m = c;
    }
    return n;
}

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        // Реализуйте конструктор
        const int gcd = GreatestCommonDivisor(numerator, denominator);
        if (denominator / gcd < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        p = numerator / gcd;
        q = denominator / gcd;
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
    const int gcd = GreatestCommonDivisor(lhs.Denominator(), rhs.Denominator());
    int n = (lhs.Denominator() * rhs.Denominator()) / gcd;
    int l = n / lhs.Denominator();
    int r = n / rhs.Denominator();
    return (lhs.Numerator() * l) == (rhs.Numerator() *r);
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    const int gcd = GreatestCommonDivisor(lhs.Denominator(), rhs.Denominator());
    int n = (lhs.Denominator() * rhs.Denominator()) / gcd;
    int l = n / lhs.Denominator();
    int r = n / rhs.Denominator();
    return (lhs.Numerator() * l) < (rhs.Numerator() *r);
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    const int gcd = GreatestCommonDivisor(lhs.Denominator(), rhs.Denominator());
    int n = (lhs.Denominator() * rhs.Denominator()) / gcd;
    int l = n / lhs.Denominator();
    int r = n / rhs.Denominator();
    return Rational((lhs.Numerator() * l) + (rhs.Numerator() *r), n);
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    const int gcd = GreatestCommonDivisor(lhs.Denominator(), rhs.Denominator());
    int n = (lhs.Denominator() * rhs.Denominator()) / gcd;
    int l = n / lhs.Denominator();
    int r = n / rhs.Denominator();
    return Rational((lhs.Numerator() * l) - (rhs.Numerator() *r), n);
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
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

    Rational r1, r2;
    char operation;
    try {
        cin >> r1 >> operation >> r2;
        if (operation == '+') {
            cout << r1 + r2 << endl;
        } else if (operation == '-') {
            cout << r1 - r2 << endl;
        } else if (operation == '*') {
            cout << r1 * r2 << endl;
        } else if (operation == '/') {
            try {
                cout << r1 / r2 << endl;
            } catch (domain_error& de) {
                cout << de.what();
            }
        }
    } catch (invalid_argument& ia) {
        cout << ia.what();
    }

    return 0;
}
