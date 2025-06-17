#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    void helper(vector<vector<int>> &ans, vector<int> &temp, int n, int k, int start)
    {
        if (temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = start; i <= n && n - i + 1 >= k - temp.size(); i++)
        {
            temp.push_back(i);
            helper(ans, temp, n, k, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, n, k, 1);
        return ans;
    }
};
int main()
{
    Solution solution;
    vector<vector<int>> result = solution.combine(4, 2);
    for (auto row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}