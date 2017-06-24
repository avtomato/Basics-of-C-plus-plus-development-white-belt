#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class Rational {
    // Вставьте сюда реализацию класса Rational
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {

    	if (denominator == 0) {
    		throw invalid_argument("zero denominator");
    	}

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

// Вставьте сюда реализацию operator / для класса Rational
Rational operator / (const Rational& lhs, const Rational& rhs) {

    if (rhs.Numerator() == 0) {
        throw domain_error("division by zero");
    }

    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
