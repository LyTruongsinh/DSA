#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};


class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum, int currentSum = 0)
    {
        if (root == NULL)
            return false;

        currentSum += root->val;

        if (root->left == NULL && root->right == NULL) // Nếu là node lá
            return currentSum == targetSum;

        return hasPathSum(root->left, targetSum, currentSum) || hasPathSum(root->right, targetSum, currentSum);
    }
};
int main()
{
    // Test cases
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(13);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    Solution s;
    cout << s.hasPathSum(root, 22) << endl; // Output: 1
    return 0;
}