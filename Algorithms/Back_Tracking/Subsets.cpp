#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  private:
    int n, k, isfinal;

    void Gen_K_Combination(vector<int> &a)
    {
        int i = k;
        // Khi i chưa đạt giá trị max n-k+i
        while (i >= 1 && a[i] == n - k + i)
        {
            --i;
        }
        // nếu tất cả các phần tử đều đạt giá trị n-k+i
        if (i == 0)
        {
            isfinal = 0;
        }
        else
        {
            a[i]++;
            for (int j = i + 1; j <= k; ++j)
            {
                a[j] = a[j - 1] + 1;
            }
        }
    }

  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        n = nums.size();
        for (k = 0; k <= n; ++k)
        {
            isfinal = 1;
            vector<int> a(k + 1); // Khởi tạo mảng a với kích thước k + 1
            for (int i = 1; i <= k; ++i)
            {
                a[i] = i;
            }
            while (isfinal)
            {
                vector<int> subset;
                for (int i = 1; i <= k; ++i)
                {
                    subset.push_back(nums[a[i] - 1]); // Chuyển đổi chỉ số từ 1-based sang 0-based
                }
                res.push_back(subset);
                Gen_K_Combination(a);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<vector<int>> res = s.subsets(nums);
    for (auto subset : res)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}