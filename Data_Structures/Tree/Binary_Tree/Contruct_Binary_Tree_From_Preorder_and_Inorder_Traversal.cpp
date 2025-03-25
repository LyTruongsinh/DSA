#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    // Hàm xây dựng cây nhị phân từ preorder & inorder
    TreeNode *buildTreeHelper(vector<int> &preorder, int &preIndex, int inStart, int inEnd, unordered_map<int, int> &inMap)
    {
        if (inStart > inEnd)
            return NULL;

        // Lấy giá trị node gốc từ preorder
        int rootVal = preorder[preIndex++];
        TreeNode *root = new TreeNode(rootVal);

        // Tìm vị trí của root trong inorder
        int inIndex = inMap[rootVal];

        // Xây cây con bên trái (trước inIndex trong inorder)
        root->left = buildTreeHelper(preorder, preIndex, inStart, inIndex - 1, inMap);
        // Xây cây con bên phải (sau inIndex trong inorder)
        root->right = buildTreeHelper(preorder, preIndex, inIndex + 1, inEnd, inMap);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }
        int preIndex = 0;
        return buildTreeHelper(preorder, preIndex, 0, inorder.size() - 1, inMap);
    }

    // Hàm inorder để kiểm tra cây
    void printInorder(TreeNode *root)
    {
        if (!root)
            return;
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
};
int main() {
    Solution s;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = s.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    s.printInorder(root); // Kết quả phải trùng với mảng inorder

    return 0;
}

// Giải thích code: Xây dựng cây nhị phân từ Preorder và Inorder
// Bài toán yêu cầu xây dựng cây nhị phân từ hai danh sách:

// Preorder Traversal: {Root, Left, Right}

// Inorder Traversal: {Left, Root, Right}

// 📌 Ý tưởng chính
// Preorder giúp ta xác định gốc của cây.

// Inorder giúp ta xác định các node con trái & phải.

// Chúng ta sử dụng đệ quy để lần lượt chia cây thành các nhánh nhỏ hơn.



// Hàm buildTreeHelper()
// 🔹 Chức năng:
// Hàm này xây dựng cây nhị phân bằng cách chọn node gốc từ preorder rồi tìm các node con từ inorder.
// 🔹 Tham số:
// TreeNode *buildTreeHelper(vector<int> &preorder, int &preIndex, 
//                           int inStart, int inEnd, unordered_map<int, int> &inMap)
// preorder: Danh sách preorder traversal.

// preIndex: Biến chỉ số hiện tại trong preorder (dùng tham chiếu để cập nhật).

// inStart, inEnd: Chỉ số của vùng inorder hiện tại.

// inMap: Bản đồ tra cứu vị trí của mỗi phần tử trong inorder.