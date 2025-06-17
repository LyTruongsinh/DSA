#include <iostream>
#define MAX 1002
using namespace std;
bool checkSymmetric(int A[], int n) {
    for(int i = 0; i < n/2; i++)
    {
        if(A[i] != A[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int A[MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    if (checkSymmetric(A, n))
    {
        cout << "Symmetric array." << endl;
    }
    else
    {
        cout << "Asymmetric array." << endl;
    }
}