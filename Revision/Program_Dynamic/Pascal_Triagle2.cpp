#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {   
        vector<vector<int>> list;
        for(int i = 0; i <= rowIndex;i++) {
            vector<int> temp(i + 1,1);
            if(i > 1) {
                for(int j = 1; j < temp.size() - 1; j++) {
                    temp[j] = list[i - 1][j - 1] + list[i - 1][j];
                }
            }
            list.push_back(temp);
        }
        return list[rowIndex];
    }
};
int main()
{
    int n; cin >> n;
    Solution s;
    vector<int> result = s.getRow(n);
    for(int i = 0 ; i <= n; i++) {
        cout << result[i] << " ";
    }
}
