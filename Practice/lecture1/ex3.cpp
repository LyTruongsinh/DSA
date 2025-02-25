#include<iostream>
using namespace std;
class Solution  {
    public:
    int UCLN(int a, int b) {
        if(a == 0) return b;
        return UCLN (b % a,a);
    }
};
int main() {
    int a,b;
    cin >> a >> b;
    Solution s;
    cout << s.UCLN(a,b) << endl;
}