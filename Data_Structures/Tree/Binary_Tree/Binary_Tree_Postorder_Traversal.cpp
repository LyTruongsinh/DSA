#include <iostream>
#include <vector>
using namespace std;
// Định nghĩa cấu trúc cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Hàm đệ quy duyệt hậu tự (Postorder)
    void postorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }

    // Hàm chính để trả về danh sách kết quả
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};

// Hàm tạo cây ví dụ
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

// Hàm main để chạy thử nghiệm
int main() {
    TreeNode* root = createSampleTree();
    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    // In kết quả duyệt hậu tự
    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
