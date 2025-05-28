#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (obstacleGrid[0][0] == 1)
            return 0;
        dp[0][0] = 1;
        // Khởi tạo cột đầu
        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1)
                dp[i][0] = 1;
            else
                dp[i][0] = 0;
        }
        // Khởi tạo dòng đầu
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1)
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
        }
        // DP cho các ô còn lại
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> obstacleGrid[i][j];
    Solution sol;
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}