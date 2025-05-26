#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

class MyCircularDeque {
private:
    int Size;
    Node* dummy; // Dummy node
    Node* front; // First actual node
    Node* rear;  // Last node
    int count;

public:
    MyCircularDeque(int k) {
        Size = k;
        count = 0;
        dummy = new Node(0); // dummy->next = nullptr ban đầu
        front = nullptr;
        rear = nullptr;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        Node* newNode = new Node(value);

        if (isEmpty()) {
            dummy->next = newNode;
            front = rear = newNode;
        } else {
            newNode->next = dummy->next;
            dummy->next = newNode;
            front = newNode;
        }
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        Node* newNode = new Node(value);

        if (isEmpty()) {
            dummy->next = newNode;
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        Node* toDelete = dummy->next;
        dummy->next = toDelete->next;
        front = dummy->next;
        delete toDelete;

        count--;
        if (count == 0) {
            front = rear = nullptr;
        }
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        if (count == 1) {
            delete rear;
            dummy->next = front = rear = nullptr;
            count = 0;
            return true;
        }

        Node* prev = dummy;
        while (prev->next != rear) {
            prev = prev->next;
        }

        delete rear;
        rear = prev;
        rear->next = nullptr;
        count--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : front->value;
    }

    int getRear() {
        return isEmpty() ? -1 : rear->value;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == Size;
    }
};

int main() {
    MyCircularDeque deque(8);        // Khởi tạo deque với kích thước 8
    cout << deque.insertFront(5) << endl; // true
    cout << deque.getFront() << endl;     // 5
    cout << deque.isEmpty() << endl;      // false
    cout << deque.deleteFront() << endl;  // true
    cout << deque.insertLast(3) << endl;  // true
    cout << deque.getRear() << endl;      // 3
    cout << deque.insertLast(7) << endl;  // true
    cout << deque.insertFront(7) << endl; // true
    cout << deque.deleteLast() << endl;   // true
    cout << deque.insertLast(4) << endl;  // true
    cout << deque.isEmpty() << endl;      // false

    return 0;
}
