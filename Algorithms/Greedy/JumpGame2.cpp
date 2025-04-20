#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == current_end) {
                jumps++;
                current_end = farthest;
            }
        }

        return jumps;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Số bước nhảy tối thiểu (Greedy): " << solution.jump(nums) << endl;
    return 0;
}
