#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, k, a[1005], ok, cnt;
void Init() {
    cnt = 1;
    a[1] = n;
}
void next() {
    int i = cnt;
    while (i >= 1 && a[i] == 1) {
        --i;
    }
    if (i == 0) {
        ok = 0;
    } else {
        int d = cnt - i + 1;
        a[i]--;
        cnt = i;
        int q = d / a[i];
        int r = d % a[i];
        if (q) {
            for (int j = 1; j <= q; ++j) {
                a[++cnt] = a[i];
            }
        }
        if (r) {
            a[++cnt] = r;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ok = 1;
        Init();
        while (ok) {
            for (int i = 1; i <= cnt; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
            next();
        }
    }
    return 0;
}