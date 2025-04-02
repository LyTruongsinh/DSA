#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        helper(res, "", 0, 0, n);
        return res;
    }
    void helper(vector<string> &v, string str, int open_count, int close_count, int n)
    {
        if(open_count == n && close_count == n) {
            v.push_back(str);
            return;
        }
        if(open_count < n) {
            helper(v, str + "(", open_count + 1, close_count, n);
        }
        if(close_count < open_count) {
            helper(v, str + ")", open_count, close_count + 1, n);
        }
    }
};
int main()
{
    Solution sol;
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;
    vector<string> ans = sol.generateParenthesis(n);
    cout << "All possible combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
//                            "" (0 open, 0 close)
//                            |
//               +------------+------------+
//               |                         |
//             "(" (1,0)                  "()" (1,1)
//               |                           |
//       +-------+-------+            +------+------+
//       |               |            |             |
//     "((" (2,0)      "()" (1,1)   "()((" (2,1)  "()()" (2,2)
//       |               |            |             |
//   +---+---+       +---+---+     +---+---+      +---+---+
//   |       |       |       |     |       |      |       |
// "((("   "(()"  "()("   "()()" "(())"  "()(("  "()()("
// (3,0)   (2,1)  (2,1)   (2,2)  (3,1)   (3,1)   (3,2)
//   |       |       |       |     |       |       |
//   |       |       |       |     |       |       |
// "((())" "(())(" "()(())" "()(())" "((()))" "(())()" "()()()"
// (3,1)   (3,2)  (3,2)    (3,3)   (3,3)    (3,3)    (3,3)
