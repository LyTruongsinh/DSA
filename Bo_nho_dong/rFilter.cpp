#include <iostream>
#include <cstring> // chỉ dùng để lấy độ dài chuỗi
using namespace std;
void rFilter(char *s) {
    char *right = s + strlen(s) - 1; // trỏ đến ký tự cuối cùng (không phải '\0')

    while (right >= s && !(
        ('a' <= *right && *right <= 'z') || 
        ('A' <= *right && *right <= 'Z')
    )) {
        *right = '_'; // thay thế bằng '_'
        right--;      // lùi về bên trái
    }
}
// Để test thử:
int main() {
    char s[51];
    cin >> s;
    rFilter(s);
    cout << s << endl;
    return 0;
}
