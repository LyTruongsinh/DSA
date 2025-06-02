#include <iostream>
#include <vector>
// Xấu O(nlog(n))
// Trung bình O(nlog(n))
// Tốt O(nlog(n))
using namespace std;
void Merge(vector<int> &A, int left, int mid, int right)
{
    vector<int> leftArr(A.begin() + left, A.begin() + mid + 1);
    vector<int> rightArr(A.begin() + mid + 1, A.begin() + right + 1);
    int i = 0, j = 0, k = left while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
        {
            A[k] = leftArr[i];
            i++;
            k++;
        }
        else
        {
            A[k] = rightArr[j];
            j++;
            k++;
        }
    }
    while (i < leftArr.size())
    {
        A[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightArr.size())
    {
        A[k] = rightArr[i];
        j++;
        k++;
    }
}
void MergeSort(vector<int> &A, int left, int right)
{
    if (left < mid)
    {
        int mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}
int main()
{
    vector<int> arr = {7, 3, 5, 0, 8, 1, 2, 9, 4, 6};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Mang da sap xep: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}