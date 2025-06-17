#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string path;
    cin >> path;
    ifstream fin(path);
    if (!fin.is_open())
    {
        cout << "Mission failed" << endl;
        return 0;
    }
    string s;
    int count = 0;
    // Đếm các dòng
    while (getline(fin, s))
    {
        count++;
    }
    fin.close();
    cout << count << endl;
    return 0;
}