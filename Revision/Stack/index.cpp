#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int x) { // Constructor khởi tạo node mới
        data = x;
        next = NULL;
    }
};
class Stack {
private:
    Node *top;
    int count;
public:
    Stack() {
        top = NULL;
        count = 0;
    }
    void push(int x) {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        count++;
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        count--;
    }
    int getTop() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }
    int size() {
        return count;
    }
    bool isEmpty() {
        return count == 0;
    }
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
    ~Stack() {
        clear();
    }
    void display() {
        Node *temp = top;
        cout << "Stack: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Stack stack;
    int choice, value;
    do {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Get Top\n";
        cout << "4. Size\n";
        cout << "5. Is Empty\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top element: " << stack.getTop() << endl;
                break;
            case 4:
                cout << "Size of stack: " << stack.size() << endl;
                break;
            case 5:
                cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case 6:
                stack.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}
