#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};
class Solution {
    public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int countleft = 1 + maxDepth(root->left);
        int countright = 1 + maxDepth(root->right);
        if(countleft < countright) {
            return countright;
        }
        return countleft;
    }
};          
int main () {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << "Maximum Depth of the Binary Tree: " << s.maxDepth(root) << endl;
    return 0;
}