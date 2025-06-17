#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int len = 2 * n + 1;
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j <= len - 1; j++)
        {
            if (j >= i && j <= -i + (len - 1))
            {
                cout << "* ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
    for(int i = -1; i >= -n; i--)
    {
        for(int j = 0; j <= len - 1; j++)
        {
            if(j >= -i && j <= i + (len - 1))
            {
                cout << "* ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
    return 0;
}