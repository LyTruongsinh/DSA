#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string path;
    cin >> path;

    ifstream fin(path);
    if (!fin.is_open())
    {
        cout << "Cannot open file." << endl;
        return 0;
    }
    fin.close();
    int n;
    fin >> n;
    vector<int> a;
    int x;
    while (fin >> x)
    {
        a.push_back(x);
    }
    double median;
    sort(a.begin(), a.end(), greater<int>());
    if (n % 2 == 0)
    {
        median = (a[n / 2 - 1] + a[n / 2]) / 2.0;
    }
    else
    {
        median = a[n / 2];
    }
    cout << median << endl;
    return 0;
}
