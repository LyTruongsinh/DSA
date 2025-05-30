#include <algorithm>
#include <iostream>

#define MAX 1000
using namespace std;
int A[10] = {7, 3, 5, 0, 8, 1, 2, 9, 4, 6};
void quick_sort(int start, int end)
{
    if (start >= end)
        return; // Điều kiện dừng đệ quy
    int pivot = A[start];
    int left = start, right = end;
    while (left <= right)
    {
        while (A[left] < pivot) // Tìm phần tử lớn hơn hoặc bằng pivot
        {
            left++;
        }
        while (A[right] > pivot) // Tìm phần tử nhỏ hơn hoặc bằng pivot
        {
            right--;
        }
        cout << "left: " << left << " right: " << right << endl;
        if (left <= right) // cho trường lợp A[left] == A[right] == pivot
        {
            swap(A[left], A[right]);
            left++;
            right--;
        }
        cout << "left: " << left << " right: " << right << endl;
    }
    quick_sort(start, right); // Đệ quy bên trái
    quick_sort(left, end);    // Đệ quy bên phải
}

int main()
{
    quick_sort(0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
