#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m; // số lượng đỉnh , cạnh
vector<int> adj[1001];
bool visited[1001];
void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u) {
    cout << u << " ";
    visited[u] = true;  // đánh dấu đã thăm

    for (int i : adj[u]) {
        if (!visited[i]) {  // kiểm tra đỉnh kề chưa được thăm
            dfs(i);
        }
    }
}

int main() {
    input();
    dfs(1); // bắt đầu thăm từ đ��nh 1
    return 0;  // kết thúc chương trình
}