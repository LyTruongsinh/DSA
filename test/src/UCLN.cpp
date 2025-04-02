#include <iostream>
using namespace std;
int UCLN(int a, int b) {
    if(a % b == 0) return b;
    return UCLN(b, a % b);
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << "UCLN: " << UCLN(a, b);
    return 0;
}