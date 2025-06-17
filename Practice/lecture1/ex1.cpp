#include <iostream>
#include <string>
using namespace std;
class Solution
{
  public:
    void reverse(string s)
    {
        for (unsigned int i = s.length() - 1; i >= 0; i--)
        {
            cout << s[i];
        }
    }
};
int main()
{
    Solution s;
    string str;
    getline(cin, str);
    s.reverse(str);
}