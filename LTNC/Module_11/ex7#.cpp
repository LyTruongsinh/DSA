#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
Node *deleteDuplicates(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        while (temp->next && temp->value == temp->next->value)
        {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
    return head;
}
Node *insert(Node *head, int value)
{
    Node *insert = new Node{value, nullptr};
    if (!head)
    {
        return insert;
    }
    Node *dummy = new Node{0, head};
    Node* temp = dummy;
    while(temp && temp->next)
    {
        if(temp->next->value >= value)
        {
            break;
        }
        temp = temp->next;
    }
    insert->next = temp->next;
    temp->next = insert;
    return dummy->next;
}
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
Node *createTestList()
{
    Node *head = nullptr;
    head = insertTail(head, 1);
    head = insertTail(head, 1);
    head = insertTail(head, 2);
    head = insertTail(head, 2);
    head = insertTail(head, 3);
    head = insertTail(head, 3);
    head = insertTail(head, 3);
    return head;
}
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
    Node *head = createTestList();
    cout << "Danh sách ban đầu: ";
    printList(head);

    head = deleteDuplicates(head); // Gọi hàm bạn muốn test

    cout << "Sau khi xoá trùng: ";
    printList(head);

    // Xoá toàn bộ danh sách (giải phóng bộ nhớ)
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}