#include <algorithm>
#include <iostream>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
  public:
    TreeNode *balanceBST(TreeNode *root) 
    {
        vector<int> values;
        inorderTraversal(root, values);
        return buildBalancedTree(values, 0, values.size() - 1);
    }
    void inorderTraversal(TreeNode *node, vector<int> &values)
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left, values);
        values.push_back(node->val);
        inorderTraversal(node->right, values);
    }
    TreeNode *buildBalancedTree(vector<int> &values, int start, int end)
    {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(values[mid]);
        node->left = buildBalancedTree(values, start, mid - 1);
        node->right = buildBalancedTree(values, mid + 1, end);
        return node;
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    TreeNode *balancedRoot = s.balanceBST(root);
    return 0;
}