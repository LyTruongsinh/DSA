#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i && dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Số bước nhảy tối thiểu (DP): " << solution.jump(nums) << endl;
    return 0;
}
