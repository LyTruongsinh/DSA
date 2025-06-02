#include <iostream>
#include <vector>
using namespace std;
// O(sodinh + socanh) với danh sách kề
int soluongdinh;
int soluongcanh;
vector<int> adj[1001];
bool visited[1001];
void input()
{
    cin >> soluongdinh >> soluongcanh;
    for (int i = 0; i < soluongcanh; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}
void DFS(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[u])
        {
            DFS(v);
        }
    }
}
int main()
{
    input();
    DFS(1);
    return 0;
}