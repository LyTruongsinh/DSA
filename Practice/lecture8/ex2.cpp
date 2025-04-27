#include <iostream>
#define MAX 10000
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
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    quick_sort(0, N - 1);
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = i; j < N; j++) {
            sum += A[j];
            if(sum == K) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
    
}

// // Example input:
// 5 10
// 2 3 1 4 6
// Sắp xếp quick như bài 1
// K = 10
// 2 + 3 + 1 + 4 = 10
// => YES
