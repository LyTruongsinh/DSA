#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
bool isChinhPhuong(int x)
{
    int root = sqrt(x);
    return root * root == x;
}
vector<int> listSquare(int a, int b)
{
    vector<int> result;
    for (int i = a; i <= b; i++)
    {
        if (isChinhPhuong(i))
        {
            result.push_back(i);
        }
    }
    return result;
}
int main()
{
    vector<int> a = listSquare(2, 30);
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    return 0;
}