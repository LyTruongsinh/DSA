#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX;
    int max_profit = 0;

    for (int price : prices) {
        if (price < min_price) {
            min_price = price; // Update the lowest price so far
        } else if (price - min_price > max_profit) {
            max_profit = price - min_price; // Update the maximum profit
        }
    }

    return max_profit;
}

int main() {
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};

    cout << "Max Profit (Example 1): " << maxProfit(prices1) << endl; // Output: 5
    cout << "Max Profit (Example 2): " << maxProfit(prices2) << endl; // Output: 0

    return 0;
}
