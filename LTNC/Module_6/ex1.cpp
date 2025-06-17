#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    string path;
    cin >> path;
    ifstream fin(path);
    if(fin.is_open())
    {
        cout << "YES" << endl;
        fin.close();
    }
    else
    {
        cout << "NO" << endl;
    }
}