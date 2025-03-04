#include <iostream>
#include <string>
using namespace std;
int count(string s, char delim)
{
    int count = 0;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (s[i] == delim)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int a, m;
    cin >> a >> m;

    string s(a+m,'0');
    if( m != 0) {
        int n = s.size() - 1;
        while (n >= 0)
        {
            if (s[n] == '1')
            {
                s[n] = '0';
                n--;
            }
            if (s[n] == '0')
            {
                s[n] = '1';
                if (count(s, '0') == a && count(s, '1') == m)
                {
                    cout << s << endl;
                }
                n = s.size() - 1;
            }
        }
    }
    else {
        cout << s << endl;
        int n = s.size() - 1;
        while (n >= 0)
        {
            if (s[n] == '1')
            {
                s[n] = '0';
                n--;
            }
            if (s[n] == '0')
            {
                s[n] = '1';
                if (count(s, '0') == a && count(s, '1') == m)
                {
                    cout << s << endl;
                }
                n = s.size() - 1;
            }
        }
    }
    return 0;
}