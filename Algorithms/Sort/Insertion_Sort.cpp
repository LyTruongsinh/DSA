#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j;
        // Duyệt từ i-1 về 0 bằng for, giống while
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];  // đẩy phần tử lớn hơn sang phải
        }
        arr[j + 1] = key;  // chèn key vào vị trí đúng
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Truoc khi sap xep: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}
