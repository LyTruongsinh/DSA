#include <cstring>
#include <iostream>
#include <string>

using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int countAl = 0;
    int countDi = 0;
    int countOt = 0;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            countDi++;
        }
        else
        {
            if(isalpha(s[i]))
            {
                countAl++;
            }
            else
            {
                countOt++;
            }
        }
    }
    cout << countAl << " " << countDi << " " << countOt << endl;
    return 0;
}