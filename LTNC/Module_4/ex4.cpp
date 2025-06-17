#include <iostream>
using namespace std;
int main()
{
    int socon, sochan;
    cin >> socon >> sochan;
    int socho = (sochan - 2*socon) / 2;
    int soga = socon - socho;
    if(socho*4 + soga*2 != sochan)
    {
        cout << "invalid";
    }
    else {
        cout << "chicken = " << soga << ", " << "dog = " << socho << endl;
    }
}