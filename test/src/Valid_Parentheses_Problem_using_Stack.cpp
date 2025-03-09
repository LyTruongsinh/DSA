#include <iostream>
#include <stack>
using namespace std;
class Solution
{
private:
    string s;

public:
    Solution(string str) : s(str) {}
    bool Check_for_Balanced_Parentheses();
};
bool Solution::Check_for_Balanced_Parentheses()
{
    stack<char> open_bracket;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            open_bracket.push(c);
        }
        else
        {
            if (open_bracket.empty())
                return false;
            char top = open_bracket.top();
            open_bracket.pop();
            if (top == '(' && c != ')')
                return false;
            if (top == '{' && c != '}')
                return false;
            if (top == '[' && c != ']')
                return false;
        }
    }
    return open_bracket.empty();
}
int main()
{
    Solution s("({[()]}");
    if (s.Check_for_Balanced_Parentheses())
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
    return 0;
}