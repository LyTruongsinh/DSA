#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;
class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        stringstream ss(path);
        string temp, result = "";

        while (getline(ss, temp, '/')) // lấy phần tử bỏ qua dấu "/"
        {
            if (temp == "." || temp.empty())
                continue; // Bỏ qua "." hoặc phần tử rỗng
            if (temp == "..")
            {
                if (!st.empty())
                    st.pop(); // Quay lại thư mục cha
            }
            else
            {
                st.push(temp); // Lưu thư mục hợp lệ vào stack
            }
        }

        // Xây dựng đường dẫn từ stack
        while (!st.empty())
        {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};
int main()
{
    Solution s;
    cout << s.simplifyPath("/home/a/./b/../../c/") << endl; // Output: /c
    return 0;
}

// Test case /home/a/./b/../../c/
// ------------------------------------
// temp = "home"
// st : "home" 
// temp = "a"
// st : "home" "a"
// temp = "." continue
// temp = "b"
// st : "home" "a" "b"
// temp = ".." st.pop()
// st : "home" "a"
// temp = ".." st.pop()
// st : "home"
// temp = "c"
// st : "home" "c"

// Result : /c
// Result : /home/c
// ------------------------------------