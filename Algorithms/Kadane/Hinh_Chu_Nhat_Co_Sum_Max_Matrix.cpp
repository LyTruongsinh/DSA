#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ifstream fin("matrix.txt");
    ofstream fout("matrix.out");
    int m, n;
    fin >> m >> n;
    vector<vector<int>> matrix(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

    // Đọc ma trận
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            fin >> matrix[i][j];

    // Tính mảng tổng tiền tố
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = matrix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    int max_sum = INT_MIN;
    int r1, c1, r2, c2;

    // Duyệt tất cả các hình chữ nhật (r1, c1) đến (r2, c2)
    for (int i1 = 1; i1 <= m; i1++) {
        for (int j1 = 1; j1 <= n; j1++) {
            for (int i2 = i1; i2 <= m; i2++) {
                for (int j2 = j1; j2 <= n; j2++) {
                    // Tính tổng submatrix (r1, c1) đến (r2, c2)
                    int sum = prefix[i2][j2] - prefix[i1 - 1][j2] - prefix[i2][j1 - 1] + prefix[i1 - 1][j1 - 1];

                    // Cập nhật kết quả nếu tìm thấy tổng lớn hơn
                    if (sum > max_sum) {
                        max_sum = sum;
                        r1 = i1;
                        c1 = j1;
                        r2 = i2;
                        c2 = j2;
                    }
                }
            }
        }
    }

    // Ghi kết quả ra file
    fout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << max_sum << endl;

    fin.close();
    fout.close();
    return 0;
}
