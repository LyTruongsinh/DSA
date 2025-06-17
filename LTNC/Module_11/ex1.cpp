#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
Node *insertHead(Node *head, int value)
{
    Node *newhead = new Node;
    newhead->value = value;
    newhead->next = head;
    return newhead;
}
Node *insertTail(Node *head, int value)
{
    if (head == nullptr)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;
        return newNode;
    }
    Node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    tail->next = new Node;
    tail->next->value = value;
    tail->next->next = nullptr;
    return head;
}
Node *deleteNode(Node *head, int pos)
{
    Node *temp = head;
    if (pos == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }
    else
    {
        int count = 0;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        Node *needdelete = temp->next;
        temp->next = needdelete->next;
        delete needdelete;
        return head;
    }
}
int getValue(Node *head, int pos)
{
    Node *temp = head;
    int position = 0;
    while (temp)
    {
        if (position == pos)
        {
            return temp->value;
        }
        else
        {
            temp = temp->next;
            position++;
        }
    }
    return -1;
}
int main()
{
    Node *head = nullptr;

    // Thêm đầu
    head = insertHead(head, 10);
    head = insertHead(head, 20);
    head = insertHead(head, 30); // Danh sách: 30 20 10

    cout << "Sau khi insertHead 3 phần tử: ";
    print(head);

    // Thêm cuối
    head = insertTail(head, 40);
    head = insertTail(head, 50); // Danh sách: 30 20 10 40 50
    cout << "Sau khi insertTail 2 phần tử: ";
    print(head);

    // Lấy giá trị
    cout << "Giá trị tại vị trí 2: " << getValue(head, 2) << endl;                  // 10
    cout << "Giá trị tại vị trí 10 (không hợp lệ): " << getValue(head, 10) << endl; // -1

    // Xoá phần tử
    head = deleteNode(head, 0); // Xoá phần tử đầu → 20 10 40 50
    head = deleteNode(head, 2); // Xoá phần tử thứ 2 → 20 10 50
    cout << "Sau khi deleteNode tại vị trí 0 và 2: ";
    print(head);

    // Giải phóng bộ nhớ
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}