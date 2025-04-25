#include <iostream>
#include <vector>
using namespace std;
void printPartition(vector<int> &partition) {
    for (int i = 0; i < partition.size(); ++i) {
        if (i > 0) cout << " + ";
        cout << partition[i];
    }
    cout << endl;
}
void partitionNumber(int n, vector<int> &current) {
    if (n == 0) {
        printPartition(current);
        return;
    }
    for (int i = n; i >= 1; --i) {
        current.push_back(i);
        partitionNumber(n - i, current);  // Giảm dần để tránh trùng lặp
        current.pop_back();
    }
}
int main() {
    int n;
    cout << "Enter a number to partition: ";
    cin >> n;
    vector<int> current;
    cout << "All partitions of " << n << ":\n";
    partitionNumber(n, current);
    return 0;
}
