#include <iostream>
#include <limits.h>
#include <vector>


using namespace std;

class Graph
{
  private:
    struct Edge
    {
        int u, v, w;
    };

    int V, E;
    vector<Edge> edges;
    vector<int> dist;
    vector<int> parent;
    int source;

  public:
    Graph() : V(0), E(0), source(0) {}

    void InputGraph()
    {
        cout << "Nhập số đỉnh: ";
        cin >> V;
        cout << "Nhập số cạnh: ";
        cin >> E;

        cout << "Nhập các cạnh dạng: u v w\n";
        for (int i = 0; i < E; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        cout << "Nhập đỉnh nguồn: ";
        cin >> source;
    }

    void Bellman_Ford()
    {
        dist.assign(V, INT_MAX);
        parent.assign(V, -1);
        dist[source] = 0;

        // Relax V - 1 times
        for (int i = 1; i < V; ++i)
        {
            for (const auto &e : edges)
            {
                if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
                {
                    dist[e.v] = dist[e.u] + e.w;
                    parent[e.v] = e.u;
                }
            }
        }

        // Check for negative cycles
        for (const auto &e : edges)
        {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
            {
                cout << "Đồ thị có chu trình âm!\n";
                return;
            }
        }

        // In kết quả
        cout << "\nKhoảng cách từ đỉnh " << source << ":\n";
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
};
int main()
{
    Graph g;
    g.InputGraph();
    g.Bellman_Ford();
    return 0;
}