#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;
int sodinh;
int socanh;
bool visited[MAX];
stack<int> stack;
vector<int> adj[MAX];
vector<int> adjtranspose[MAX];
void Input()
{
    cin >> sodinh >> socanh;
    for(int i = 0; i < socanh; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjtranspose[v].push_back(u);
    }
}
void DFS(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            DFS(v);
        }
    }
    Stack.push(v)
}
void DFS_Transpose(int u)
{
    visited[u] = true;
    cout << v << " ";
    for(int v : adjtranspose[u])
    {
        if(!visited[v])
        {
            DFS_Transpose(v)
        }
    }
}
void Count_Scc()
{
    memset(visited, false, sizeof(visited));
    // Bước 1: Duyệt đồ thị ban đầu và lưu thứ tự hoàn thành vào stack
    for(int i = 0; i <= sodinh; i++)
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
    // Bước 2: Đảo ngược đồ thị
    // Bước 3: Duyệt đồ thị chuyển vị theo thứ tự hoàn thành
    memset(visited, false, sizeof(visited));
    while(!Stack.empty())
    {
        int v = Stack.top();
        Stack.pop();
        if(!visited[v])
        {
            DFS_Transpose(v);
        }
    }
}
int main()
{
    Input();
    Count_Scc();
    return 0;
}