// Cho một đồ thị vô hướng G = (V, E) với V là tập đỉnh và E là tập cạnh. Nhiệm vụ của bạn là:
// Đếm số lượng thành phần liên thông trong đồ thị G.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m; // n: số đỉnh, m: số cạnh
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // đọc cạnh u-v
        graph[u].push_back(v);
        graph[v].push_back(u); // đồ thị vô hướng
    }

    int componentCount = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, graph, visited);
            componentCount++;
        }
    }

    cout << componentCount << endl;

    return 0;
}