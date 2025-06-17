#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // cho accumulate
// max(sum(A1), sum(A2), ..., sum(Ak)) là nhỏ nhất

using namespace std;

// Hàm kiểm tra: Với maxSum cho trước, có thể chia mảng thành <= k đoạn không?
bool isValid(const vector<int>& a, int k, long long maxSum) {
    int count = 1;
    long long currentSum = 0;
    for (int num : a) {
        if (currentSum + num > maxSum) {
            count++;            // Cắt sang đoạn mới
            currentSum = num;   // Đặt lại tổng đoạn mới
        } else {
            currentSum += num;
        }
    }
    return count <= k;  // Đúng nếu ta chia được thành k đoạn (hoặc ít hơn)
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    // Tìm giới hạn nhị phân
    long long left = *max_element(a.begin(), a.end());         // Ít nhất là phần tử lớn nhất
    long long right = accumulate(a.begin(), a.end(), 0LL);     // Nhiều nhất là tổng cả dãy

    // Tìm kiếm nhị phân
    while (left < right) {
        long long mid = (left + right) / 2;
        if (isValid(a, k, mid)) {
            right = mid;  // Có thể tối ưu hơn
        } else {
            left = mid + 1; // mid nhỏ quá, cần tăng lên
        }
    }

    cout << left << endl; // hoặc right (vì left == right khi thoát vòng lặp)
    return 0;
}
