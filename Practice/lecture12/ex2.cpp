#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

#define MAX 1001
using namespace std;
//         6
//    2----------4
// 9 /|\         |\ 10
//  / |  \       | \
// 1  |1   \ 3  3|  6
//  \ |      \   | /
// 4 \|        \ |/ 8
//    3----------5
//         2

// Bước 1 : Khởi tạo
// Khởi tạo tập V : [1,2,3,4,5,6];
// Khởi tạo tập Vmst : []
// Khỏi tạo tập cây khung nhỏ nhất MST : []

// Bước 2 : Chọn đỉnh bất kỳ trong V, thêm vào Vmst, xóa đỉnh đó khỏi tập V
// Lấy 1 đẩy 1 vào Vmst : [1]
// Xóa 1 trong trong tập V : [2,3,4,5,6]

// Bước 3 : Tìm cảnh có trọng số nhỏ nhất Trong tất cả các cạnh xuất phát từ các đỉnh trong Vmst
// Vmst : [1]
// từ 1 có thể nối với 2 và 3
// cạnh (1 , 2) : 9
// cạnh (1 , 3) : 4
// Lấy cạnh (1,3) thêm vào cây khung nhỏ nhất MST: [(1,3)]
// Xóa 3 trong V : [2,4,5,6]
// Thêm 3 vào Vmst : [1,3]

// Lặp lại bước 3 cho đến khi tập V rỗng
// Vmst : [1,3]
// Đỉnh 1 có thể đến 2 trong tập  V  được cạnh (1,2) : 9
// Đỉnh 3 có thể đến 2 và 5 trong tập V  được cạnh (3,2) : 1
// Chọn cạnh (3,2) thêm vào cây khung nhỏ nhất MST: [(1,3),(3,2)]
// Xóa 2 trong V : [4,5,6]
// Thêm 2 vào Vmst : [1,3,2]

// Lặp lại bước 3 cho đến khi tập V rỗng
// Vmst : [1,3,2]
// Đỉnh 1 ko thể đến đỉnh nào trong V
// Đỉnh 3 có thể đến 5 trong tập V  được cạnh (3,5) : 2
// Đỉnh 2 có thể đến 4 trong tập V  được cạnh (2,4) : 6
// Đỉnh 2 có thể đến 5 trong tập V  được cạnh (2,5) : 3
// Chọn cảnh (3,5) thêm vào cây khung nhỏ nhất MST:[(1,3),(3,2),(3,5)]
// Xóa 5 trong V : [4,6]
// Thêm 5 vào Vmst : [1,3,2,5]

//...
struct Edge
{
    int dinhdau;
    int dinhcuoi;
    int trongso;
};
class Graph
{
  public:
    Graph();
    void InputGraph();
    void Prim(int u);

  private:
    int sodinh;
    int socanh;
    vector<pair<int, int>> adj[MAX]; // lưu danh sách kề có trọng số
    bool used[MAX];                  // mảng đánh dấu các đỉnh đã được duyệt
};
Graph::Graph()
{
    sodinh = 0;
    socanh = 0;
}
void Graph::InputGraph()
{
    ifstream fin("input.txt");
    cout << "Nhap so dinh: ";
    fin >> sodinh;
    cout << "Nhap so canh: ";
    fin >> socanh;
    for (int i = 0; i < socanh; i++)
    {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    fin.close();
    memset(used, false, sizeof(used)); // khởi tạo tất cả các đỉnh đều thuộc V
}
void Graph::Prim(int u)
{
    vector<Edge> MST; // lưu cây khung nhỏ nhất
    int d = 0;        // Lưu trọng số của cây khung nhỏ nhất
    used[u] = true;   // đưa đỉnh u vào Vmst
    while (MST.size() < sodinh - 1)
    {
        int minweight = INT_MAX; // khởi tạo trọng số nhỏ nhất
        int X, Y;                // lưu đỉnh đầu và đỉnh cuối
        for (int i = 1; i <= sodinh; i++)
        {
            if (used[i]) // Nếu đỉnh i thuộc Vmst
            {
                for(auto x : adj[i]) // Duyệt tất các các đỉnh kề với i và trọng số của cạnh bắt đầu từ đỉnh i
                {
                    int v = x.first; // đỉnh kề
                    int w = x.second; // trọng số cạnh
                    if (!used[v] && w < minweight) // nếu đỉnh v không thuộc Vmst và trọng số cạnh nhỏ hơn trọng số nhỏ nhất
                    {
                        minweight = w; // cập nhật trọng số nhỏ nhất
                        X = i;         // cập nhật đỉnh đầu
                        Y = v;         // cập nhật đỉnh cuối
                    }
                }
            }
        }
        MST.push_back({X, Y, minweight}); // thêm cạnh vào cây khung nhỏ nhất
        d += minweight;                  // cập nhật trọng số của cây khung nhỏ nhất
        used[Y] = true; // đưa đỉnh Y vào Vmst
    }
    ofstream fout("output.txt");
    fout << "Cay khung nho nhat la: " << endl;
    for (int i = 0; i < MST.size(); i++)
    {
        fout << "(" << MST[i].dinhdau << "," << MST[i].dinhcuoi << ") : " << MST[i].trongso << endl;
    }
    fout << "Tong trong so: " << d << endl;
    fout.close();
}
int main()
{
    Graph g;
    g.InputGraph();
    g.Prim(1);
    return 0;
}