#include <iostream>
using namespace std;
int n, k, a[1005];
void next() {
    int i = k;
    // Tìm vị trí đầu tiên từ phải qua trái sao cho a[i] < n - k + i hay đạt giá trị max tại i
    while(i > 1 && a[i] == n - k + i) {
        --i;
    }
    if(i == 0) {
        for(int i = 1; i <= k; ++i) {
            cout << i << " ";
        }
    }
    else {
        a[i]++;
        for(int j = i + 1; j <= k; ++j) {
            a[j] = a[j - 1] + 1;
        }
        for(int i = 1; i <= k; ++i) {
            cout << a[i] << " ";
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= k; ++i) {
            cin >> a[i];
        }
        next();
    }
    return 0;
}