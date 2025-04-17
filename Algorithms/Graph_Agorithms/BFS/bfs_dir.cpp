#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;
// 10 11
// 1 2 
// 1 3
// 1 10
// 2 4
// 3 5
// 3 6
// 5 8
// 5 10
// 6 7
// 7 3
// 8 9
class Breath_First_Search
{
public:
    Breath_First_Search();
    void input();
    void bfs(int u);
private:
    bool visited[MAX]; // check được thăm
    int n, m;
    vector<int> adj[MAX]; // mảng danh sách kề
};
Breath_First_Search::Breath_First_Search() {
    memset(visited, false, sizeof(visited));
}
void Breath_First_Search::input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}
void Breath_First_Search::bfs(int u) {
    // Bước khởi tạo
    queue<int> q;
    q.push(u);
    visited[u] = true;
    // Bước lặp
    while(!q.empty()) {
        int v = q.front(); // lấy đỉnh ở đầu hàng đợi 
        q.pop();
        cout << v << " ";
        for(int x : adj[v]) {
            if(!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
int main() {
    Breath_First_Search bfs_solver;
    bfs_solver.input();

    int start_vertex;
    cout << "Nhap dinh bat dau BFS: ";
    cin >> start_vertex;

    cout << "Thu tu duyet BFS: ";
    bfs_solver.bfs(start_vertex);

    return 0;
}
