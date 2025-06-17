#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 1001
using namespace std;

int n, m;
bool visited[MAX][MAX];
int dx[] = {0, 1, 0, -1}; // phải, xuống, trái, lên
int dy[] = {1, 0, -1, 0}; // phải, xuống, trái, lên
int a[MAX][MAX];
bool finded = false;

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
}

void DFS(int i, int j)
{
    visited[i][j] = true;
    a[i][j] = 2;

    if (i == n && j == m)
    {
        finded = true;
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1] && a[i1][j1] == 0)
        {
            DFS(i1, j1);
            if (finded)
                return; // Dừng sớm nếu đã tìm được đường
        }
    }

    if (!finded)
    {
        a[i][j] = 0; // quay lui
    }
}

int main()
{
    Input();
    DFS(1, 1);
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
