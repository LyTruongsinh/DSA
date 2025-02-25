#include <iostream>
#include<iomanip>
using namespace std;
void chen(double a[], int n, double x)
{
    for (int i = 0; i < n + 1; i++)
    {
        if (a[i] >= x)
        {
            cout << i << endl;
            for (int j = n; j >= i + 1; j--)
            {
                a[j] = a[j - 1];
            }
            a[i] = x;
            break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    double a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    double sochen;
    cin >> sochen;
    chen(a, n, sochen);
    for (int i = 0; i < n + 1; i++)
    {
        cout << fixed << setprecision(2) << a[i] << " ";
    }
}