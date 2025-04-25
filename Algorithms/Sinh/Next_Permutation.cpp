#include<iostream>
#include<algorithm>
using namespace std;
int n, k, a[1005];
void next_permutation() {
    int i = n - 1;
    while (i >= 1 && a[i] >= a[i + 1]) { // Xét xem đây có phải là hoán vị cuối cùng không nếu là hoán vị cuối cùng thì i--;
        i--;
    }
    if(i == 0) { // quay về hoán vị đầu tiên
        for(int i = 1; i <= n; i++) {
            cout << i << " ";
        }
    }
    else { // tìm phần tử lớn hơn a[i] từ phải qua trái
        int j = n;
        while(a[j] < a[i]) { // tìm phần từ lớn hơn a[i] từ phải qua trái
            --j;
        }
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
        for(int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        next_permutation();
    }
    return 0;
}