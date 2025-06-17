#include <iostream>
using namespace std;
int* getPointerToArray(int n)
{
    int * arr = new int[n];
    for(int i = 0; i <n ;i++)
    {
        cin >> *(arr + i);
    }
    return arr;
}
int main()
{
    int *a = getPointerToArray(5);
    for(int i = 0; i < 5; i++)
    {
        cout << *(a+i) << endl;
    }
}