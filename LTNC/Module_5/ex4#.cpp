#include <iomanip>
#include <iostream>

using namespace std;
void insert(double A[], double x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] >= x)
        {
            for(int j = n; j > i; j--)
            {
                A[j] = A[j - 1];
            }
            A[i] = x;
            break;
        }
    }
}
int main()
{
    int n; cin >> n;
    double A[1002];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    double x;
    cin >> x;
    insert(A, x, n);
    for(int i = 0; i <= n; i++)
    {
        cout << fixed << setprecision(2) << A[i] << " ";
    }
}