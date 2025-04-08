#include <iostream>
using namespace std;
class Tree {
public:
    int data;
    Tree *left, *right;
    Tree(int val) {
        data = val;
        left = right = NULL;
    }
    void preorder();
    void inorder();
    void postorder();
};
void Tree::preorder() {
    if (this == NULL) return;
    cout << data << " ";
    left->preorder();
    right->preorder();
}
void Tree::inorder() {
    if (this == NULL) return;
    left->inorder();
    cout << data << " ";
    right->inorder();
}
void Tree::postorder() {
    if (this == NULL) return;
    left->postorder();
    right->postorder();
    cout << data << " ";
}
int main() {
    Tree *root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    cout << "Preorder: ";
    root->preorder();
    cout << endl;
    cout << "Inorder: ";
    root->inorder();
    cout << endl;
    cout << "Postorder: ";
    root->postorder();
    cout << endl;
    return 0;
}