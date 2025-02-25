#include <iostream>
#include <string>

using namespace std;

int countWords(const string& s) {
    int num_word = 0;
    string str = " " + s;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] != ' ' && str[i - 1] == ' ') {
            num_word++;
        }
    }
    return num_word;
}

int main() {
    string s;
    getline(cin, s);
    cout << countWords(s) << endl;
    return 0;
}
