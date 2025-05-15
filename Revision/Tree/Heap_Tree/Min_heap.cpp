#include <iostream>
#include <algorithm>
using namespace std;
class MinHeap
{
private:
    int *heap;
    int capacity; // Maximum capacity of the heap
    int size; // Current number of elements in the heap
    void heapifyUp(int index);
    void heapifyDown(int index);
public:
    MinHeap(int capacity) : capacity(capacity), size(0) {
        heap = new int[capacity];
    }
    ~MinHeap() {
        delete[] heap;
    }
    void insert(int value);
    int extractMin();
    void deleteValue(int value);
    int getMin();
    int getMax();
    bool isEmpty();
    void printHeap();
};
void MinHeap::heapifyUp(int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;
        if(heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}
void MinHeap::heapifyDown(int index) {
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;
    
        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
    
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }    
}
void MinHeap::insert(int value) {
    if (size < capacity) {
        heap[size] = value;
        heapifyUp(size);
        size++;
    } else {
        cout << "Heap is full!" << endl;
    }
}
int MinHeap::extractMin() {
    if (size > 0) {
        int minValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return minValue;
    } else {
        cout << "Heap is empty!" << endl;
        return -1; // Return a sentinel value to indicate the heap is empty
    }
}
int MinHeap::getMin() {
    if (size > 0) {
        return heap[0];
    } else {
        cout << "Heap is empty!" << endl;
        return -1; // Return a sentinel value to indicate the heap is empty
    }
}
int MinHeap::getMax() {
    if (size > 0) {
        int maxValue = heap[0];
        for (int i = 1; i < size; i++) {
            maxValue = max(maxValue, heap[i]);
        }
        return maxValue;
    } else {
        cout << "Heap is empty!" << endl;
        return -1; // Return a sentinel value to indicate the heap is empty
    }
}
bool MinHeap::isEmpty() {
    return size == 0;
}
void MinHeap::deleteValue(int value) {
    for(int i = 0; i < size; i++) {
        if(heap[i] == value) {
            heap[i] = heap[size - 1];
            size--;
            heapifyDown(i);
            return;
        }
    }
}
void MinHeap::printHeap() {
    for(int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}
int main() {
    MinHeap minHeap(10);
    minHeap.insert(3);
    minHeap.insert(1);
    minHeap.insert(4);
    minHeap.insert(2);
    minHeap.insert(5);
    
    cout << "Min Heap: ";
    minHeap.printHeap();
    
    cout << "Extracted Min: " << minHeap.extractMin() << endl;
    
    cout << "Min Heap after extraction: ";
    minHeap.printHeap();
    
    cout << "Minimum value in heap: " << minHeap.getMin() << endl;
    
    return 0;
}