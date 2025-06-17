#include <iostream>
#include <vector>
using namespace std;

// Hàm kiểm tra xem có thể chia mảng thành k đoạn có tổng bằng nhau
bool canPartition(const vector<int>& A, int n, int k, int totalSum) {
    if (totalSum % k != 0) return false;
    int target = totalSum / k;
    int currentSum = 0, count = 0;

    for (int i = 0; i < n; ++i) {
        currentSum += A[i];
        if (currentSum == target) {
            count++;
            currentSum = 0;
        } else if (currentSum > target) {
            return false;
        }
    }

    return count == k;
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    int totalSum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        totalSum += A[i];
    }

    // Tìm số đoạn lớn nhất có thể
    for (int k = n; k >= 1; --k) {
        if (canPartition(A, n, k, totalSum)) {
            cout << k << endl;
            return 0;
        }
    }

    // Trường hợp tối thiểu luôn chia được 1 đoạn
    cout << 1 << endl;
    return 0;
}
