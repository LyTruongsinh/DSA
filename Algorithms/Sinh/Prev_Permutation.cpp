#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, a[1005], ok;
void prev_permutation() {
    int i = n - 1;
    while(i >= 1 && a[i] <= a[i + 1]) {
        i--;
    }
    if(i == 0) {
        ok = 0;
    }
    else {
        int j = n;
        while(a[j] >= a[i]) {
            j--;
        }
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        ok = 1;
        while(ok) {
            for(int i = 1; i <= n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
            prev_permutation();
        }
    }
    return 0;
}
