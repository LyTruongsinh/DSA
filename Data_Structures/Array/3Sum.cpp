#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            set<vector<int>> result;
    
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        if (nums[i] + nums[j] + nums[k] == 0) {
                            vector<int> triplet = {nums[i], nums[j], nums[k]};
                            sort(triplet.begin(), triplet.end());
                            result.insert(triplet);  // tránh trùng bằng set
                        }
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