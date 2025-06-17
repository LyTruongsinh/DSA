#include <iostream>
using namespace std;
int change(int &x)
{
    x = x + 1;
    return x;
}
int main()
{
    int n;
    cin >> n;
    cout << "trước : " << n << endl;
    change(n);
    cout << "sau : " << n << endl;
}