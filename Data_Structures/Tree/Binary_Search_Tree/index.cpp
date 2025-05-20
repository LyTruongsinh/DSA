#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *findMin(TreeNode *root);
    TreeNode *findMax(TreeNode *root);
    void fineOne(TreeNode *root, int val);
    TreeNode *insert(TreeNode *root, int val);
    TreeNode *erase(TreeNode *root, int val);
    TreeNode *eraseMin(TreeNode *root, int val);
    TreeNode *eraseMax(TreeNode *root, int val);
    bool checkBinarySearchTree(TreeNode *root);
    void findLCA(TreeNode *root);
    bool balanceBST(TreeNode *root);
    void printInorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
    void helperForCheckBST (TreeNode * root) {
        if (root == nullptr)
            return;
        helperForCheckBST(root->left);
        arr.push_back(root->val);
        helperForCheckBST(root->right);
    }
};
TreeNode *Solution::findMin(TreeNode *root)
{
    TreeNode *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}
TreeNode *Solution::findMax(TreeNode *root)
{
    TreeNode *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp;
}
void Solution::fineOne(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        cout << "Not found" << endl;
        return;
    }
    if (root->val == val)
    {
        cout << "Found: " << root->val << endl;
        return;
    }
    else
    {
        if (val < root->val)
        {
            fineOne(root->left, val);
        }
        else
        {
            fineOne(root->right, val);
        }
    }
}
TreeNode *Solution::insert(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        root = new TreeNode(val);
        return root;
    }
    else
    {
        if (val < root->val)
        {
            root->left = insert(root->left, val);
        }
        else
        {
            root->right = insert(root->right, val);
        }
    }
    return root;
}
TreeNode *Solution::erase(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        cout << "Not found" << endl;
        return nullptr;
    }
    else
    {
        if (root->val == val)
        {
            if (root->left != nullptr)
            {
                TreeNode *temp = findMax(root->left);
                root->val = temp->val;
                root->left = erase(root->left, temp->val); // ✅ đệ quy xóa node max bên trái
                return root;
            }
            else
            {
                if (root->right != nullptr)
                {
                    TreeNode *temp = findMin(root->right);
                    root->val = temp->val;
                    root->right = erase(root->right, temp->val); // ✅ đệ quy xóa node min bên phải
                    return root;
                }
                else
                {
                    delete root;
                    return nullptr; // ✅ node lá
                }
            }
        }
        else
        {   // tìm kiếm node cần xóa
            if (val < root->val)
            {
                root->left = erase(root->left, val);
            }
            else
            {
                root->right = erase(root->right, val);
            }
        }
    }
    return root;
}

bool Solution::checkBinarySearchTree(TreeNode *root)
{
    arr.clear(); // Clear the vector before using it
    helperForCheckBST(root); // Fill the vector with inorder traversal values
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}
bool Solution::balanceBST(TreeNode *root)
{
    if (root == nullptr)
        return true;
    int leftHeight = balanceBST(root->left) ? 1 : 0;
    int rightHeight = balanceBST(root->right) ? 1 : 0;
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    return true;
}

TreeNode* eraseMin(TreeNode* root) {
    if (root == NULL) return NULL;

    if (root->left == NULL) {
        TreeNode* temp = root->right;
        delete root;          // Giải phóng node nhỏ nhất
        return temp;          // Trả về cây mới sau khi xóa node
    }

    root->left = eraseMin(root->left); // Tiếp tục đệ quy xuống trái
    return root;                       // Cập nhật lại cây
}
TreeNode* eraseMax(TreeNode* root) {
    if (root == NULL) return NULL;

    if (root->right == NULL) {
        TreeNode* temp = root->left;
        delete root;          // Giải phóng node lớn nhất
        return temp;          // Trả về cây mới sau khi xóa node
    }

    root->right = eraseMax(root->right); // Tiếp tục đệ quy xuống phải
    return root; // Cập nhật lại cây
}                        
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    cout << "Minimum value: " << s.findMin(root) << endl;
    cout << "Maximum value: " << s.findMax(root) << endl;
    s.fineOne(root, 7);
    s.fineOne(root, 20);
    root = s.insert(root, 6);
    cout << "Inserted 6 into the tree." << endl;
    cout << "Inorder traversal after insertion: ";
    s.printInorder(root);
    cout << endl;
    root = s.erase(root, 7);
    cout << "Deleted 7 from the tree." << endl;
    cout << "Inorder traversal after deletion: ";
    s.printInorder(root);
    cout << endl;
    cout << "Is the tree a binary search tree? " << (s.checkBinarySearchTree(root) ? "Yes" : "No") << endl;
    cout << "Is the tree balanced? " << (s.balanceBST(root) ? "Yes" : "No") << endl;
    cout << "Inorder traversal: ";
    s.printInorder(root);
    return 0;
}