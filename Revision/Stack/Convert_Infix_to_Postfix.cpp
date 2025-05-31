#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
vector<char> result;
int MucUuTien(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
void infixToPostfix(const vector<char> &infix)
{
    stack<char> s;
    for (int i = 0; i < infix.size(); i++)
    {
        if (isdigit(infix[i]))
        {
            result.push_back(infix[i]);
        }
        if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                result.push_back(s.top());
                s.pop();
            }
            if (!s.empty())
                s.pop(); // Bỏ '('
        }
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (!s.empty() && MucUuTien(s.top()) >= MucUuTien(infix[i]))
            {
                result.push_back(s.top());
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    // Đẩy các toán tử còn lại vào kết quả
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
}
int main()
{
    vector<char> infix = {'3', '+', '5', '*', '(', '2', '-', '8', ')'};
    infixToPostfix(infix);
    cout << "Postfix: ";
    for (char c : result)
    {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}