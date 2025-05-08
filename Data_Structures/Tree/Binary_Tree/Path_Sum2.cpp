#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
class Solution {
   public:
    vector<vector<int>> result;

    void dfs(TreeNode *node, int targetSum, vector<int> &path, int currentSum) {
        if (node == nullptr) return;
        currentSum += node->val;
        path.push_back(node->val);
        // Nếu node là lá, kiểm tra xem tổng hiện tại có bằng targetSum không
        if (!node->left && !node->right && currentSum == targetSum) {
            result.push_back(path);
        }

        dfs(node->left, targetSum, path, currentSum);
        dfs(node->right, targetSum, path, currentSum);
        // Quay lại trạng thái trước khi thêm node hiện tại vào path
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path, 0);
        return result;
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    int targetSum = 22;
    vector<vector<int>> result = s.pathSum(root, targetSum);
    for (const auto &path : result) {
        for (int val : path) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}