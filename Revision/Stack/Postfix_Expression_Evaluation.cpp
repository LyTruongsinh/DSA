#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int evaluatePostfix(vector<string> &tokens)
    {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++)
        {
            // Nếu là toán tử
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                switch (tokens[i][0])
                {
                case '+':
                    s.push(b + a);
                    break;
                case '-':
                    s.push(b - a);
                    break;
                case '*':
                    s.push(b * a);
                    break;
                case '/':
                    s.push(b / a);
                    break;
                }
            }
            else
            {
                // Là số (cả âm và dương)
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};

int main()
{
    Solution solution;
    vector<string> expr1 = {"2", "3", "1", "*", "+", "9", "-"};
    int result1 = solution.evaluatePostfix(expr1);
    cout << " Example 1 Result : " << result1 << endl;

    vector<string> expr2 = {"100", "200", "+", "2", "/", "5", "*", "7", "+"};
    int result2 = solution.evaluatePostfix(expr2);
    cout << " Example 2 Result : " << result2 << endl;
    return 0;
}