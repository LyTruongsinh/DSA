#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[currRow] += c;
            // Đảo chiều khi chạm dòng đầu hoặc cuối
            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }

        // Nối các dòng lại thành kết quả
        string result;
        for (string row : rows)
            result += row;
        return result;
    }
};
int main()
{
    Solution sol;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string result = sol.convert(s, numRows);
    cout << result << endl; // Expected output: "PAHNAPLSIIGYIR"
    return 0;
}
// Dòng 0: P       I       N
// Dòng 1: A     L S     I G
// Dòng 2: Y   A   H   R
// Dòng 3: P       I

// Ký tự	Dòng	Hướng đi
// P	     0	       ↓
// A	     1	       ↓
// Y	     2	       ↓
// P	     3	       ⬆ 
// A	     2	       ⬆
// L	     1	       ⬆
// I	     0	       ↓
// S	     1	       ↓
// H	     2	       ↓
// I	     3	       ⬆
// R	     2	       ⬆
// I	     1	       ⬆
// N	     0	       ↓
// G	     1	       ↓
