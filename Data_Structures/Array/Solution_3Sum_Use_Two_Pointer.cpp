#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Bước 1: Sắp xếp mảng

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // Bỏ qua các phần tử trùng nhau để tránh bộ ba trùng
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Bỏ qua phần tử trùng bên trái
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Bỏ qua phần tử trùng bên phải
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < 0) {
                    left++; // Tăng tổng
                } else {
                    right--; // Giảm tổng
                }
            }
        }

        return result;
    }
};

// Test
int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = s.threeSum(nums);
    for (auto& triplet : res) {
        cout << "[ ";
        for (int num : triplet) cout << num << " ";
        cout << "]\n";
    }
    return 0;
}
