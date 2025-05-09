#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int j = 0;
        int i = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 0) return result;
        while(i < n && j < m) {
            for(int k = j; k < m; k++) {
                result.push_back(matrix[i][k]);
            }
            i++;
            for(int k = i; k < n;k++) {
                result.push_back(matrix[k][m - 1]);
            }
            m--;
            if (i < n) {
                for(int k = m - 1; k >= j; k--) {
                    result.push_back(matrix[n - 1][k]);
                }
                n--;
            }
            if (j < m) {
                for(int k = n - 1; k >= i; k--) {
                    result.push_back(matrix[k][j]);
                }
                j++;
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = s.spiralOrder(matrix);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}