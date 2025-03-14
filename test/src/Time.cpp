#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
    int h, m, s;

public:
    // Các constructor với số tham số khác nhau
    Time(int hour = 0, int minute = 0, int second = 0)
    {
        h = hour;
        s = second % 60;
        m = minute + second / 60;
        h += m / 60;
        m = m % 60;
        h = h % 24;
    }
    int hour() const { return h; }
    int minute() const { return m; }
    int second() const { return s; }
    bool operator<(const Time &other) const
    {
        return (h < other.h) || (h == other.h && m < other.m) || (h == other.h && m == other.m && s < other.s);
    }

    bool operator<=(const Time &other) const
    {
        return *this < other || *this == other;
    }

    bool operator>(const Time &other) const
    {
        return other < *this;
    }

    bool operator>=(const Time &other) const
    {
        return *this > other || *this == other;
    }

    bool operator==(const Time &other) const
    {
        return h == other.h && m == other.m && s == other.s;
    }

    bool operator!=(const Time &other) const
    {
        return !(*this == other);
    }

    // Toán tử xuất dữ liệu ra màn hình
    friend ostream &operator<<(ostream &os, const Time &t)
    {
        os << setw(2) << setfill('0') << t.h << ":"
           << setw(2) << setfill('0') << t.m << ":"
           << setw(2) << setfill('0') << t.s;
        return os;
    }
};

// Kiểm tra chương trình
int main()
{
    Time t(2);
    cout << t << endl;

    cout << Time(1, 10) << endl;
    cout << Time(23, 0, 30) << endl;
    cout << (Time(12, 4, 3) < Time(12, 3, 8)) << endl;
    cout << (Time(12, 4, 3) <= Time(12, 3, 8)) << endl;
    cout << (Time(12, 4, 3) > Time(12, 3, 8)) << endl;
    cout << (Time(12, 4, 3) >= Time(12, 3, 8)) << endl;
    cout << (Time(12, 4, 3) == Time(12, 3, 8)) << endl;
    cout << (Time(12, 4, 3) != Time(12, 3, 8)) << endl;

    Time t2(13, 30, 45);
    cout << t2.hour() << " " << t2.minute() << " " << t2.second() << endl;

    cout << endl;
    Time k(2, 70, 80);
    cout << k;

    return 0;
}
