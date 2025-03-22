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

MyString ::MyString()
{
    str = new char[1];
    len = 0;
    str[0] = '\0';
}
MyString ::MyString(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    len = i;
    str = new char[i];
    for (int j = 0; j <= i; j++)
    {
        str[j] = s[j];
    }
}
MyString ::MyString(const MyString &s)
{
    len = s.len;
    str = new char[len + 1];
    for (int i = 0; i <= len; i++)
    {
        str[i] = s.str[i];
    }
}
MyString ::~MyString()
{
    delete[] str;
}
MyString MyString::operator=(const MyString &s)
{
    len = s.len;
    str = new char[len + 1];
    for (int i = 0; i <= len; i++)
    {
        str[i] = s.str[i];
    }
    return *this;
}
MyString MyString::operator=(const char *s)
{
    len = 0;
    while (s[len] != '\0')
        len++;
    str = new char[len + 1];
    for (int i = 0; i <= len; i++)
    {
        str[i] = s[i];
    }
    return *this;
}
MyString MyString::operator+=(const MyString &s)
{
    char *temp = new char[len + s.len + 1];
    for (int i = 0; i < len; i++)
        temp[i] = str[i];
    for (int i = 0; i <= s.len; i++)
        temp[len + i] = s.str[i];
    str = temp;
    len += s.len;
    return *this;
}
char &MyString ::operator[](unsigned int index)
{
    return str[index];
}
const char &MyString ::operator[](unsigned int index) const
{
    return str[index];
}
int MyString ::size()
{
    return len;
}
MyString MyString ::upper() const
{
    MyString result(*this);
    for (int i = 0; i < len; i++)
    {
        if (result.str[i] >= 'a' && result.str[i] <= 'z')
        {
            result.str[i] -= 32;
        }
    }
    return result;
}
MyString MyString ::lower() const
{
    MyString result(*this);
    for (int i = 0; i < len; i++)
    {
        if (result.str[i] >= 'A' && result.str[i] <= 'Z')
        {
            result.str[i] += 32;
        }
    }
    return result;
}
ostream &operator<<(ostream &os, const MyString &s)
{
    os << s.str;
    return os;
}
MyString operator+(const MyString &a, const MyString &b)
{
    MyString result(a);
    result += b;
    return result;
}
bool operator<(const MyString &a, const MyString &b)
{
    int i = 0;
    while (a.str[i] != '\0' && b.str[i] != '\0')
    {
        if (a.str[i] < b.str[i])
            return true;
        if (a.str[i] > b.str[i])
            return false;
        i++;
    }
    return (a.str[i] == '\0' && b.str[i] != '\0');
}
bool operator>(const MyString &a, const MyString &b) { return b < a; }
bool operator<=(const MyString &a, const MyString &b) { return !(b < a); }
bool operator>=(const MyString &a, const MyString &b) { return !(a < b); }
bool operator==(const MyString &a, const MyString &b) { return !(a < b) && !(b < a); }
bool operator!=(const MyString &a, const MyString &b) { return !(a == b); }
int main()
{
    MyString s1("Hello");
    MyString s2("World");
    MyString s3 = s1 + s2;
    MyString s4 = s1.upper();
    MyString s5 = s1.lower();
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    cout << "s5 = " << s5 << endl;
    return 0;
}