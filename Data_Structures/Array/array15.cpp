#include <iostream>
#include <string>
#include <cctype> 
using namespace std;
bool ValidSignout(string s) {
    if (isdigit(s[0])) return false;
    if( s.length() < 6 || s.length() > 15) return false;
    bool check = false;
    for (unsigned int i = 0; i < s.length(); i++) {
        if(isalpha(s[i]) || isdigit(s[i])) {
            check = true;
        }
        else {
            check = false;
            break;
        }
    }
    return check;
}

int main() {
    string s;
    getline(cin,s);
    if(ValidSignout(s)) {
        cout <<"Valid username.";
    }
    else {
        cout << "Invalid username.";
    }
}