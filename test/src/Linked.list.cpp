#include <iostream>
using namespace std;
struct NodeList
{
    int data;
    NodeList *next;
    NodeList(int value) : data(value), next(nullptr) {}
};
void append(NodeList *&root, int x)
{
    NodeList *newNode = new NodeList(x);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    else
    {
        NodeList *tmp = root;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        return;
    }
}
int search(NodeList *root, int x)
{
    int count = 0;
    bool found = false;
    NodeList *tmp = root;
    while (tmp != NULL)
    {
        if (tmp->data == x)
        {
            count++;
            found = true;
            break;
        }
    }
    if (!found)
        return -1;
    return count;
}
NodeList* reverse(NodeList *&root)
{
    NodeList* prev = nullptr;
    NodeList* curr = root;
    
    while (curr) {
        NodeList* nextTemp = curr->next;  // Lưu node tiếp theo
        curr->next = prev;  // Đảo chiều liên kết
        prev = curr;  // Di chuyển prev lên
        curr = nextTemp;  // Di chuyển curr lên
    }
    
    return prev; 
}
void print(NodeList *root)
{
    NodeList *tmp = root;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}
int main()
{
    NodeList *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "append")
        {
            int x;
            cin >> x;
            append(root, x);
        }
        if (str == "search")
        {
            int x;
            cin >> x;
            if (search(root, x) == -1)
                cout << "NO" << endl;
            else
                cout << search(root, x) << endl;
        }
        if (str == "reverse")
        {
            print(reverse(root));
        }
    }
    print(root);
}
