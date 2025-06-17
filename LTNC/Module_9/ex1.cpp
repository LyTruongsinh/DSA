#include <cmath>
#include <iostream>

using namespace std;
struct Complex
{
    double a, b;
};
void print(const Complex &c)
{
    if (c.a != 0)
    {
        if (c.b > 0)
        {
            if (c.b == 1)
            {
                cout << c.a << "+"
                     << "i" << endl;
            }
            else
            {
                cout << c.a << "+" << c.b << "i" << endl;
            }
        }
        else
        {
            if (c.b == -1)
            {
                cout << c.a << "-"
                     << "i" << endl;
            }
            else
            {
                if (c.b == 0)
                {
                    cout << c.a << endl;
                }
                else
                {
                    cout << c.a  << c.b << "i" << endl;
                }
            }
        }
    }
    else
    {
        if (c.b > 0)
        {
            if (c.b == 1)
            {
                cout << "i" << endl;
            }
            else
            {
                cout << c.b << "i" << endl;
            }
        }
        else
        {
            if (c.b == -1)
            {
                cout << "-"
                     << "i" << endl;
            }
            else
            {
                if (c.b == 0)
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << c.a << c.b << "i" << endl;
                }
            }
        }
    }
}
Complex add(const Complex &c1, const Complex &c2)
{
    Complex result;
    result.a = c1.a + c2.a;
    result.b = c1.b + c2.b;
    return result;
}
int compare(const Complex &c1, const Complex &c2)
{
    if (sqrt(pow(c1.a, 2) + pow(c1.b, 2)) == sqrt(pow(c2.a, 2) + pow(c2.b, 2)))
    {
        return 0;
    }
    if (sqrt(pow(c1.a, 2) + pow(c1.b, 2)) > sqrt(pow(c2.a, 2) + pow(c2.b, 2)))
    {
        return 1;
    }
    return -1;
}
int main()
{
    Complex c1 = {1, 3};
    Complex c2 = {2, 1};
    print(add(c1, c2));
    cout << compare(c1, c2);
}