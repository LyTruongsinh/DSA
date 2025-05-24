#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001
using namespace std;
class Graph
{
  public:
    Graph(int _sodinh, int _socanh)
    void Input();
    void Kahn();
    void Print();
  private:
    int sodinh;
    int socanh;
    vector<int> adj[MAX];
    bool visited[MAX];
    vector<int> topo;
    int banbacIn[MAX];
    int banbacOut[MAX];
};
Graph::Graph(int _sodinh, int _socanh)
{
    sodinh = _sodinh;
    socanh = _socanh;
    memset(visited, false, sizeof(visited));
}
void Graph::Input()
{
    cin >> sodinh >> socanh;
    for(int i = 0; i < socanh; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        banbacIn[v]++;
        banbacOut[u]++;
    }
}
void Graph::Kahn()
{
    queue<int> Q;
    for(int i = 1; i <= sodinh; i++)
    {
        if(banbacIn[i] == 0)
        {
            Q.push(i);
        }
    }
    while(!Q.empty())
    {
        int u = Q.fron();
        Q.pop();
        topo.push_back(u);
        for(int v : adj[u])
        {
            banbacIn[v]--;
            if(banbacIn[v] == 0)
            {
                Q.push(v);
            }
        }
    }
}
void Graph::Print()
{
    for(int i = 0; i < topo.size(); i++)
    {
        cout << topo[i] << " ";
    }
}
int main()
{
    Graph g(sodinh, socanh);
    g.Input();
    g.Kahn();
    g.Print();
    return 0;
}
    
