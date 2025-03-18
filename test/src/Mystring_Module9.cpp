#include <iostream>
#include <cctype>
using namespace std;

class MyString
{
    char *str;
    int len;

public:
    MyString();
    MyString(const char *);
    MyString(const MyString &);
    ~MyString();
    MyString operator=(const MyString &);
    MyString operator=(const char *);
    MyString operator+=(const MyString &);
    char &operator[](unsigned int index);
    const char &operator[](unsigned int index) const;
    int size();
    MyString upper() const;
    MyString lower() const;
    friend ostream &operator<<(ostream &, const MyString &);
    friend MyString operator+(const MyString &, const MyString &);
    friend bool operator<(const MyString &, const MyString &);
    friend bool operator>(const MyString &, const MyString &);
    friend bool operator<=(const MyString &, const MyString &);
    friend bool operator>=(const MyString &, const MyString &);
    friend bool operator==(const MyString &, const MyString &);
    friend bool operator!=(const MyString &, const MyString &);
};

int myStrCmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// Hàm khởi tạo xâu rỗng
MyString::MyString() : str(nullptr), len(0) {}

// Hàm khởi tạo từ một xâu kiểu c-string
MyString::MyString(const char *s)
{
    len = 0;
    while (s[len] != '\0')
        len++;
    str = new char[len + 1];
    for (int i = 0; i < len; i++)
        str[i] = s[i];
    str[len] = '\0';
}

// Hàm khởi tạo sao chép
MyString::MyString(const MyString &other) : len(other.len)
{
    str = new char[len + 1];
    for (int i = 0; i < len; i++)
        str[i] = other.str[i];
    str[len] = '\0';
}

// Hàm huỷ
MyString::~MyString()
{
    delete[] str;
}

// Toán tử gán
MyString MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        delete[] str;
        len = other.len;
        str = new char[len + 1];
        for (int i = 0; i < len; i++)
            str[i] = other.str[i];
        str[len] = '\0';
    }
    return *this;
}

MyString MyString::operator=(const char *s)
{
    delete[] str;
    len = 0;
    while (s[len] != '\0')
        len++;
    str = new char[len + 1];
    for (int i = 0; i < len; i++)
        str[i] = s[i];
    str[len] = '\0';
    return *this;
}

// Toán tử nối xâu rồi gán
MyString MyString::operator+=(const MyString &other)
{
    int newLen = len + other.len;
    char *newStr = new char[newLen + 1];
    for (int i = 0; i < len; i++)
        newStr[i] = str[i];
    for (int i = 0; i < other.len; i++)
        newStr[len + i] = other.str[i];
    newStr[newLen] = '\0';
    delete[] str;
    str = newStr;
    len = newLen;
    return *this;
}

// Toán tử truy cập kí tự
char &MyString::operator[](unsigned int index)
{
    return str[index];
}

const char &MyString::operator[](unsigned int index) const
{
    return str[index];
}

// Hàm trả về độ dài của xâu
int MyString::size()
{
    return len;
}

// Hàm chuyển thành chữ hoa
MyString MyString::upper() const
{
    MyString temp(*this);
    for (int i = 0; i < temp.len; i++)
        temp.str[i] = toupper(temp.str[i]);
    return temp;
}

// Hàm chuyển thành chữ thường
MyString MyString::lower() const
{
    MyString temp(*this);
    for (int i = 0; i < temp.len; i++)
        temp.str[i] = tolower(temp.str[i]);
    return temp;
}

// Toán tử xuất
ostream &operator<<(ostream &os, const MyString &s)
{
    os << s.str;
    return os;
}

// Toán tử nối xâu
MyString operator+(const MyString &s1, const MyString &s2)
{
    MyString temp = s1;
    temp += s2;
    return temp;
}

// Các toán tử so sánh
bool operator<(const MyString &s1, const MyString &s2)
{
    return myStrCmp(s1.str, s2.str) < 0;
}

bool operator>(const MyString &s1, const MyString &s2)
{
    return myStrCmp(s1.str, s2.str) > 0;
}

bool operator<=(const MyString &s1, const MyString &s2)
{
    return myStrCmp(s1.str, s2.str) <= 0;
}

bool operator>=(const MyString &s1, const MyString &s2)
{
    return myStrCmp(s1.str, s2.str) >= 0;
}

bool operator==(const MyString &s1, const MyString &s2)
{
    return myStrCmp(s1.str, s2.str) == 0;
}

bool operator!=(const MyString &s1, const MyString &s2)
{
    return myStrCmp(s1.str, s2.str) != 0;
}
int main()
{
    cout << (MyString("abc") != MyString("abd"));
}