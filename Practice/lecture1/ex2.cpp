#include <iostream>
#include <cmath>
using namespace std;
class Point
{

public:
    float x;
    float y;
    void import()
    {
        cin >> x >> y;
    }
};
class Line
{

public:
    float a;
    float b;
    void line(Point P1, Point P2)
    {
        float P1_y = P1.y;
        float P1_x = P1.x;
        float P2_y = P2.y;
        float P2_x = P2.x;
        a = (P2_y - P1_y) / (P2_x - P1_x);
        b = P1_y - a * P1_x;
    }
};
int main()
{
    Point A, B, C, D, giaodiem;
    A.import();
    B.import();
    C.import();
    D.import();
    Line AB, CD;
    AB.line(A, B);
    CD.line(C, D);
    cout << CD.a << " " << CD.b << endl;
    cout << AB.a << " " << AB.b << endl;
    if (CD.a == AB.a && CD.b != AB.b)
    {
        cout << "NO" << endl;
    }
    if (CD.a == AB.a && CD.b == AB.b)
    {
        cout << "MANY" << endl;
    }
    if (CD.a != AB.a && CD.b != AB.b)
    {
        giaodiem.x = (CD.b - AB.b) / (AB.a - CD.a);
        giaodiem.y = AB.a * giaodiem.x + AB.b;
        cout << giaodiem.x << " " << giaodiem.y << endl;
    }
}