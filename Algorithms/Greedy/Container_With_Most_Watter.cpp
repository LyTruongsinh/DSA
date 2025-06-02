#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right)
        {
            // Calculate the area with the current left and right pointers
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            maxArea = max(maxArea, width * currentHeight);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxArea;
    }
};
int main()
{
    Solution solution;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = solution.maxArea(height);
    cout << "Maximum area: " << result << endl; // Output: Maximum area: 49
    return 0;
}