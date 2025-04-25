#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};
class Solution {
   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;


        int rootVal = postorder.back();          // Lấy giá trị gốc từ postorder
        TreeNode* root = new TreeNode(rootVal);  // Tạo nút gốc
        postorder.pop_back();  // Xóa giá trị gốc khỏi postorder
        auto it = find(inorder.begin(), inorder.end(),
                       rootVal);  // Tìm vị trí của gốc trong inorder


        //------------Tách các phần tử bên trái và bên phải của gốc trong
        //inorder thành các cây con bên trái và cây con bên phải
        vector<int> leftInorder(inorder.begin(), it);
        vector<int> rightInorder(it + 1, inorder.end());
        //------------Tách các phần tử bên trái và bên phải của gốc trong
        //inorder và postorder thành các cây con bên trái và cây con bên phải


        //------------Tách các phần tử bên trái và bên phải của gốc trong postorder
        // thành các cây con bên trái và cây con bên phải
        vector<int> leftPostorder(postorder.begin(),
                                  postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(),
                                   postorder.end());
        //------------Tách các phần tử bên trái và bên phải của gốc trong postorder
        // thành các cây con bên trái và cây con bên phải


        //------------Tạo cây con bên trái và bên phải
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
        //------------Tạo cây con bên trái và bên phải
        return root;
    }
};
int main() {
    Solution s;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = s.buildTree(inorder, postorder);
    return 0;
}