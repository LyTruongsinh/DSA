#include <iostream>
using namespace std;
bool BinarySearch(int a[], int x, int n)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return true;
        else
        {
            if (a[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}
int main()
{
    int n, x;
    int a[100000];
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (BinarySearch(a, x, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}