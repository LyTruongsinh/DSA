#include <iostream>
#include <vector>
using namespace std;
void findCombinations(int n, int start, vector<int>& current) {
    if (n == 0) { 
        for (unsigned i = 0; i < current.size(); i++) {
            cout << current[i];
            if (i == current.size() - 1) {
                cout << "\n";
            } else {
                cout << " ";
            }
        }
        return;
    }
    for (int i = start; i <= n; i++) {
        current.push_back(i);
        findCombinations(n - i, i, current);
        current.pop_back();
    }
}
int main() {
    int n;
    cin >> n;
    cout << n << "\n"; 
    vector<int> current;
    findCombinations(n, 1, current);
    return 0;
}
