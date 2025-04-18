#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 1001
using namespace std;
// input : n , m số lượng đỉnh và số lượng cạnh
// đúng với cả có hướng lẫn vô hướng
class Solution
{
private:
    int n, m;
    vector<int> adj[MAX];
    bool visited[1001];

public:
    void input()
    {
        cout << "Nhap so luong dinh: ";
        cin >> n;
        cout << "Nhap so luong canh: ";
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x); // nếu đồ thị có hướng bỏ cái này đi
        }
    }
    void dfs(int u)
    {
        visited[u] = true;
        cout << u << " ";
        for (int x : adj[u])
        {
            if (!visited[x])
            {
                dfs(x);
            }
        }
    }
    void bfs(int u)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " ";
            for (int x : adj[v])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
    void connectedComponent()
    {
        int ans = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                ++ans;
                cout << "Cac dinh thuoc thanh phan lien thong thu " << ans << " :";

                // dfs(i)
                bfs(i);
                cout << endl;
            }
        }
        if (ans == 1)
        {
            cout << "Do thi lien thong !";
        }
        else
        {
            cout << "Do thi khong lien thong !";
            cout << ans << endl;
        }
    }
};
int main()
{
    Solution s;
    s.input();
    s.connectedComponent();
}