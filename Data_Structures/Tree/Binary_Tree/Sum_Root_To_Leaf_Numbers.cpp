#include <cmath>
#include <iostream>
#include <vector>

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
    void dfs(TreeNode *node, vector<int> &path, int &sum)
    {
        path.push_back(node->val);
        if (!node->left && !node->right)
        {
            int num = 0;
            for (int i = 0; i < path.size(); ++i)
            {
                num = num * 10 + path[i];
            }
            sum += num;
        }
        else
        {
            if (node->left)
                dfs(node->left, path, sum);
            if (node->right)
                dfs(node->right, path, sum);
        }
        path.pop_back();
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        int sum = 0;
        vector<int> path;
        dfs(root, path, sum);
        return sum;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution s;
    cout << s.sumNumbers(root) << endl;
    return 0;
}