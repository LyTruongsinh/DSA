#include <iostream>
using namespace std;
int &getPointerToTen()
{
    int *x = new int;
    cout << &x << endl;
    *x = 10;
    return *x;
}
int main()
{
    cout << getPointerToTen() << endl;
}