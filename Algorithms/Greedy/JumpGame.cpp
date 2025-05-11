#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> dp(n, false); // biểu diễn ta có thể nhảy đến vị trí i hay không
        dp[0] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && j + nums[j] >= i) // Kiêm tra xem có thể nhảy từ vị trí j đến i hay không
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n - 1];
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    bool result = solution.canJump(nums);
    cout << (result ? "true" : "false") << endl;
    return 0;
}