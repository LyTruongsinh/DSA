#include <iostream>
#include <numeric>
using namespace std;
class MyFraction
{
  private:
    int a, b;

  public:
    MyFraction(int _a = 1, int _b = 1);
    void print() const;
    MyFraction add(const MyFraction &f) const;
    MyFraction substract(const MyFraction &f) const;
    MyFraction multiply(const MyFraction &f) const;
    MyFraction divide(const MyFraction &f) const;
    void simplify();
    int compare(const MyFraction &f) const;
};
MyFraction::MyFraction(int _a, int _b)
{
    a = _a;
    b = _b;
}
void MyFraction::simplify()
{
    int ucln = gcd(a, b);
    a = a / ucln;
    b = b / ucln;
}
MyFraction MyFraction::add(const MyFraction &f) const
{
    MyFraction result;
    result.a = this->a * f.b + this->b * f.a;
    result.b = this->b * f.b;
    result.simplify();
    return result;
}
MyFraction MyFraction::substract(const MyFraction &f) const
{
    MyFraction result;
    result.a = this->a * f.b - this->b * f.a;
    result.b = this->b * f.b;
    result.simplify();
    return result;
}
MyFraction MyFraction::multiply(const MyFraction &f) const
{
    MyFraction result;
    result.a = this->a * f.a;
    result.b = this->b * f.b;
    result.simplify();
    return result;
}
MyFraction MyFraction::divide(const MyFraction &f) const
{
    MyFraction result;
    result.a = this->a * f.b;
    result.b = this->b * f.a;
    result.simplify();
    return result;
}
int MyFraction::compare(const MyFraction &f) const
{
    MyFraction temp = this->substract(f);
    if (temp.a * temp.b > 0)
    {
        return 1;
    }
    else
    {
        if (temp.a * temp.b < 0)
        {
            return -1;
        }
    }
    return 0;
}
void MyFraction::print() const
{
    if ((*this).b == 0)
    {
        cout << "invalid";
    }
    else
    {
        cout << (*this).a << "/" << (*this).b;
    }
}
int main()
{
    MyFraction x(1, 3), y(1, 3);
    x = x.add(y);
    x.print();
}