#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
class Solution {
   public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        // Find the middle element
        ListNode *mid = head, *fast = head, *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        // Find the left and right subtrees
        ListNode *right = mid->next;
        if (prev != nullptr) {
            prev->next = nullptr;  // Split the list into two halves
        }
        ListNode *left = head;
        // Create the root node
        TreeNode *root = new TreeNode(mid->val);
        // Recursively build the left and right subtrees
        root->left = sortedListToBST(left);
        root->right = sortedListToBST(right);
        return root;
    }
};
int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    TreeNode *root = s.sortedListToBST(head);
    return 0;
}