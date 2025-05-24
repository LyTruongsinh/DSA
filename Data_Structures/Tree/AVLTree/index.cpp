#include <algorithm>
#include <iostream>
using namespace std;
struct AVLNode
{
    int key;
    AVLNode *left;
    AVLNode *right;
    int height;
    AVLNode(int val)
    {
        key = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};
// ======= Hàm phụ =======
int height(AVLNode *node)
{
    if (node != nullptr)
        return node->height;
    else
        return 0;
}

int getBalance(AVLNode *node)
{
    if (node != nullptr)
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        int balanceFactor = leftHeight - rightHeight;
        return balanceFactor;
    }
    return 0;
}
AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Quay
    x->right = y;
    y->left = T2;
    // Cập nhật chiều cao
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Quay
    y->left = x;
    x->right = T2;

    // Cập nhật chiều cao
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode *minValueNode(AVLNode *node)
{
    AVLNode *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// ======= Thêm node =======
AVLNode *insert(AVLNode *root, int key)
{
    // Trường hợp cơ bản: cây rỗng, tạo nút mới
    if (root == nullptr)
        return new AVLNode(key);

    // Nếu key nhỏ hơn, chèn vào cây con bên trái
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    // Nếu key lớn hơn, chèn vào cây con bên phải
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    // Nếu key đã tồn tại, không chèn gì cả
    else
    {
        return root;
    }

    // Cập nhật chiều cao của nút hiện tại
    root->height = 1 + max(height(root->left), height(root->right));

    // Tính hệ số cân bằng
    int balance = getBalance(root);

    // === Các trường hợp mất cân bằng ===

    // Trường hợp Left Left (LL)
    if (balance > 1 && key < root->left->key)
    {
        return rightRotate(root);
    }

    // Trường hợp Right Right (RR)
    if (balance < -1 && key > root->right->key)
    {
        return leftRotate(root);
    }

    // Trường hợp Left Right (LR)
    if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Trường hợp Right Left (RL)
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Trường hợp không mất cân bằng, trả về root
    return root;
}

// ======= Xoá node =======
AVLNode *deleteNode(AVLNode *root, int key)
{
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node có một hoặc không có con
        if (root->left == nullptr)
        {
            AVLNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            AVLNode *temp = root->left;
            delete root;
            return temp;
        }

        // Node có 2 con
        AVLNode *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    if (root == nullptr)
        return root;

    // Cập nhật chiều cao và cân bằng
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // Kiểm tra cân bằng và xoay
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// ======= In-order =======
void inorder(AVLNode *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// ======= Main =======
int main()
{
    AVLNode *root = nullptr;

    int keys[] = {9, 5, 1, 2, 3};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
    {
        root = insert(root, keys[i]);
    }

    cout << "Cay AVL sau khi them: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 9);

    cout << "Cay AVL sau khi xoa 9: ";
    inorder(root);
    cout << endl;

    return 0;
}
