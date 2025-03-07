#include <iostream>
#define MAX 100
using namespace std;
void minHeapify(int heap[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (heap[left] < heap[smallest] && left < n)
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}
void buildMinHeap(int heap[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(heap, n, i);
    }
}
void printHeap(int heap[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}


void insert(int heap[], int x, int &n)
{
    heap[n] = x;
    n++;
    buildMinHeap(heap, n);
}

void delete_Min_Heap(int heap[], int &n, int val) {
    for(int i = 0; i < n; i++) {
        if(heap[i] == val) {
            heap[i] = heap[--n];
            minHeapify(heap, n, i);
            break;
        }
    }
}

int main()
{
    int minHeap[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    int n = sizeof(minHeap) / sizeof(minHeap[0]);
    buildMinHeap(minHeap, n);
    printHeap(minHeap, n);
    cout << endl; 

    cout << "Heap tree after inserting 14, 0, 35 là :";
    insert(minHeap, 14, n);
    insert(minHeap, 0, n);
    insert(minHeap, 35, n);
    printHeap(minHeap, n);
    cout << endl;


    cout << "Heap tree after deleting 6, 13, 35 là :";
    delete_Min_Heap(minHeap, n, 6);
    delete_Min_Heap(minHeap, n, 13);
    delete_Min_Heap(minHeap, n, 35);
    printHeap(minHeap, n);
    cout << endl;

}