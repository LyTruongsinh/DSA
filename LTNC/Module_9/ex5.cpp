#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Vector
{
    double x_, y_;

  public:
    Vector(double x = 0, double y = 0);
    void print(int precision = 2, bool newLine = true);
    void truncate(double length);
    bool isOrtho(const Vector &v) const;
    static float dot(const Vector &v1, const Vector &v2);
    static float cross(const Vector &v1, const Vector &v2);
    friend ostream &operator<<(ostream &os, const Vector &v);
};
Vector::Vector(double x, double y)
{
    x_ = x;
    y_ = y;
}
void Vector::print(int precision, bool newLine) { cout << *this << endl; }
void Vector::truncate(double length)
{
    x_ = x_ - length;
    y_ = y_ - length;
}
float Vector::dot(const Vector &v1, const Vector &v2) { return v1.x_ * v2.x_ + v1.y_ * v2.y_; }
bool Vector::isOrtho(const Vector &v) const { return dot((*this), v) == 0; }
float Vector::cross(const Vector &v1, const Vector &v2) { return v1.x_ * v2.y_ - v1.y_ * v2.x_; }
ostream &operator<<(ostream &os, const Vector &v)
{
    os << fixed << setprecision(2) <<  "(" << v.x_ << ", " << v.y_ << ")";
    return os;
}
int main()
{
    Vector y(2, 4);
    y.truncate(2);
    y.print();
    cout << y << endl;
}