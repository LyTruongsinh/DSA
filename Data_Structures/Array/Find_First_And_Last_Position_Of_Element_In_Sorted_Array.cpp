#include <iostream>
using namespace std;
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {}
};
int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = s.searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl; // Output: [3, 4]
    return 0;
}