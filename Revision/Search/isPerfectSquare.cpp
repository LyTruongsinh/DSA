#include <iostream>
using namespace std;
class Solution
{
  public:
    bool isPerfectSquare(int num)
    {
        int left = 0;
        int right = num;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            long long square = mid * mid;
            if (square == num)
            {
                return true;
            }
            if (square < num)
            {
                left = mid + 1;
            }
            if (square > num)
            {
                right = mid - 1;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    int n; cin >> n;
    if(s.isPerfectSquare(n))
    {
        cout << "so chinh phuong";
    }
    else {
        cout << "Khong phai so chinh phương";
    }
}