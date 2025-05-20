#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
  public:
    int reverse(int x) {
        long long res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res > INT_MAX || res < INT_MIN) {
            return 0; // overflow
        }
        return res;
    }
};
int main()
{
    Solution s;
    int x = 123;
    cout << s.reverse(x) << endl; // Output: 321
    x = -123;
    cout << s.reverse(x) << endl; // Output: -321
    x = 120;
    cout << s.reverse(x) << endl; // Output: 21
    x = 1534236469;
    cout << s.reverse(x) << endl; // Output: 0 (overflow)
    return 0;
}