#include <iostream>
#define MAX 20
using namespace std;

int Bool[MAX] = {0};
char res[MAX];

<<<<<<< Tabnine <<<<<<<
/**//+
 * @brief This function generates all permutations of a given string.//+
 *//+
 * The function uses a recursive approach to generate all permutations of a string.//+
 * It maintains a boolean array 'Bool' to keep track of characters that have already been used in the current permutation.//+
 * The 'res' array is used to store the current permutation.//+
 *//+
 * @param s The input string for which permutations need to be generated.//+
 * @param k The current position in the permutation.//+
 *//+
 * @return This function does not return a value. It prints all the permutations to the console.//+
 *///+
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
>>>>>>> Tabnine >>>>>>>// {"conversationId":"7fd22ce1-17fe-44a5-b727-e998bfb7561e","source":"instruct"}

int main() {
    string s;
    cin >> s;
    permutation(s, 0);
    return 0;
}
