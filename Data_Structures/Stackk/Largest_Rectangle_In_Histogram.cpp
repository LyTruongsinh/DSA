#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution
{
  public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> s;
        int maxArea = 0, area = 0, i = 0;
        heights.push_back(0); // Add a sentinel value to pop all elements from stack at the end

        while (i < heights.size()) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i++);
            } else {
                int top = s.top();
                s.pop();
                area = heights[top] * (s.empty() ? i : i - s.top() - 1);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
int main()
{
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}