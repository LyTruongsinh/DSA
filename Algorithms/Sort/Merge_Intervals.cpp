#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty())
            return {};

        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i)
        {
            // If the current interval overlaps with the last merged one, merge them
            if (intervals[i][0] <= merged.back()[1])
            {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
            else
            {
                // Otherwise, add the current interval to the merged list
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = s.merge(intervals);
    for (const auto &interval : mergedIntervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}