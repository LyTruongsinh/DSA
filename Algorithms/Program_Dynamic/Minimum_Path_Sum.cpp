#include <iostream>
#include <vector>
#include <algorithm> // cần cho hàm min

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main() {
    Solution sol;

    // Khởi tạo lưới (grid) ví dụ
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    // Gọi hàm và in kết quả
    int result = sol.minPathSum(grid);
    cout << "Minimum path sum is: " << result << endl;

    return 0;
}
