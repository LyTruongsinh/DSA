#include <iostream>
#include <cstring>
#define MAX 1000
using namespace std;
int main() {
    int n, S; cin >> n >> S;
    int w[n + 1] , v[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    int dp[n + 1][S + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 1 ; j <= S; j++) {
            // khong lựa chọn vật thứ i vào trong túi
            dp[i][j] = dp[i - 1][j];
            // lựa chọn vật thứ i vào trong túi
            if( j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][S] << endl;
    return 0;
}
