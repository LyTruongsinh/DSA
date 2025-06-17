#include <iostream>
#include <vector>
using namespace std;
void SinhNhiPhan(vector<int> &result, int n)
{
    if (result.size() == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << result[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        result.push_back(i);
        SinhNhiPhan(result, n);
        result.pop_back();
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> result;
    SinhNhiPhan(result, n);
    return 0;
}