#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear, size;
public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = x;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        front = (front + 1) % MAX_SIZE;
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }

    int getSize() {
        return size;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front: " << q.getFront() << endl;
    
    q.dequeue();
    cout << "Front after dequeue: " << q.getFront() << endl;
    
    return 0;
}
// Enqueue (Thêm phần tử): O(1)
// Dequeue (Xóa phần tử): O(1)
// GetFront (Lấy phần tử đầu): O(1)
// IsEmpty (Kiểm tra rỗng): O(1)