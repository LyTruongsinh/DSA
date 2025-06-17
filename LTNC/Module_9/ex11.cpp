#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
class BigInt
{
    string value;
    int sign;

  public:
    // Hàm khởi tạo số nguyên lớn
    BigInt();
    BigInt(const char *);
    BigInt(int);
    BigInt(const BigInt &);
    // Toán tử in ra màn hình
    friend ostream &operator<<(ostream &, const BigInt &);
    // Toán tử gán
    BigInt &operator=(int);
    BigInt &operator=(const char *);
    BigInt &operator=(const BigInt &);
    // Toán tử cộng
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, int);
    friend BigInt operator+(int, const BigInt &);
    // Toán tử trừ
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, int);
    friend BigInt operator-(int, const BigInt &);
    // Toán tử cộng rồi gán
    BigInt &operator+=(int);
    BigInt &operator+=(const BigInt &);
    // Toán tử trừ rồi gán
    BigInt &operator-=(int);
    BigInt &operator-=(const BigInt &);
};
BigInt::BigInt()
{
    this->value = "";
    this->sign = 1;
}
BigInt::BigInt(const char *num)
{
    int len = strlen(num);
    this->value = (num[0] == '-') ? string(num + 1, len - 1) : string(num, len);
    this->sign = (num[0] == '-') ? -1 : 1;
}
BigInt::BigInt(int num)
{
    this->value = to_string(abs(num));
    this->sign = (num >= 0) ? 1 : -1;
}