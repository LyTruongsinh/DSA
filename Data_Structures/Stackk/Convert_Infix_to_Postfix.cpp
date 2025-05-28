#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<char> result;

int precedence(char op)
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
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                result.push_back(s.top());
                s.pop();
            }
            if (!s.empty())
                s.pop(); // Bỏ '('
        }
        else // toán tử
        {
            while (!s.empty() && precedence(s.top()) >= precedence(infix[i]))
            {
                result.push_back(s.top());
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
}

int main()
{
    vector<char> infix = {'(', '5', '-', '2', '+', '3', ')', '+', '4', '*', '(', '8', '-', '5', '*', '4', ')'};
    infixToPostfix(infix);

    for (char c : result)
    {
        cout << c << " ";
    }
    return 0;
}
