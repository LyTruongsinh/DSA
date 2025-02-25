#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(vector<string> &operations) {
        stack<int> s;
        int sum = 0;
        
        for (const string &op : operations) {
            if (op == "C") {
                if (!s.empty()) {
                    s.pop();
                }
            } 
            else if (op == "D") {
                if (!s.empty()) {
                    s.push(2 * s.top());
                }
            } 
            else if (op == "+") {
                if (s.size() >= 2) {
                    int top1 = s.top(); s.pop();
                    int top2 = s.top();
                    s.push(top1); 
                    s.push(top1 + top2);
                }
            } 
            else {
                s.push(stoi(op));
            }
        }

        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }

        return sum;
    }
};

int main() {
    Solution s;
    vector<string> operations = {"5", "2", "C", "D", "+"};
    cout << s.calPoints(operations) << endl; 
    return 0;
}
