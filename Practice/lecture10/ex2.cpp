#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001

using namespace std;

class Solution {
  private:
   int n, m, s, t;
   vector<int> adj[MAX];
   bool visited[MAX];
   int parent[MAX];

  public:
   void input() {
      cout << "Nhap so dinh : ";
      cin >> n;
      cout << "Nhap so canh : ";
      cin >> m;
      cout << "Nhap dau duong di : ";
      cin >> s;
      cout << "Nhap cuoi duong di : ";
      cin >> t;
      for (int i = 0; i < m; i++) {
         int x, y;
         cin >> x >> y;
         adj[x].push_back(y);  // chỉ thêm 1 chiều: x -> y
      }
   }

   void dfs(int u) {
      visited[u] = true;
      for (int v : adj[u]) {
         if (!visited[v]) {
            parent[v] = u;
            dfs(v);
         }
      }
   }

   void bfs(int u) {
      queue<int> q;
      q.push(u);
      visited[u] = true;
      while (!q.empty()) {
         int v = q.front();
         q.pop();
         for (int x : adj[v]) {
            if (!visited[x]) {
               q.push(x);
               visited[x] = true;
               parent[x] = v;
            }
         }
      }
   }

   void path() {
      memset(visited, false, sizeof(visited));
      memset(parent, 0, sizeof(parent));
      bfs(s);  // hoặc dfs(s);

      if (!visited[t]) {
         cout << "Khong co duong di" << endl;
      } else {
         vector<int> Path;
         while (t != s) {
            Path.push_back(t);
            t = parent[t];
         }
         Path.push_back(s);
         reverse(Path.begin(), Path.end());
         int len = Path.size() - 1;
         cout << "Độ dài đường đi là: " << len << endl;
         cout << "Duong di la: ";
         for (int x : Path) {
            cout << x << " ";
         }
      }
   }
};

int main() {
   Solution s;
   s.input();
   s.path();
}
