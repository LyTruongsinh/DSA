#include <iostream>
using namespace std;
class MyString
{
  private:
    char *str;
    int len;

  public:
    // Hàm khởi tạo xâu rỗng
    MyString();

    // Hàm khởi tạo từ một xâu kiểu c-string
    MyString(const char *);

    // Hàm khởi tạo sao chép từ một thực thể (instance) MyString khác
    MyString(const MyString &);

    // Hàm huỷ
    ~MyString();

    // Toán tử gán
    MyString operator=(const MyString &);
    MyString operator=(const char *);

    // Toán tử nối xâu rồi gán
    MyString operator+=(const MyString &);

    // Toán tử truy cập đến từng kí tự
    char &operator[](unsigned int index);
    const char &operator[](unsigned int index) const;

    // Hàm trả về độ dài của xâu
    int size();

    // Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết hoa
    MyString upper() const;

    // Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết thường
    MyString lower() const;

    // Toán tử để in ra màn hình
    friend ostream &operator<<(ostream &, const MyString &);

    // Toán tử nối xâu
    friend MyString operator+(const MyString &, const MyString &);

    // Các toán tử so sánh
    friend bool operator<(const MyString &, const MyString &);
    friend bool operator>(const MyString &, const MyString &);
    friend bool operator<=(const MyString &, const MyString &);
    friend bool operator>=(const MyString &, const MyString &);
    friend bool operator==(const MyString &, const MyString &);
    friend bool operator!=(const MyString &, const MyString &);
};
MyString::MyString()
{
    this->str = new char[1];
    this->len = 0;
    this->str[0] = '\0';
}
// KHÔNG THỂ GIÁN TRỰC TIẾP this->str = s vì sẽ xảy ra hai trường hợp hai đối tượng cùng trỏ vào 1 địa chỉ
//  MyString a(s);
// MyString b(s); b.str cũng trỏ tới cùng vùng nhớ với a.str (và s)
MyString::MyString(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    this->len = i;
    this->str = new char[i + 1];
    for (int j = 0; j < i; j++)
    {
        this->str[j] = s[j];
    }
    this->str[i] = '\0'; // Kết thúc chuỗi
}
MyString::MyString(const MyString &s)
{
    this->len = s.len;
    this->str = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        this->str[i] = s.str[i];
    }
    this->str[len] = '\0'; // Ký tự kết thúc chuỗi
}
MyString ::~MyString() { delete[] str; }
MyString MyString::operator=(const MyString &s)
{
    this->len = s.len;
    this->str = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        str[i] = s.str[i];
    }
    this->str[len] = '\0';
    return *this;
}
MyString MyString::operator=(const char *s)
{
    if (str != nullptr)
        delete[] str; // Giải phóng vùng nhớ cũ nếu có
    int len = 0;
    while (s[len] != '\0')
        len++;
    this->len = len;
    this->str = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        this->str[i] = s[i];
    }
    this->str[len] = '\0';
    return *this;
}
MyString MyString::operator+=(const MyString &s)
{
    char *newstr = new char[this->len + s.len + 1];
    // sao chép chuỗi gốc
    for (int i = 0; i < this->len; i++)
    {
        newstr[i] = this->str[i];
    }
    // nối chuỗi thêm
    for (int i = 0; i < s.len; i++)
    {
        newstr[this->len + i] = s.str[i];
    }
    newstr[this->len + s.len] = '\0';
    // giải phóng chuỗi cũ
    delete[] this->str;
    this->str = newstr;
    this->len = this->len + s.len;
    return *this;
}

char &MyString::operator[](unsigned int index) { return *(str + index); }
const char &MyString::operator[](unsigned int index) const
{
    return *(str + index);
} // không được phép thay đổi giá trị tại (str + index) trong qua reference const &char
int MyString ::size() { return len; }
MyString MyString::upper() const
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
    // Nếu chuỗi a kết thúc mà b còn ký tự, thì a < b
    if (a.str[i] == '\0' && b.str[i] != '\0')
        return true;
    return false;
}
bool operator>(const MyString &a, const MyString &b) { return b < a; }
bool operator<=(const MyString &a, const MyString &b) { return !(b < a); }
bool operator>=(const MyString &a, const MyString &b) { return !(a < b); }
bool operator==(const MyString &a, const MyString &b) { return !(a < b) && !(b < a); }
bool operator!=(const MyString &a, const MyString &b) { return !(a == b); }