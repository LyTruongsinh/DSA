#include<iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a = 0;
    for(int i = 1; i <= 2*n + 1; i++) {
        for(int j = 1; j <= 2*n + 1; j++) {
            if( i == j || j == 2*n + 1 - a) {
                cout<<"* ";
            }
            else {
                cout<<". ";
            }
            
        }
        a++;
        cout << endl;
    }
}