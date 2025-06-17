#include <iostream>
using namespace std;

int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

int BCNN(int a, int b)
{
    return a / UCLN(a, b) * b; // an toàn hơn a*b/UCLN
}

int BCNNArray1(int a[], int n)
{
    int BCNNarray1 = a[0];
    for (int i = 1; i < n; i++)
    {
        BCNNarray1 = BCNN(a[i], BCNNarray1);
    }
    return BCNNarray1;
}

int UCLNArray2(int a[], int m)
{
    int UCLNarray2 = a[0];
    for (int i = 1; i < m; i++)
    {
        UCLNarray2 = UCLN(a[i], UCLNarray2);
    }
    return UCLNarray2;
}

int find(int a[], int b[], int n, int m)
{
    int count = 0;
    int BCNNa = BCNNArray1(a, n);
    int UCLNb = UCLNArray2(b, m);

    // Nếu BCNN > UCLN, không có số nào thỏa mãn
    if (BCNNa > UCLNb)
        return 0;

    for (int i = BCNNa; i <= UCLNb; i++) // dùng i++
    {
        if (i % BCNNa == 0 && UCLNb % i == 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[11], b[11];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << find(a, b, n, m) << endl;
    return 0;
}
