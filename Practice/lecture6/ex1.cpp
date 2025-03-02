#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
    ~TreeNode()
    {
        delete left;
        delete right;
        left = right = NULL;
    }
};
class Solution {
    public:
    TreeNode* Binary_Search_Tree(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if(val < root->val) root->left = Binary_Search_Tree(root->left, val);
        else root->right = Binary_Search_Tree(root->right, val);
        return root;
    }

    TreeNode* Delete(TreeNode* root, int val) {
        
    }

    void prinInorder(TreeNode* root) {
        if(root) {
            prinInorder(root->left);
            cout << root->val << " ";
            prinInorder(root->right);
        }
    }
};
int main() {
    Solution s;
    TreeNode* root = NULL;
    int a[9] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for(int i = 0 ; i < 9 ; i++) {
        root = s.Binary_Search_Tree(root, a[i]);
    }

    int insertValues[3] = {14, 0, 35};
    for(int i = 0 ; i < 3; i++) {
        root = s.Binary_Search_Tree(root, insertValues[i]);
    }
    cout << "Sau khi chen 14, 0, 35: ";  s.prinInorder(root);
    cout << endl;
}