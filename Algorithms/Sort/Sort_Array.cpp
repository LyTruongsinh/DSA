#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    // Hàm đệ quy chia nhỏ mảng và sắp xếp
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    // Hàm gộp hai mảng con đã sắp xếp
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> leftArr(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> rightArr(nums.begin() + mid + 1, nums.begin() + right + 1);
        int i = 0, j = 0, k = left;
        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                nums[k] = leftArr[i];
                i++;
                k++;
            } else {
                nums[k] = rightArr[j];
                j++;
                k++;
            }
        }
        // Thêm phần còn lại (nếu có)
        while (i < leftArr.size()) {
            nums[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < rightArr.size()) {
            nums[k] = rightArr[j];
            j++;
            k++;
        }
    }
    // Hàm chính để sắp xếp mảng
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
int main() {
    Solution s;
    vector<int> nums = {5, 2, 3, 1, 8, 0, 9, 4, 6, 7};
    vector<int> sortedArray = s.sortArray(nums);
    for (int num : sortedArray) {
        cout << num << " ";
    }
    return 0;
}


// mergeSort(nums, 0, 9)
//   mid = 4
//   ├─ mergeSort(nums, 0, 4)
//   │     mid = 2
//   │     ├─ mergeSort(nums, 0, 2)
//   │     │     mid = 1
//   │     │     ├─ mergeSort(nums, 0, 1)
//   │     │     │     mid = 0
//   │     │     │     ├─ mergeSort(nums, 0, 0) → return
//   │     │     │     └─ mergeSort(nums, 1, 1) → return
//   │     │     │     → merge(nums, 0, 0, 1) → [2, 5]
//   │     │     └─ mergeSort(nums, 2, 2) → return
//   │     │     → merge(nums, 0, 1, 2) → [2, 3, 5]
//   │     └─ mergeSort(nums, 3, 4)
//   │           mid = 3
//   │           ├─ mergeSort(nums, 3, 3) → return
//   │           └─ mergeSort(nums, 4, 4) → return
//   │           → merge(nums, 3, 3, 4) → [1, 8]
//   │     → merge(nums, 0, 2, 4) → [1, 2, 3, 5, 8]
//   └─ mergeSort(nums, 5, 9)
//         mid = 7
//         ├─ mergeSort(nums, 5, 7)
//         │     mid = 6
//         │     ├─ mergeSort(nums, 5, 6)
//         │     │     mid = 5
//         │     │     ├─ mergeSort(nums, 5, 5) → return
//         │     │     └─ mergeSort(nums, 6, 6) → return
//         │     │     → merge(nums, 5, 5, 6) → [0, 9]
//         │     └─ mergeSort(nums, 7, 7) → return
//         │     → merge(nums, 5, 6, 7) → [0, 4, 9]
//         └─ mergeSort(nums, 8, 9)
//               mid = 8
//               ├─ mergeSort(nums, 8, 8) → return
//               └─ mergeSort(nums, 9, 9) → return
//               → merge(nums, 8, 8, 9) → [6, 7]
//         → merge(nums, 5, 7, 9) → [0, 4, 6, 7, 9]

// → merge(nums, 0, 4, 9) → [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
