#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj; // Danh sách kề
vector<bool> visited;    // Mảng đánh dấu đã thăm
void dfs(int node) {
    visited[node] = true;
    for (size_t i = 0; i < adj[node].size(); i++) { // Sử dụng chỉ số mảng
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int countConnectedComponents(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) { 
            count++;  // Tìm thấy thành phần liên thông mới
            dfs(i);   // Duyệt tất cả đỉnh trong thành phần đó
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << countConnectedComponents(n) << endl;

    return 0;
}
