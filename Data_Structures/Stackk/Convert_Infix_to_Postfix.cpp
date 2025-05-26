#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<char> result;

void infixToPostfix(const vector<char> infix)
{
    stack<char> s;
    for (int i = 0; i < infix.size(); i++)
    {
        if (isdigit(infix[i]))
        {
            result.push_back(infix[i]);
        }
        else
        {
            if (infix[i] == '(')
            {
                s.push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (!s.empty())
                {
                    
                    result.push_back(s.top());
                    s.pop();
                    if (!s.empty() && s.top() == '(')
                    {
                        s.pop(); // Bỏ dấu ngoặc mở
                    }
                }
            }
            else
            {
                // Nếu là toán tử, đẩy vào stack (chưa xét ưu tiên)
                s.push(infix[i]);
            }
        }
    }

    // Sau vòng lặp, pop hết còn lại trong stack
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
}

int main()
{
    vector<char> infix = {'8', '/', '4', '*', '2'};
    infixToPostfix(infix);

    for (char c : result)
    {
        cout << c << " ";
    }
    return 0;
}
