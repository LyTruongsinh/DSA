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
        int maxReachable = 0;

        for (int i = 0; i < n; i++)
        {
            if (i > maxReachable) {
                return false; // Không thể đến vị trí i
            }
            maxReachable = max(maxReachable, i + nums[i]);
            if (maxReachable >= n - 1)
                return true; // Có thể đến cuối mảng
        }
        return false;
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