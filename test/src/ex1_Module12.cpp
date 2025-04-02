#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>  // Thêm thư viện để sử dụng fixed và setprecision
using namespace std;

double evaluateFractionString(string fraction) {
    stringstream ss(fraction);
    int a, b;
    char slash;
    
    if (!(ss >> a)) {
        throw "Bad fraction string.";
    }
    
    if (!(ss >> slash) || slash != '/') {
        throw "Bad fraction string.";
    }
    
    if (!(ss >> b) || b <= 0) {
        throw "Bad fraction string.";
    }
    
    // Kiểm tra còn dữ liệu thừa không
    if (!ss.eof()) {
        throw "Bad fraction string.";
    }
    
    return static_cast<double>(a) / b;
}


int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        // fflush(stdin);
        try
        {
            double val = evaluateFractionString(line);
            cout << fixed << setprecision(2) << val << endl;
        }
        catch (const char *str)
        {
            cout << "Caught " << str << endl;
        }
    }
}
