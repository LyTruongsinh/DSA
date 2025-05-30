#include <iostream>
#include <string>
using namespace std;
class Solution
{
  public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--; // Adjust for 0-based index
            char currentChar = 'A' + (columnNumber % 26);
            result = currentChar + result; // Prepend the character
            columnNumber /= 26; // Move to the next "digit"
        }
        return result;
    }
};
int main()
{
    Solution solution;
    int columnNumber = 28; // Example input
    string result = solution.convertToTitle(columnNumber);
    cout << "Column title for " << columnNumber << " is: " << result << endl;
    return 0;
}