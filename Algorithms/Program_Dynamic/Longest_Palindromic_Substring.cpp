#include <cstring>  // chỉ dùng để lấy độ dài chuỗi
#include <iostream>

using namespace std;
class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;  // Chuỗi đã là palindrome hoặc rỗng

        int start = 0, maxLength = 1;  // Khởi tạo vị trí bắt đầu và độ dài tối đa
        for (int i = 0; i < n; i++) {
            // Kiểm tra palindrome với tâm là i (cho chuỗi lẻ)
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
            // Kiểm tra palindrome với tâm là i và i+1 (cho chuỗi chẵn)
            left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxLength);  // Trả về chuỗi con palindrome dài nhất
    }
};
int main() {
    Solution s;
    string str = "babad";
    cout << s.longestPalindrome(str) << endl;  // Output: "bab" or "aba"
    return 0;
}