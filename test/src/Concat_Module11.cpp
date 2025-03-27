#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int value;
    Node* next;
};
Node* concat(vector<Node*> heads) {
    Node* result = nullptr;
    Node* rear = nullptr;
    for (size_t i = 0; i < heads.size(); i++) {
        Node* head = heads[i];
        if (!head) continue;  // Bỏ qua danh sách rỗng

        if (!result) {
            result = head;
        } else {
            rear->next = head;
        }
        // Duyệt đến node cuối cùng của danh sách hiện tại
        while (head->next) {
            head = head->next;
        }
        rear = head;
    }

    return result;
}

int main() {
    vector<Node*> heads;
    Node* head1 = new Node();
    head1->value = 1;
    Node* node2 = new Node();
    node2->value = 2;
    Node* node3 = new Node();
    node3->value = 3;
    head1->next = node2;
    node2->next = node3;
    heads.push_back(head1);
    Node* head2 = new Node();
    head2->value = 4;
    Node* node5 = new Node();
    node5->value = 5;
    Node* headCombined = concat(heads);
    while(headCombined) {
        cout << headCombined->value << " ";
        headCombined = headCombined->next;
    }
}