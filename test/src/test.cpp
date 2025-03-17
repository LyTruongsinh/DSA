#include <iostream>
#define MAX 1000
using namespace std;

int main() {
    int a[MAX][MAX] = {0};
    int m, n;
    cin >> m >> n;
    // Nhập mảng (đúng thứ tự hàng, cột)
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            bool check = true;
            if (i > 1 && a[i][j] <= a[i-1][j]) check = false;       
            if (i < m && a[i][j] <= a[i+1][j]) check = false;        
            if (j > 1 && a[i][j] <= a[i][j-1]) check = false;       
            if (j < n && a[i][j] <= a[i][j+1]) check = false;       
            if (i > 1 && j > 1 && a[i][j] <= a[i-1][j-1]) check = false;  
            if (i > 1 && j < n && a[i][j] <= a[i-1][j+1]) check = false;  
            if (i < m && j > 1 && a[i][j] <= a[i+1][j-1]) check = false;  
            if (i < m && j < n && a[i][j] <= a[i+1][j+1]) check = false;  

            if (check) {
                cout << a[i][j] << " ";
            }
        }
    }

    cout << endl;
    return 0;
}
