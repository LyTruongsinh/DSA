#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State {
    int x, y, time;
};

int W, H;
vector<string> grid;

bool isSafe(int x, int y, int t) {
    if (x < 0 || x >= W || y < 0 || y >= H) return false;
    if (grid[y][x] == 'R') return false;
    if (y - t >= 0 && grid[y - t][x] == 'R') return false;
    return true;
}

bool bfs(int startX) {
    queue<State> q;
    q.push({startX, 0, 0});
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    visited[0][startX] = true;
    
    while (!q.empty()) {
        State current = q.front(); q.pop();
        int x = current.x, y = current.y, t = current.time;
        
        if (y == H - 1) return true; // Reached the top safely
        
        int dx[] = {-1, 0, 1};
        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i], ny = y + 1;
            if (isSafe(nx, ny, t + 1) && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({nx, ny, t + 1});
            }
        }
    }
    return false;
}

int main() {
    cin >> W >> H;
    grid.resize(H);
    
    int startX;
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
        if (i == 0) {
            for (int j = 0; j < W; j++) {
                if (grid[i][j] == 'Y') startX = j;
            }
        }
    }
    
    if (bfs(startX)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}