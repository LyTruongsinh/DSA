#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int countPartitions(vector<int> &nums) {
        int num1 = 0;
        int num2 = 0;
        int index = 0;

        for (int i = 0; i < nums.size(); i++) {
            num1 += nums[i];
            num2 = 0;  // reset num2 mỗi khi bắt đầu vòng lặp mới với i

            for (int j = i + 1; j < nums.size(); j++) {
                num2 += nums[j];

                // Kiểm tra nếu hiệu giữa num1 và num2 là số chẵn
                if ((num1 - num2) % 2 == 0) {
                    index++;
                }
            }
        }

        return index;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    for (int i = 0; i < 5; i++) {
        int x;
        cout << "nhap phan tu thu " << i << ":";
        cin >> x;
        nums.push_back(x);
    }
    cout << solution.countPartitions(nums) << endl;  // Kết quả mong muốn: 4
    return 0;
}
