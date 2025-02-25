#include <iostream>
using namespace std;
class Stack
{
public:
    int peek;
    int arr[100];
    Stack()
    {
        peek = -1;
    }
    void push(int x)
    {
        if (peek == 99)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[++peek] = x;
        }
    }
    int pop()
    {
        if (peek == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[peek--];
    }

    int top()
    {
        if (peek == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[peek];
    }

    int size()
    {
        return peek + 1;
    }

    void print()
    {
        for (int i = 0; i <= peek; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    Stack s;
    while (1)
    {
        cout << "---------------------\n";
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. top\n";
        cout << "4. size\n";
        cout << "0. Exit\n";
        cout << "---------------------\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int x;
            cout << "Nhập số: ";
            cin >> x;
            s.push(x);
            s.print();
            cout << endl;
            break;
        }
        case 2:
        {
            cout << s.pop() << endl;
            cout << endl;
            break;
        }
        case 3:
        {
            cout << s.top() << endl;
            s.print();
            cout << endl;
            break;
        }
        case 4:
        {
            cout << s.size() << endl;
            cout << endl;
            break;
        }
        case 0:
            return 0;
        default:
            cout << "Lựa chọn không hợp lệ!" << endl;
        }
    }
}