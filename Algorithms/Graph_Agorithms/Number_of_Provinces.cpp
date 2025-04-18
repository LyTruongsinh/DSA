#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int u, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[u] = true;
        for (int v = 0; v < isConnected.size(); v++) {
            if (isConnected[u][v] == 1 && !visited[v]) {
                dfs(v, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }
        return provinces;
    }
};

int main() {
    int n;
    cout << "Nhap so thanh pho (n): ";
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));
    cout << "Nhap ma tran ke " << n << "x" << n << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> isConnected[i][j];
        }
    }

    Solution sol;
    int result = sol.findCircleNum(isConnected);
    cout << "So luong thanh phan lien thong (tinh/provinces): " << result << endl;

    return 0;
}
