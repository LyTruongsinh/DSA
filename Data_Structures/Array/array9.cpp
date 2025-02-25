#include <iostream>
#include <iomanip>
using namespace std;
void sort(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cout << "Nhập số n :";
    cin >> n;
    double a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << a[i] << endl;
    }
}