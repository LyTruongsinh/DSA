#include <algorithm>
#include <iostream>

using namespace std;
int *merge(int *firstArr, int lenArr1, int *secondArr, int lenArr2)
{
    int *newArr = new int[lenArr1 + lenArr2];
    int i = 0, j = 0, k = 0;
    bool isIncreasing = (firstArr[0] < firstArr[1]) ? true : false;
    while (i < lenArr1 && j < lenArr2)
    {
        if (isIncreasing)
        {
            if (firstArr[i] > secondArr[j])
            {
                newArr[k] = secondArr[j];
                k++;
                j++;
            }
            else
            {
                newArr[k] = firstArr[i];
                k++;
                i++;
            }
        }
        else
        {
            if (firstArr[i] > secondArr[j])
            {
                newArr[k] = firstArr[i];
                k++;
                i++;
            }
            else
            {
                newArr[k] = secondArr[j];
                k++;
                j++;
            }
        }
    }
    // Nối phần còn lại của mảng đầu
    while (i < lenArr1)
        newArr[k++] = firstArr[i++];
    // Nối phần còn lại của mảng sau
    while (j < lenArr2)
        newArr[k++] = secondArr[j++];
    return newArr;
}