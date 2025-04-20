#include <iostream>
using namespace std;
void reverse(char *s)
{
    if (s == nullptr)
        return;
    char *st = s;
    char *en = s;
    // Di chuyển con trỏ en đến cuối xâu (trước ký tự '\0')
    while (*en != '\0')
    {
        en++;
    } 
    en--; // Quay lại ký tự cuối cùng (không phải '\0')
    // Đổi chỗ các ký tự từ đầu đến cuối
    while (st < en)
    {
        char tmp = *st;
        *st = *en;
        *en = tmp;
        st++;
        en--;
    }
}
int main()
{
    char str[] = "Hello, world!";
    reverse(str);
    cout << "Reversed: " << str << endl; // Output: !dlrow ,olleH
    return 0;
}
