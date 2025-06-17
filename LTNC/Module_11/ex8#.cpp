#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};

Node *convert(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *head2 = slow->next;
    slow->next = nullptr; // cắt liên kết
    Node *p1 = head;
    Node *p2 = head2;
    while (p2)
    {
        Node *tm1 = p1->next;
        Node *tm2 = p2->next;
        p1->next = p2;
        if (tm1)
        {
            p2->next = tm1;
        }
        p1 = tm1;
        p2 = tm2;
    }
    return head;
}
// Hàm thêm node vào cuối danh sách
Node *insertTail(Node *head, int value)
{
    Node *newNode = new Node{value, nullptr};
    if (!head)
        return newNode;

    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Hàm in danh sách
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->value;
        if (temp->next)
            cout << " → ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    // Tạo danh sách: 1 → 2 → 3 → 4 → 5 → 6
    int values[] = {1, 2, 3, 4, 5, 6};
    for (int val : values)
        head = insertTail(head, val);

    cout << "Danh sách ban đầu:\n";
    printList(head);

    head = convert(head);

    cout << "Sau khi trộn:\n";
    printList(head);

    // Giải phóng bộ nhớ
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}