#include <cmath>
#include <iostream>

using namespace std;
bool isprime(int n)
{
    int root = sqrt(n);
    return root * root == n;
}
bool checkFibo(int n) { return isprime(5 * n * n + 4) || isprime(5 * n * n - 4); }
int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}
void printfibo(int n)
{
    int i = 0;
    while (true)
    {
        int f = fibo(i);
        if (f > n)
            break;
        cout << f << " ";
        i++;
    }
}
int main()
{
    int n;
    cin >> n;
    if (checkFibo(n))
    {
        cout << "Thuoc day Fibonacci" << endl;
        printfibo(n);
    }
    else
    {
        cout << "Khong thuoc day Fibonacci" << endl;
        printfibo(n);
    }
}