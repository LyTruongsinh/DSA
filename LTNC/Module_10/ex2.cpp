#include <iostream>
using namespace std;
void multiply (int* n, int k)
{
    *n = *n *k;
}
int main()
{
    int n; cin >> n;
    multiply (&n, 3);
    cout << n;
}