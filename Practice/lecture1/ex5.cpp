#include <iostream>
#include <limits>

using namespace std;

int main() {
    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    
    double min_val = numeric_limits<double>::max();
    double max_val = numeric_limits<double>::lowest();

    
    double numbers[] = {a, b, c, d, e};
    for (double num : numbers) {
        if (num < min_val) min_val = num;
        if (num > max_val) max_val = num;
    }

    cout << min_val + max_val << endl;

    return 0;
}
