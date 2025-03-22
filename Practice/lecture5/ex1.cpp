#include <iostream>
#include <stack>
#include <vector>
#define MAX 10000
using namespace std;
int f[MAX] = {0};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};
class Solution
{
public:
    int Height_Tree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int countLeft = 1 + Height_Tree(root->left);
        int countRight = 1 + Height_Tree(root->right);
        return max(countLeft, countRight);
    }

    void printPreorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
    void printPostorder(TreeNode *root)
    {
        stack<TreeNode *> children;
        TreeNode *cur = root;
        while (true)
        {
            if (cur != NULL)
            {
                children.push(cur);
                cur = cur->left;
            }
            else
            {
                if (children.top()->right == NULL)
                {
                    cout << children.top()->val << " ";
                    children.pop();
                    if (children.empty())
                        break;
                    cur = NULL;
                }
                else
                {
                    cur = children.top()->right;
                    children.top()->right = NULL;
                }
            }
        }
    }
    void inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
    
        while (cur != NULL || !st.empty()) {
            while (cur != NULL) { 
                st.push(cur);  
                cur = cur->left;
            }
            cur = st.top();
            st.pop();   
            cout << cur->val << " ";
            cur = cur->right; 
        }
    }




    
};
int main()
{
    Solution s;
    vector<TreeNode *> parents;
    int M;
    cout << "Nhap M = ";
    cin >> M;
    bool check = true;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        f[u]++;


        // đẩy hết các nốt cha vào 1 mảng 
        // ví dụ trên   1
        //            /   \ 
        //           2     3
        //          / \   / \ 
        //         4   6 7   8
        // Parents[ 1           2         3 ]
        //        /   \       /   \     /   \ 
        //       2     3     4     6   7     8
        // 
        // Prenst[i]->left = Parent[2*i + 1]
        // Prenst[i]->right = Parent[2*i + 2]
        if (f[u] == 1)
        {
            {
                parents.push_back(new TreeNode(u));
                parents[parents.size() - 1]->left = new TreeNode(v);
            }
        }
        if (f[u] == 2)
        {
            parents[parents.size() - 1]->right = new TreeNode(v);
        }
        if(f[u] == 1 || f[u] == 3) {
            check = false;
        }
    }
    if(check) {
        
    for (int i = 0; i < parents.size(); i++)
    {
        if (parents[i] == NULL)
            continue;
        if (2 * i + 1 < parents.size() && parents[2 * i + 1] != NULL)
        {
            parents[i]->left = parents[2 * i + 1];
        }

        if (2 * i + 2 < parents.size() && parents[2 * i + 2] != NULL)
        {
            parents[i]->right = parents[2 * i + 2];
        }
    }
    cout << "Height of tree : " << s.Height_Tree(parents[0]) - 1 << endl;
    cout << "Preoder :" ;s.printPreorder(parents[0]);cout << endl;
    cout << "Inorder : " ;s.inorderTraversal(parents[0]);cout << endl;
    cout << "Postoder : " ;s.printPostorder(parents[0]); cout << endl;
    }

    else {
        cout << "Graph is not a tree" << endl;
    }
    return 0;
}