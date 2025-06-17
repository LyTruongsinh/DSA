#include <iomanip>
#include <iostream>

using namespace std;
class Vector
{
    double x_, y_;

  public:
    Vector(double x = 0, double y = 0);
    void print(int precision = 2, bool newLine = true);
    Vector &operator=(const Vector &v);
    Vector operator+(const Vector &v) const;
    Vector operator-(const Vector &v) const;
    Vector &operator+=(const Vector &v);
    Vector &operator-=(const Vector &v);
    friend ostream &operator<<(ostream &os, const Vector &v);
};
Vector::Vector(double x, double y)
{
    x_ = x;
    y_ = y;
}
ostream &operator<<(ostream &os, const Vector &v)
{
    os << fixed << setprecision(2) << "(" << v.x_ << ", " << v.y_ << ")";
    return os;
}
void Vector::print(int precision, bool newLine) { cout << (*this) << endl; }
Vector &Vector::operator=(const Vector &v)
{
    if (this != &v)
    {
        this->x_ = v.x_;
        this->y_ = v.y_;
    }
    return *this;
}
Vector Vector::operator+(const Vector &v) const
{
    Vector result;
    result.x_ = this->x_ + v.x_;
    result.y_ = this->y_ + v.y_;
    return result;
}
Vector &Vector::operator+=(const Vector &v)
{
    this->x_ += v.x_;
    this->y_ += v.y_;
    return *this;
}
Vector &Vector::operator-=(const Vector &v)
{
    this->x_ -= v.x_;
    this->y_ -= v.y_;
    return *this;
}
Vector Vector::operator-(const Vector& v) const
{
    Vector result;
    result.x_ = this->x_ - v.x_;
    result.y_ = this->y_ - v.y_;
    return result;
}
int main()
{
    Vector x(1, 2), y(3, 3), z;
    z = x + y;
    z.print();
    return 0;
}