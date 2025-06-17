#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
int main() {
  float c, f;
  cin >> c;
  f = c * 1.8 + 32;
  cout << fixed << setprecision(2) << f << endl;
  return 0;
}