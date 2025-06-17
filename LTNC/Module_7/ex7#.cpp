#include <iostream>
#include <vector>
using namespace std;
bool used[1000] = {false};
void permutation(vector<char> &result, string s) 
{
    if(result.size() == s.length())
    {
        for(unsigned int i = 0; i < result.size(); i++)
        {
            cout << result[i];
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(!used[s[i] - 'a'])
        {
            used[s[i] - 'a'] = true;
            result.push_back(s[i]);
            permutation(result, s);
            used[s[i] - 'a'] = false;
            result.pop_back();
        }
    }
}
int main()
{
    string s;
    cin >> s;
    vector<char> result;
    permutation(result, s);
}