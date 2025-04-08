#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Lớp Solution dùng để xử lý bài toán đọc số, sắp xếp, và ghi ra file
class Solution
{
private:
    vector<int> numbers; // Danh sách các số nguyên

public:
    void input(const string &pathin);   // Đọc dữ liệu từ file input
    void sortNumbers();                 // Sắp xếp dãy số
    void output(const string &pathout); // Ghi dữ liệu ra file output
};

// Hàm đọc dữ liệu từ file input
void Solution::input(const string &pathin)
{
    ifstream inputfile(pathin); // Mở file để đọc
    if (!inputfile)
    { // Nếu không mở được file
        cerr << "Error: Cannot open file " << pathin << endl;
        return;
    }

    int num;
    while (inputfile >> num)
    {                           // Đọc từng số nguyên
        numbers.push_back(num); // Thêm vào vector
    }

    inputfile.close(); // Đóng file sau khi đọc
}

// Hàm sắp xếp dãy số bằng thuật toán Bubble Sort
void Solution::sortNumbers()
{
    for (size_t i = 0; i < numbers.size() - 1; i++)
    {
        for (size_t j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[i] > numbers[j])
            {
                swap(numbers[i], numbers[j]); // Hoán đổi nếu không đúng thứ tự
            }
        }
    }
}

// Hàm ghi dữ liệu đã sắp xếp ra file output
void Solution::output(const string &pathout)
{
    ofstream outputfile(pathout); // Mở file để ghi
    if (!outputfile)
    { // Nếu không mở được file
        cerr << "Error: Cannot write to file " << pathout << endl;
        return;
    }

    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (i > 0)
            outputfile << " ";    // Thêm dấu cách giữa các số
        outputfile << numbers[i]; // Ghi từng số ra file
    }

    outputfile.close(); // Đóng file sau khi ghi
}

// Hàm main - nơi chương trình bắt đầu
int main()
{
    Solution s;
    s.input("input.txt");       // Đọc dữ liệu từ file input.txt
    s.sortNumbers();            // Sắp xếp dãy số
    s.output("numbers.sorted"); // Ghi kết quả ra file numbers.sorted

    cout << "Sorting completed! Check 'numbers.sorted'.\n";
    return 0;
}
