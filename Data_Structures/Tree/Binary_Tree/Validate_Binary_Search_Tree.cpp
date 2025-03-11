#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    bool isValidBSTHelper(TreeNode *root, TreeNode* left, TreeNode* right){};
    bool isValidBST(TreeNode *root){};
};

bool TreeNode::isValidBSTHelper(TreeNode *root, TreeNode* left, TreeNode* right) {
    if (root == NULL) return true;
    if (left != NULL && root->val <= left->val) return false;
    if (right != NULL && root->val >= right->val) return false;
    return isValidBSTHelper(root->left, left, root) && isValidBSTHelper(root->right, root, right);
}

bool TreeNode::isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, NULL, NULL);
}

int main() {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    TreeNode checker(0);  // Đối tượng để gọi isValidBST
    cout << checker.isValidBST(root) << endl; // Expected: 1 (true)

    return 0;
}
