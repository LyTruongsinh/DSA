#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
    void input (const string& pathinput) {;}
    void output (const string& pathoutput) {;}
    void Hcn_Sum_Max () {;}
    private:
    vector<vector<int>> matrix;
};
void Solution::input(const string& pathinput) {
    ifstream file(pathinput);
    if(!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }
    int m, n; file >> m >> n;
    // Cấp phát kích thước cho ma trận
    matrix.resize(m, vector<int>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            file >> matrix[i][j];
        }
    }
    file.close();
}
void Solution::Hcn_Sum_Max() {
    
}
int main() {
    Solution s;
    s.input("input.txt");
    s.Hcn_Sum_Max();
    s.output("output.txt");
    return 0;
} 