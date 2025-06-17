#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
string combineWordsFromFile(const char fileName[])
{
    ifstream fin(fileName);
    string s;
    vector<string> words;
    string result = "";
    while (fin >> s)
    {
        words.push_back(s);
    }
    fin.close();
    sort(words.begin(), words.end(), greater<string>());
    for (unsigned int i = 0; i < words.size(); i++)
    {
        result += words[i] + (i == words.size() - 1 ? "" : " ");
    }

    return result;
}
int main()
{
    char testFileName[] = "words1.txt";
    string combined = combineWordsFromFile(testFileName);
    cout << combined << endl;
    cout << boolalpha << ("this test is a" == combined);
    return 0;
}