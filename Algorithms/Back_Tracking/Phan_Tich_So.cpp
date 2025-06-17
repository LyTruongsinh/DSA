#include <iostream>
#include <vector>
using namespace std;
void printPartition(vector<int> &partition)
{
    for (int i = 0; i < partition.size(); ++i)
    {
        if (i > 0)
            cout << " + ";
        cout << partition[i];
    }
    cout << endl;
}
void partitionNumber(int n, vector<int> &current, int index)
{
    if (n == 0)
    {
        printPartition(current);
        return;
    }
    // thỏa mãn những số nhỏ hơn hoặc bằng số đã được đẩy vào nó lớn hơn số được đẩy vào thì nó sẽ lặp lại
    // ví dụ đẩy vào 3 thì nó chỉ có từ 3 trở xuống nhưng tổng các số tiếp theo khi đẩy vào vẫn phải thỏa mãn tổng của
    // nó = n - 3 = 2 ví dụ đẩy vào 2 thì nó chỉ có từ 2 trở xuống nếu đẩy vào cái lớn > 2 thì nó sẽ lặp lại nhưng tổng
    // các số tiếp theo khi đẩy vào vẫn phải thỏa mãn tổng của nó = n - 2 = 3
    for (int i = index; i >= 1; --i)
    {
        if (i <= n)
        { // những số lớn hơn số cần phân tích thì bỏ qua
            current.push_back(i);
            partitionNumber(n - i, current, i);
            current.pop_back();
        }
    }
}
int main()
{
    int n;
    cout << "Enter a number to partition: ";
    cin >> n;
    vector<int> current;
    cout << "All partitions of " << n << ":\n";
    partitionNumber(n, current, n);
    return 0;
}
// Example: n = 5
// đẩy vào [5] số cần phân tích tiếp theo là số 0 => [5] (in kêt quả)
// đẩy vào [4] số cần phân tích tiếp theo là 1 => [4, 1] (in kêt quả)
// đẩy vào [3] số cần phân tích tiếp theo là 2 => [3]
// với những chỉ số nhỏ hơn hoặc bằng 3 mà vẫn thỏa mãn tổng các số tiếp theo bằng 2
// đẩy vào chỉ số [2] số cần phân tích tiếp theo là 0 được => [3,2] (in kêt quả)
// đẩy vào chỉ số [1] số cẩn phân tích tiếp theo là 1 được => [3,1]
// với những chỉ số nhỏ hơn hoặc bằng 1 màn vẫn thỏa mãn tổng các số tiếp theo bằng 1
// đẩy vào chỉ số [1] số cần phân tích tiếp theo là 0 được => [3,1,1] (in kêt quả)
// đẩy vào chỉ số [2] số cần phân tích tiếp theo là 3 => [2]
// với những chỉ số nhỏ hơn hoặc bằng 2 mà vẫn thoản mãn tổng các số tiếp theo bằng 3
// đẩy vào chỉ số [2] số cần phân tích tiếp theo là 1 được => [2,2]
// với những chỉ số nhỏ hơn hoặc bằng 1 mà vẫn thoản mãn tổng các số tiếp theo bằng 1
// đẩy vào chỉ số [1] số cần phân tích tiếp theo là 0 được => [2,2,1] (in kêt quả)
// đẩy vào chỉ số [1] số cần phân tích tiếp theo là 2 được => [2,1]
// với những chỉ số nhỏ hơn hoặc bằng 1 mà vẫn thoản mãn tổng các số tiếp theo bằng 2
// đẩy vào chỉ số [1] số cần phân tích tiếp theo là 1 được => [2,1,1]
// với những chỉ số nhỏ hơn hoặc bằng 1 mà vẫn thỏa mãn tổng các số tiếp theo bằng 1
// đẩy vào chỉ số [1] số cần phân tích tiếp theo là 0 được => [2,1,1,1] (in kêt quả)