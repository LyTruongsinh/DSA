// Cho một dãy gồm n số nguyên A(1) ... A(n), nhiệm vụ của bạn là:
// Tìm dãy con dài nhất (không nhất thiết phải liên tiếp) sao cho các giá trị trong dãy con này tạo thành một dãy tăng nghiêm ngặt (strictly increasing).
#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int N;
    cin >> N;
    int A[N], dp[N], pr[N];
    for(int i = 0; i < N;) {
        cin >> A[i];
        dp[i] = 1;
        pr[i] = -1;
    }
    int max_l = 1, ei = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i;j++)
        {
            if(A[i] > A[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                pr[i] = j;
            }
        }
        if(dp[i] > max_l)
        {
            max_l = dp[i];
            ei = i;
        }
    }
    // Truy vết lại LIS
    int lis[max_l];
    int index = max_l - 1;
    while (ei != -1) {
        lis[index--] = A[ei];
        ei = pr[ei];
    }
    for (int i = 0; i < max_l; i++) {
        cout << lis[i] << " ";
    }
    return 0;
}

