#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<string> S;
int order[256];

bool compare(const string &a, const string &b) {
    unsigned int len = min(a.size(), b.size());
    for (unsigned int i = 0; i < len; i++) {
        if (a[i] != b[i]) return order[(unsigned char)a[i]] < order[(unsigned char)b[i]];
    }
    return a.size() < b.size(); 
}


void sort(vector<string> &words, const string &alphabet) {
    for (unsigned int i = 0; i < alphabet.size(); i++) order[(unsigned char)alphabet[i]] = i;
    unsigned int n = words.size();
    for (unsigned int i = 0; i < n - 1; i++) {
        for (unsigned int j = 0; j < n - i - 1; j++) {
            if (!compare(words[j], words[j + 1])) {
                swap(words[j], words[j + 1]);
            }
        }
    }
}
void print(const vector<string> &words) {
    for (unsigned int i = 0; i < words.size(); i++){
        cout << words[i] << " ";
    }
    cout << endl;
}
void Generate(const string &str, string cur, unsigned int leg) {
    if (cur.length() == leg) {
        S.push_back(cur);
        return;
    }
    for (unsigned int i = 0; i < str.size(); i++) {
        Generate(str, cur + str[i], leg);
    }
}

int main() {
    string str;
    cin >> str;
    Generate(str, "", 2);
    Generate(str, "", 3);
    sort(S, str);
    print(S);
    return 0;
}
