#include <iostream>
using namespace std;
int main()
{
    int day, month, year;
    cin >> day >> month >> year;
    int y0 = year - (14 - month) / 12;
    int x = y0 + y0 / 4 - y0 / 100 + y0 / 400;
    int m0 = month + 12 * ((14 - month) / 12) - 2;
    int dayOfWeek = (day + x + 31 * m0 / 12) % 7;
    switch (dayOfWeek)
    {
    case 0:
        cout << "sun" << endl;
        break;
    case 1:
        cout << "mon" << endl;
        break;
    case 2:
        cout << "tue" << endl;
        break;
    case 3:
        cout << "wed" << endl;
        break;
    case 4:
        cout << "thu" << endl;
        break;
    case 5:
        cout << "fri" << endl;
        break;
    case 6:
        cout << "sat" << endl;
        break;
    }

    return 0;
}