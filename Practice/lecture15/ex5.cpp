#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> result;
void SinhNhiPhan(int n) {
    if(result.size() == n) {
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
        }
        cout << endl;
        return;
    }
    for(int i = 0; i <= 1; i++) {
        result.push_back(i);
        SinhNhiPhan(n);
        result.pop_back();
    }
}
int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    SinhNhiPhan(n);
    return 0;
}