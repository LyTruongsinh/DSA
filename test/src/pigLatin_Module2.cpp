#include <iostream>
#include <string>
using namespace std;
string pigLatin(string word) {
    for(int i = 0; i < word.length(); i++) {
        if(word[i] == 'u' || word[i] == 'e' || word[i] == 'o' || word[i] == 'a' || word[i] == 'i') {
            word = word + "way";
            break;
        }
        else {
            word = word.substr(1) + word[0] + "ay";
            break;
        }
    }
    return word;
}
int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;
    cout << "Pig Latin: " << pigLatin(word) << endl;
    return 0;
 
}