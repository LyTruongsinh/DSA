#include <limits.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define MAX 1001
using namespace std;
// thứ tự sắp xếp topological
// có đường đi từ đỉnh u cho đến đỉnh v
// thì u phải đứng trước v trong thứ tự sắp xếp topological

// ví dụ
// 1 ---> 2 ---> 3
// |      |      |
// v      v      v
// 6      4 ---> 5
// ^
// |
// 7
// 1 2 3 4 5 6
// 1 6 2 4 3 5
// áp đụng vào bài toán sắp xếp các công việc mà các công việc này có mối quan
// hệ trước sau không thể sắp xếp được cái thứ tự topological nếu có chu trình
// trong đồ thị Có 3 trạng thái của đỉnh
// 1. Đỉnh đó đã được thăm xong
// 2. Đỉnh đó đang được thăm nhưng chưa duyệt xong
// 3. Đỉnh đó chưa được thăm
// Thăm DFS bằng cách
// đầu tiên đẩy đỉnh u vào stack
// sau đó duyệt tất cả các đỉnh kề của u
// nếu đỉnh kề chưa được thăm thì đẩy vào stack
// dfs(kề)
// Cứ nhiều thế đến khi gặp đỉnh ko có kề nào nữa thì đẩy đỉnh đó ra stack và in
// ra ngoài
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