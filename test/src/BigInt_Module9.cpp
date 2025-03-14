#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
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

// Toán tử in ra màn hình
ostream &operator<<(ostream &os, const BigInt &num)
{
    if (num.sign == -1)
        os << "-";
    os << num.value;
    return os;
}














string addStrings(string num1, string num2)
{
    string result = "";
    int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}


string subtractStrings(const string& num1, const string& num2) {
    string result;
    int borrow = 0, diff;
    int len1 = num1.size(), len2 = num2.size();
    for (int i = 0; i < len1; i++) {
        int digit1 = num1[len1 - 1 - i] - '0';
        int digit2 = (i < len2) ? num2[len2 - 1 - i] - '0' : 0;
        diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }
    while (result.size() > 1 && result.back() == '0')
        result.pop_back();
    reverse(result.begin(), result.end());
    return result;
}














// Hàm khởi tạo
BigInt::BigInt() : value("0"), sign(1) {};
BigInt::BigInt(const char *num)
{
    int len = strlen(num);
    if (num[0] == '-')
    {
        sign = -1;
        value = string(num + 1, len - 1);
    }
    else
    {
        sign = 1;
        value = string(num, len);
    }
}
BigInt::BigInt(int num)
{
    this->value = to_string(abs(num));
    this->sign = (num >= 0) ? 1 : -1;
}

BigInt::BigInt(const BigInt &other)
{
    sign = other.sign;
    value = other.value;
}

// // Toán tử gán
BigInt &BigInt::operator=(int num)
{
    this->sign = (num >= 0) ? 1 : -1;
    this->value = to_string(abs(num));
    return *this;
}

BigInt &BigInt::operator=(const BigInt &num)
{
    this->value = num.value;
    this->sign = num.sign;
    return *this;
}

BigInt &BigInt::operator=(const char *num)
{
    int len = strlen(num);
    if (num[0] == '-')
    {
        this->sign = -1;
        this->value = string(num + 1, len - 1);
    }
    else
    {
        this->sign = 1;
        this->value = string(num, len);
    }
    return *this;
}

// Toán tử cộng
BigInt operator+(const BigInt &num, const BigInt &other)
{
    BigInt result;
    if (num.sign == 1)
    {
        if (other.sign == -1)
        {
            int S = stoll(num.value) - stoll(other.value);
            if (S < 0)
            {
                result.sign = -1;
                result.value = to_string(abs(S));
            }
            else
            {
                result.sign = 1;
                result.value = to_string(S);
            }
        }
        else
        {
            int S = stoll(num.value) + stoll(other.value);
            result.sign = num.sign;
            result.value = to_string(S);
        }
    }
    else
    {
        if (other.sign == 1)
        {
            int S = stoll(other.value) - stoll(num.value);
            if (S < 0)
            {
                result.sign = -1;
                result.value = to_string(abs(S));
            }
            else
            {
                result.sign = 1;
                result.value = to_string(S);
            }
        }
        else
        {
            int S = stoll(other.value) + stoll(num.value);
            result.sign = num.sign;
            result.value = to_string(S);
        }
    }
    return result;
}

BigInt operator+(const BigInt &num, int other)
{
    BigInt result;
    if (num.sign == 1)
    {
        int S = stoll(num.value) + other;
        if (S < 0)
        {
            result.sign = -1;
            result.value = to_string(abs(S));
        }
        else
        {
            result.sign = 1;
            result.value = to_string(S);
        }
    }
    else
    {
        int S = other - stoll(num.value);
        if (S < 0)
        {
            result.sign = -1;
            result.value = to_string(abs(S));
        }
        else
        {
            result.sign = 1;
            result.value = to_string(S);
        }
    }
    return result;
}

BigInt operator+(int num, const BigInt &other)
{
    BigInt result;
    if (other.sign == 1)
    {
        int S = num + stoll(other.value);
        if (S < 0)
        {
            result.sign = -1;
            result.value = to_string(abs(S));
        }
        else
        {
            result.sign = 1;
            result.value = to_string(S);
        }
    }
    else
    {
        int S = num - stoll(other.value);
        if (S < 0)
        {
            result.sign = -1;
            result.value = to_string(abs(S));
        }
        else
        {
            result.sign = 1;
            result.value = to_string(S);
        }
    }
    return result;
}

// Toán tử trừ
BigInt operator-(const BigInt &num, const BigInt &other)
{
    BigInt result;
    if (num.sign == 1)
    {
        if (other.sign == -1)
        {
            int S = stoll(num.value) + stoll(other.value);
            result.sign = 1;
            result.value = to_string(S);
        }
        else
        {
            int S = stoll(num.value) - stoll(other.value);
            if (S < 0)
            {
                result.sign = -1;
                result.value = to_string(abs(S));
            }
            else
            {
                result.sign = 1;
                result.value = to_string(S);
            }
        }
    }
    else
    {
        if (other.sign == 1)
        {
            int S = stoll(other.value) + stoll(num.value);
            result.sign = -1;
            result.value = to_string(S);
        }
        else
        {
            int S = stoll(other.value) - stoll(num.value);
            if (S < 0)
            {
                result.sign = -1;
                result.value = to_string(abs(S));
            }
            else
            {
                result.sign = 1;
                result.value = to_string(S);
            }
        }
    }
    return result;
}

BigInt operator-(const BigInt &num, int other)
{
    BigInt result;
    if (num.sign == 1)
    {
        int S = stoll(num.value) - other;
        if (S < 0)
        {
            result.sign = -1;
            result.value = to_string(abs(S));
        }
        else
        {
            result.sign = 1;
            result.value = to_string(S);
        }
    }
    else
    {
        int S = -stoll(num.value) - other;
        if (S < 0)
        {
            result.sign = -1;
            result.value = to_string(abs(S));
        }
        else
        {
            result.sign = 1;
            result.value = to_string(S);
        }
    }
    return result;
}

BigInt operator-(int num, const BigInt &other)
{
    BigInt result;
    if (other.sign == 1)
    {
        int S = num - stoll(other.value);
        if (S < 0)
        {
            result.sign = -1;
            result.value = to_string(abs(S));
        }
        else
        {
            result.sign = 1;
            result.value = to_string(S);
        }
    }
    else
    {
        int S = num + stoll(other.value);
        if (S < 0)
        {
            result.sign = -1;
            result.value = to_string(abs(S));
        }
        else
        {
            result.sign = 1;
            result.value = to_string(S);
        }
    }
    return result;
}

// Toán tử cộng rồi gán
BigInt &BigInt::operator+=(int num)
{
    *this = *this + num;
    return *this;
}

BigInt &BigInt::operator+=(const BigInt &num)
{
    *this = *this + num;
    return *this;
}

// Toán tử trừ rồi gán
BigInt &BigInt::operator-=(int num)
{
    *this = *this - num;
    return *this;
}

BigInt &BigInt::operator-=(const BigInt &num)
{
    *this = *this - num;
    return *this;
}
int main()
{
    BigInt a = BigInt("7412391231723192399991239");
    BigInt b = BigInt(21348123);
    cout << b + a << endl;
    return 0;
}