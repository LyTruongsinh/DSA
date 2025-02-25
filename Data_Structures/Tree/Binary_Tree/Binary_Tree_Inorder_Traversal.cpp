#include <iostream>
#include <vector>
#include<stack>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stack;
        TreeNode * curRoot = root;
        while(true) {
            while(curRoot != NULL) {
                stack.push(curRoot);
                curRoot = curRoot->left;
            }
            if(stack.empty()) {
                break;
            }
            curRoot = stack.top();
            stack.pop();
            result.push_back(curRoot->val);
            curRoot = curRoot->right;
        }
        return result;
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> result = s.inorderTraversal(root);
    for(int i = 0 ;i < result.size(); i++) {
        cout << result[i] << " ";
    }
}