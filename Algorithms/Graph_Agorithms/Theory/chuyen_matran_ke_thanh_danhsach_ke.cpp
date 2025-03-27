#include <iostream>
#include <map>
#include <vector>
using namespace std;
int a[1001][1001];
vector<int> adj[1001];
int main() {
    int n; cin >> n;
    for(int i = 1; i <= n ; i ++) {
        for(int j = 1; j <= n ; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n ; i ++) {
        for(int j = 1; j <= n ; j++) {
            if(a[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }
    for(int i = 1; i <= n ; i ++) {
        cout << i << " : ";
        for(auto x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}