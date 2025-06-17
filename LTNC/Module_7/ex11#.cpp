#include <iostream>
#include <vector>

using namespace std;
void backtrack(int n, int sum, int start, vector<int>& current) {
    if (sum == n) {
        for (int num : current) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n - sum; i++) {
        current.push_back(i);
        backtrack(n, sum + i, i, current); 
        current.pop_back();
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> current;
    backtrack(n, 0, 1, current);
    return 0;
}
