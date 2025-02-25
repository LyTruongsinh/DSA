#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) {}
};
class Solution
{
public:
    bool helper(TreeNode *a, TreeNode *b)
    {
        // Nếu cả hai node đều NULL, trả về true (đối xứng)
        if (a == NULL && b == NULL)
            return true;

        // Nếu chỉ một trong hai node là NULL, trả về false (không đối xứng)
        if (a == NULL || b == NULL)
            return false;

        // Nếu giá trị của hai node không giống nhau, không đối xứng
        if (a->val != b->val)
            return false;

        // Kiểm tra đối xứng của hai nhánh con
        bool leftCheck = helper(a->left, b->right);
        bool rightCheck = helper(a->right, b->left);

        // Trả về kết quả cuối cùng
        if (leftCheck == true && rightCheck == true)
        {
            return true;
        }

        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return helper(root->left, root->right);
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3); // Output: 1
    return 0;
}