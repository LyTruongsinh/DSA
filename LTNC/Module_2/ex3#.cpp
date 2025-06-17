#include <iostream>
using namespace std;
void printArrow(int n, bool left)
{
    if (left == 0)
    {
        // Mũi tên hướng trái
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
                cout << " ";
            for (int j = i; j <= 2 * i; j++)
                cout << "*";
            cout << endl;
        }
        for (int i = -1; i >= -n + 1; i--)
        {
            for (int j = 0; j < -i; j++)
                cout << " ";
            for (int j = -i; j <= 2 * (-i); j++)
                cout << "*";
            cout << endl;
        }
    }
    if (left == 1)
    {
        // Mũi tên hướng phải
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2 * (n - 1) - 2 * i; j++)
                cout << " ";
            for (int j = 2 * (n - 1) - 2 * i; j <= (-1) * i + 2 * (n - 1); j++)
                cout << "*";
            cout << endl;
        }
        for (int i = -1; i >= -n + 1; i--)
        {
            for (int j = 0; j < 2 * i + 2 * (n - 1); j++)
                cout << " ";
            for (int j = 2 * i + 2 * (n - 1); j <= i + 2 * (n - 1); j++)
                cout << "*";
            cout << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    printArrow(n, 1);
}

// i
// 5        ******
// 4       *****
// 3      ****
// 2     ***
// 1    **
// 0   *
// -1   **
// -2    ***
// -3     ****
// -4      *****
// -5       ******