#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
int A[MAX];
void quick_sort(int start, int end) {
    if (start >= end) return; // Điều kiện dừng đệ quy
    int pivot = A[start];
    int left = start, right = end;
    while (left <= right) {
        while (A[left] < pivot) left++;
        while (A[right] > pivot) right--;
        if (left <= right) {
            swap(A[left], A[right]);
            left++;
            right--;
        }
    }
    quick_sort(start, right);  // Đệ quy bên trái
    quick_sort(left, end);     // Đệ quy bên phải
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    quick_sort(0, N - 1);
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
// Example input:
// A = [3, 7, 2, 5, 1]
// 1. quick_sort(0, 4)
// pivot = A[0] = 3

// left = 0, right = 4

// So sánh:

// A[0]=3 không < 3 → dừng

// A[4]=1 < 3 → đúng
// => swap(A[0], A[4]) → [1, 7, 2, 5, 3], left = 1, right = 3

// Tiếp tục:

// A[1]=7 > 3 → dừng

// A[3]=5 > 3 → giảm right

// A[2]=2 < 3 → đúng
// => swap(A[1], A[2]) → [1, 2, 7, 5, 3], left = 2, right = 1 → dừng vòng while

// Gọi đệ quy:

// quick_sort(0, 1)

// quick_sort(2, 4)

// 2. quick_sort(0, 1)
// pivot = 1

// A[0]=1, A[1]=2 → không cần swap => quick_sort(0, -1) và quick_sort(1, 1) → đều dừng

// 3. quick_sort(2, 4)
// pivot = 7

// A[2]=7, A[3]=5, A[4]=3
// → right di chuyển: A[4]=3 < 7 → swap(A[2], A[4]) → [1, 2, 3, 5, 7]
// left = 3, right = 3
// A[3]=5 < 7 → left tăng
// => quick_sort(2, 3) và quick_sort(4, 4)

// 4. quick_sort(2, 3)
// pivot = 3

// A[2]=3, A[3]=5 → không cần swap
// → quick_sort(2, 2) và quick_sort(3, 3) → dừng
