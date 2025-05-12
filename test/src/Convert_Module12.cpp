#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

Node *convert(Node *head)
{
    if (!head || !head->next)
        return head;

    // Tìm node b1 (giữa danh sách)
    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // prev là node cuối của dãy a, slow là node đầu của dãy b
    prev->next = nullptr; // Cắt danh sách thành 2 nửa

    Node *left = head;
    Node *right = slow;
    Node dummy; // Không dùng constructor
    dummy.val = 0;
    dummy.next = nullptr;
    Node *tail = &dummy;

    // Trộn 2 nửa lại
    while (left && right)
    {
        tail->next = left;
        left = left->next;
        tail = tail->next;

        tail->next = right;
        right = right->next;
        tail = tail->next;
    }
    // Nếu còn dư (trường hợp n lẻ, nhưng đề bài nửa-nửa nên không cần)
    if (left)
        tail->next = left;
    if (right)
        tail->next = right;

    return dummy.next;
}
int main()
{
    // Tạo danh sách liên kết
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Chuyển đổi danh sách
    Node *result = convert(head);

    // In danh sách kết quả
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}