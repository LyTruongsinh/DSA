#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[99][99]; // giới hạn N tối đa 99, bạn có thể tăng nếu cần

    // Siamese method
    int num = 1;
    int i = 0, j = n / 2; // bắt đầu từ dòng đầu, cột giữa

    while (num <= n * n) {
        a[i][j] = num;
        num++;

        int next_i = (i - 1 + n) % n;
        int next_j = (j + 1) % n;

        if (a[next_i][next_j] != 0) {
            i = (i + 1) % n;
        } else {
            i = next_i;
            j = next_j;
        }
    }

    // In dòng thứ (N/2 + 1) ⇒ chỉ số N/2
    for (int j = 0; j < n; j++) {
        cout << a[n / 2][j] << " ";
    }
    cout << endl;

    return 0;
}
