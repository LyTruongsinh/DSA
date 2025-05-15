#include <algorithm>
#include <iostream>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
  public:
    int height(TreeNode *node, int &diameter)
    {
        if (node == nullptr)
            return 0;

        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << s.diameterOfBinaryTree(root) << endl; // Output: 3
    return 0;
}