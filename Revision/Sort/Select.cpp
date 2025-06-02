#include <iostream>
#include <vector>
using namespace std;
void Select(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int min_idx = i;
        for(int j = i + 1; j < n; j++)
        {
            if(A[j] < A[min_idx])
            {
                min_idx = j;
            }
        }
        swap(A[i], A[min_idx]);
    }
}
int main() {
    int A[] = {64, 25, 12, 22, 11};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Mang ban dau: ";
    print_array(A, n);

    selection_sort(A, n);

    cout << "Mang sau khi sap xep tang dan: ";
    print_array(A, n);

    return 0;
}