#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   private:
    vector<int> nums;
    int target;
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];  // gán một giá trị khởi tạo

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if (sum < target)
                    left++;
                else
                    right--;
            }
        }
        return closest;
    }
};
int main() {
    Solution s;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << s.threeSumClosest(nums, target) << endl;  // Output: 2
    return 0;
}