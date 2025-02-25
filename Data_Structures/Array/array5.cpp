#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> result;
        stack<int> s;
        int n = 0;
        int number = 0;
        while (n <= digits.size() - 1)
        {
            number = number * 10 + digits[n];
            n++;
        }
        while ((number + 1) > 0)
        {
            s.push((number + 1) % 10);
            number = (number + 1) / 10;
        }

        while (!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> digits = {2, 3, 4};
    vector<int> result = s.plusOne(digits);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}