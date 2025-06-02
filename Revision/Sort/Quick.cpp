#include <algorithm>
#include <iostream>
#include <vector>

// Trường hợp xấu nhất O(n^2)
// Trường hợp tốt nhất O(nlog(n))
// Trường hợp trung bình O(nlog(n))
using namespace std;
void Quicksort(int A[], int start, int end)
{
    if (start >= end)
        return;
    int pivot = A[start];
    int left = start;
    int right = end;
    while (left <= right)
    {
        while (A[right] > pivot)
        {
            right--;
        }
        while (A[left] < pivot)
        {
            left++;
        }
        if (left <= right)
        {
            swap(A[left], A[right]);
            left++;
            right--;
        }
    }
    Quicksort(A, start, right);
    Quicksort(A, left, end);
}
int main()
{
    int A[10] = {7, 3, 5, 0, 8, 1, 2, 9, 4, 6};
    quick_sort(A, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}