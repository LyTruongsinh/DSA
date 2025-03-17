#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();

            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);

            if (!st.empty()) cur->right = st.top();
            cur->left = nullptr;  // Đảm bảo left luôn là nullptr
        }
    }
};

// Hàm hỗ trợ in danh sách liên kết
void printLinkedList(TreeNode* root) {
    while (root) {
        cout << root->val << " -> ";
        root = root->right;
    }
    cout << "NULL\n";
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution().flatten(root);
    printLinkedList(root);

    return 0;
}
