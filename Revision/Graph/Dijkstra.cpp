#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define MAX 1001
using namespace std;
int sodinh;
int socanh;
int s;
int e;
vector<pair<int, int>> adj[MAX];
vector<int> dist;
bool marked[MAX];
vector<int> previous;
// O(sodinh^2) mảng thường
// O((sodinh + socanh)*log(sodinh))
void Input()
{
    cin >> sodinh >> socanh;
    for (int i = 0; i < socanh; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cin >> s >> e;
}
void Init()
{
    dist.assign(sodinh + 1, 1e9);
    previous.assign(sodinh + 1, -1);
    memset(marked, false, sizeof(marked));
    dist[s] = 0;
}
void Dijkstra(int s)
{
    marked[s] = true;
    if (s == e)
    {
        vector<int> path;
        int v = e;
        while (v != -1)
        {
            path.push_back(v);
            v = previous[v];
        }
        reverse(path.begin(), path.end());
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
        if (dist[s] + w < dist[v])
        {
            dist[v] = dist[s] + w;
            previous[v] = s;
        }
    }
    int mindist = 1e9;
    int next = -1;
    for (int i = 0; i <= sodinh; i++)
    {
        if (!marked[i] && dist[i] < mindist)
        {
            mindist = dist[i];
            next = i;
        }
    }
    if (next != -1)
        Dijkstra(next);
}
int main()
{
    Input();
    Init();
    Dijkstra(s);
}