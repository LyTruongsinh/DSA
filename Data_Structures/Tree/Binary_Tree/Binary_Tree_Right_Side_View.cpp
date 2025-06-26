#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (i == n - 1)
                    result.push_back(node->val); // node cuối cùng của level
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return result;
    }
};
int main()
{
    // Ví dụ: xây dựng cây [1,2,3,null,5,null,4]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> res = sol.rightSideView(root);
    for (int v : res)
        cout << v << " ";
    cout << endl;

    // Giải phóng bộ nhớ (nếu cần)
    // ... (tùy bạn bổ sung)

    return 0;
}