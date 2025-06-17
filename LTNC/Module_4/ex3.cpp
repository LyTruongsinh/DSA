#include <cmath>
#include <iostream>

using namespace std;
bool checkIsPerfect(int n)
{
    int root = sqrt(n);
    return root * root == n;
}
int main()
{
    int lb;
    int ub;
    cin >> lb >> ub;
    for(int i = lb; i <= ub; i++)
    {
        if(checkIsPerfect(i))
        {
            cout << i << " ";
        }
    }
    return 0;
}