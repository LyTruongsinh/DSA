#include <iostream>
#include <string>
using namespace std;
void generate(string &alphabet, string cur, unsigned int length) {
    if (cur.size() == length) {
        cout << cur << endl;
        return;
    }
    
    for (unsigned int  i = 0; i < alphabet.size(); i++) {
        generate(alphabet, cur + alphabet[i], length);
    }
    
}

int main() {
    string alphabet;
    cin >> alphabet;
    for (unsigned int len = 1; len <= alphabet.size(); len++) {
        generate(alphabet, "", len);
    }

    return 0;
}
