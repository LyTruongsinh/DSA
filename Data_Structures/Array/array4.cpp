#include <iostream>
using namespace std;
int main()
{
    int n = 7;
    int a = 1;
    int index = n;
    for (int i = 1; i <= 2 * index - 1; i++)
    {
        if (i <= index)
        {
            for (int j = 1; j <= 2 * index - 1; j++)
            {
                if (j >= a && j <= n)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            if (a != n)
            {
                a += 2;
                n++;
            }
        }
        else
        {
            n--;
            a -= 2;
            for (int j = 1; j <= 2 * index - 1; j++)
            {
                if (j >= a && j <= n)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    cout << endl;
    int n1 = 7;
    int index1 = n1;
    int a1 = 2 * index1 - 1;
    for (int i = 1; i <= 2 * index1 - 1; i++)
    {
        if (i <= index1)
        {
            for (int j = 1; j <= 2 * index1 - 1; j++)
            {
                if (j >= n1 && j <= a1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            if (a1 != n1)
            {
                n1--;
                a1 -= 2;
            }
        }
        else
        {
            a1 += 2;
            n1++;
            for (int j = 1; j <= 2 * index1 - 1; j++)
            {
                if (j >= n1 && j <= a1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}