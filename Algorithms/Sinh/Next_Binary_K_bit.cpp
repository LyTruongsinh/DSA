#include <algorithm>
#include <iostream>

using namespace std;
int n, k, a[1005], ok;
void Init() {
    for (int i = 1; i <= n; ++i) {
        a[i] = 0;
    }
}
void next_permutation() {
    int i = n;
    while (i >= 0 && a[i] == 1) {
        a[i] = 0;
        --i;
    }
    if (i == 0) {
        ok = 0;
    } else {
        a[i] = 1;
    }
}
bool check() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += a[i];
    }
    return res == k;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> k;
        ok = 1;
        Init();
        while (ok) {
            if (check()) {
                for (int i = 1; i <= n; ++i) {
                    cout << a[i];
                }
                cout << endl;
            }
            next_permutation();
        }
    }
    return 0;
}