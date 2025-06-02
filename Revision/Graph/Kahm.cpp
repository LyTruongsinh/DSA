#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits.h>
#include <cstring>
#include <stack>
#define MAX 1001
using namespace std;
int sodinh;
int socanh;
// O(V+E)
vector<int> adj[MAX];
bool visited[MAX];
vector<int> topo;
int Banbacin[MAX];
void Input()
{
    cin >> sodinh >> socanh;
    for(int i = 0; i < socanh; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        Banbacin[v]++;
    }
    memset(visited, false, sizeof(visited));
}
void Kahn()
{
    queue<int> q;
    for(int i = 1; i <= sodinh; i++)
    {
        if(Banbacin[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : adj[u])
        {
            Banbacin[v]--;
            if(Banbacin[v] == 0)
            {
                q.push(v);
            }
        }
    }
}
void Print() {
    for(int i = 0; i < topo.size(); i++) {
        cout << topo[i] << " ";
    }
}
int main() {
    Input();
    Kahn();
    Print();
    return 0;
}