#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, vector<int> &temp, vector<int> &used)
    {
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue; // Bỏ qua nếu phần tử đã được sử dụng
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue; // Bỏ qua số trùng đã xét

            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, temp, used);
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> used(nums.size(), false);
        vector<int> temp;
        res.clear(); // Đảm bảo kết quả rỗng trước mỗi lần gọi
        backtrack(nums, temp, used);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = s.permuteUnique(nums);
    for (auto v : res)
    {
        for (int num : v)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}