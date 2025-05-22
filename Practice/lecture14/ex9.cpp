// write TreeSearch(k, T) function to check if k is in the binary tree search T.
#include <iostream>
using namespace std;

// Định nghĩa cấu trúc node của cây
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};

// Hàm tìm kiếm giá trị k trong cây T
bool TreeSearch(int k, Node* T) {
    if (T == nullptr) return false;

    if (k == T->value) return true;
    else if (k < T->value) return TreeSearch(k, T->left);
    else return TreeSearch(k, T->right);
}
int main() {
    // Tạo một cây nhị phân tìm kiếm
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    int k;
    cout << "Nhập giá trị k để tìm kiếm: ";
    cin >> k;

    if (TreeSearch(k, root)) {
        cout << "Giá trị " << k << " có trong cây." << endl;
    } else {
        cout << "Giá trị " << k << " không có trong cây." << endl;
    }

    return 0;
}
