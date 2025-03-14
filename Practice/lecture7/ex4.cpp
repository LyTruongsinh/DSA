#include <iostream>
using namespace std;
int n, a[100], isfinal;
int k; // in ra xâu có k bit 1
void Init() {
    for(int i = 1; i <= n; i++ ) {
        a[i] = 0;
    }
}
void Sinh_Binary() {
    // Bắt đầu từ bit cuoi cung, và đi tìm bit 0 đầu tiên
    int i = n;
    while(i >= 1 && a[i] == 1) {
        a[i] = 0;
        --i;
    }
    if( i == 0) {
        isfinal = 0; // cấu hình cuối cùng
    }
    else {
        a[i] = 1; 
    }
}
bool check() {
    int count;
    for(int i = 1; i <= n; i++) {
        count+= a[i];
    }
    return count == k;
}
int main() {
    cin >> n; cin >> k;
    isfinal = 1;
    Init();
    // Nếu chưa phải cấu hình cuối cùng
    while(isfinal) {
        for(int i = 1; i <= n; i++) {
            cout << a[i];
        }
        cout << endl;
        Sinh_Binary();
    }
    cout << endl;
    // while(isfinal) {
    //     if(check()) {
    //         for(int i = 1; i <= n; i++) {
    //             cout << a[i];
    //         }
    //         cout << endl;
    //     }
    //     Sinh_Binary();
    // }
    return 0;
}

// 0000
// 0001 gặp 0 chuyển thành 1
// 0010 gặp 1 chuyền thành 0 và dịch 1 sang 