#include <iostream>
#include <vector>
#include <limits>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
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
    TreeNode *Binary_Search_Tree(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);
        if (val < root->val)
            root->left = Binary_Search_Tree(root->left, val);
        else
            root->right = Binary_Search_Tree(root->right, val);
        return root;
    }

    TreeNode *findMin(TreeNode *root)
    {
        while (root->left)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int val) {
        if (root == nullptr) {  // Thay thế !root bằng root == nullptr
            return nullptr;
        }
        
        if (val < root->val) {
            root->left = deleteNode(root->left, val);
        } 
        if (val > root->val) {
            root->right = deleteNode(root->right, val);
        } 
        if (val == root->val) {
            // Node có một hoặc không có con
            if (root->left == nullptr) { 
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == nullptr) { 
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
    
            // Node có hai con, tìm phần tử nhỏ nhất bên phải
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
    

    void prinInorder(TreeNode *root)
    {
        if (root)
        {
            prinInorder(root->left);
            cout << root->val << " ";
            prinInorder(root->right);
        }
    }
};
int main()
{
    Solution s;
    TreeNode *root = NULL;
    int a[9] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int i = 0; i < 9; i++)
    {
        root = s.Binary_Search_Tree(root, a[i]);
    }

    int insertValues[3] = {14, 0, 35};
    for (int i = 0; i < 3; i++)
    {
        root = s.Binary_Search_Tree(root, insertValues[i]);
    }
    cout << "Sau khi chen 14, 0, 35: ";
    s.prinInorder(root);
    cout << endl;
    // Xóa giá trị 6 khỏi cây
    root = s.deleteNode(root, 6);
    cout << "Sau khi xoa 6: ";
    s.prinInorder(root);
    cout << endl;
}