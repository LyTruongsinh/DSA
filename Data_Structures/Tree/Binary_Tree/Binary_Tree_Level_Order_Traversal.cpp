#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> level;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
};
int main()
{
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    vector<vector<int>> result = solution.levelOrder(root);
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}


// EXAMPLE:
// Input:
//         3
//        / \
//       9   20
//          /  \
//         15   7
// How to  operate:
// IF(root == NULL) => result;
// ELSE 
// 1. Create a queue and push the root node into it.
//---------------------------------------------------------//
//                                                        3
//---------------------------------------------------------//
// 2. While the queue is not empty, do the following:
//    a. Get the size of the queue (number of nodes at the current level).
//    b. Create a vector to store the values of the nodes at the current level.
// level = [3] 
//---------------------------------------------------------//
//                                                   20   9
//---------------------------------------------------------//
// result = [3]
// queue = [9,20] != NULL
// level = [9]