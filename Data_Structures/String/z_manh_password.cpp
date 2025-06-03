#include <iostream>
#include <string>
using namespace std;
int countPassword = 0;
void generatePassord(string current, int n, int p, int zCount)
{
    if (current.length() == n)
    {
        if (zCount >= p)
        {
            cout << current << endl;
            countPassword++;
        }
        return;
    }

    // Cắt nhánh nếu không đủ số lượng chữ 'z'
    if ((n - current.length()) + zCount < p)
        return;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (c == 'z')
        {
            generatePassord(current + c, n, p, zCount + 1);
        }
        else
        {
            generatePassord(current + c, n, p, zCount);
        }
    }
}
int main()
{
    int n, p;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap p: ";
    cin >> p;

    generatePassord("", n, p, 0);
    cout << "Tong so password: " << countPassword << endl;
    return 0;
}
