#include <iostream>
#include <vector>
using namespace std;
int n, m; // số lượng đỉnh , cạnh
vector<int> adj[1001];
bool visited[1001];
void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u) {
    cout << u <<" ";
    // Đánh dấu u đã được thăm 
    visited[u] = true;
    for(int i: adj[u]) {
        // nếu đỉnh u chưa được thăm
        if(!visited[u]) {
            dfs(i);
        }
    }
}
int main() {
    input();
    dfs(1); // bắt đầu thăm từ đ��nh 1
    return 0;  // kết thúc chương trình
}