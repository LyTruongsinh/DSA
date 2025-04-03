// Sinh tổ hợp chập K
#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<vector<int>> res;
vector<int> a;
void Gen_K_Combination(int start, vector<int> &a)
{
    if(a.size() == k ) {
        res.push_back(a);
        return;
    }
    for(int i = start; i <= n; i++) {
        a.push_back(i);
        Gen_K_Combination(i + 1, a);
        a.pop_back();
    }
}
int main()
{
    cin >> n >> k;
    Gen_K_Combination(1,a);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

