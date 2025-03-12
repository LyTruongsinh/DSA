#include <iostream>
#include <iomanip>
using namespace std;
class Vector {
    double x_, y_;
public:
    Vector(double x = 0, double y = 0) : x_(x), y_(y) {};  
    void print(); 
    Vector operator+(double s) const;    
    Vector operator-(double s) const;
    Vector operator*(double s) const;
    Vector operator/(double s) const;
    Vector& operator+=(double s);    
    Vector& operator-=(double s);
    Vector& operator*=(double s);
    Vector& operator/=(double s);
};
void Vector::print()
{
    cout << fixed << setprecision(2) << "(" << x_ << ", " << y_ << ")";
}
Vector Vector::operator+(double s) const {
    Vector result(0, 0);
    result.x_ = this->x_ + s;
    result.y_ = this->y_ + s;
    return result;
}
Vector Vector::operator-(double s) const {
    Vector result(0, 0);
    result.x_ = this->x_ - s;
    result.y_ = this->y_ - s;
    return result;
}
Vector Vector::operator*(double s) const {
    Vector result(0, 0);
    result.x_ = this->x_ * s;
    result.y_ = this->y_ * s;
    return result;
}
Vector Vector::operator/(double s) const {
    Vector result(0, 0);
    result.x_ = x_ / s;
    result.y_ = y_ / s;
    return result;
}
Vector& Vector::operator+=(double s) {
    this->x_ += s;
    this->y_ += s;
    return *this;
}
Vector& Vector::operator-=(double s) {
    this->x_ -= s;
    this->y_ -= s;
    return *this;
}
Vector& Vector::operator*=(double s) {
    this->x_ *= s;
    this->y_ *= s;
    return *this;
}

Vector& Vector::operator/=(double s) {
    if (s == 0) {
        cout << "Error: Division by zero" << endl;
        return *this;
    }
    this->x_ /= s;
    this->y_ /= s;
    return *this;
}
int main() {
    Vector v1(3, 4);
    Vector v2(2, 5);
    Vector v3 = v1 + 2;
    Vector v4 = v2 - 1;
    Vector v5 = v1 * 3;
    Vector v6 = v2 / 2;
    v3.print(); cout << endl;
    v4.print(); cout << endl;
    v5.print(); cout << endl;
    v6.print(); cout << endl;
    v3 += 1;
    v3.print(); cout << endl;
    v4 -= 2;
    v4.print(); cout << endl;
    v5 *= 0.5;
    v5.print(); cout << endl;
    v6 /= 1.5;
    v6.print(); cout << endl;
    return 0;
}