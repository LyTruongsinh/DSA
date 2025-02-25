#include<iostream>
#include<string>
using namespace std;
unsigned int countStartSpaces(string s) {
    int count = 0;
    for(unsigned int i = 0; i < s.length();i++) {
        if(s[i] == ' ') {
            count++;
        }
        else {
            break;
        }
    }
    return count;
}
int main() {
    string s;
    getline(cin,s);
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (i < countStartSpaces(s))
        {
            cout << " ";
        }
        else
        {
            if(s[i] != ' ') {
                cout << s[i];
            }
            else {
                cout << " ";
                while(s[i] == ' ') {
                    i++;
                }
                i = i - 1;
            }
        }
    }
    return 0;
}