#include <iostream>

using namespace std;

// Định nghĩa Node của danh sách liên kết
struct Node {
    int data;
    Node* next;
};


struct Queue {
    Node* front; // Con trỏ đến phần tử đầu tiên
    Node* rear;  // Con trỏ đến phần tử cuối cùng
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }
    void dequeue() {
        if (front == NULL) return; 
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL; 
        delete temp;
    }
    void printQueue() {
        if (front == NULL) {
            cout << "Queue is empty";
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    Queue q;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (command == "dequeue") {
            q.dequeue();
        }
    }

    // In kết quả
    q.printQueue();

    return 0;
}
