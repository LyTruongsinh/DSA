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
// Lấy cạnh (1,4) thêm vào cây khung nhỏ nhất MST: [(1,3)]
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
    void Prim2(int u);
  private:
    int sodinh;
    int socanh;
    vector<pair<int, int>> adj[MAX]; // lưu danh sách kề có trọng số
    bool used[MAX]; // đánh dấu đỉnh đó thuộc V hay Vmst if(used[i] == true) thì đỉnh i thuộc Vmst ngược lại
    int parent[MAX]; // lưu cha của đỉnh i
    int depth[MAX]; // lưu độ sâu của đỉnh i
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
    for(int i = 1; i <= sodinh; i++)
    {
        depth[i] = INT_MAX; // khởi tạo độ sâu của đỉnh i là vô cực
    }
}
void Graph::Prim2(int u)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; // khai báo hàng đợi ưu tiên
    vector<Edge> MST; // lưu cây khung nhỏ nhất
    int d = 0; // tổng trọng số của cây khung nhỏ nhất
    Q.push({0, u}); // thêm đỉnh u vào hàng đợi ưu tiên
    while(!Q.empty())
    {
        pair<int, int> top = Q.top(); // lấy đỉnh có trọng số nhỏ nhất
        Q.pop(); // xóa đỉnh đó khỏi hàng đợi ưu tiên
        int dinh = top.second; // lấy đỉnh
        int trongso = top.first; // lấy trọng số
        if(used[dinh]) // nếu đỉnh đó đã được duyệt rồi thì bỏ qua
        {
            continue;
        }
        d += trongso; // cộng trọng số vào tổng trọng số
        used[dinh] = true; // đánh dấu đỉnh đó đã được duyệt
        if(u != dinh) {
            MST.push_back({dinh, parent[dinh], trongso}); // thêm cạnh vào cây khung nhỏ nhất
        }
        for(auto x : adj[dinh]) // duyệt tất cả các đỉnh kề với đỉnh đó
        {
            int v = x.first; // lấy đỉnh kề
            int w = x.second; // lấy trọng số
            if(!used[v] && w < depth[v]) // nếu đỉnh kề chưa được duyệt và trọng số nhỏ hơn độ sâu của đỉnh kề
            {
                depth[v] = w; // cập nhật độ sâu của đỉnh kề
                parent[v] = dinh; // cập nhật cha của đỉnh kề
                Q.push({w, v}); // thêm đỉnh kề vào hàng đợi ưu tiên
            }
        }
    }
    ofstream fout("output.txt");
    fout << "Tong trong so cua cay khung nho nhat la: " << d << endl;
    fout << "Cay khung nho nhat la: " << endl;
    for(int i = 0; i < MST.size(); i++)
    {
        fout << MST[i].dinhcuoi << " " << MST[i].dinhdau << " " << MST[i].trongso << endl;
    }
    fout.close();
}
int main()
{
    Graph g;
    g.InputGraph();
    g.Prim2(1); // Bắt đầu từ đỉnh 1
    return 0;
}
