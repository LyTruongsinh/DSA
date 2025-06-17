#include <iomanip>
#include <iostream>

using namespace std;
class Time
{
  private:
    int h;
    int p;
    int s;

  public:
    Time(int h, int p, int s);
    Time(int h, int p);
    Time(int h);
    friend ostream &operator<<(ostream &os, const Time &f);
    int hour();
    int minute();
    int second();
    // Các toán tử so sánh
    bool operator==(const Time &other) const { return h == other.h && p == other.p && s == other.s; }
    bool operator!=(const Time &other) const { return !(*this == other); }
    bool operator<(const Time &other) const
    {
        if (h != other.h)
            return h < other.h;
        if (p != other.p)
            return p < other.p;
        return s < other.s;
    }
    bool operator>(const Time &other) const { return other < *this; }
    bool operator<=(const Time &other) const { return !(*this > other); }
    bool operator>=(const Time &other) const { return !(*this < other); }
};
Time::Time(int h)
{
    this->h = (h <= 24) ? h : h - 24;
    this->p = 0;
    this->s = 0;
}
Time::Time(int h, int p)
{
    int thua = 0;
    while (p >= 60)
    {
        p -= 60;
        thua++;
    }
    this->h = (h + thua <= 24) ? h + thua : h + thua - 24;
    this->p = p;
}
Time::Time(int h, int p, int s)
{
    int thuas = 0;
    int thuap = 0;
    while (s >= 60)
    {
        s -= 60;
        thuas++;
    }
    p = thuas + p;
    while (p >= 60)
    {
        p -= 60;
        thuap++;
    }
    this->s = s;
    this->p = p;
    this->h = (h + thuap <= 24) ? h + thuap : h + thuap - 24;
}
int Time::hour() { return this->h; }
int Time::minute() { return this->p; }
int Time::second() { return this->s; }
ostream &operator<<(ostream &os, const Time &f)
{
    os << setfill('0') << setw(2) << f.h << ":" << setw(2) << f.p << ":" << setw(2) << f.s << endl;
    return os;
}
int main()
{
    Time t(2);
    cout << t;
}