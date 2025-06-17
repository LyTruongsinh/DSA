#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
string combine(const vector<string> &words)
{
    vector<string> temp = words; // tạo bản sao để sắp xếp
    string result;
    sort(temp.begin(), temp.end(), greater<string>());
    for (unsigned int i = 0; i < temp.size(); i++)
    {
        result += temp[i] + (i == temp.size() - 1 ? "" : " ");
    }
    return result;
}

int main()
{
    vector<string> word = {"this", "is", "a", "test"};
    string combined = combine(word);
    cout << combined << endl;
}
