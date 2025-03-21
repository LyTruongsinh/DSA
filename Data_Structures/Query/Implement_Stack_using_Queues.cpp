#include <iostream>
#include <queue>
using namespace std;
class MyStack
{
public:
    queue<int> que;

    MyStack()
    {
    }

    void push(int x)
    {
        que.push(x);
        int n = que.size();

        for (int i = 0; i < n - 1; i++)
        {
            que.push(que.front());
            que.pop();
        }
    }

    int pop()
    {
        int result = que.front();
        que.pop();

        return result;
    }

    int top()
    {
        return que.front();
    }

    bool empty()
    {
        return que.empty();
    }
};
int main()
{
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
    cout << stack.empty() << endl;
    return 0;
}