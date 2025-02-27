// #include<iostream>
// using namespace std;
// class Solution {
//     public:
//     void push(int x, int a[], int &top) {
//         a[top] = x;
//         top++;
//     }
//     void pop(int a[], int &top) {
//         if(top == 0) {
//             cout << "Stack is empty" << endl;
//             return;
//         }
//         top--;
//     }
//     void print(int a[], int &top) {
//         if (top == 0) {
//             cout << "Empty" << endl;
//             return;
//         }
//         for (int i = 0; i < top; i++) {
//             cout << a[i] << " ";
//         }
//         cout << endl;
//     }
// };
// int main() {
//     int stack[1000];
//     int top = 0;
//     Solution s;
//     int n; cin >> n;
//     for(int i = 0; i < n; i++) {
//         string choice;
//         cin >> choice;
//         if(choice == "push") {
//             int x; cin >> x;
//             s.push(x, stack, top);
//             s.print(stack,top);
//         }
//         if(choice == "pop") {
//             s.pop(stack, top);
//             s.print(stack,top);
//         }
//     }
// }

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
struct Stack {
    Node* top; 
    Stack() {
        top = NULL;
    }
    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }
    void pop() {
        if (top == NULL) return; 
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    void printStack() {
        if (top == NULL) {
            cout << "Stack is empty";
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    Stack s;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (command == "pop") {
            s.pop();
        }
    }
    s.printStack();

    return 0;
}
