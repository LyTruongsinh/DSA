#include <iostream>
#include <cstring> // dùng để sử dụng hàm memset
#define MAX 1000
using namespace std;

int main()
{
    int n, S;
    cin >> n >> S; // Nhập số lượng vật phẩm và trọng lượng tối đa của túi
    int w[n + 1], v[n + 1]; // w[i]: trọng lượng, v[i]: giá trị của vật thứ i
    // Nhập trọng lượng và giá trị của từng vật
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    // Khai báo bảng dp: dp[i][j] là giá trị lớn nhất khi xét i vật và túi có trọng lượng j
    int dp[n + 1][S + 1];
    memset(dp, 0, sizeof(dp)); // Khởi tạo tất cả phần tử trong dp về 0
    // Duyệt từng vật từ 1 đến n
    for (int i = 1; i <= n; i++)
    {
        // Duyệt từng trọng lượng túi từ 1 đến S
        for (int j = 1; j <= S; j++)
        {
            // Trường hợp không chọn vật thứ i
            dp[i][j] = dp[i - 1][j];

            // Trường hợp có thể chọn vật thứ i (túi còn đủ chỗ)
            if (j >= w[i])
            {
                // So sánh giá trị giữa không chọn và chọn vật i, lấy giá trị lớn hơn
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][S] << endl;
    return 0;
}

// Example input:
// 3 7
// 3 4
// 4 5
// 2 3

// Bước 1: i = 1 (xét vật phẩm 1: w=3, v=4)
// Duyệt j = 1 đến 7:

// j < 3: không chọn được vật 1 → giữ nguyên dp[1][j] = dp[0][j] = 0

// j ≥ 3: chọn hoặc không chọn vật 1:

// dp[1][3] = max(dp[0][3], dp[0][0] + 4) = max(0, 4) = 4

// dp[1][4] = max(0, 4)

// dp[1][5] = max(0, 4)

// dp[1][6] = max(0, 4)

// dp[1][7] = max(0, 4)

// => Hàng dp[1][*]: [0, 0, 0, 4, 4, 4, 4, 4]

// Bước 2: i = 2 (vật phẩm 2: w=4, v=5)
// Duyệt j = 1 → 7:

// j < 4: không chọn được vật 2 → giữ nguyên dp[2][j] = dp[1][j]

// j ≥ 4: có thể chọn vật 2:

// dp[2][4] = max(4, dp[1][0] + 5) = max(4, 5) = 5

// dp[2][5] = max(4, dp[1][1] + 5) = max(4, 5) = 5

// dp[2][6] = max(4, dp[1][2] + 5) = max(4, 5) = 5

// dp[2][7] = max(4, dp[1][3] + 5) = max(4, 4+5) = 9

// => Hàng dp[2][*]: [0, 0, 0, 4, 5, 5, 5, 9]

// Bước 3: i = 3 (vật phẩm 3: w=2, v=3)
// Duyệt j = 1 → 7:

// j < 2: không chọn được vật 3 → giữ nguyên dp[3][j] = dp[2][j]

// j ≥ 2:

// dp[3][2] = max(0, dp[2][0] + 3) = 3

// dp[3][3] = max(4, dp[2][1] + 3) = max(4, 3) = 4

// dp[3][4] = max(5, dp[2][2] + 3) = max(5, 3) = 5

// dp[3][5] = max(5, dp[2][3] + 3) = max(5, 4+3) = 7

// dp[3][6] = max(5, dp[2][4] + 3) = max(5, 5+3) = 8

// dp[3][7] = max(9, dp[2][5] + 3) = max(9, 5+3) = 9

// => Hàng dp[3][*]: [0, 0, 3, 4, 5, 7, 8, 9]

// Kết quả cuối cùng là dp[3][7] = 9