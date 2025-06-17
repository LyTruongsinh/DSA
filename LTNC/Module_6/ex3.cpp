#include <fstream>
#include <iostream>

using namespace std;
int main()
{
    string path;
    cin >> path;
    ifstream fin(path);
    int count = 0;
    int sum = 0;
    int max;
    int min;
    int a;
    fin >> a;
    sum += a;
    count++;
    max = min = a;
    while (fin >> a)
    {
        sum += a;
        count++;
        if (a > max)
            max = a;
        if (a < min)
            min = a;
    }
    cout << count << " " << min << " " << max << " " << sum << endl;
    return 0;
}