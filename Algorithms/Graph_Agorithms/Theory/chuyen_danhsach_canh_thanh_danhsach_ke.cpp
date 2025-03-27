#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> adj[1001];
// adj[i] lưu danh sách kề của đỉnh i vô hướng
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <=n ;i++) {
        cout << i << ": ";
        for(int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}
