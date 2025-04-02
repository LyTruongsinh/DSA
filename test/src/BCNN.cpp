#include <iostream>
using namespace std;
int UCLN(int a, int b) {
    if(a % b == 0) return b;
    return UCLN(b, a % b);
}
int BCNN(int a, int b) {
    return (a * b) / UCLN(a, b);
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << "UCLN: " << UCLN(a, b);
    cout << "\nBCNN: " << BCNN(a, b);
    return 0;
}