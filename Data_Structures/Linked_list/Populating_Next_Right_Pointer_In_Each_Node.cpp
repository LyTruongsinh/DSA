#include <iostream>
using namespace std;
class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node* leftmost = root;
        while (leftmost->left) {
            Node* head = leftmost;
            while (head) {
                head->left->next = head->right;
                if (head->next) {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};
int main() {
    Solution s;
    Node* root = new Node{1, nullptr, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr, nullptr};
    root->right->left = new Node{6, nullptr, nullptr, nullptr};
    root->right->right = new Node{7, nullptr, nullptr, nullptr};
    s.connect(root);
    return 0;
}

// Explanation:
        //        1
        //      /   \
        //     2     3
        //    / \   / \
        //   4   5 6   7
// The next pointers will be set as follows:
// leftmost = 1
// Because leftmost->left != NULL, we enter the while loop.
//     head = 1
//     head != NULL, we enter the inner while loop.
//         head->left->next = head->right => 2->next = 3 => 2 -> 3
//         head->next = NULL, so we skip the second assignment.
// leftmost = 1->left => 2
// Because leftmost->left != NULL, we enter the while loop.
//     head = 2
//     head != NULL, we enter the inner while loop.
//         head->left->next = head->right => 4->next = 5 => 4 -> 5
//         head->next != NULL, so we do the second assignment.
//             head->right->next = head->next->left => 5->next = 6 => 5 -> 6
//         head = head->next => 3
//     head = 3
//     head != NULL, we enter the inner while loop.
//         head->left->next = head->right => 6->next = 7 => 6 -> 7
//         head->next = NULL, so we skip the second assignment.