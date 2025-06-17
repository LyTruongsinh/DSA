#include <fstream>
#include <iostream>

using namespace std;
int main()
{
    string path;
    cin >> path;
    ifstream fin(path);
    if (fin.is_open())
    {
        int a;
        fin >> a;
        int max = a;
        int min = a;
        while (fin >> a)
        {
            if (a > max)
            {
                max = a;
            }
            if (a < min)
            {
                min = a;
            }
        }
        cout << max << " " << min << endl;
        fin.close();
    }
    else
    {
        cout << "Mission failed" << endl;
    }
    return 0;
}