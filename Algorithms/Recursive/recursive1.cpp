#include <iostream>
using namespace std;

long long int factorial(int n) {
    if (n == 0 || n == 1) return 1;  // Điều kiện dừng
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    
    if (n < 0) {
        cout << "Giai thua khong xac dinh voi so am.\n";
    } else {
        cout << n << "! = " << factorial(n) << endl;
    }
    
    return 0;
}
