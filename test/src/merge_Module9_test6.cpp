#include <iostream>
using namespace std;
bool isAscending(int *arr, int len)
{
    if (len < 2)
        return true;
    return arr[0] <= arr[len - 1];
}
int *merge(int *firstArr, int lenArr1, int *secondArr, int lenArr2)
{
    int *mergeArr = new int[lenArr1 + lenArr2]; // Cấp phát động
    int firstIndex = 0, secondIndex = 0, mergeIndex = 0;
    bool asc = isAscending(firstArr, lenArr1);
    while (firstIndex < lenArr1 && secondIndex < lenArr2)
    {
        if ((asc && firstArr[firstIndex] <= secondArr[secondIndex]) ||
            (!asc && firstArr[firstIndex] >= secondArr[secondIndex]))
        {
            mergeArr[mergeIndex++] = firstArr[firstIndex++];
        }
        else
        {
            mergeArr[mergeIndex++] = secondArr[secondIndex++];
        }
    }
    // Thêm phần tử còn lại của firstArr
    while (firstIndex < lenArr1)
    {
        mergeArr[mergeIndex++] = firstArr[firstIndex++];
    }
    // Thêm phần tử còn lại của secondArr
    while (secondIndex < lenArr2)
    {
        mergeArr[mergeIndex++] = secondArr[secondIndex++];
    }
    return mergeArr;
}
int main()
{
    int a[] = {0, 5, 5, 15, 23, 25, 33, 61};
    int b[] = {
        12, 25, 36, 44, 45, 45, 53, 65, 71,
    };
    int lenA = 8, lenB = 9;

    int *result = merge(a, lenA, b, lenB);

    cout << "Merged array: ";
    for (int i = 0; i < lenA + lenB; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result; // Giải phóng bộ nhớ
    return 0;
}
