#include <iostream>       // Thư viện nhập xuất cơ bản (cout, cerr)
#include <fstream>        // Thư viện để đọc/ghi file
#include <vector>         // Dùng vector 2 chiều cho ma trận
#include <algorithm>      // Có thể dùng sau để xử lý tìm max
using namespace std;

// Định nghĩa lớp Solution chứa các hàm xử lý
class Solution {
public:
    void input(const string& pathinput);   // Đọc dữ liệu từ file input
    void output(const string& pathoutput); // Ghi kết quả ra file output
    void Hcn_Sum_Max();                    // Tìm hình chữ nhật có tổng lớn nhất

private:
    vector<vector<int>> matrix;            // Ma trận 2 chiều lưu dữ liệu đầu vào
};

// Hàm đọc dữ liệu từ file input
void Solution::input(const string& pathinput) {
    ifstream file(pathinput);              // Mở file
    if(!file.is_open()) {                  // Kiểm tra nếu mở file thất bại
        cerr << "Error opening file" << endl;
        return;
    }

    int m, n;
    file >> m >> n;                        // Đọc số hàng và cột của ma trận

    // Cấp phát kích thước ma trận m x n
    matrix.resize(m, vector<int>(n));

    // Đọc từng phần tử vào ma trận
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            file >> matrix[i][j];
        }
    }

    file.close(); // Đóng file sau khi đọc xong
}

// Hàm xử lý tìm hình chữ nhật có tổng lớn nhất
void Solution::Hcn_Sum_Max() {
    // ⚠️ Hiện tại chưa có nội dung xử lý. 
    // Sau này sẽ cài thuật toán để tìm tổng lớn nhất trong hình chữ nhật con.
}

// Hàm main – nơi chương trình bắt đầu chạy
int main() {
    Solution s;

    s.input("input.txt");      // Gọi hàm đọc dữ liệu từ file input.txt
    s.Hcn_Sum_Max();           // Gọi hàm xử lý (hiện chưa làm gì)
    s.output("output.txt");    // Gọi hàm ghi kết quả ra file output.txt

    return 0;
}
