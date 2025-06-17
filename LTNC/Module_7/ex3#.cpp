#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[10000];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, less<int>());
    for(int i = 0 ; i <n ; i++)
    {
        cout << a[i] << " ";
    }
    int totalwait = 0;
    int waittime = 0;
    for(int i = 1;i < n ; i++)
    {
        waittime = waittime + a[i - 1];
        totalwait += waittime;
    }
    cout << totalwait << endl;
    return 0;
}