#include <iostream>
#include <cmath>
using namespace std;
// O(n)
double power_iterative1(int n)
{
    double result = 1;
    for (int i = 0; i < abs(n); i++)
    {
        result *= 2;
    }
    if (n < 0)
        return (1 / result);
    return result;
}

// O(logn)
double power_recursive2(int n)
{
    if (n < 0)
    {
        if (abs(n) == 0)
            return 1;
        if (abs(n) % 2 == 0)
            return 1 / (power_recursive2(n / 2) * power_recursive2(n / 2));
        else
            return 1 / (power_recursive2(n / 2) * power_recursive2(n / 2) * 2);
    }

    if (abs(n) == 0)
        return 1;
    if (abs(n) % 2 == 0)
        return power_recursive2(n / 2) * power_recursive2(n / 2);
    else
        return power_recursive2(n / 2) * power_recursive2(n / 2) * 2;
}

int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;
    cout << "Result :" << power_iterative1(n) << endl;
    cout << "Result :" << power_recursive2(n) << endl;
}