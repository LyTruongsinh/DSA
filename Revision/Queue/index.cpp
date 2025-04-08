#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    { // Constructor khởi tạo node mới
        data = x;
        next = NULL;
    }
};
class Queue
{
private:
    Node *front, *rear;
    int count;

public:
    Queue()
    {
        front = rear = nullptr;
        count = 0;
    }
    void enqueue(int x)
    {
        Node *newNode = new Node(x);
        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty!\n";
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == NULL)
        { // Nếu sau khi xóa mà rỗng, cần cập nhật rear
            rear = NULL;
        }
        delete temp;
        count--;
    }
    int getFront() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }
    int size() {
        return count;
    }
    bool isEmpty() {
        return count == 0;
    }
    void printQueue() {
        Node *temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    void copy(const Queue &other) {
        clear(); // Xóa nội dung hiện tại
        Node *temp = other.front;
        while (temp != NULL) {
            enqueue(temp->data);
            temp = temp->next;
        }
    }
};
int main()
{
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.printQueue(); // In ra hàng đợi: 1 2 3

    cout << "Front element: " << q1.getFront() << endl; // In ra phần tử đầu tiên: 1
    cout << "Size of queue: " << q1.size() << endl; // In ra kích thước hàng đợi: 3

    q1.dequeue();
    q1.printQueue(); // In ra hàng đợi sau khi xóa phần tử đầu tiên: 2 3

    Queue q2;
    q2.copy(q1); // Sao chép nội dung từ q1 sang q2
    q2.printQueue(); // In ra hàng đợi q2: 2 3

    return 0;
}