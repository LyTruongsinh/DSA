#include <iostream>
#include <cmath>
using namespace std;
struct Complex
{
    double a, b;
};
void print(const Complex &c)
{
    if (c.a != 0)
    {
        if (c.b == 0)
        {
            cout << c.a << endl;
        }
        else
        {
            if (c.b > 0)
            { 
                if(c.b != 1) cout << c.a << "+" << c.b << "i" << endl;
                else cout << c.a << "+i" << endl;
            }
            else
            {   
                if(c.b != -1) cout << c.a << c.b << "i" << endl;
                else cout << c.a << "-i" << endl;
            }
        }
    }
    else
    {
        if (c.b == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            if (c.b > 0)
            { 
                if(c.b != 1) cout << c.b << "i" << endl;
                else cout << "i" << endl;
            }
            else
            {   
                if(c.b != -1) cout << c.b << "i" << endl;
                else cout << "-i" << endl;
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
    if (sqrt(c1.a * c1.a + c1.b * c1.b) == sqrt(c2.a * c2.a + c2.b * c2.b))
    {
        return 0;
    }
    if (sqrt(c1.a * c1.a + c1.b * c1.b) > sqrt(c2.a * c2.a + c2.b * c2.b))
    {
        return 1;
    }
    return -1;
}
int main()
{
    Complex c1 = {-1, 0};
    Complex c2 = {1, -2};
    Complex c3 = {0, 1};
    Complex c4 = {0, 0};
    Complex c5 = {2, 1};
    print(c1);
    print(c2);
    print(c3);
    print(c4);
    print(c5);
    cout << compare(c1, c2) << endl;
    cout << compare(c3, c4) << endl;
    cout << compare(c5, add(c5, c4)) << endl;
    print(add(c1, add(c2, c3)));
}