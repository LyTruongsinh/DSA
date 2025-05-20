#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Node
{
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
  public:
    Node *connect(Node *root) {
        if (root == NULL)
            return root;
        Node *cur = root;
        while (cur != NULL)
        {
            Node *dummy = new Node(0);
            Node *tail = dummy;
            while (cur != NULL)
            {
                if (cur->left != NULL)
                {
                    tail->next = cur->left;
                    tail = tail->next;
                }
                if (cur->right != NULL)
                {
                    tail->next = cur->right;
                    tail = tail->next;
                }
                cur = cur->next;
            }
            cur = dummy->next;
        }
        return root;
    }
};
int main()
{
    Solution s;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    s.connect(root);
    return 0;
}