#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    while(true)
    {
        int x; cin >> x;
        if(x == -1)
        {
            a.push_back(x);
            break;
        }
        else
        {
            a.push_back(x);
        }
    }
    
    for(unsigned int i = 0; i < a.size(); i++)
    {
        bool check  = false;
        for(unsigned int j = 0; j < a.size(); j++)
        {
            if(a[i] == a[j] && i != j)
            {
                check = true;
            }
        }
        if(check == false)
        {
            cout << a[i] << " ";
        }
    }
}