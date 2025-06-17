#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n));
        int start = 0;
        int k = n;
        while (true)
        {
            // Hàng trên cùng
            for (int j = start; j < n; j++)
            {
                if (j - 1 < 0)
                {
                result[start][j] = 1;
                }
                else
                {
                    result[start][j] = result[start][j - 1] + 1;
                }
            }
            // Hàng phải cùng
            for (int i = start + 1; i < n; i++)
            {
                result[i][n - 1] = result[i - 1][n - 1] + 1;
            }
            // Hàng dưới cùng
            for (int j = n - 2; j >= start; j--)
            {
                result[n - 1][j] = result[n - 1][j + 1] + 1;
            }
            // Hàng trái cùng
            for (int i = n - 2; i >= start + 1; i--)
            {
                result[i][start] = result[i + 1][start] + 1;
            }
            start++;
            n--;
            if (n - 1 < k / 2)
            {
                break;
            }
        }
        return result;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<vector<int>> result = s.generateMatrix(n);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] <<" ";
        }
        cout <<
    }
}