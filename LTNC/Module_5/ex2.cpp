#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;
void sort(double A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] < A[j])
            {
                swap(A[i], A[j]);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    double A[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << A[i] << " ";
    }
}