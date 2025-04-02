#include <iostream>
#include <cmath>

using namespace std;


bool isPerfectSquare(long long x) {
    long long s = sqrt(x);
    return s * s == x;
}

// Hàm kiểm tra số Fibonacci
bool isFibonacci(int n) {
    return isPerfectSquare(5LL * n * n + 4) || isPerfectSquare(5LL * n * n - 4);
}

void printFinbonaci(int f0, int f1, int N) {
    cout << f1 << " ";
    if(f1 == N) {
        return;
    }
    return printFinbonaci(f1, f0 + f1, N);
}
int main() {
    int f0 = 0, f1 = 1;
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    cout << "Fibonacci sequence till " << N << " is: ";
    printFinbonaci(f0, f1, N);
    return 0;
}