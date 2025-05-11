#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
int n, m, s, e;
// Cấu trúc lưu cạnh
struct Edge
{
    int u, v, w;
};
vector<Edge> edges;
vector<int> dist;
vector<int> parent;
// Bellman-Ford: tìm đường đi ngắn nhất từ s đến e
bool bellman_ford(int s)
{
    dist.assign(n + 1,
                INF);         // Gán tất cả các đỉnh là vô cùng (chưa biết đường đi)
    parent.assign(n + 1, -1); // Gán cha của tất cả các đỉnh là -1
    dist[s] = 0;              // Đặt khoảng cách từ đỉnh s đến chính nó là 0

    for (int i = 1; i <= n - 1; i++)
    { // Lặp lại n-1 lần để đảm bảo tính chính xác
        for (auto edge : edges)
        { // Duyệt tất cả các cạnh
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v])
            {                                         // Nếu có thể cập nhật
                dist[edge.v] = dist[edge.u] + edge.w; // Cập nhật khoảng cách
                parent[edge.v] = edge.u;              // Cập nhật cha của đỉnh v
            }
        }
    }

    // Kiểm tra chu trình âm (nếu có chu trình âm, thuật toán sẽ trả về false)
    for (auto edge : edges)
    {
        if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v])
        {
            return false; // Có chu trình âm
        }
    }

    return dist[e] != INF; // Kiểm tra xem có đường đi đến đỉnh e không
}
vector<int> get_path(int e)
{
    vector<int> path;
    while (e != -1)
    {
        path.push_back(e);
        e = parent[e];
    }
    reverse(path.begin(), path.end());
    return path;
}
// Floyd-Warshall: tất cả cặp đỉnh
vector<vector<int>> floyd_warshall()
{
    vector<vector<int>> dist_fw(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i)
        dist_fw[i][i] = 0;
    for (auto edge : edges)
        dist_fw[edge.u][edge.v] = min(dist_fw[edge.u][edge.v], edge.w);
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dist_fw[i][k] < INF && dist_fw[k][j] < INF)
                {
                    dist_fw[i][j] = min(dist_fw[i][j], dist_fw[i][k] + dist_fw[k][j]);
                }
            }
        }
    }

    return dist_fw;
}

int main()
{
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    fin >> n >> m >> s >> e;

    for (int i = 0; i < m; ++i)
    {
        int u, v, d;
        fin >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    // Bài toán a
    if (bellman_ford(s))
    {
        fout << dist[e] << "\n";
        vector<int> path = get_path(e);
        for (int city : path)
            fout << city << " ";
        fout << "\n";
    }
    else
    {
        fout << "INF\n";
        fout << "NO PATH\n";
    }

    // Bài toán b
    vector<vector<int>> fw = floyd_warshall();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (fw[i][j] == INF)
                fout << "INF ";
            else
                fout << fw[i][j] << " ";
        }
        fout << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
