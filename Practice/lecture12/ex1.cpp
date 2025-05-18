#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits.h>
#include <cstring>
#include <stack>
#include <fstream>
#define MAX 1001
using namespace std;
int Sodinh;
int Socanh;
vector<int> adj[MAX]; // Lưu danh sách kề 
bool visited[MAX]; // Mảng đánh dấu các đỉnh đã được duyệt
vector<int> topo; // Lưu thứ tự topo
int banbacIn[MAX]; // Mảng lưu bậc vào của các đỉnh
void Input() {
    ifstream fin("jobs.txt");
    fin >> Sodinh >> Socanh;
    for(int i = 0; i < Socanh; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(V); // Thêm cạnh từ u đến v
        banbacIn[v]++; // Tăng bậc vào của đỉnh v
    }
}
void Kahn() {
    queue<int> q;
    // Duyệt qua các đỉnh đồ thị tìm đỉnh có bậc vào bằng 0
    for(int i = 1; i <= Sodinh; i++) {
        if (banbacIn[i] == 0) {
            q.push(i); // Thêm đỉnh vào hàng đợi
        }
    }
    while(!q.empty()) {
        int u = q.front(); // Lấy đỉnh đầu hàng đợi
        q.pop(); // Xóa đỉnh khỏi hàng đợi
        topo.push_back(u); // Thêm đỉnh vào thứ tự topo
        // Duyệt các đỉnh kề với đỉnh u và xóa bậc vào của các đỉnh đó
        for(auto v : adj[u]) {
            banbacIn[v]--;
            if(banbacIn[v] == 0) {
                q.push(v); // Nếu bậc vào của v bằng 0 thì thêm vào hàng đợi
            }
        }
    }
}
void Print() {
    ofstream fout("result.txt");
    for(int i = 0; i < topo.size(); i++) {
        fout << topo[i] << " "; // In thứ tự topo ra file
    }
}
int main() {
    Input(); // Nhập dữ liệu từ file
    Kahn(); // Thực hiện thuật toán Kahn
    Print(); // In kết quả ra file
    return 0;
}