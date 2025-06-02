#include <fstream>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
int sodinh;
int socanh;
vector<vector<long long>> dist // ma trận lưu trọng số
    vector<vector<int>>
        next; // ma trận truy vết
void Input()
{
    cin >> sodinh >> socanh;
    // đường chéo bằng 0
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        next[u][v] = u
    }
}
void Init()
{
    dist.assign(sodinh + 1, vector<long long>(sodinh + 1, LLONG_MAX / 2));
    next.assign(sodinh + 1, vector<int>(sodinh + 1, -1));
}
void FloyWarshall()
{
    for (int k = 1; k <= sodinh; k++)
    {
        for (int i = 1; i <= sodinh; i++)
        {
            for (int j = 1; j <= sodinh; j++)
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

void printPath(int u, int v)
{
    if (next[u][v] == -1)
    {
        cout << "Khong co duong di tu " << u << " den " << v << endl;
        return;
    }

    vector<int> path;
    path.push_back(u);
    while (u != v)
    {
        u = next[u][v];
        if (u == -1)
        {
            cout << "Khong co duong di (dang loi)" << endl;
            return;
        }
        path.push_back(u);
    }

    cout << "Duong di ngan nhat tu " << path.front() << " den " << path.back() << ": ";
    for (int i : path)
        cout << i << " ";
    cout << endl;
}
void PrintAllDistances()
{
    cout << "Ma tran khoang cach ngan nhat:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] >= LLONG_MAX / 2)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Init();
    Input();
    FloyWarshall();
    printPath(1,5);
    PrintAllDistances();
}