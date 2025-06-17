#include <algorithm>
#include <iostream>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), right(NULL), left(NULL) { ; }
    TreeNode(int x) : val(x), left(NULL), right(NULL) { ; }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) { ; }
    ~TreeNode()
    {
        delete left;
        delete right;
        left = right = NULL;
    }
};
class Solution
{
  public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        if (root->left == NULL && root->right != NULL)
        {
            return minDepth(root->right) + 1;
        }
        if (root->left != NULL && root->right == NULL)
        {
            return minDepth(root->left) + 1;
        }
        int minleft = 1 + minDepth(root->left);
        int minright = 1 + minDepth(root->right);
        return min(minleft, minright);
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << s.minDepth(root);
    return 0;
}