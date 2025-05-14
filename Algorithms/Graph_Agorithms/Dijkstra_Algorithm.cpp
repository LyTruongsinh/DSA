#include <algorithm>
#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define MAX 100001
const long long INF = 1e18;

using namespace std;

class Graph
{
  public:
    Graph();
    void InputGraph();
    void Dijkstra();

  private:
    int sodinh;
    int socanh;
    int s; // đỉnh bắt đầu
    vector<pair<int, int>> adj[MAX]; // danh sách kề có trọng số
    vector<long long> dist;          // khoảng cách từ s đến các đỉnh khác
};

Graph::Graph()
{
    sodinh = 0;
    socanh = 0;
    s = 1; // mặc định
}

void Graph::InputGraph()
{
    ifstream fin("input.txt");
    if (!fin)
    {
        cerr << "Khong the mo file input.txt" << endl;
        exit(1);
    }

    cout << "Dang doc du lieu tu file input.txt...\n";

    fin >> sodinh;
    fin >> socanh;
    fin >> s; // đọc đỉnh bắt đầu

    dist.assign(sodinh + 1, INF); // khởi tạo khoảng cách vô cực

    for (int i = 0; i < socanh; i++)
    {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u].push_back({v, w});
        // Nếu là đồ thị vô hướng, thêm dòng sau:
        // adj[v].push_back({u, w});
    }

    fin.close();
}

void Graph::Dijkstra()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
    dist[s] = 0;
    Q.push({0, s});

    while (!Q.empty())
    {
        pair<long long, int> top = Q.top();
        Q.pop();
        int u = top.second;
        long long distance = top.first;

        if (distance > dist[u])
            continue;

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                Q.push({dist[v], v});
            }
        }
    }

    cout << "Khoang cach tu dinh " << s << " den cac dinh khac:\n";
    for (int i = 1; i <= sodinh; i++)
    {
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    Graph g;
    g.InputGraph();
    g.Dijkstra();
    return 0;
}
