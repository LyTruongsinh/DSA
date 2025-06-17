#include <cmath>
#include <iostream>

using namespace std;
struct Point
{
    double x, y;           // Toạ độ x, y
    Point();               // Hàm khởi tạo điểm (0, 0)
    Point(double, double); // Hàm khởi tạo từ toạ độ x, y
    Point(const Point &);  // Hàm khởi tạo sao chép từ một thực thể (instance) Point khác
};

class Triangle
{
    Point p1, p2, p3;

  public:
    Triangle(Point, Point, Point); // Hàm khởi tạo tam giác từ 3 điểm
    double getPerimeter() const;   // Hàm trả về chu vi tam giác
    double getArea() const;        // Hàm trả về diện tích tam giác
};
Point::Point(double a, double b)
{
    this->x = a;
    this->y = b;
}
Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::Point(const Point &f)
{
    this->x = f.x;
    this->y = f.y;
}
Triangle::Triangle(Point a, Point b, Point c)
{
    this->p1 = a;
    this->p2 = b;
    this->p3 = c;
}
double Triangle::getPerimeter() const
{
    double ab = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    double bc = sqrt(pow((p2.x - p3.x), 2) + pow((p2.y - p3.y), 2));
    double ac = sqrt(pow((p1.x - p3.x), 2) + pow((p1.y - p3.y), 2));
    return ab + bc + ac;
}
double Triangle::getArea() const
{
    double p = getPerimeter() / 2.0;
    double ab = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    double bc = sqrt(pow((p2.x - p3.x), 2) + pow((p2.y - p3.y), 2));
    double ac = sqrt(pow((p1.x - p3.x), 2) + pow((p1.y - p3.y), 2));
    return sqrt(p * (p - ab) * (p - ac) * (p - bc));
}
int main()
{
    Point A(1, 1), B(1, 4), C(5, 1);
    Triangle tri(A, B, C);
    cout << tri.getPerimeter() << endl;
    cout << tri.getArea() << endl;
}