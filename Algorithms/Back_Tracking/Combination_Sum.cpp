#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void helper(vector<int> &candidates, int remain, int start, vector<int> &cur)
    {
        if(remain == 0) {
            ans.push_back(cur);
            return;
        }
        if(remain < 0) {
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            helper(candidates, remain - candidates[i], i, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> cur;
        helper(candidates, target, 0, cur);
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> candidates = {1,2,5};
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