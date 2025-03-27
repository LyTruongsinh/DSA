#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void helper(vector<int> &candidates, int target, int idx, vector<int> &v)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        if (idx == candidates.size())
            return;
        if (candidates[idx] <= target)
        { // picking the element
            v.push_back(candidates[idx]);
            helper(candidates, target - candidates[idx], idx, v);
            v.pop_back();
        }

        int j = idx + 1;
        while (j < candidates.size() && candidates[j] == candidates[j - 1])
            j++;
        helper(candidates, target, j, v); // not picking the element
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        helper(candidates, target, 0, v);
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    for (auto &v : result)
    {
        for (int num : v)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}