#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int soluongdinh;
int soluongcanh;
int st, en;             // đỉnh đầu và đỉnh cuối của đường đi
vector<int> adj[1001];  // danh sách kề
int degree[1001];      // mảng bậc của các đỉnh
void InputGraph() {
    cout << "Nhap so dinh: ";
    cin >> soluongdinh;
    cout << "Nhap so canh: ";
    cin >> soluongcanh;
    for (int i = 0; i < soluongcanh; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Đồ thị có hướng
        degree[v]++;        // Tăng bậc của đỉnh v
    }
}
bool Kahm() {
    queue<int> q;
    for(int i = 1; i <= soluongdinh;i++) {
        if(degree[i] == 0) {
            q.push(i); // Đỉnh không có bậc vào
        } 
    }
    int count = 0; // Đếm số đỉnh đã được duyệt
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        for(int v: adj[u]) {
            degree[v]--;
            if(degree[v] == 0) {
                q.push(v); // Đỉnh không có bậc vào
            }
        }
    }
    if(count == soluongdinh) {
        return false; // Không có chu trình
    }
    return true; // Có chu trình
}
int main() {
    InputGraph();
    if(Kahm()) {
        cout << "Do thi co chu trinh" << endl;
    } else {
        cout << "Do thi khong co chu trinh" << endl;
    }
    return 0;
}