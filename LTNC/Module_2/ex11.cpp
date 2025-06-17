#include <iostream>
#include <string>
using namespace std;
string pigLatin(string word)
{
    if (word[0] == 'u' || word[0] == 'e' || word[0] == 'o' || word[0] == 'a' || word[0] == 'i')
    {
        return word + "way";
    }

    char temp = word[0];
    return word.substr(1) + temp + "ay";
}