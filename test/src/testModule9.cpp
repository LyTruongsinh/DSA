#include <iostream>
using namespace std;
void inputArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }
}
int findsela(int *arr, int size) {
    if (size < 2) return -1;
    int la = *arr;
    int se = -1;
    bool check = false;
    // Tìm phần tử lớn nhất đầu tiên
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > la) {
            la = *(arr + i);
        }
    }
    // Tìm phần tử lớn thứ hai
    for (int i = 0; i < size; i++) {
        if (*(arr + i) != la) {
            if (!check || *(arr + i) > se) {
                se = *(arr + i);
                check = true;
            }
        }
    }

    if(check = true) {
        return se;
    }
    return -1;
}
int main() {
    int size;
    cout << "Nhap kich thuoc mang: ";
    cin >> size;
    int *arr = new int[size];
    inputArray(arr, size);
    int result = findsela(arr, size);
    if (result == -1) {
        cout << "Khong co phan tu lon thu hai!" << endl;
    } else {
        cout << "Phan tu lon thu hai la: " << result << endl;
    }

    delete[] arr; // giải phóng bộ nhớ
    return 0;
}

