#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9; // Giá trị lớn để biểu diễn vô cực
int main() {
    int N, k;
    cin >> N >> k;
    int coins[k]; // Mảng lưu các loại đồng xu
    for (int i = 0; i < k; i++) {
        cin >> coins[i];
    }
    int dp[N + 1]; // Mảng lưu số đồng xu tối thiểu để tạo số tiền từ 0 đến N
    fill(dp, dp + N + 1, INF); // Khởi tạo mảng với giá trị lớn
    dp[0] = 0; // Không cần đồng xu nào để tạo số tiền 0

    for (int i = 0; i < k; i++) { // Duyệt qua từng loại đồng xu
        for (int j = coins[i]; j <= N; j++) { // Duyệt qua các giá trị tiền có thể tạo
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    // Kiểm tra kết quả bằng if-else
    if (dp[N] == INF) {
        cout << -1 << endl; // Không thể tạo số tiền N
    } else {
        cout << dp[N] << endl; // In ra số đồng xu ít nhất
    }

    return 0;
}

//
// Giải thích từng phần
// dp[j]

// Là số đồng xu ít nhất đã biết trước đó để tạo ra số tiền j.

// dp[j - coins[i]] + 1

// Nếu ta sử dụng đồng xu coins[i], thì số tiền còn lại cần tạo là j - coins[i].

// dp[j - coins[i]] là số đồng xu ít nhất để tạo số tiền j - coins[i].

// Khi thêm 1 đồng xu coins[i], tổng số đồng xu cần thiết là dp[j - coins[i]] + 1.

// min(dp[j], dp[j - coins[i]] + 1)

// So sánh hai cách:

// Không dùng coins[i]: Giữ nguyên dp[j] cũ.

// Dùng coins[i]: Cập nhật dp[j] = dp[j - coins[i]] + 1.

// Chọn cách nào sử dụng ít đồng xu nhất.