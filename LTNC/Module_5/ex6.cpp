#include <iostream>
#include <string>
using namespace std;
int countword(string s)
{
    int count = 0;
    for(unsigned int i = 1; i < s.length(); i++)
    {
        if(s[i] != ' ' && s[i - 1] == ' ')
        {
            count ++;
        }
    }
    return count;
}
int main()
{
    string s;
    getline(cin, s);
    cout << countword(s) + 1 << endl;
    return 0;
}