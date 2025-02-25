#include<iostream>
#include<string>
using namespace std;
void Count(string s, int &countAlpha, int &countNumber, int &countOther) {
    for(unsigned int i = 0; i < s.length();i++) {
        if(isalpha(s[i])) {
            countAlpha++;
        }
        else if(isdigit(s[i])) {
            countNumber++;
        }
        else {
            countOther++;
        }
    }
}
int main() {
    string s;
    getline(cin,s);
    int cA = 0;
    int cN = 0;
    int cO = 0;
    Count(s, cA,cN,cO);
    cout << cA << " " << cN << " " << cO << endl;
}