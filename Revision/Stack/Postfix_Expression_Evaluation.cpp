#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
int evaluatePostfix(const vector<string> &expression)
{
    stack<int> s;
    for (int i = 0; i < expression.size(); i++)
    {
        if (isdigit(expression[i][0]))
        {
            s.push(stoi(expression[i]));
        }
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (expression[i][0])
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
    }
    return s.top();
    s.pop();
    return 0; // Chỉ để tránh cảnh báo, không bao giờ đến đây
}
int main()
{
    vector<string> expr1 = {"2", "3", "1", "*", "+", "9", "-"};
    int result1 = evaluatePostfix(expr1);
    cout << " Example 1 Result : " << result1 << endl;

    vector<string> expr2 = {"100", "200", "+", "2", "/", "5", "*", "7", "+"};
    int result2 = evaluatePostfix(expr2);
    cout << " Example 2 Result : " << result2 << endl;
    return 0;
}