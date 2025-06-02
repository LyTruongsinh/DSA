#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
struct AVLTreeNode
{
    int key;
    int height;
    AVLTreeNode *left;
    AVLTreeNode *right;
    AVLTreeNode(int val)
    {
        key = val;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};
AVLTreeNode *RotateRight(AVLTreeNode *Y)
{
    AVLTreeNode *X = Y->left;
    AVLTreeNode *T2 = X->right;
    // Quay
    X->right = Y;
    Y->left = T2;
    // Cập nhật chiều cao
    Y->height = max(Height(Y->left), Height(Y->right)) + 1;
    X->height = max(Height(X->left), Height(X->right)) + 1;
    return X;
}
AVLTreeNode *RotateLeft(AVLTreeNode *X)
{
    AVLTreeNode *Y = X->right;
    AVLTreeNode *T2 = Y->left;
    // Quay
    Y->left = X;
    X->right = T2;
    // Cập nhật chiều cao
    X->height = max(Height(X->left), Height(X->right)) + 1;
    Y->height = max(Height(Y->left), Height(Y->right)) + 1;
    return Y;
}
int Height(AVLTreeNode *root)
{
    if (root == nullptr)
        return 0;
    return root->height;
}
bool Balance(AVLTreeNode *root)
{
    if (root == nullptr)
        return true;
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    if (abs(leftHeight - rightHeight) > 1)
    {
        return false;
    }
    return true;
}
int HeightDifference(AVLTreeNode *root)
{
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return leftHeight - rightHeight;
}
AVLTreeNode *Insert(AVLTreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new AVLTreeNode(val); // Tạo nút mới khi cây rỗng hoặc đến vị trí cần chèn
    }

    if (val < root->key)
    {
        root->left = Insert(root->left, val); // Chèn vào cây con bên trái
    }
    else
    {
        root->right = Insert(root->right, val); // Chèn vào cây con bên phải
    }

    // Cập nhật chiều cao
    root->height = max(Height(root->left), Height(root->right)) + 1;
    if (!Balance(root))
    {
        // Lệch phải phải
        if (HeightDifference(root) < -1 && val > root->right->key)
        {
            return RotateLeft(root);
        }
        // Lệch phải trái
        if (HeightDifference(root) < -1 && val < root->right->key)
        {
            root->right = RotateRight(root->right);
            return RotateLeft(root);
        }
        // Lệch trái trái
        if (HeightDifference(root) > 1 && val < root->left->key)
        {
            return RotateRight(root);
        }
        // Lệch trái phải
        if (HeightDifference(root) > 1 && val > root->left->key)
        {
            root->left = RotateLeft(root->left);
            return RotateRight(root);
        }
    }
    return root; // Trả về gốc sau khi cập nhật
}

int main()
{
    AVLTreeNode *head = nullptr;
    head = Insert(head, 10);
    return 0;
}