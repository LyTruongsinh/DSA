#include <iostream>
#define MAX 1001
#include <vector>
using namespace std;
class Solution {
private:
    int N;
    vector<int> arr;
    vector<int> prefix_sum;
public:
    void input() {
        cout << "Nhap so luong phan tu: ";
        cin >> N;
        cout << "Nhap cac phan tu: ";
        prefix_sum.resize(N,1);
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
    }

    int solve() {
        int sum = 0;
        for(int i = 0; i < N; i ++) {
            sum += arr[i];
            arr[i] = sum;
        }
        for(int i = 0; i < N; i++) {
            int j = i + 1;
            int index = arr[i];
            while(j < N) {
                if(j == N - 1) {
                    if(arr[j] - index == arr[i]) {
                        prefix_sum[i]++;
                    }
                    else {
                        prefix_sum[i] = 0;
                    }
                }
                else {
                    if(arr[j] - index == arr[i]) {
                        prefix_sum[i]++;
                        index = arr[j];
                    }
                }
                j++;
            }
        }
        int max = 0;
        for(int i = 0; i < N; i++) {
            cout << prefix_sum[i] << " ";
        }
        return max;
    }
        
};
int main() {
    Solution s;
    s.input();
    cout << s.solve();
    return 0;
}