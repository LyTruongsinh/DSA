#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int n, m;
char a[1001][1001];
bool visited[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int dist[1001][1001];
int endi;
int endj;
void dfs(int i, int j)
{
    cout << "Duyệt từ ô (" << i << ", " << j << ")\n";
    visited[i][j] = true;
    // duyệt các đỉnh kề hay còn gọi là duyệt 4 cái ô xung quanh
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 'x' && !visited[x][y])
        {
            dfs(x, y);
        }
    }
}

void bfs(int i, int j)
{
    cout << "Duyệt từ ô (" << i << ", " << j << ")\n";
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        if (top.first == endi && top.second == endj)
        {
            cout << "Đã tìm thấy đích tại ô (" << endi << ", " << endj << ")\n";
            return;
        }
        for (int k = 0; k < 4; k++)
        {
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];

            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1])
            {
                q.push({i1, j1});
                visited[i1][j1] = true;
                dist[i1][j1] = dist[top.first][top.second] + 1;
            }
        }
    }
}

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 'x' && !visited[i][j])
            {
                cout << "Thành phần liên thông thứ " << cnt + 1 << ":\n";
                bfs(i, j);
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
}
int main()
{
    Input();
    return 0;
}