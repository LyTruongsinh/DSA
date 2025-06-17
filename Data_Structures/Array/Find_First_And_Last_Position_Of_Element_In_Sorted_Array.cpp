#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1); // Initialize result with -1 for both positions
        int n = nums.size();
        if (n == 0) return result; // If the array is empty, return [-1, -1]

        // Find the first occurrence of target
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left >= n || nums[left] != target) return result; // Target not found

        result[0] = left; // First occurrence

        // Find the last occurrence of target
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        result[1] = right; // Last occurrence

        return result;
    }
};
int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = s.searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl; // Output: [3, 4]
    return 0;
}