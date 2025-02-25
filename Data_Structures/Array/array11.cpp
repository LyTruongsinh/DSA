#include<iostream>
using namespace std;

bool checkSymmetric(int a[], int n) {
    for(int i = 0; i < n/2; i++) {
        if(a[i] != a[n-1-i]) 
        return false;
    }
    return true;
}
int main() {
    int n;cin >> n;
    int a[1000];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(checkSymmetric(a,n)) {
        cout << "Symmetric array." << endl;
    }
    else {
        cout << "Asymmetric array." << endl;
    }
}