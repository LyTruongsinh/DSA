#include <iostream>
using namespace std;
#define MAX 100
void minHeapify(int heap[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;  // Vị trí con trái
    int right = 2 * i + 2; // Vị trí con phải
    // Kiểm tra con trái
    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    // Kiểm tra con phải
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    // Nếu smallest thay đổi, hoán đổi và tiếp tục heapify
    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

// Hàm tạo Min Heap từ mảng đầu vào
void buildMinHeap(int heap[], int n)
{
    // Heapify từ nửa cuối cây (các node có con) lên gốc
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(heap, n, i);
    }
}



void insert(int heap[], int x, int &n)
{
    heap[n] = x;
    n++;
    buildMinHeap(heap, n);
}
void delete_Min(int heap[], int &n)
{
    swap(heap[0], heap[n - 1]);
    n--;
    minHeapify(heap, n, 0);
}

void printHeap(int heap[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}
int main()
{
    int minHeap[] = {10, 14, 19, 26, 31, 42, 27, 44, 35, 33};
    int n = sizeof(minHeap) / sizeof(minHeap[0]);
    // Xây dựng Min Heap từ mảng đầu vào
    buildMinHeap(minHeap, n);

    // In ra Min Heap
    printHeap(minHeap, n);
    cout << endl;

    // Insert 8
    cout << "Heap sau khi insert 8" << endl;
    insert(minHeap, 8, n);
    printHeap(minHeap, n);

    // Delete Min
    cout << "Heap sau khi delete Min" << endl;
    delete_Min(minHeap, n);
    printHeap(minHeap, n);
    return 0;
}
