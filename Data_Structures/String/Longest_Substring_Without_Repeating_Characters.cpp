#include <iostream>
#include <string>
using namespace std;
class Solution
{
  public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        int start = 0; // left pointer
        int charIndex[256] = {0};

        for (int i = 0; i < n; i++) {
            if (charIndex[s[i]] > start) {
                start = charIndex[s[i]]; // Nếu gặp phấn tử trùng, dịch left pointer sang phải
            }
            charIndex[s[i]] = i + 1; // Cập nhật right pointer
            maxLength = max(maxLength, i - start + 1);
        }
        return maxLength;
    }
};
int main()
{
    Solution solution;
    string s = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;
    return 0;
}
// Explanation:
// Phân tích chi tiết với chuỗi "abcabcbb":
// Step	left	right	s[right]	 seen	       maxLength	Ghi chú
// 1	      0	      0	      'a'	     {a}	           1	    Chưa trùng
// 2	      0	      1	      'b'	     {a, b}	           2	    Chưa trùng
// 3	      0	      2	      'c'	     {a, b, c}	       3	    Chưa trùng
// 4	      0→1	  3	      'a'	     {b, c, a}	       3	    'a' lặp → xóa 'a' cũ
// 5	      1→2	  4	      'b'	     {c, a, b}	       3	    'b' lặp → xóa 'b' cũ
// 6	      2→3	  5	      'c'	     {a, b, c}	       3	    'c' lặp → xóa 'c' cũ
// 7	      3→4	  6	      'b'	     {a, c, b}	       3	    'b' lặp → xóa 'b' cũ
// 8	      4→5	  7	      'b'	     {a, c, b}	       3	    'b' lặp lại nữa → xóa tiếp

// 💡 Ý tưởng thuật toán (Sliding Window):
// 1.Duyệt chuỗi từ trái sang phải.

// 2.Sử dụng một cửa sổ trượt (window) với hai con trỏ left và right để giữ chuỗi con hiện tại không có ký tự lặp.

// 3.Dùng một set hoặc dict để theo dõi các ký tự đã gặp trong cửa sổ đó.

// 4.Mỗi lần gặp ký tự lặp, ta dịch left sang phải cho đến khi không còn trùng lặp, xóa phần tử cũ.

// 5.Cập nhật độ dài lớn nhất (max_length).


// ✅ Ví dụ: s = "abcabcbb"
// i	s[i]	start	charIndex	maxLength	Giải thích
// 0	 a	      0	      a = 1	       1	      a mới
// 1	 b	      0	      b = 2	       2	      ab
// 2	 c	      0	      c = 3	       3	      abc
// 3	 a	      0 → 1	  a = 4	       3	      gặp a (đã ở index 0), nên start = 1
// 4	 b	      1 → 2	  b = 5	       3	      gặp b (ở index 1), nên start = 2
// 5	 c	      2 → 3	  c = 6	       3	      gặp c
// 6	 b	      3	      b = 7	       3	      ok
// 7	 b	      3 → 7	  b = 8	       3	      gặp b ở 6, update start


