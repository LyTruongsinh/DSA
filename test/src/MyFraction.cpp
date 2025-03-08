#include <iostream>
#include <algorithm>
using namespace std;
class MyFraction
{
private:
    int a;
    int b;
    int UCLN(int x, int y)
    {
        if (y == 0)
            return x;
        return UCLN(y, x % y);
    }
    void simplify()
    {
        if (b == 0)
            return;
        if (a > 0)
        {
            if (b > 0)
            {
                int gcd = UCLN(a, b);
                a /= gcd;
                b /= gcd;
            }
            else
            {
                int gcd = UCLN(a, -b);
                a /= gcd;
                a = -a;
                b = -b;
                b /= gcd;
            }
        }
        else
        {
            if (b > 0)
            {
                int gcd = UCLN(-a, b);
                a /= gcd;
                b /= gcd;
            }
            else
            {
                int gcd = UCLN(-a, -b);
                a /= -gcd;
                b /= -gcd;
            }
        }
    }

public:
    MyFraction(int _a, int _b) : a(_a), b(_b)
    {
        simplify();
    }
    void print() const
    {
        if (b == 0)
        {
            std::cout << "invalid" << std::endl;
        }
        else
        {
            std::cout << a << "/" << b << std::endl;
        }
    }
    MyFraction add(const MyFraction &f) const
    {
        int new_a = a * f.b + b * f.a;
        int new_b = b * f.b;
        return MyFraction(new_a, new_b);
    }
    MyFraction subtract(const MyFraction &f) const
    {
        int new_a = a * f.b - b * f.a;
        int new_b = b * f.b;
        return MyFraction(new_a, new_b);
    }
    MyFraction multiply(const MyFraction &f) const
    {
        int new_a = a * f.a;
        int new_b = b * f.b;
        return MyFraction(new_a, new_b);
    }
    MyFraction divide(const MyFraction &f) const
    {
        int new_a = a * f.b;
        int new_b = b * f.a;
        return MyFraction(new_a, new_b);
    }
    int compare(const MyFraction &f) const
    {
        int new_a = a * f.b;
        int new_b = b * f.a;
        return new_a > new_b ? 1 : (new_a < new_b ? -1 : 0);
    };
};
int main()
{
    MyFraction f1(2, 3);
    MyFraction f2(4, 2);
    f1.print();
    f2.print();
    MyFraction sum = f1.add(f2);
    sum.print();
    return 0;
}