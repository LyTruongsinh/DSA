//   1 2 3 4 5 6
// 1 A o o x o o
// 2 o x o o o o
// 3 o x o o o o
// 4 o o o o x x
// 5 B o o o x o
// 6 o o o x x x
// o : là có đường đi
// x : là không có đường đi
// Bước 1: Đếm số thành phân liên thông trong đồ thị
// Bước 2: Kiểm tra đường đi giữa 2 điểm trên lưới
// Bước 3 : Tìm đường đi ngắn nhất giữa 2 điểm trên lưới
#include <cstring>  // for memset
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int n, m, xA, yA, xB, yB;
char a[1001][1001];
bool visited[1001][1001];
int d[1001][1001];  // lưu số bước từ ô (i, j) đến ô (xA, yA)
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool dfs(int i, int j) {
    cout << "Duyệt từ ô (" << i << ", " << j << ")\n";
    if (a[i][j] == 'B') {
        return true;
    }
    visited[i][j] = true;
    // duyệt các đỉnh kề hay còn gọi là duyệt 4 cái ô xung quanh
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 'x' &&
            !visited[x][y]) {
            if (dfs(x, y)) {
                return true;
            }
        }
    }
    return false;
}

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    d[i][j] = 0;  // đi từ chính nó đến chính nó là 0 bước
    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        cout << "Duyệt từ ô (" << top.first << ", " << top.second << ")\n";
        // duyệt các ô kề theo 4 hướng
        for (int k = 0; k < 4; k++) {
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'x' &&
                !visited[i1][j1]) {
                visited[i1][j1] = true;  // đánh dấu đã thăm
                d[i1][j1] = d[top.first][top.second] + 1;
                q.push({i1, j1});
            }
        }
    }
}

void Input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                xA = i;
                yA = j;
            } else if (a[i][j] == 'B') {
                xB = i;
                yB = j;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    memset(d, 0, sizeof(d));  // đảm bảo không bị rác
    bfs(xA, yA);

    if (!visited[xB][yB]) {
        cout << "Không có đường đi từ ô A đến ô B\n";
    } else {
        cout << "Đường đi ngắn nhất từ ô A đến ô B là: " << d[xB][yB] << endl;
    }
}

int main() {
    Input();
    return 0;
}
