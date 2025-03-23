#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
Node* deleteDuplicates(Node* head) {
    Node* rear = head;
    Node* font = head;
    while(rear != nullptr) {
        if(font != nullptr) {
            if(rear->value == font->value) {
                font = font->next;
            }
            else {
                rear->next = font;
                rear = rear->next;
            }
        }
        else {
            rear->next = font;
            rear = rear->next;
        }
    }
    return head;
}
Node* insert(Node* head, int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;
    if(head == nullptr) {
        head = newNode;
    }
    else {
        Node* end = head;
        while(end->next != nullptr) {
            end = end->next;
        }
        if(end->value <= value ) {
            end->next = newNode;
        }
        else if(head->value >= value) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* prev = head;
            while(prev != nullptr) {
                if(prev->value <= value && prev->next->value >= value) {
                    newNode->next = prev->next;
                    prev->next = newNode;
                    break;
                }
                prev = prev->next;
            }
        }
    }
    return head;
}
void print(Node* head) {
    while(head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    head = insert(head, 2);
    head = insert(head, 2);
    head = insert(head, 1);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 4);
    head = deleteDuplicates(head);
    print(head);
    return 0;
}