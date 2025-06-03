#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> temp(i + 1, 1);
            if (i > 1)
            {
                for (int j = 1; j < temp.size() - 1; j++)
                {
                    temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main() {
    Solution s;
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;
    vector<vector<int>> result = s.generate(numRows);
    cout << "Pascal's Triangle:" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}