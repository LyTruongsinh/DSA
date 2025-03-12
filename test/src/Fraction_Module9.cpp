#include <iostream>
#include <numeric>  // std::gcd
using namespace std;

class Fraction {
    int a, b; 
public:
    Fraction(int a = 1, int b = 1) {
        if (b == 0) {
            cout << "invalid" << endl;
            this->a = 0;
            this->b = 1;
        } else {
            this->a = a;
            this->b = b;
            simplify();
        }
    }
    void simplify() {
        int gcd = std::gcd(a, b);
        a /= gcd;
        b /= gcd;
        if (b < 0) {  
            a = -a;
            b = -b;
        }
    }
    Fraction operator+(const Fraction& f) const {
        return Fraction(a * f.b + f.a * b, b * f.b);
    }
    Fraction operator-(const Fraction& f) const {
        return Fraction(a * f.b - f.a * b, b * f.b);
    }
    Fraction operator*(const Fraction& f) const {
        return Fraction(a * f.a, b * f.b);
    }

    Fraction operator/(const Fraction& f) const {
        return Fraction(a * f.b, b * f.a);
    }

    bool operator>(const Fraction& f) const {
        return a * f.b > f.a * b;
    }

    bool operator<(const Fraction& f) const {
        return a * f.b < f.a * b;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.b == 0) {
            os << "invalid";
        } else {
            os << f.a << "/" << f.b;
        }
        return os;
    }
};

int main() {
    Fraction f1(2, 3), f2(4, 5);
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;

    cout << "f1 > f2: " << (f1 > f2 ? "True" : "False") << endl;
    cout << "f1 < f2: " << (f1 < f2 ? "True" : "False") << endl;

    return 0;
}
