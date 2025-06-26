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

class BSTIterator
{
  private:
    vector<int> result;
    int index;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }

  public:
    BSTIterator(TreeNode *root)
    {
        inorder(root);
        index = -1; // Đặt con trỏ "trước phần tử đầu tiên"
    }

    int next()
    {
        index++;
        return result[index];
    }

    bool hasNext() { return index + 1 < result.size(); }
};
int main()
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15, new TreeNode(9), new TreeNode(20));

    BSTIterator it(root);

    while (it.hasNext())
    {
        cout << it.next() << " ";
    }

    // Output: 3 7 9 15 20
}
