#include<iostream>
using namespace std;
class Solution {
    public:
    int ex1(int a[], int n) {
        int count = 0;
        for(int i = 0; i < n ; i ++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] == a[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};
int main() {
    int a[1000];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution s;
    cout << s.ex1(a, n) << endl;
}