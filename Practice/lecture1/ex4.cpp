#include<iostream>
using namespace std;
class Solution {
    public:
    void Sort (int a[], int n) {
        for(int i = 0 ; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] > a[j] ){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
};
int main() {
    int n; cin >> n;
    int a[100];
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    Solution s;
    s.Sort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}