#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &heap, int n, int i)
{
    int biggest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[biggest])
    {
        biggest = left;
    }
    if (right < n && heap[right] > heap[biggest])
    {
        biggest = right;
    }
    if (biggest != i)
    {
        swap(heap[i], heap[biggest]);
        maxHeapify(heap, n, biggest);
    }
}

void Make_Max_Heap(vector<int> &heap, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(heap, n, i);
    }
}

void printHeap(const vector<int> &heap, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void dequeue(vector<int> &heap, int &n)
{
    if (n <= 0)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    swap(heap[0], heap[n - 1]);
    heap.pop_back();
    n--;
    maxHeapify(heap, n, 0);
}

int main()
{
    vector<int> heap;
    int k;
    cout << "Nhap k : ";
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        if (s == "enqueue")
        {
            int x;cin >> x;
            heap.push_back(x);
            Make_Max_Heap(heap, heap.size());
        }
        if (s == "dequeue") {
            int n = heap.size();
            dequeue(heap, n);
        }
    }
    printHeap(heap, heap.size());
}