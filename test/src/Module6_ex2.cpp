#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;
class Solution
{
private:
    int min;
    int max;
public:
    Solution() : min(numeric_limits<int>::max()), max(numeric_limits<int>::min()) {;}
    void findMinMax(const string& filepath) {
        ifstream file(filepath);
        if(!file.is_open()) {
            cout << "Missing failed" << endl;
            return;
        }
        int num;
        bool hasNumber = false;
        while(file >> num) {
            hasNumber = true;
            if(num < min) min = num;
            if(num > max) max = num;
        }
        file.close();
        if(hasNumber) {
            cout << max << " " << min << endl;
        }
        else {
            cout << "Missing failed" << endl;
        }
    }
};
int main() {
    string filePath;
    getline(cin, filePath);
    Solution s;
    s.findMinMax(filePath);
}