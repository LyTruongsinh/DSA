#include<iostream>
using namespace std;
class MaxHeap {
private:
    int *heap; // Mảng chứa các phần tử của heap
    int capacity; // Sức chứa tối đa của heap
    int size; // Số lượng phần tử hiện tại trong heap

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }
    void heapifyDown(int index) {
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            //-------------------------tìm phần tử lớn nhất trong 3 phần tử-------------------------//
            if (leftChild < size && heap[leftChild] > heap[largest]) largest = leftChild;
            if (rightChild < size && heap[rightChild] > heap[largest]) largest = rightChild;
            //-------------------------tìm phần tử lớn nhất trong 3 phần tử-------------------------//

            // ------------------------nếu phần tử lớn nhất ko phải giá trị tại index---------------//
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            // ------------------------nếu phần tử lớn nhất ko phải giá trị tại index---------------//
            else {
                break;
            }
        }
    }
public:
    MaxHeap(int capacity) : capacity(capacity), size(0) {
        heap = new int[capacity];
    }
    ~MaxHeap() {
        delete[] heap;
    }
    void insert(int value) {
        if (size < capacity) {
            heap[size] = value;
            heapifyUp(size);
            size++;
        } else {
            cout << "Heap is full!" << endl;
        }
    }
    int extractMax() {
        if (size > 0) {
            int maxValue = heap[0];
            heap[0] = heap[size - 1];
            size--;
            heapifyDown(0);
            return maxValue;
        } else {
            cout << "Heap is empty!" << endl;
            return -1; // Hoặc một giá trị khác để chỉ ra rằng heap rỗng
        }
    }
    void deleteValue(int value) {
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) {
                heap[i] = heap[size - 1];
                size--;
                heapifyDown(i);
                return;
            }
        }
        cout << "Value not found in heap!" << endl;
    }
    int getMax() {
        if (size > 0) {
            return heap[0];
        } else {
            cout << "Heap is empty!" << endl;
            return -1; // Hoặc một giá trị khác để chỉ ra rằng heap rỗng
        }
    }
    bool isEmpty() {
        return size == 0;
    }
    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    MaxHeap maxHeap(10); // Tạo một max heap với sức chứa tối đa là 10
    maxHeap.insert(5);
    maxHeap.insert(10);
    maxHeap.insert(3);
    maxHeap.insert(8);
    maxHeap.insert(15);
    maxHeap.insert(20);


    cout << "Max Heap: ";
    maxHeap.printHeap();

    cout << "Extracted Max: " << maxHeap.extractMax() << endl;
    cout << "Max Heap after extraction: ";
    maxHeap.printHeap();

    return 0;
}