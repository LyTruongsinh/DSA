// Sinh tổ hợp chập K
#include <iostream>
using namespace std;
int n, k, a[100], isfinal;
void Init()
{
    for (int i = 1; i <= k; i++)
    {
        a[i] = i;
    }
}
void Gen_K_Combination()
{
    int i = k; // bắt đầu từ phần tử cuối cùng
    // đi tìm i chưa đạt giá trị max n-k+i
    while (i >= 1 && a[i] == n - k + i)
    {
        --i;
    }
    // nếu tất cả các phần tử đều đạt giá trị n-k+i
    if(i == 0) {
        isfinal = 0;
    }
    else {
        a[i]++;
        for(int j = i + 1;j <= k; ++j) {
            a[j] = a[j - 1] + 1;
        }
    }
}
int main()
{
    cin >> n >> k;
    isfinal = 1; 
    Init();
    while(isfinal) {
        for(int i = 1; i <= k; i++) {
            cout << a[i];
        }
        cout << endl;
        Gen_K_Combination();
    }
    return 0;
}

// Explain
