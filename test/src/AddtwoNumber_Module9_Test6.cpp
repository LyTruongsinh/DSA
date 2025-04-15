#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node* next;
    Node (int x) : value(x), next(NULL) {}
};
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* temphead = new Node(0); // node giả làm đầu danh sách
    Node* cur = temphead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry > 0) {
        int val1 = 0;
        int val2 = 0;

        if (l1 != NULL) {
            val1 = l1->value;
        }

        if (l2 != NULL) {
            val2 = l2->value;
        }

        int sum = val1 + val2 + carry;
        carry = 0;
        if (sum >= 10) {
            carry = 1;
        }

        int digit = sum % 10;
        cur->next = new Node(digit);
        cur = cur->next;

        if (l1 != NULL) {
            l1 = l1->next;
        }

        if (l2 != NULL) {
            l2 = l2->next;
        }
    }
    return temphead->next;
}
Node* createListFromArray(int arr[], int size) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < size; ++i) {
        Node* newNode = new Node(arr[i]);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->value;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int a[] = {2, 4, 3}; // biểu diễn 342
    int b[] = {5, 6, 4}; // biểu diễn 465
    Node* l1 = createListFromArray(a, 3);
    Node* l2 = createListFromArray(b, 3);

    Node* result = addTwoNumbers(l1, l2); // Kết quả là 807 => 7 -> 0 -> 8
    printList(result);

    return 0;
}
