#include <iostream>
using namespace std;
class Solution {
    public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.length() - 1;
        while( i >= 0 && s[i] == ' ') {
            i--;
        }
        while(i >= 0 && s[i] != ' ') {
            i--; 
            count++;
        }
        return count;
    }
};
int main() {
    Solution s;
    string str = "   fly me   to   the moon  ";
    cout << s.lengthOfLastWord(str) << endl;
}