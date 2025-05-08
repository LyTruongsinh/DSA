// đường đi có đỉnh đầu trùng với đỉnh cuối gọi là xác định chu trình
#include <limits.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;
int soluongdinh;
int soluongcanh;
int st, en;             // đỉnh đầu và đỉnh cuối của đường đi
vector<int> adj[1001];  // danh sách kề
bool visited[1001];     // mảng đánh dấu đã duyệt
int parent[1001];       // mảng cha của các đỉnh trong DFS
void InputGraph() {
    cout << "Nhap so dinh: ";
    cin >> soluongdinh;
    cout << "Nhap so canh: ";
    cin >> soluongcanh;
    for (int i = 0; i < soluongcanh; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Đồ thị vô hướng
    }
    memset(visited, false, sizeof(visited));  // Khởi tạo mảng visited
}
bool DFS(int u) {
    visited[u] = true;        // Đánh dấu đỉnh u đã được duyệt
    for (int v : adj[u]) {    // Duyệt qua các đỉnh kề với u
        if (!visited[v]) {    // Nếu đỉnh v chưa được duyệt
            parent[v] = u;    // Gán cha của v là u
            if (DFS(v)) {     // Gọi đệ quy DFS cho đỉnh v
                return true;  // Nếu tìm thấy chu trình, trả về true
            }
        } else if (v != parent[u]) {  // Nếu v đã được duyệt và không phải là
                                      // cha của u
            st = u;       // Gán đỉnh đầu là u
            en = v;       // Gán đỉnh cuối là v
            return true;  // Tìm thấy chu trình, trả về true
        }
    }
    return false;  // Không tìm thấy chu trình, trả về false
}
bool BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;  // Đánh dấu đỉnh u đã được duyệt
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w : adj[v]) {  // Duyệt qua các đỉnh kề với v
            if (!visited[w]) {  // Nếu đỉnh w chưa được duyệt
                visited[w] = true;  // Đánh dấu đỉnh w đã được duyệt
                q.push(w);          // Thêm w vào hàng đợi
                parent[w] = v;     // Gán cha của w là v
            } else if (w != parent[v]) {  // Nếu w đã được duyệt và không phải là cha của v
                st = v;       // Gán đỉnh đầu là v
                en = w;       // Gán đỉnh cuối là w
                return true;  // Tìm thấy chu trình, trả về true
            }
        }
    }
    return false;  // Không tìm thấy chu trình, trả về false
}
int main() {
    InputGraph();
    bool hasCycle = false;

    for (int i = 1; i <= soluongdinh; i++) {
        if (!visited[i]) {
            parent[i] = -1;  // ❗ Bắt buộc phải khởi tạo
            if (DFS(i)) {
                vector<int> cycle;
                cycle.push_back(en);  // bắt đầu từ en
                int cur = st;
                while (cur != en) {
                    cycle.push_back(cur);
                    cur = parent[cur];
                }
                cycle.push_back(en);
                reverse(cycle.begin(), cycle.end());
                cout << "Chu trinh: ";
                for (int v : cycle) cout << v << " ";
                cout << endl;
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) {
        cout << "Do thi co chu trinh" << endl;
    } else {
        cout << "Do thi khong co chu trinh" << endl;
    }

    return 0;
}
