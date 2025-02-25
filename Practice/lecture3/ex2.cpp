#include<iostream>
using namespace std;
// O(n)
long long power_iterative1(int n) {
    long long result = 1;
    for(int i = 0; i < n; i++) {
        result *=2;
    }
    return result;
} 

// O(logn)
long long power_recursive2(int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return power_recursive2(n/2) * power_recursive2(n/2);
    else return power_recursive2(n/2) * power_recursive2(n/2) * 2;
}

int main() {
    int n; 
    cout << "Enter number : "; cin >> n;
    cout << "Result :" << power_iterative1(n) << endl;
    cout << "Result :" << power_recursive2(n) << endl;
}