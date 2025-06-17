#include <iostream>
#include <vector>
using namespace std;
void Input(vector<int> &A, vector<int> &B, int n)
{
    for(int i = 0; i < n ;i++)
    {
        int x; cin >> x;
        A.push_back(x);
    }
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        B.push_back(x);
    }
}
bool check(vector<int> A, vector<int> B)
{
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] != B[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n; cin >> n;
    vector<int> A;
    vector<int> B;
    Input(A,B,n);
    if(check)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}