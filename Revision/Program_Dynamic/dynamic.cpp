#include <iostream>
using namespace std;
class Solution {
    public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 1, b = 2, c;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};


int main() {
    int n;
    Solution s;
    cout << "Nhập số bậc: ";
    cin >> n;
    cout << "Số cách leo: " << s.climbStairs(n) << endl;
    return 0;
}
