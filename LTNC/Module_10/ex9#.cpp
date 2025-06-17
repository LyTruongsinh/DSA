#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
void reverse(char* s)
{
    int len = strlen(s);         // Tính trước độ dài 1 lần
    char* left = s;
    char* right = s + len - 1;

    while (left < right)
    {
        swap(*left, *right);  // hoặc dùng hàm tự viết nếu không có std::swap
        left++;
        right--;
    }
}
int main()
{
    char* s = new char[5];
    for(int i = 0; i < 5; i++)
    {
        cin >> s[i];
    }
    s[5] = '\0';
    reverse (s);
    for(int i = 0; i < strlen(s); i++)
    {
        cout << s[i];
    }
}