#include <iostream>
using namespace std;
void Insertion(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (A[j] > key)
            {
                A[j + 1] = A[j];
            }
            else
            {
                break;
            }
        }
        A[j + 1] = key;
    }
}
int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Truoc khi sap xep: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sau khi sap xep: ";
    printArray(arr, n);
}