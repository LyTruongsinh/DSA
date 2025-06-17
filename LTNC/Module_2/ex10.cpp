#include <iostream>
#include <cctype>
#include <string>
using namespace std;
string toLower (string s)
{
    for(int i = 0 ; i < s.length(); i++)
    {
        if(isupper(s[i]))
        {
            s[i] = tolower(s[i]);
        }
        else
        {
            continue;
        }
    }
    return s;
}
int main()
{
    string s;
    cin >> s;
    string t = toLower (s);
    
}
