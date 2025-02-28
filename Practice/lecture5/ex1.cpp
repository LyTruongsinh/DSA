#include <iostream>
#include <stack>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    int Height_Tree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int countLeft = 1 + Height_Tree(root->left);
        int countRight = 1 + Height_Tree(root->right);
        if (countLeft < countRight)
            return countRight;
        return countLeft;
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
                    if(children.empty()) break;
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

    void printInorder(struct TreeNode* root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
};
int main()
{
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M;i++) {
        
    }
}