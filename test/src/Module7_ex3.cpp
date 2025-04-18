#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
long long minWating(int N, vector<int> &times) {
    sort(times.begin(), times.end());
    long long totalWatingTimes = 0;
    long long waitingTimes = 0;
    for(int i = 0 ; i < N - 1; i++) {
        waitingTimes += times[i];
        totalWatingTimes += waitingTimes;
    }
    return totalWatingTimes;
}
int main() {
    int N;
    cin >> N;
    vector<int> times(N);
    for(int i = 0; i < N; i++) {
        cin >> times[i];
    }
    cout << minWating(N, times) << endl;
}