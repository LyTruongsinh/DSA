#include <iostream>
#include <string>
using namespace std;
string Afterfix(string s)
{
    string result = "";
    int si = 0;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            si = i;
            break;
        }
        result += s[i];
    }
    for (unsigned int i = si; i < s.length(); i++)
    {
        if (s[i] == ' ' && s[i - 1] == ' ')
        {
            continue;
        }
        else
        {
            result += s[i];
        }
    }
    return result;
}
int main()
{
    string s;
    getline(cin, s);
    string result = Afterfix(s);
    cout << result << endl;
}