#include <iostream>
#include <cmath>    // dùng cho round

// Hàm tính bình phương và trả về con trỏ đến kết quả
double* getSquare(double number) {
    double* result = new double;  // cấp phát động
    *result = number * number;

    // Làm tròn đến 2 chữ số thập phân
    *result = round(*result * 100) / 100;

    return result;
}
int main() {
    double number;
    std::cout << "Nhập số thực: ";
    std::cin >> number;

    double* square = getSquare(number);

    std::cout << "Bình phương (làm tròn 2 chữ số thập phân): " << *square << std::endl;

    delete square; // Giải phóng bộ nhớ

    return 0;
}
