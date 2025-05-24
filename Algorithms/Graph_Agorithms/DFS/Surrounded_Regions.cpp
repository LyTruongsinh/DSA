#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  private:
    static constexpr int dx[4] = {-1, 0, 0, 1};
    static constexpr int dy[4] = {0, -1, 1, 0};
    bool visited[1001][1001] = {};
  public:
    void dfs(int i, int j, vector<vector<char>> &board)
    {
        visited[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            // Sửa lại điều kiện chỉ số mảng bắt đầu từ 0
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'O' && !visited[x][y])
            {
                dfs(x, y, board);
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        if (m == 0)
            return;
        int n = board[0].size();
        // Đánh dấu các 'O' ở viền và các 'O' nối với viền
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, board);
            if (board[i][n - 1] == 'O' && !visited[i][n - 1])
                dfs(i, n - 1, board);
        }
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O' && !visited[0][j])
                dfs(0, j, board);
            if (board[m - 1][j] == 'O' && !visited[m - 1][j])
                dfs(m - 1, j, board);
        }
        // Đổi các 'O' chưa được đánh dấu thành 'X'
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
int main()
{
    Solution s;
    vector<vector<char>> board = {{'X', 'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'O', 'X'},
                                  {'X', 'O', 'X', 'O', 'X'},
                                  {'O', 'X', 'O', 'X', 'X'},
                                  {'X', 'X', 'X', 'X', 'X'}};
    s.solve(board);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}