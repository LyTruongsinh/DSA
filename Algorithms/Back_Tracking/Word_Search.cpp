#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        // Start DFS from every cell
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

  private:
    bool dfs(vector<vector<char>> &board, const string &word, int i, int j, int index)
    {
        if (index == word.length())
            return true;

        // Boundary or character mismatch
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
        {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#'; // mark as visited

        // Explore 4 directions
        bool found = dfs(board, word, i + 1, j, index + 1) || dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) || dfs(board, word, i, j - 1, index + 1);

        board[i][j] = temp; // unmark

        return found;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    bool result = sol.exist(board, word);
    cout << (result ? "true" : "false") << endl; // Output: true
}