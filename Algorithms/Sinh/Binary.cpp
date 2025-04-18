#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;

void helper(vector<int> &tmp, int n) {
    if (tmp.size() == n) {
        result.push_back(tmp);
        return;
    }

    tmp.push_back(0);
    helper(tmp, n);
    tmp.pop_back();

    tmp.push_back(1);
    helper(tmp, n);
    tmp.pop_back();
}

void sinh_binary(int n) {
    vector<int> tmp;
    helper(tmp, n);
}

int main() {
    int n;
    cin >> n;
    sinh_binary(n);

    // In kết quả
    for (const auto& vec : result) {
        for (int bit : vec) {
            cout << bit;
        }
        cout << endl;
    }

    return 0;
}
