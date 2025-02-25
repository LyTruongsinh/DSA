#include<iostream>
using namespace std;
int Sum(int n) {
    if( n == 0) return 0;
    int number  = n % 10;
    n = n / 10;
    return (number + Sum(n));
}
int main() {
    int n;
    cin >> n;
    cout << Sum(n) << endl;
}