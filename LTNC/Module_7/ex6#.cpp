#include <iostream>
#include <vector>
using namespace std;
void SinhNhiPhan(vector<int> &result, int s, int count0, int n, int count1, int m)
{
    if (result.size() == s)
    {
        if (count1 == m && count0 == n)
        {
            for (int i = 0; i < s; i++)
            {
                cout << result[i];
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        if (i == 0)
        {
            result.push_back(i);
            SinhNhiPhan(result, s, count0 + 1, n, count1, m);
        }
        if (i == 1)
        {
            result.push_back(i);
            SinhNhiPhan(result, s, count0, n, count1 + 1, m);
        }
        result.pop_back();
    }
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> result;
    SinhNhiPhan(result, n + m, 0, n, 0, m);
    return 0;
}