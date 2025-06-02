#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;
int n,m;
vector<int> adj[MAX];
bool visited[MAX];
// O(sodinh + socanh) với danh sách kề
// O(sodinh^2) với ma trận kề
void Input()
{
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int x : adj[v])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    } 
}
int main()
{
    Input();
    BFS(1);
    return 0;
}