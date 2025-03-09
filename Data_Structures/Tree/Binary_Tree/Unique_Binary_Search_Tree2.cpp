#include <iostream>
using namespace std;
int result = 0;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};
class Solution {
    public:
        int memo[20][20]; // Mảng tĩnh để lưu kết quả
    
        Solution() {
            memset(memo, -1, sizeof(memo)); // Khởi tạo tất cả giá trị -1
        }
    
        int sum(int start, int end) {
            if (start >= end)
                return 1;
            if (memo[start][end] != -1)
                return memo[start][end];
    
            int result = 0;
            for (int i = start; i <= end; i++) { // Duyệt qua tất cả các giá trị root
                int left = sum(start, i - 1);
                int right = sum(i + 1, end);
                result += left * right;
            }
    
            return memo[start][end] = result;
        }
    
        int numTrees(int n) {
            return sum(1, n);
        }
    };
    
int main()
{
    int n = 3;
    Solution s;
    cout << s.numTrees(n) << endl;
    return 0;
}