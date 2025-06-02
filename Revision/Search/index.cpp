#include <iostream>
using namespace std;
bool binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (arr[mid] == x)
            return true;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
int main() {
    int n, x;
    cin >> n >> x;
    int arr[n]; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (binarySearch(arr, n, x)) 
        cout << "YES\n";
    else 
        cout << "NO\n";

    return 0;
}
