#include <iostream>
using namespace std;
void next(string s) {
    int i = s.length() - 1;
    while( i >= 0 && s[i] == '1') {
        s[i] = '0';
        i--;
    }
    if( i != -1) {
        s[i] = '1';
    } 
    cout << s << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        next(s);
    }
    return 0;
}