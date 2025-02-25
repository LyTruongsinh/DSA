#include<iostream>
using namespace std;
class Solution {
    public:
        int mySqrt(int x) {
            if (x == 0) return 0; 
    
            int left = 1, right = x, ans = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                cout << mid << " " << x/mid <<" ";
                if (mid <= x / mid) {  
                    ans = mid;  
                    left = mid + 1;
                    cout << ans;
                } else {
                    right = mid - 1;
                    cout << ans;
                }
                cout << endl;
            }
            return ans;  
        }
    };
int main() {
    Solution s;
    cout << s.mySqrt(8) << endl;
    return 0;
}