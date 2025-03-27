#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int n, m;
int a[10001][1001];
vector<pair<int, int>> adge;
int main() {
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++) {
        string s, num;
        getline(cin, s); 
        stringstream ss(s);
        while(ss >> num) {
            if(stoi(num) > i) {
                adge.push_back({i, stoi(num)});
            }
        }
    }
    for(auto i : adge) {
        cout << i.first << " " << i.second << endl;
    }
}