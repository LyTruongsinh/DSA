#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution
{
  public:
    int calculate(string s)
    {
        stack<int> nums;
        stack<char> ops;
        int num = 0;
        char lastOp = '+';
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1)
            {
                if (lastOp == '+')
                {
                    nums.push(num);
                }
                else if (lastOp == '-')
                {
                    nums.push(-num);
                }
                else if (lastOp == '*')
                {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top * num);
                }
                else if (lastOp == '/')
                {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top / num);
                }
                lastOp = s[i];
                num = 0;
            }
        }
        int result = 0;
        while (!nums.empty())
        {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};
int main()
{
    Solution sol;
    string s = "8/4*2";
    int result = sol.calculate(s);
    cout << result << endl; // Output: 4
    return 0;
}