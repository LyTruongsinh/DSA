#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void SinhNhiPhan(int n, vector<int> &a)
{
    if (a.size() == n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        a.push_back(i);
        SinhNhiPhan(n, a);
        a.pop_back();
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    SinhNhiPhan(n, a);
    return 0;
}
