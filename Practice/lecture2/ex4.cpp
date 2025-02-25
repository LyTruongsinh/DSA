#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

void enqueue(queue<int> &q, int x)
{
    q.push(x);
}

void dequeue(queue<int> &q)
{
    if (!q.empty())
    {
        q.pop();
    }
}

void processCommands(int n)
{
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "enqueue")
        {
            int x;
            cin >> x;
            enqueue(q, x);
        }
        else if (s == "dequeue")
        {
            dequeue(q);
        }
    }

    // In kết quả hàng đợi
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    processCommands(n);

    return 0;
}
