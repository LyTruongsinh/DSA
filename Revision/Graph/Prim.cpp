#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

#define MAX 1001
using namespace std;
struct Edge
{
    int dinhdau;
    int dinhcuoi;
    int trongso;
};
int sodinh;
int socanh;
vector<pair<int, int>> adj[MAX];
bool Vmst[MAX];
void Input()
{
    cin >> sodinh >> socanh;
    for (int i = 0; i < socanh; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(Vmst, false, sizeof(Vmst)); // tất cả các đỉnh thuộc V ko thuộc tập Vmst
}
void Prim(int u)
{
    vector<Edge> MST;
    int totalweight;
    Vmst[u] = true;
    while (MST.size() < sodinh - 1)
    {
        int minweight = INT_MAX;
        int V, U;
        for (int i = 1; i <= sodinh; i++)
        {
            if (Vmst[i])
            {
                for (auto x : adj[i])
                {
                    int v = x.first;
                    int w = x.second;
                    if (!Vmst && w < minweight)
                    {
                        minweight = w;
                        V = v;
                        U = i;
                    }
                }
            }
        }
        MST.push_back({U, V, minweight});
        totalweight += minweight Vmst[X] = true;
    }
    cout << "Cay khung nho nhat la: " << endl;
    for (int i = 0; i < MST.size(); i++)
    {
        cout << "(" << MST[i].dinhdau << "," << MST[i].dinhcuoi << ") : " << MST[i].trongso << endl;
    }
    cout << "Tong trong so: " << d << endl;
}
int main()
{
    Input();
    Prim(1);
    return 0;
}
