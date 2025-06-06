#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

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
    for (int x : adj[v]) {
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
    for (int x : adjTranspose[v]) {
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
    int count = 0;
    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();
        if (!visited[v]) {
            count++;
            DFS_Transpose(v);
            cout << endl;
        }
    }
    if (count == 1) {
        cout << "Do thi lien thong manh" << endl;
    } else {
        cout << "Do thi khong lien thong manh" << endl;
    }
}
int main() {
    Graph g;
    g.InputGraph();
    g.Count_SCC();
    return 0;
}