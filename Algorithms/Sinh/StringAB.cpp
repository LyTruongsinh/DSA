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
    if(i == 0) {
        ok = 0;
    }
    else {
        a[i] = 1;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ok = 1;
        Init();
        while(ok) {
            for (int i = 1; i <= n; ++i) {
                if(a[i] == 1) {
                    cout << "B";
                }
                else {
                    cout << "A";
                }
            }
            cout << endl;
            next_permutation();
        }
    }
    return 0;
}