#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    int findKthPositive(vector<int> &arr, int k) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int missingCount = arr[mid] - (mid + 1);
            if (missingCount < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // left is the first index where the number of missing numbers is >= k
        // The kth missing number is k + left
        return k + left;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "Kth Missing Positive Number: " << s.findKthPositive(arr, k) << endl;
    return 0;
}