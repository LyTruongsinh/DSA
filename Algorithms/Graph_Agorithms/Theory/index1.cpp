#include <iostream>
using namespace std;
// Đơn đồ thị vô hướng hai định chỉ có 1 cạnh nối nhau 
// Đa đồ thị vô hướng hai định có nhiều cạnh nối với nhau
// Gỉa đồ thị vô hướng cạnh có đỉnh đầu và cuối giống nhau

// Đơn đồ thị có hướng đi từ đỉnh này sang đỉnh khác chỉ có 1 cạnh như nó có chiều đi giữa hai đỉnh 
// Đa đồ thị có hướng giữa hai định có nhiều cạnh nhưng các cạnh có hướng
// Đỉnh kề ví dụ A----B
// Cạnh liên thuộc ví dụ cạnh AB là cạnh liên thuộc 2 đỉnh kề AB

// Bậc của đỉnh ở trên đồ thị A-----B------C // chỉ áp dụng cho vô hướng
//                                  |
//                                  D
// A có bậc là 1, B có bậc là 3, C có bậc là 1, D có bậc là 1
// Định lý khi tồn tại cạnh AB thì nó sẽ làm tăng bậc của định A và B lên 1 đơn vị => số cạnh = 1/2 tổng tất bậc của tất cả các định trên đồ thị

// Bán bậc ra và bán bậc vào của đồ thị có hướng 
// Định lý nếu tồn tại 1 cạnh AB thì tăng tổng của bán bậc ra lên 1 và bán bậc vào lên 1 => tổng bán bậc ra = bán bậc vào = số cạnh

// Đướng đi 
// chu trình là đường đi nhưng điểm đầu trùn điểm cuối các cạnh phải phân biệt với nhau
// chu trình đơn

// liên thông một đồ thị được gọi là liên thông nếu giữa hai đỉnh bất kỳ luôn có đường đi ( chỉ tồn tại trên đồ thị vô hướng)
// trong trường hợp ko liên thông nó sẽ sinh ra cái gọi là thành phần liên thông (chỉ tồn tại trên đồ thị vô hướng)

// Liên thông mạnh (có hướng) nếu giữa hai đỉnh bất kỳ luôn có đường đi
// Liên thông yếu nếu đồ thị vô hướng của nó là liên thông


// Cách biểu biễn
// Ma trận kề 
// Danh sách cạnh
// Danh sách kề (tối ưu nhất)
// Chuyển đổi các cách biểu diễn
int main() {

}