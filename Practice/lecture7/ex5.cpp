#include <iostream>     // Thư viện nhập xuất
using namespace std;

// Hàm đệ quy sinh các hoán vị của mảng a từ vị trí l đến r
void permute(int a[], int l, int r) {
    if (l == r) {
        // Khi đã cố định hết các vị trí, in ra một hoán vị hoàn chỉnh
        for (int i = 0; i <= r; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        // Duyệt từng phần tử từ l đến r
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);                 // Hoán đổi a[l] với a[i] để tạo hoán vị mới
            permute(a, l + 1, r);             // Gọi đệ quy cho phần còn lại
            swap(a[l], a[i]);                 // Trả mảng về trạng thái ban đầu (backtrack)
        }
    }
}
int main() {
    int n;
    cin >> n;             // Nhập số lượng phần tử cần hoán vị
    int a[n];             // Khai báo mảng a với n phần tử
    for (int i = 0; i < n; i++) {
        a[i] = i;         // Gán giá trị ban đầu cho mảng (0, 1, ..., n-1)
    }
    permute(a, 0, n - 1); // Gọi hàm sinh hoán vị từ chỉ số 0 đến n-1
    return 0;
}
