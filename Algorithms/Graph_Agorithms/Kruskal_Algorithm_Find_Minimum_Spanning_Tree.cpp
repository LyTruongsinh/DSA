#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#define MAX 1001
using namespace std;

// Cây khung tối thiểu là cây
// con của đồ thị liên thông, không có chu trình và có trọng số nhỏ nhất.
// là đồ thị vô hướng
// có n đỉnh và n-1 cạnh
// Sử dụng 2 thuật toán chính:
// Kruskal's algorithm: tìm cây khung tối thiểu
// Disjoint Set DisjointSetUnion (DSU): tìm tập hợp đại diện cho các đỉnh
struct Edge
{
    int dinhdau;
    int dinhcuoi;
    int trongso;
};
class MinimumSpanningTree
{
  public:
    void MakeSet();
    int Find(int x);
    bool DisjointSetUnion(int a, int b);
    void Input();
    static bool Compare(Edge a, Edge b); // thêm static
    void Kruskal();

  private:
    int n, m;
    int parent[MAX];
    int size[MAX];
    vector<Edge> edges;
};
void MinimumSpanningTree::MakeSet()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}
int MinimumSpanningTree::Find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = Find(parent[x]);
}
bool MinimumSpanningTree::DisjointSetUnion(int a, int b)
{
    int rootA = Find(a);
    int rootB = Find(b);
    if (rootA == rootB)
    {
        return false; // Đã có chu trình không thể gộp a, b với nhau
    }
    if (size[rootA] < size[rootB])
    {
        swap(rootA, rootB); // Đảm bảo rootA là lớn hơn rootB
    }
    parent[rootB] = rootA;
    size[rootA] += size[rootB];
    return true;
}
void MinimumSpanningTree::Input()
{
    ifstream fin("input.txt");
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        Edge e;
        fin >> e.dinhdau >> e.dinhcuoi >> e.trongso;
        edges.push_back(e);
    }
    fin.close();
}
bool MinimumSpanningTree::Compare(Edge a, Edge b) { return a.trongso < b.trongso; }
void MinimumSpanningTree::Kruskal()
{
    // Bước 1: Tạo cây khung cực tiểu rỗng
    vector<Edge> mst;
    int totalWeight = 0; // Tổng trọng số của cả cây khung tối thiểu
    // Bước 2: Sắp xếp các cạnh theo trọng số tăng dần để dễ dàng tim cạnh trọng số nhỏ nhất
    sort(edges.begin(), edges.end(), Compare);
    // Bước 3: lặp duyệt qua các cạnh
    for (int i = 0; i < m; i++)
    {
        if (mst.size() == n - 1)
        {
            break; // Đã đủ n-1 cạnh
        }
        Edge e = edges[i]; // lấy cạnh có trọng số nhỏ nhất
        if (DisjointSetUnion(e.dinhdau, e.dinhcuoi))
        {
            mst.push_back(e);         // thêm cạnh vào cây khung
            totalWeight += e.trongso; // cộng trọng số của cạnh vào tổng trọng số
        }
    }
    // Bước 4: In ra kết quả
    if (mst.size() != n - 1)
    {
        cout << "Khong co cay khung toi thieu" << endl;
    }
    else
    {
        ofstream fout("output.txt");
        fout << "Cay khung toi thieu: " << endl;
        for (int i = 0; i < mst.size(); i++)
        {
            fout << mst[i].dinhdau << " " << mst[i].dinhcuoi << " " << mst[i].trongso << endl;
        }
        fout << "Tong trong so: " << totalWeight << endl;
        fout.close();
    }
}
int main()
{
    MinimumSpanningTree mst;
    mst.Input();
    mst.MakeSet();
    mst.Kruskal();
    return 0;
}