#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> nums;
    set<vector<int>> result;

public:
    bool BinarySearch(int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& inputNums) {
        nums = inputNums;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int index = nums[i] + nums[j];
                int target = -index;
                if (BinarySearch(j + 1, n - 1, target)) {
                    vector<int> triplet = {nums[i], nums[j], target};
                    sort(triplet.begin(), triplet.end());
                    result.insert(triplet);
                }
            }
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = s.threeSum(nums);
    for (const auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
