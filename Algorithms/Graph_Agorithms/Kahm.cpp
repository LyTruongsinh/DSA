#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits.h>
#include <cstring>
#include <stack>
#define MAX 1001
using namespace std;
int Soluongdinh;
int Soluongcanh;
vector<int> adj[MAX];
bool visited[MAX];
vector<int> topo;
int banbacIn[MAX];
int banbacOut[MAX];
void Input() {
    cin >> Soluongdinh >> Soluongcanh;
    for (int i = 0; i < Soluongcanh; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        banbacIn[v]++;
        banbacOut[u]++;
    }
    memset(visited, false, sizeof(visited));
}
void Kahn() {
    queue<int> q;
    // duyệt qua các đỉnh đồ thị tìm đỉnh có bán bậc vào bằng 0
    for(int i = 1; i <= Soluongdinh; i++) {
        if (banbacIn[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        // duyệt các đỉnh kề với đỉnh u và xóa bán bậc vào của các đỉnh đó
        for(int v : adj[u]) {
            banbacIn[v]--; // giảm bán bậc vào
            if(banbacIn[v] == 0) {
                q.push(v);
            }
        }
    }
}
void Print() {
    for(int i = 0; i < topo.size(); i++) {
        cout << topo[i] << " ";
    }
}
int main() {
    Input();
    Kahn();
    Print();
    return 0;
}