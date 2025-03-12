#include <iostream>
#include <numeric> // std::gcd
using namespace std;

class Fraction
{
    int a, b;

public:
    Fraction(int a = 1, int b = 1)
    {
        if (b == 0)
        {
            this->a = 1; // Gán giá trị bất kỳ, không quan trọng vì sẽ in "invalid"
            this->b = 0;
        }
        else
        {
            this->a = a;
            this->b = b;
            simplify();
        }
    }

    void simplify()
    {
        if (b == 0)
            return; // Không cần tối giản nếu phân số không hợp lệ
        int gcd = std::gcd(a, b);
        a /= gcd;
        b /= gcd;
        if (b < 0)
        {
            a = -a;
            b = -b;
        }
    }

    Fraction operator+(const Fraction &f) const
    {
        if (b == 0 || f.b == 0)
            return Fraction(1, 0);
        return Fraction(a * f.b + f.a * b, b * f.b);
    }

    Fraction operator-(const Fraction &f) const
    {
        if (b == 0 || f.b == 0)
            return Fraction(1, 0);
        return Fraction(a * f.b - f.a * b, b * f.b);
    }

    Fraction operator*(const Fraction &f) const
    {
        if (b == 0 || f.b == 0)
            return Fraction(1, 0);
        return Fraction(a * f.a, b * f.b);
    }

    Fraction operator/(const Fraction &f) const
    {
        if (b == 0 || f.b == 0 || f.a == 0)
            return Fraction(1, 0);
        return Fraction(a * f.b, b * f.a);
    }

    bool operator>(const Fraction &f) const
    {
        if (b == 0 || f.b == 0)
            return false;
        return a * f.b > f.a * b;
    }

    bool operator<(const Fraction &f) const
    {
        if (b == 0 || f.b == 0)
            return false;
        return a * f.b < f.a * b;
    }

    friend ostream &operator<<(ostream &os, const Fraction &f)
    {
        if (f.b == 0)
        {
            os << "invalid";
        }
        else
        {
            os << f.a << "/" << f.b;
        }
        return os;
    }
};

int main()
{
    Fraction x(4, 5), y(2, 5), z(-8, 5);
    Fraction result1 = x + y;
    Fraction result2 = y - z;
    if (result1 < result2)
    {
        cout << "result1 < result2";
    }
    else
    {
        cout << "result1 >= result2";
    }
}
