#include <iostream>
#include <queue>
#include <utility>
#include <vector>


#define MAX 1001
using namespace std;

class Solution
{
  private:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    bool visited[MAX][MAX] = {false};
    int n, m;

  public:
    void BFS(int si, int sj, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> Q;
        Q.push({si, sj});
        visited[si][sj] = true;

        while (!Q.empty())
        {
            int ci = Q.front().first;
            int cj = Q.front().second;
            Q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ni = ci + dx[i];
                int nj = cj + dy[i];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1' && !visited[ni][nj])
                {
                    Q.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        if (n == 0)
            return 0;
        m = grid[0].size();

        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    BFS(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'}, 
        {'1', '1', '0', '0', '0'}, 
        {'0', '0', '1', '0', '0'}, 
        {'0', '0', '0', '1', '1'}};

    Solution sol;
    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
