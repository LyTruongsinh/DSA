#include <iostream>
#include <vector>
using namespace std;
class SingleNumberFinder {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(1000, 0); 

        for (size_t i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (count[nums[i]] == 1) {
                return nums[i];
            }
        }

        return -1; 
    }
};

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    SingleNumberFinder finder;
    int result = finder.singleNumber(nums);

    cout << "Số duy nhất là: " << result << endl;

    return 0;
}
