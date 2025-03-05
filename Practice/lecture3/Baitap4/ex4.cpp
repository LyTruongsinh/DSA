
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int x) {  // Constructor khởi tạo node mới
        data = x;
        next = NULL;
    }
};

// Hàng đợi sử dụng danh sách liên kết
class Queue {
private:
    Node *front, *rear;
    int count; 

public:
    Queue() { // Constructor
        front = rear = NULL;
        count = 0;
    }

    // Thêm phần tử vào cuối hàng đợi
    void enqueue(int x) {
        Node *newNode = new Node(x);
        if (rear == NULL) { 
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    // Xóa phần tử ở đầu hàng đợi
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == NULL) { // Nếu sau khi xóa mà rỗng, cần cập nhật rear
            rear = NULL;
        }
        delete temp;
        count--;
    }

    // Trả về phần tử đầu tiên trong hàng đợi
    int getFront() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }

    // Trả về số phần tử trong hàng đợi
    int size() {
        return count;
    }

    // In danh sách hàng đợi
    void printQueue() {
        Node *temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "Front: " << q.getFront() << endl;
    cout << "Size: " << q.size() << endl;
    q.printQueue();
    q.dequeue();
    cout << "After dequeue:\n";
    q.printQueue();
    return 0;
}
