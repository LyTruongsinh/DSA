#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// BFS from given source s (in đề là từ 0)
vector<int> bfs(vector<vector<int>>& adj) {
    int V = adj.size();                  // Số đỉnh
    vector<int> result;
    vector<bool> visited(V, false);     // Đánh dấu đã thăm
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        // Duyệt tất cả đỉnh kề
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return result;
}
int main() {
    vector<vector<int>> adj = {{1, 2}, {0, 2, 3}, {0, 4}, {1, 4}, {2, 3}};
    vector<int> ans = bfs(adj);

    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}
