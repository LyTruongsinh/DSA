#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  private:
    vector<int> dp; // memo hóa
    int count;      // bước hiện tại
    int minCount;   // số bước ít nhất tìm được
  public:
    void helper(int start, vector<int> &nums)
    {
        if (start == nums.size() - 1)
        {
            minCount = min(minCount, count); // cập nhật kết quả tốt nhất
            return;
        }
        // Cắt nhánh nếu đã tệ hơn kết quả tốt nhất
        if ((dp[start] != -1 && count >= dp[start]) || count >= minCount)
            return;
        dp[start] = count;
        // Ưu tiên nhảy xa trước để tìm kết quả tốt sớm
        for (int i = start + nums[start]; i > start; i--)
        {
            if (i < nums.size())
            {
                count++;
                helper(i, nums);
                count--;
            }
        }
    }
    int jump(vector<int> &nums)
    {
        count = 0;
        minCount = INT_MAX;
        dp.assign(nums.size(), -1);
        helper(0, nums);
        return minCount;
    }
};
int main()
{
    Solution solution;
    vector<int> nums;
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << solution.jump(nums) << endl;
    return 0;
}
