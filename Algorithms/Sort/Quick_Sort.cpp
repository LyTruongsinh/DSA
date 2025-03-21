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
