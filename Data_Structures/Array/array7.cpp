#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int x;
    cin >> x;
    double sum = 1.0;
    double oldsum = 0.0;
    int i = 1;
    double giaithua = 1.0;

    while (sum - oldsum > 0.001) {
        double mu = pow(x, i);
        giaithua = giaithua * i;
        i++;
        oldsum = sum;
        sum = sum + mu / giaithua;
    }
    sum = round(sum * 10000) / 10000.0;
    cout << fixed << setprecision(4) << sum << endl;

    return 0;
}
