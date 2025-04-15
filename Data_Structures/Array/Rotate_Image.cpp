#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> temp(n, vector<int>(n)); // Tạo ma trận tạm
    
        // Gán các phần tử vào vị trí xoay 90 độ
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                temp[j][n - 1 - i] = matrix[i][j];
            }
        }
    
        // Sao chép temp trở lại matrix
        matrix = temp;
    }
    void printMatrix(const vector<vector<int>> &matrix)
    {
        for (const auto &row : matrix)
        {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    s.rotate(matrix);
    s.printMatrix(matrix);

    return 0;
}