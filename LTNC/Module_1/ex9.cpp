#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    // Kiểm tra điều kiện tạo thành tam giác
    if (a > 0 && b > 0 && c > 0 &&
        a + b > c && a + c > b && b + c > a)
    {
        double p = (a + b + c) / 2.0;
        double S = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << fixed << setprecision(2) << S << endl;
    }
    else
    {
        cout << "invalid" << endl;
    }
    return 0;
}
