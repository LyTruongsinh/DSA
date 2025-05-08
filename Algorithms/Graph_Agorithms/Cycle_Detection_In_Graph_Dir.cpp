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
// trạng thái node trong đồ thị
// màu trắng : chưa được duyệt (1)
// màu xám : đang duyệt (2)
// màu đen : đã duyệt (3)

using namespace std;
int soluongdinh;
int soluongcanh;
int st, en;             // đỉnh đầu và đỉnh cuối của đường đi
vector<int> adj[1001];  // danh sách kề
bool visited[1001];     // mảng đánh dấu đã duyệt
int parent[1001];       // mảng cha của các đỉnh trong DFS
int color[1001];       // mảng màu của các đỉnh
void InputGraph() {
    cout << "Nhap so dinh: ";
    cin >> soluongdinh;
    cout << "Nhap so canh: ";
    cin >> soluongcanh;
    for (int i = 0; i < soluongcanh; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(visited, false, sizeof(visited));  // Khởi tạo mảng visited
}
bool DFS(int u) {
    color[u] = 1;  // Đánh dấu đỉnh u đang duyệt (màu xám)
    for(int v : adj[u]) {    // Duyệt qua các đỉnh kề với u
        if (color[v] == 0) {  // Nếu đỉnh v chưa được duyệt (màu trắng)
            parent[v] = u;    // Gán cha của v là u
            if (DFS(v)) {     // Gọi đệ quy DFS cho đỉnh v
                return true;  // Nếu tìm thấy chu trình, trả về true
            }
        } else if (color[v] == 1) {  // Nếu v đang duyệt (màu xám)
            st = u;       // Gán đỉnh đầu là u
            en = v;       // Gán đỉnh cuối là v
            return true;  // Tìm thấy chu trình, trả về true
        }
    }
    color[u] = 2;  // Đánh dấu đỉnh u đã duyệt (màu đen)
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
