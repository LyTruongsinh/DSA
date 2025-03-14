#include <iostream>
#include <cmath>
using namespace std;
struct Point
{
    double x, y;

    Point();               // Hàm khởi tạo mặc định
    Point(double, double); // Hàm khởi tạo với tọa độ x, y
    Point(const Point &);  // Hàm khởi tạo sao chép
};
class Triangle
{
    Point p1, p2, p3;

public:
    Triangle(Point, Point, Point);
    double getPerimeter() const;
    double getArea() const;
};

Point::Point() : x(0), y(0) {}
Point::Point(double xVal, double yVal) : x(xVal), y(yVal) {}
Point::Point(const Point &other) : x(other.x), y(other.y) {}
Triangle::Triangle(Point a, Point b, Point c) : p1(a), p2(b), p3(c) {}
double Triangle::getPerimeter() const
{
    double a = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    double b = sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));
    double c = sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));
    return a + b + c;
}
double Triangle::getArea() const
{
    double a = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    double b = sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));
    double c = sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));
    double s = (a + b + c) / 2; // Nửa chu vi
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main()
{
    Point A(1, 1), B(1, 4), C(5, 1);
    Triangle tri(A, B, C);
    cout << tri.getPerimeter() << endl;
    cout << tri.getArea() << endl;
}
