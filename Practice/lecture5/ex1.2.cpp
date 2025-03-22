#include <iostream>
#include <algorithm>
#include <cstring>
#define rootS_SIZE 1000
using namespace std;
struct Treeroot
{
    int data;              // Gía trị của nút
    Treeroot *firstChild;  // con đầu tiên của nút
    Treeroot *nextSibling; // anh chị em của nút
    Treeroot(int val) : data(val), firstChild(NULL), nextSibling(NULL) {};
};
class Tree
{
public:
    Treeroot *root;                  // Khởi tạo cây bằng root root
    Treeroot *rootLists[rootS_SIZE]; // Mảng lưu trữ các root
    bool isChild[rootS_SIZE];        // Mảng lưu trữ các root con, mảng để tìm root con
    Tree() : root(NULL)
    {
        memset(rootLists, NULL, sizeof(rootLists)); // Khởi tạo mảng rootLists tất cả bằng NULL
        memset(isChild, false, sizeof(isChild));    // Khởi tạo mảng isChild tất cả là false
    }
    void updateRoot()
    {
        // Duyệt qua danh sách rootLists để tìm root KO PHẢI LÀ con của bất kỳ root nào cập nhật root
        for (int i = 0; i < rootS_SIZE; i++)
        {
            if (rootLists[i] != NULL && !isChild[i])
            {
                root = rootLists[i];
                break;
            }
        }
    }
    void addChild(int parent, int child)
    {
        //  Kiểm tra xem root đã tồn tại trong rootLists hay chưa
        if (!rootLists[parent])
            rootLists[parent] = new Treeroot(parent); // nếu chưa thì tạo Treeroot [parent|firstChild|nextSibling] và lưu vào rootLists
        if (!rootLists[child])
            rootLists[child] = new Treeroot(child); // nếu chưa thì tạo Treeroot [child|firstChild|nextSibling] và lưu vào rootLists

        // Lấy root từ trong rootLists
        Treeroot *parentroot = rootLists[parent];
        Treeroot *childroot = rootLists[child];

        if (parentroot->firstChild == NULL)
        {
            parentroot->firstChild = childroot; // nếu parentroot chưa có firtChild thì gán firstChild = childroot (Đứa con đầu tiên)
        }
        else
        {
            // Nếu đã có con cả rồi ( có firstChild)
            Treeroot *temp = parentroot->firstChild;

            // Duyệt đến cuối danh sách con của parentroot để đưa childroot vào cuối
            while (temp->nextSibling != NULL)
            {
                temp = temp->nextSibling;
            }
            temp->nextSibling = childroot;
        }
        isChild[child] = true;
        updateRoot();
    }
    int Height(Treeroot *root)
    {
        if (root == NULL)
            return 0; // điều kiện dùng

        int height = 0;
        Treeroot *tmp = root->firstChild;
        while (tmp != NULL)
        {
            height = max(height, Height(tmp)); // tìm chiều cao của từng cây con sibing
            tmp = tmp->nextSibling;
        }
        return height + 1;
    }

    bool isBinaryTree(Treeroot *root)
    {
        if (!root)
            return true; // Nếu cây rỗng thì là Binary Tree

        int count = 0;
        Treeroot *child = root->firstChild;

        // Đếm số lượng con của root
        while (child)
        {
            count++;
            if (count > 2)
                return false; // Nếu có hơn 2 con → Không phải Binary Tree
            child = child->nextSibling;
        }
        // Kiểm tra đệ quy với các root con
        return isBinaryTree(root->firstChild) && isBinaryTree(root->nextSibling);
    }
    void printPreOrder(Treeroot *root)
    {
        if (root == NULL)
            return;                       // rỗng thì dừng
        cout << root->data << " ";        // in giá trị
        printPreOrder(root->firstChild);  // đệ quy duyệt đến con cả của cây
        printPreOrder(root->nextSibling); // đệ quy duyệt đến các cây con khác
    }
    void printInOrder(Treeroot *root)
    {
        if (root == NULL)
            return;
        printInOrder(root->firstChild);
        cout << root->data << " ";
        printInOrder(root->nextSibling);
    }
    void printPostOrder(Treeroot *root)
    {
        if (root == NULL)
            return;
        printPostOrder(root->firstChild);
        printPostOrder(root->nextSibling);
        cout << root->data << " ";
    }
};
int main()
{

    Tree tree;
    tree.addChild(1, 2);
    tree.addChild(1, 3);
    tree.addChild(2, 4);
    tree.addChild(2, 5);

    cout << "Height of tree: " << tree.Height(tree.root) - 1 << endl;
    if (tree.isBinaryTree(tree.root))
    {
        cout << "This is a Binary Tree" << endl;
        tree.printPreOrder(tree.root);
        cout << endl;
        tree.printInOrder(tree.root);
        cout << endl;
        tree.printPostOrder(tree.root);
        cout << endl;
    }
    else
    {
        cout << "This is not a Binary Tree" << endl;
    }
    return 0;
}