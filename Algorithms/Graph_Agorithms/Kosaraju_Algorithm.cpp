// Giai thích thuật toán Kosaraju
// 1. Đầu tiên, ta thực hiện DFS trên đồ thị ban đầu và lưu lại thứ tự hoàn thành của các đỉnh.
// 2. Sau đó, ta chuyển đổi đồ thị ban đầu thành đồ thị chuyển vị (đồ thị đảo ngược).
// 3. Cuối cùng, ta thực hiện DFS trên đồ thị chuyển vị theo thứ tự hoàn thành đã lưu lại ở bước 1. Các đỉnh được duyệt trong cùng một lần DFS sẽ tạo thành một thành phần liên thông mạnh.
// Example:
// Input:
// Đồ thị ban đầu:
// 1------>2                7--------. 
// ^       |                ^        |
// |       v                |        v
// 4<------3------->5------>6<-------8 
// Đồ thị chuyển vị:
// 1<------2                7<-------.
// |       ^                |        |
// v       |                v        |
// 4------>3<-------5<------6------->8
// Duyệt đồ thị Topological: (phần thử nào duyệt xong đẩy vào stack)
// Đẩy vào stack:
// 4 8 7 6 5 3 2 1
// Duyệt đồ thị chuyển vị:
// Pop(1) -> DFS(1) -> {1, 4, 3, 2} (1 thành phần liên thông)
// visited[2] = true Pop(2) Không duyệt DFS(2) vì đã duyệt
// visited[3] = true Pop(3) Không duyệt DFS(3) vì đã duyệt
// Pop(5) -> DFS(5) -> {5} (1 thành phần liên thông)
// visited[5] = true Pop(5) Không duyệt DFS(5) vì đã duyệt
// visited[6] = true Pop(6) Không duyệt DFS(6) vì đã duyệt
// visited[7] = true Pop(7) Không duyệt DFS(7) vì đã duyệt
// visited[8] = true Pop(8) Không duyệt DFS(8) vì đã duyệt
// visited[4] = true Pop(4) Không duyệt DFS(4) vì đã duyệt
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;
class Graph {
   public:
    Graph() {
        sodinh = 0;
        socanh = 0;
    }
    void InputGraph();
    void DFS(int v);
    void DFS_Transpose(int v);
    void Count_SCC();
   private:
    int sodinh;
    int socanh;
    bool visited[MAX];
    stack<int> Stack;
    vector<int> adj[MAX];
    vector<int> adjTranspose[MAX];
};
void Graph::InputGraph() {
    cout << "Nhap so dinh: ";
    cin >> sodinh;
    cout << "Nhap so canh: ";
    cin >> socanh;
    for (int i = 0; i < socanh; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjTranspose[v].push_back(u);
    }
}
void Graph::DFS(int v) {
    visited[v] = true;
    for(int x : adj[v]) {
        if (!visited[x]) {
            DFS(x);
        }
    }
    // Đã duyệt xong đỉnh v, đẩy vào stack
    Stack.push(v);
}
void Graph::DFS_Transpose(int v) {
    visited[v] = true;
    cout << v << " ";
    for(int x : adjTranspose[v]) {
        if (!visited[x]) {
            DFS_Transpose(x);
        }
    }
}
void Graph::Count_SCC() {
    memset(visited, false, sizeof(visited));
    // Bước 1: Duyệt đồ thị ban đầu và lưu thứ tự hoàn thành vào stack
    for (int i = 0; i < sodinh; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    cout << endl;
    // Bước 2: Đảo ngược đồ thị
    // Bước 3: Duyệt đồ thị chuyển vị theo thứ tự hoàn thành
    memset(visited, false, sizeof(visited));
    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();
        if (!visited[v]) {
            DFS_Transpose(v);
            cout << endl;
        }
    }
}
int main() {
    Graph g;
    g.InputGraph();
    cout << "Cac thanh phan lien thong manh la: " << endl;
    g.Count_SCC();
    return 0;
}