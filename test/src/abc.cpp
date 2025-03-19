#include <iostream>

using namespace std;

const int MAX = 50; 

int main() {
    int N;
    cin >> N;

    if (N % 2 == 0 || N <= 0 || N > MAX) {
        cout << "N phải là số nguyên dương lẻ và không vượt quá " << MAX << "!";
        return 1;
    }

    int mS[MAX][MAX] = {0}; 

    int i = 0, j = N / 2; 

    for (int num = 1; num <= N * N; num++) {
        mS[i][j] = num; 

        
        int new_i = (i - 1 + N) % N;
        int new_j = (j + 1) % N;

       
        if (mS[new_i][new_j] != 0) {
            i = (i + 1) % N;
        } else {
            i = new_i;
            j = new_j;
        }
    }

   
    int row = N / 2;
    for (int j = 0; j < N; j++) {
        cout << mS[row][j] << " ";
    }

    return 0;
}
