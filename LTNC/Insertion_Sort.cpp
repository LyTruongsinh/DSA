#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j;
        // Tìm vị trí chèn thích hợp cho key
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > key) {
                arr[j + 1] = arr[j];  // đẩy phần tử sang phải
            } else {
                break;  // không còn phần tử nào lớn hơn key
            }
        }
        // Chèn key vào đúng vị trí
        arr[j + 1] = key;
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
