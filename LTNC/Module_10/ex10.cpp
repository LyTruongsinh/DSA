#include <cstring>
#include <iostream>

using namespace std;
void rFilter(char *s)
{
    int len = strlen(s);
    int i = len - 1;
    while (i >= 0)
    {
        if (((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z')))
        {
            s[i] = '_';
            i--;
        }
    }
}

int main()
{
    char *s = new char[7];
    for (int i = 0; i < 7; i++)
    {
        cin >> s[i];
    }
    s[7] = '\0';
    rFilter(s);
}