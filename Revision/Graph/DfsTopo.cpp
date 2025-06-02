#include <limits.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// O(V+E)
#define MAX 1001
using namespace std;
int Soluongdinh;
int Soluongcanh;
vector<int> adj[MAX];
bool visited[MAX];
bool onStack[MAX]; // Mảng kiểm tra đỉnh đang được duyệt
bool hasCycle = false;
vector<int> topo;

void Input()
{
    cin >> Soluongdinh >> Soluongcanh;
    for (int i = 0; i < Soluongcanh; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(visited, false, sizeof(visited));
    memset(onStack, false, sizeof(onStack));
}

void dfs(int u)
{
    visited[u] = true;
    onStack[u] = true;


    for (int x : adj[u])
    {
        if (!visited[x])
        {
            dfs(x);
            if (hasCycle)
                return; // Nếu đã phát hiện chu trình, dừng lại
        }
        else if (onStack[x])
        {
            hasCycle = true; // Phát hiện chu trình
            return;
        }
    }

    onStack[u] = false; // Rời khỏi đỉnh u
    topo.push_back(u);  // Đưa vào kết quả topo
}

int main()
{
    Input();
    for (int i = 1; i <= Soluongdinh; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            if (hasCycle)
            {
                cout << "Do thi co chu trinh. Khong the sap xep topo.\n";
                return 0;
            }
        }
    }

    reverse(topo.begin(), topo.end());
    for (int i = 0; i < topo.size(); i++)
    {
        cout << topo[i] << " ";
    }
    cout << "\n";
    return 0;
}