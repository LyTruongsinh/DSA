#include <fstream>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class FloydWarshall
{
  public:
    int n;                          // số đỉnh
    vector<vector<long long>> dist; // ma trận khoảng cách
    vector<vector<int>> next;       // ma trận truy vết

    FloydWarshall() : n(0) {}

    void InputGraph()
    {
        ifstream fin("input.txt");
        fin >> n;
        dist.assign(n + 1, vector<long long>(n + 1, LLONG_MAX / 2));
        next.assign(n + 1, vector<int>(n + 1, -1));
        int m;
        fin >> m;
        for (int i = 1; i <= n; i++)
            dist[i][i] = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            fin >> u >> v >> w;
            dist[u][v] = w;
            next[u][v] = v;
        }
        fin.close();
    }

    void Run()
    {
        // Thuật toán Floyd-Warshall
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }

    void PrintPath(int u, int v)
    {
        if (next[u][v] == -1)
        {
            cout << "Khong co duong di!" << endl;
            return;
        }
        cout << u;
        while (u != v)
        {
            u = next[u][v];
            cout << " -> " << u;
        }
        cout << endl;
    }

   +++
};

int main()
{
    FloydWarshall fw;
    fw.InputGraph();
    fw.Run();
    fw.PrintAllDistances();
    // Ví dụ in đường đi ngắn nhất từ 1 đến n
    // fw.PrintPath(1, fw.n);
    return 0;
}
