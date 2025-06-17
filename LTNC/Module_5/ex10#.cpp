#include <iostream>
#include <string>
using namespace std;
bool checkvalid(string s)
{
    if (s.length() < 6 || s.length() > 15)
        return false;
    if (isdigit(s[0]))
        return false;

    for (int i = 0; i < s.length(); i++)
    {
        if (!isalpha(s[i]) && !isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s;
    getline(cin, s);
    if (checkvalid(s))
    {
        cout << "Valid username." << endl;
    }
    else
    {
        cout << "Invalid username." << endl;
    }
}