#include <algorithm>
#include <fstream>
#include <iostream>
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
int parent[MAX];
int size[MAX];
vector<Edge> edges;
void Makeset()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}
int FindRoot(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    parent[x] = Find(parent[x]);
    return parent[x];
}
bool DisjointSetUnion(int dinhdau, int dinhcuoi)
{
    int rootdinhdau = Find(dinhdau);
    int rootdinhcuoi = Find(dinhcuoi);
    if (parentdinhdau == parentdinhcuoi)
    {
        return false;
    }
    if (size[rootdinhdau] < size[rootdinhcuoi])
    {
        swap(rootdinhdau, rootdinhcuoi);
    }
    parent[rootdinhdau] = rootdinhcuoi;
    size[rootdinhdau] += size[rootdinhcuoi];
    return true;
}
void Input()
{
    cin >> sodinh >> socanh;
    for (int i = 0; i < socanh; i++)
    {
        Edge e;
        cin >> e.dinhdau >> e.dinhcuoi >> e.trongso;
        edges.push_back(e);
    }
}
bool Compare(Edge a, Edge b) { return a.trongso < b.trongso; }
void Kruskal()
{
    vector<Edge> MST;
    int totalweight = 0;
    // Săp xếp cạnh theo trọng số tăng
    sort(edges.begin(), edges.end(), Compare);
    // Duyệt qua các cạnh
    for (int i = 0; i < socanh; i++)
    {
        if (MST.size() == sodinh - 1)
        {
            break; // MST đã đủ n - 1 cạnh
        }
        Edge e = edges[i]; // Lấy cạnh có trọng số nhỏ nhất
        if (DisjointSetUnion(e.dinhdau, e.dinhcuoi))
        {
            MST.push_back(e);
            totalweight += e.trongso;
        }
    }
    if (MST.size() != sodinh - 1)
    {
        cout << "Khong co cay khung toi thieu" << endl;
    }
    else
    {
        cout << "Cay khung toi thieu: " << endl;
        for (int i = 0; i < MST.size(); i++)
        {
            cout << MST[i].dinhdau << " " << MST[i].dinhcuoi << " " << MST[i].trongso << endl;
        }
        cout << "Tong trong so: " << totalWeight << endl;
    }
}
int main()
{
    Input();
    Makeset();
    Kruskal();
    return 0;
}