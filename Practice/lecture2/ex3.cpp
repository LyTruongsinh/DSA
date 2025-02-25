#include <iostream>
#define MAX_SIZE 10000
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};


int count_triplets(Node* head) {
    if (head == NULL || !head->next == NULL || !head->next->next == NULL) {
        return 0; 
    }

    int count = 0;
    Node* curr = head->next;

    while (curr->next != NULL) { 
        int sum = curr->prev->data + curr->data + curr->next->data;
        if (sum == 0) {
            count++;
        }
        curr = curr->next;
    }

    return count;
}


Node* createDoublyLinkedList(int arr[], int n) {
    if (n == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    return head;
}

void deleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    int n;
    cin >> n;
    if (n < 3) {
        cout << 0 << endl; 
        return 0;
    }

    int arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = createDoublyLinkedList(arr, n);
    cout << count_triplets(head) << endl;
    
    deleteList(head);
    return 0;
}
