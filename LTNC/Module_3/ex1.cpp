#include <iostream>
using namespace std;
int main()
{
    string a[11];
    cin >> a[0] >> a[1];
    cout << a[0] << endl;
    cout << a[1] << endl;
    for (int i = 2; i <= 10; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
        cout << a[i] << endl;
    }
    return 0;
}