#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> res; // Lưu kết quả
    void backtrack(vector<int> &nums, vector<int> &temp, vector<bool> &used)
    {
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!used[i])
            {
                used[i] = true;
                temp.push_back(nums[i]);
                backtrack(nums, temp, used);
                temp.pop_back(); // Quay lui
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrack(nums, temp, used);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.permute(nums);

    for (auto &vec : result)
    {
        for (int num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
