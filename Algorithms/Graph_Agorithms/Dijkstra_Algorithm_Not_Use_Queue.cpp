#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define MAX 1001
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
    int s;
    int e;
    vector<pair<int, int>> adj[MAX]; // danh sách kề có trọng số
    vector<long long> dist;          // khoảng cách từ s đến các đỉnh khác
    bool marked[MAX];                // mảng đánh dấu các đỉnh đã được xử lý
    vector<int> previous;            // lưu đường đi
};
Graph::Graph()
{
    sodinh = 0;
    socanh = 0;
    s = 0; // mặc định
}

void Graph::InputGraph()
{

    ifstream fin("input.txt");
    fin >> sodinh >> socanh >> e;          // đọc số đỉnh, số cạnh và đỉnh bắt đầu
    dist.assign(sodinh + 1, 1e18);         // khởi tạo khoảng cách vô cực
    previous.assign(sodinh + 1, -1);       // khởi tạo đường đi
    memset(marked, false, sizeof(marked)); // khởi tạo mảng đánh dấu

    for (int i = 0; i < socanh; i++)
    {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
}

void Graph::Dijkstra()
{
    marked[s] = true;
    if (dist[s] == 1e18)
        dist[s] = 0;

    if (s == e)
    {
        cout << "Đã đến đỉnh đích: " << e << endl;
        cout << "Khoảng cách từ điểm bắt đầu đến " << e << " là: " << dist[e] << endl;

        vector<int> path;
        for (int v = e; v != -1; v = previous[v])
        {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Đường đi: ";
        for (int v : path)
        {
            cout << v << " ";
        }
        cout << endl;
        return;
    }

    for (auto x : adj[s])
    {
        int v = x.first;
        int w = x.second;
        if (dist[v] > dist[s] + w)
        {
            dist[v] = dist[s] + w;
            previous[v] = s;
        }
    }

    long long min_dist = 1e18;
    int next = -1;
    for (int i = 0; i <= sodinh; ++i)
    {
        if (!marked[i] && dist[i] < min_dist)
        {
            min_dist = dist[i];
            next = i;
        }
    }

    if (next != -1)
    {
        s = next;
        Dijkstra();
    }
}

int main()
{
    Graph g;
    g.InputGraph();
    g.Dijkstra();
    return 0;
}