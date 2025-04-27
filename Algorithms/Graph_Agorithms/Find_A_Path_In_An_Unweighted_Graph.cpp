#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 1001

using namespace std;
// ý tưởng : code tương tụ thuật toán dfs bfs nhưng duy trì thêm mảng parent để truy vết đường đi
// input số lượng đỉnh và số lượng cạnh
// 10 8
// 1 2
// 2 3
// 2 4
// 3 6
// 3 7
// 6 7
// 5 8
// 8 9
class Solution
{
private:
    int n, m, s, t;
    vector<int> adj[MAX];
    bool visited[MAX];
    int parent[MAX];

public:
    void input()
    {
        cout << "Nhap so dinh : ";
        cin >> n;
        cout << "Nhap so canh : ";
        cin >> m;
        cout << "Nhap dau duong di : ";
        cin >> s;
        cout << "Nhap cuoi duong di : ";
        cin >> t;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    void dfs(int u)
    {
        visited[u] = true;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                // ghi nhận cha của v là u
                parent[v] = u;
                dfs(v);
            }
        }
    }
    void bfs(int u)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while(!q.empty()) {
            int v = q.front(); q.pop();
            for(int x: adj[v]) {
                if(!visited[x]) {
                    q.push(x);
                    visited[x] = true;
                    parent[x] = v;
                }
            }
        }
    }
    void path()
    {
        memset(visited, false, sizeof(visited));
        memset(parent, 0, sizeof(parent));
        // dfs(s);
        bfs(s);
        if (!visited[t])
        {
            cout << "Khong co duong di" << endl;
        }
        else
        {
            vector<int> Path; // Truy vet duong di
            // Bat dau tu dinh t
            while (t != s)
            {
                Path.push_back(t);
                t = parent[t]; // Lần ngược lại
            }
            Path.push_back(s);
            reverse(Path.begin(), Path.end());
            int len = Path.size() - 1;
            cout << "Độ dài đường đi là: " << len << endl;
            cout << "Duong di la: ";
            for (int x : Path)
            {
                cout << x << " ";
            }
        }
    }
};
int main()
{
    Solution s;
    s.input();
    s.path();
}