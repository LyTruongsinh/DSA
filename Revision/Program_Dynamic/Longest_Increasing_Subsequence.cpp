#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int N = nums.size();
        int dp[N];
        int pr[N];
        for(int i = 0; i < N; i++) {
            dp[i] = 1; // Lưu độ dài của dãy con tăng dài nhất kết thúc ở chỉ số i
            pr[i] = -1;
        }
        int max_length = 1, end_index = 0;
        for(int i = 1 ; i < nums.size() ; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pr[i] = j;
                }
            }
            if(dp[i] > max_length) {
                max_length = dp[i];
                end_index = i;
            }
        }
        int lis[max_length];
        int index = max_length - 1;
        while(end_index!= -1) {
            lis[index--] = nums[end_index];
            end_index = pr[end_index];
        }
        int count = 0;
        for(int i = 0; i < max_length; i++) {
            count++;
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(nums);
    return 0;
}