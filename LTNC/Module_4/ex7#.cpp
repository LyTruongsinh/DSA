#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// Đổi kiểu trả về của giaithua thành double
double giaithua(int n)
{
    if (n == 0 || n == 1)
        return 1.0;
    return n * giaithua(n - 1);
}
int main()
{
    int x;
    cin >> x;

    double sum = 0.0;
    double delta = 100.0;
    int i = 0;

    while (fabs(delta) >= 0.001)
    {
        double sumpre = sum;
        sum += pow(x, i) / giaithua(i); // Tất cả kiểu double
        delta = sum - sumpre;
        i++;
    }

    cout << fixed << setprecision(4) << sum << endl;
    return 0;
}
