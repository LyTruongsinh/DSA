#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin ,s);
    for (unsigned int i = 0; i < s.length();i++)
    {
        if(s[i] == 'Z')
        {
            if(s.substr(i, 4) == "Zues")
            {
                s.erase(i,4);
                s.insert(i,"Zeus");
                break;
            }
        }
    }
    cout << s << endl;
    return 0;
}