#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // Để dùng std::swap

using namespace std;

class Solution {
private:
    vector<int> numbers;

public:
    void input(const string& pathin);
    void sortNumbers();
    void output(const string& pathout);
};

// Đọc dữ liệu từ file
void Solution::input(const string& pathin) {
    ifstream inputfile(pathin);
    if (!inputfile) {
        cerr << "Error: Cannot open file " << pathin << endl;
        return;
    }
    
    int num;
    while (inputfile >> num) {
        numbers.push_back(num);
    }
    
    inputfile.close();
}

// Sắp xếp Bubble Sort (có thể thay bằng sort của STL)
void Solution::sortNumbers() {
    for (size_t i = 0; i < numbers.size() - 1; i++) {
        for (size_t j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] > numbers[j]) {
                swap(numbers[i], numbers[j]); // Dùng std::swap()
            }
        }
    }
}

// Ghi kết quả ra file
void Solution::output(const string& pathout) {
    ofstream outputfile(pathout);
    if (!outputfile) {
        cerr << "Error: Cannot write to file " << pathout << endl;
        return;
    }
    
    for (size_t i = 0; i < numbers.size(); i++) {
        if (i > 0) outputfile << " ";
        outputfile << numbers[i];
    }
    
    outputfile.close();
}

int main() {
    Solution s;
    s.input("input.txt");
    s.sortNumbers();
    s.output("numbers.sorted");

    cout << "Sorting completed! Check 'numbers.sorted'.\n";
    return 0;
}
