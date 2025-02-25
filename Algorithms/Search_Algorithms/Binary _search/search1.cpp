#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        if (target > nums[high])
        {
            return high + 1;
        }
        while (low <= high)
        {
            mid = (low + high) / 2; 
            if (nums[mid] == target)
            {
                return mid;
            }

            if (target < nums[mid])
            {
                high = mid - 1;
                cout << low << " " << high << endl;
            }
            else
            {
                low = mid + 1;
                cout << low << " " << high << endl;
            }
        }
        return low;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    int target = 4;
    cout << s.searchInsert(nums, target) << endl;
}