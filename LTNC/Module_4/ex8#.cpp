#include <cmath>
#include <iostream>

using namespace std;

int count_digits(long long n)
{
    if (n == 0)
        return 1; // Trường hợp đặc biệt

    long long k = llabs(n); // Dùng llabs cho kiểu long long
    int c = 0;
    while (k > 0)
    {
        k /= 10;
        c++;
    }
    return c;
}

int main()
{
    long long n; // Sửa kiểu dữ liệu
    cin >> n;
    cout << count_digits(n) << endl;
    return 0;
}
