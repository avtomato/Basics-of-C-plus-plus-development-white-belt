#include <iostream>
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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}