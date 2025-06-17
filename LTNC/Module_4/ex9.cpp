#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAX 1001
using namespace std;
double a[MAX];
int n;
void input() {
    cin >> n;
    for(int i = 0 ;i < n; i++)
    {
        cin >> a[i];
    }
}
void reverse(int n) {
    for(int i = 0; i < n / 2; i++)
    {
        swap(a[i], a[n - 1 - i]);
    }
}
void print()
{
    for(int i = 0; i < n ; i++)
    {
        cout << fixed << setprecision(2) << a[i] << " ";
    }
}
int main()
{
    input();
    reverse(n);
    print();
}