#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string addBinary1(string a, string b)
    {
        int carry = 0;
        string result = "";
        int n = a.length() - 1;
        int m = b.length() - 1;

        while (n >= 0 || m >= 0 || carry)
        {
            int sum = carry;

            if (n >= 0)
                sum += a[n--] - '0';
            if (m >= 0)
                sum += b[m--] - '0';

            result = to_string(sum % 2) + result;
            carry = sum / 2;
        }

        return result;
    }
    string addBinary2(string a, string b)
    {
        int carry = 0;
        string result = "";
        int n = a.length() - 1;
        int m = b.length() - 1;
        int count = 0;
        while (n >= 0 || m >= 0)
        {
            int sum;
            if (n >= 0 && m >= 0)
            {
                sum = (a[n] - '0') + (b[m] - '0') + carry;
            }
            if (m < 0)
            {
                sum = (a[n] - '0') + carry;
            }
            if (n < 0)
            {
                sum = (b[m] - '0') + carry;
            }

            if (sum == 2)
            {
                carry = 1;
                sum = 0;
            }
            else if (sum == 3)
            {
                carry = 1;
                sum = 1;
            }
            else
            {
                carry = 0;
            }
            n--;
            m--;
            result = (char)(sum + '0') + result;
        }
        if(carry == 0) return result;
        return  (char)(carry + '0') + result;
    }
};

int main()
{
    Solution s;

    string a = "0";
    string b = "1";
    cout << s.addBinary2(a, b) << endl;
    return 0;
}
