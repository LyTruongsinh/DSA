#include <iostream>
#include <vector>
using namespace std;
int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}
int BCNN(int a, int b)
{
    return (a * b) / UCLN(a, b);
}
int BCNN_Array(vector<int> arr, int n, int index = 0)
{
    if (index == n - 1)
        return arr[index];
    return BCNN(arr[index], BCNN_Array(arr, n, index + 1));
}
int UCLN_Array(vector<int> arr, int n, int index = 0)
{
    if (index == n - 1)
        return arr[index];
    return UCLN(arr[index], UCLN_Array(arr, n, index + 1));
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    int count = 0;
    for (int i = BCNN_Array(a, n); i <= UCLN_Array(b, m); i++)
    {
        if (UCLN_Array(b, m) % i == 0)
        {
            count++;
        }
    }
    cout << count << endl;
}