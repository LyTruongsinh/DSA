#include <iostream>
#include <cctype>
using namespace std;
struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};
class Solution
{
  public:
    TreeNode *PostfixExpressionToTree(char postfix[]) 
    {
        TreeNode *stack[100]; // Stack to hold tree nodes
        int top = -1; // Stack pointer

        for (int i = 0; postfix[i] != '\0'; i++) {
            char ch = postfix[i];

            // If the character is an operand, create a new node and push it onto the stack
            if (isalnum(ch)) {
                TreeNode *node = new TreeNode(ch);
                top++;
                stack[top] = node;
            } 
            // If the character is an operator, pop two nodes from the stack, create a new node, and push it back
            else {
                TreeNode *right = stack[top];
                top--; // Pop the right child
                TreeNode *left = stack[top];
                top--; // Pop the left child
                TreeNode *node = new TreeNode(ch, left, right);
                top++; // Push the new node onto the stack
                stack[top] = node;
            }
        }

        // The root of the tree will be the only node left in the stack
        return stack[top];
    }
};
void printInOrder(TreeNode *root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}
int main() {
    Solution solution;
    char postfix[] = "12345-/*+";
    TreeNode *root = solution.PostfixExpressionToTree(postfix);
    
    cout << "In-order traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;

    return 0;
}