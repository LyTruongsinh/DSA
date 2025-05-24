#include <iostream>
#include <vector>
using namespace std;
vect
    // Hàm gộp hai mảng con đã sắp xếp
    void
    merge(vector<int> &arr, int left, int mid, int right)
{
    // Tạo hai mảng tạm
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0;
    j = 0;
    k = left;

    // Trộn hai mảng con lại
    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    // Thêm phần còn lại (nếu có)
    while (i < leftArr.size())
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightArr.size())
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);      // Sắp xếp nửa trái
        mergeSort(arr, mid + 1, right); // Sắp xếp nửa phải
        merge(arr, left, mid, right);   // Gộp hai nửa lại
    }
}
int main()
{
    vector<int> arr = {12, 5, 7, 22, 2, 11, 30, 104, 20};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Mảng sau khi sắp xếp: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}