#include <iostream>
#include <limits.h>
#include <vector>
// O(sodinh*socanh)
using namespace std;
struct Edge
{
    int u, v, w;
};
int sodinh, socanh;
vector<Edge> edges;
vector<int> dist;
vector<int> parent;
int source;
void Input()
{
    cin >> sodinh >> socanh;
    for (int i = 0; i < socanh; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w})
    }
    cin >> source;
}
void BellmanFord()
{
    dist.assign(sodinh, INT_MAX);
    parent.assign(sodinh, -1);
    dist[source] = 0;
    for (int i = 1; i < V; ++1)
    {
        for (const auto &e : edges)
        {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w parent[e.v] = e.u;
            }
        }
    }

    // kiểm tra chu trình âm
    for (const auto &e : edges)
    {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
        {
            cout << "Đồ thị có chu trình âm!\n";
            return;
        }
    }

    // in kết quả
    for (int i = 0; i < V; ++i)
    {
        if (dist[i] == INT_MAX)
            cout << "Đỉnh " << i << ": Không thể tới\n";
        else
        {
            cout << "Đỉnh " << i << ": " << dist[i] << ", Đường đi: ";
            PrintPath(i);
            cout << endl;
        }
    }
}
void PrintPath(int v)
{
    if (v == source)
    {
        cout << source;
    }
    else if (parent[v] == -1)
    {
        cout << "không có đường";
    }
    else
    {
        PrintPath(parent[v]);
        cout << " -> " << v;
    }
}
int main()
{
    InputGraph();
    BellmanFord();
    return 0;
}