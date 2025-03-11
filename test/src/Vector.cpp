#include <iostream>
#include <iomanip>
using namespace std;
class Vector
{
private:
    double x_;
    double y_;

public:
    Vector(double x = 0, double y = 0) : x_(x), y_(y) {};
    void print();
    double getX() const { return x_;}
    double getY() const { return y_;}
    Vector& operator=(const Vector& v); 
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector& operator+=(const Vector& v);
    Vector& operator-=(const Vector& v);
    void truncate(double length);
    bool isOrtho(const Vector &v) const;
    static float dot(const Vector &v1, const Vector &v2);
    static float cross(const Vector &v1, const Vector &v2);
    friend ostream &operator<<(ostream &os, const Vector &v);
};
void Vector::print()
{
    cout << fixed << setprecision(2) << "(" << x_ << ", " << y_ << ")";
}
void Vector::truncate(double length) {
    x_ = x_ - length;
    y_ = y_ - length;
}

bool Vector::isOrtho(const Vector &v) const {
    return dot(*this, v) == 0;
}

float Vector::dot(const Vector &v1, const Vector &v2) {
    return v1.x_ * v2.x_ + v1.y_ * v2.y_;
}
float Vector::cross(const Vector &v1, const Vector &v2) {
    return v1.x_ * v2.y_ - v1.y_ * v2.x_;
}
ostream& operator<<(ostream& os, const Vector& v) {
    os << fixed << setprecision(2) << "(" << v.x_ << ", " << v.y_ << ")";
    return os;
}
Vector& Vector::operator=(const Vector& v) {
    x_ = v.x_;
    y_ = v.y_;
    return *this;
}
Vector Vector::operator+(const Vector& v) const {
    return Vector(x_ + v.x_, y_ + v.y_);
}

Vector Vector::operator-(const Vector& v) const {
    return Vector(x_ - v.x_, y_ - v.y_);
}

Vector& Vector::operator+=(const Vector& v) {
    x_ += v.x_;
    y_ += v.y_;
    return *this;
}

Vector& Vector::operator-=(const Vector& v) {
    x_ -= v.x_;
    y_ -= v.y_;
    return *this;
}
int main()
{
    Vector v1(3, 4);
    Vector v2(2, 5);
    Vector v3 = v1 + v2;
    Vector v4 = v1 - v2;
    Vector v5 = v1;
    v5 += v2;
    v1 -= v2;
    v1.truncate(2);
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;
    cout << "v4: " << v4 << endl;
    cout << "v5: " << v5 << endl;
    cout << "v1 is orthogonal to v2: " << (v1.isOrtho(v2)? "Yes" : "NO") << endl;
    cout << "Dot product of v1 and v2: " << Vector::dot(v1, v2) << endl;
    cout << "Cross product of v1 and v2: " << Vector::cross(v1, v2) << endl;
    return 0;
}