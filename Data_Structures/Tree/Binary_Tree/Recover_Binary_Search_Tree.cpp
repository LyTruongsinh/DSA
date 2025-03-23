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
    vector<TreeNode *> result;

    void loopInorder(TreeNode *root)
    { // Duyệt cây theo thứ tự inorder
        if (root == NULL)
            return;
        loopInorder(root->left);
        result.push_back(root);
        loopInorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        loopInorder(root);
        for(int i = 0; i < result.size(); i++) {
            for(int j = i + 1; j < result.size(); j++) {
                if(result[i]->val > result[j]->val) {
                    swap(result[i]->val, result[j]->val);
                }
            }
        }
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    s.recoverTree(root);
    cout << root->left->val << endl;
    return 0;
}
