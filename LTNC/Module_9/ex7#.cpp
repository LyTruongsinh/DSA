#include <iomanip>
#include <iostream>

using namespace std;
class Vector
{
    double x_, y_;

  public:
    Vector(double x = 0, double y = 0);
    void print(int precision = 2, bool newLine = true);
    Vector operator+(double s) const;
    Vector operator-(double s) const;
    Vector operator*(double s) const;
    Vector operator/(double s) const;
    Vector &operator+=(double s);
    Vector &operator-=(double s);
    Vector &operator*=(double s);
    Vector &operator/=(double s);
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
Vector Vector::operator+(double s) const
{
    Vector result;
    result.x_ = this->x_ + s;
    result.y_ = this->y_ + s;
    return result;
}
Vector Vector::operator-(double s) const
{
    Vector result;
    result.x_ = this->x_ - s;
    result.y_ = this->y_ - s;
    return result;
}
Vector Vector::operator*(double s) const
{
    Vector result;
    result.x_ = this->x_ * s;
    result.y_ = this->y_ * s;
    return result;
}
Vector Vector::operator/(double s) const
{
    Vector result;
    result.x_ = this->x_ / s;
    result.y_ = this->y_ / s;
    return result;
}
Vector &Vector::operator+=(double s)
{
    this->x_ = x_ + s;
    this->y_ = y_ + s;
    return *this;
}
Vector &Vector::operator-=(double s)
{
    this->x_ = x_ - s;
    this->y_ = y_ - s;
    return *this;
}
Vector &Vector::operator*=(double s)
{
    this->x_ = x_ * s;
    this->y_ = y_ * s;
    return *this;
}
Vector &Vector::operator/=(double s)
{
    this->x_ = x_ / s;
    this->y_ = y_ / s;
    return *this;
}
int main()
{
    Vector x(2, 3);
    (x += 2) += 3;
    x.print();
    cout << &(x += 2) << " " <<  &x << endl;
}
