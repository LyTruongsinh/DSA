#include <iostream>
#include <vector>
using namespace std;
void generate(vector<char> &result, string s, int len)
{
    if(result.size() == len)
    {
        for(unsigned int i = 0; i < result.size(); i++)
        {
            cout << result[i];
        }
        cout << endl;
        return;
    }
    for(unsigned int i = 0; i < s.length(); i++)
    {
        result.push_back(s[i]);
        generate(result, s, len);
        result.pop_back();
    }
}
int main()
{
    string s;
    cin >> s;
    vector<char> result;
    // in ra tất cả các hoán vị với các độ dài
    for(int i = 1; i <= s.length(); i++)
    {
        generate(result,s,i);
    }
}