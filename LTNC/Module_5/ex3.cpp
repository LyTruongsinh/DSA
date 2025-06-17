#include <iostream>
#include <vector>
using namespace std;
void removeduplicate(vector<int> A)
{
    int key = A[0];
    cout << A[0];
    for(int i = 1; i < A.size(); i++)
    {
        if(A[i] == key)
        {
            continue;
        }
        else
        {
            cout << A[i] << " ";
            key = A[i];
        }
    }
}
int main()
{
    int n; cin >> n;
    vector<int> A;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        A.push_back(x);
    }
    removeduplicate(A);
    return 0;
}