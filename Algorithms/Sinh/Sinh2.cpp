#include <iostream>
#define MAX 20
using namespace std;

int Bool[MAX] = {0};
char res[MAX];

void permutation(string s, int k) {
    if (k == s.size()) {
        cout << res << endl;
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (!Bool[i]) {
            res[k] = s[i];
            Bool[i] = 1;
            permutation(s, k + 1);
            Bool[i] = 0;
        }
    }
}


int main() {
    string s;
    cin >> s;
    permutation(s, 0);
    return 0;
}
