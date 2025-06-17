#include <iostream>
#include <iomanip>
#define MAX 1001
using namespace std;
int n;
double A[MAX];
double B[MAX];
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
}
double Caculate()
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i] * B[i];
    }
    return sum;
}
int main()
{
    input();
    cout << fixed << setprecision(2) << Caculate() << endl;
}