#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void helper(vector<int> &candidates, int target, int start) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates to avoid duplicate combinations.
                // This condition is needed to avoid duplicate combinations.
                // For example, given candidates = [10, 1, 2, 7, 6, 1, 5], target = 8,
                // the expected output should be [[1, 7], [1, 2, 5], [2, 6], [1, 1, 6]]
                // but the current output will have [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]] due to this condition.
            } 
            if(target < candidates[i]) {
                return;
            }
            cur.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); // Sort the candidates for efficiency.
        helper(candidates, target, 0);
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    for (auto &v : result)
    {
        for (int num : v)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}