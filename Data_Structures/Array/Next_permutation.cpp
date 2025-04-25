#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
   void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;

    // Bước 1: tìm phần tử đầu tiên từ phải qua trái sao cho nums[i] < nums[i+1]
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Bước 2: tìm phần tử lớn hơn nums[i] từ phải qua trái
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        // Đổi chỗ nums[i] và nums[j]
        swap(nums[i], nums[j]);
    }

    // Bước 3: đảo ngược đoạn từ i+1 đến hết mảng
    reverse(nums.begin() + i + 1, nums.end());
}

};
int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    s.nextPermutation(nums);
    for (int i : nums) {
        cout << i << " ";
    }
    return 0;
}