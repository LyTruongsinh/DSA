#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution
{
  private:
    vector<int> result;
  public:
    vector<int> nextSmallerElement(vector<int> &nums)
    {
        stack<int> s;
        int n = nums.size();
        result.resize(n, -1); // Khởi tạo kết quả với -1
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty())
            {
                if(s.top() < nums[i])
                {
                    result[i] = s.top(); // Lưu giá trị nhỏ hơn tiếp theo
                    s.push(nums[i]); // Thêm giá trị hiện tại vào stack
                    break; // Dừng lại khi tìm thấy giá trị nhỏ hơn
                }
                else 
                {
                    s.pop();
                }
            }
            if(s.empty())
            {
                result[i] = -1;
                s.push(nums[i]); // Thêm giá trị hiện tại vào stack
            }
        }
        return result;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {7, 4, 6, 1, 9, 6, 3};
    vector<int> result = solution.nextSmallerElement(nums);
    
    cout << "Next smaller elements to the right: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}

