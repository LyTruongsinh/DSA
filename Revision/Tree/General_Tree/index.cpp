#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Treeroot
{
    int data;              // Gía trị của nút
    Treeroot *firstChild;  // con đầu tiên của nút
    Treeroot *nextSibling; // anh chị em của nút
    Treeroot(int val) : data(val), firstChild(nullptr), nextSibling(nullptr) {};
};
class Tree
{
private:
    Treeroot *root;
    Treeroot *rootlists[1000];
    bool isChild[1000];

public:
    Tree() : root(nullptr)
    {
        memset(rootlists, NULL, sizeof(rootlists)); // Khởi tạo mảng rootLists tất cả bằng nullptr
        memset(isChild, false, sizeof(isChild));    // Khởi tạo mảng isChild tất cả là false
    }
    void updateRoot();
    void addChild(int parent, int child);
    int Height(Treeroot *root);
    bool isBinaryTree(Treeroot *root);
    void printPreOrder(Treeroot *root);
    void printInOrder(Treeroot *root);
    void printPostOrder(Treeroot *root);
    Treeroot *getRoot(); // Getter for root
};
void Tree::updateRoot()
{
    for (int i = 0; i < 1000; i++)
    {
        if (rootlists[i] != nullptr && isChild[i] == false)
        {
            root = rootlists[i];
            break;
        }
    }
}
void Tree::addChild(int parent, int child)
{
    if (rootlists[parent] == NULL) rootlists[parent] = new Treeroot(parent); // nếu chưa thì tạo Treeroot [parent|firstChild|nextSibling] và lưu vào rootLists
    
    if (rootlists[child] == NULL) rootlists[child] = new Treeroot(child); // nếu chưa thì tạo Treeroot [child|firstChild|nextSibling] và lưu vào rootLists
    
    Treeroot *parentroot = rootlists[parent]; // nếu tồn tại thì lấy ra
    Treeroot *childroot = rootlists[child]; // nếu tồn tại thì lấy ra
    if (parentroot->firstChild == nullptr) // Nếu chưa có con cả
    {
        parentroot->firstChild = childroot;
    }
    else // nếu có con cả
    {
        Treeroot *temp = parentroot->firstChild;
        // Duyệt qua các anh em (nextSibling) của con đầu tiên cho đến khi gặp nút cuối cùng
        while (temp->nextSibling != nullptr)
        {
            temp = temp->nextSibling;
        }
        temp->nextSibling = childroot; // Gán con mới vào cuối danh sách anh em
    }
    isChild[child] = true; // Đánh dấu nút con đã được thêm vào
    updateRoot();
}
// Hàm tính chiều cao của cây (hoặc chiều cao của một nút trong cây)
// Trả về chiều cao của cây có gốc là `root`
int Tree::Height(Treeroot *root)
{
    if (root == nullptr)
        return -1; // Nếu cây rỗng thì chiều cao là -1 (không có nút nào)

    Treeroot *temp = root->firstChild; // Lấy con đầu tiên của nút gốc
    int max_height_of_root = Height(temp); // Tính chiều cao của nhánh đầu tiên
    // Nếu có con đầu tiên thì duyệt qua các anh em (nextSibling) của nó
    if (temp != nullptr)
    {
        Treeroot *tempnext = temp->nextSibling;
        while (tempnext != nullptr)
        {
            // Cập nhật chiều cao lớn nhất trong các nhánh con
            max_height_of_root = max(max_height_of_root, Height(tempnext));
            tempnext = tempnext->nextSibling; // Chuyển sang anh em tiếp theo
        }
    }
    return max_height_of_root + 1; // Cộng thêm 1 để tính chiều cao tính từ gốc
}
Treeroot *Tree::getRoot()
{
    return root;
}
bool Tree::isBinaryTree(Treeroot *root)
{
    if (root == nullptr)
        return true;

    // Đếm số lượng con của nút hiện tại
    int childCount = 0;
    Treeroot *child = root->firstChild;
    while (child != nullptr)
    {
        childCount++;
        if (childCount > 2)
            return false;
        // Đệ quy kiểm tra cây con
        if (isBinaryTree(child) == false)
            return false;
        child = child->nextSibling;
    }

    return true;
}
void Tree::printPreOrder(Treeroot *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    printPreOrder(root->firstChild);
    printPreOrder(root->nextSibling);
}
void Tree::printInOrder(Treeroot *root)
{
    if (root == nullptr)
        return;
    printInOrder(root->firstChild);
    cout << root->data << " ";
    printInOrder(root->nextSibling);
}
void Tree::printPostOrder(Treeroot *root)
{
    if (root == nullptr)
        return;
    printPostOrder(root->firstChild);
    printPostOrder(root->nextSibling);
    cout << root->data << " ";
}

int main()
{
    Tree tree;
    tree.addChild(1, 2);
    tree.addChild(1, 3);
    tree.addChild(2, 4);
    tree.addChild(2, 5);
    tree.addChild(3, 6);
    tree.addChild(3, 7);
    tree.addChild(7, 8);
    cout << "Height of tree: " << tree.Height(tree.getRoot()) << endl;
    cout << "Pre-order traversal: ";
    tree.printPreOrder(tree.getRoot());
    cout << endl;
    cout << "In-order traversal: ";
    tree.printInOrder(tree.getRoot());
    cout << endl;
    cout << "Post-order traversal: ";
    tree.printPostOrder(tree.getRoot());
    cout << endl;
    if (tree.isBinaryTree(tree.getRoot()))
    {
        cout << "The tree is a binary tree." << endl;
    }
    else
    {
        cout << "The tree is not a binary tree." << endl;
    }
    return 0;
}
