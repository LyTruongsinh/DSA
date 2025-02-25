#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution s;
    vector<int> digits = {2, 3, 4};
    vector<int> result = s.plusOne(digits);

    for (int num : result)
    {
        cout << num << " ";
    }
}
