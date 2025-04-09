#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node* findIntersection(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* intersectionDummy = new Node(0); // Dummy node để dễ return
    Node* intersectionTail = intersectionDummy;

    while (temp1 != NULL) {
        Node* temp2 = head2; // reset lại temp2 cho mỗi vòng lặp của temp1
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                // Thêm node mới vào danh sách kết quả
                Node* newNode = new Node(temp1->data);
                intersectionTail->next = newNode;
                intersectionTail = intersectionTail->next;
                break; // Dừng khi đã tìm thấy 1 node trùng
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return intersectionDummy->next;
}

// Driver code
int main()
{
    // Create the first linked list
    Node *head1 = new Node(1);
    head1-> next = new Node(2);
    head1-> next-> next = new Node(3);
    head1-> next-> next-> next = new Node(4);
    head1-> next-> next-> next-> next = new Node(6);
    // Create the second linked list
    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next-> next = new Node(6);
    head2-> next-> next->next = new Node(8);
    // Find the intersection of the two linked lists
    Node *result = findIntersection(head1, head2);
    // Print the intersection list
    while (result)
    {
        cout << result-> data << " ";
        result = result-> next;
    }
    cout << endl;
    return 0;
}