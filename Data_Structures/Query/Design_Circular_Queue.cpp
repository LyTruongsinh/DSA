#include <iostream>
using namespace std;
struct Queue
{
    int value;
    Queue *next;
    Queue(int x) : value(x), next(NULL) {};
};
class MyCircularQueue
{
public:
    int size;
    int frontIndex;
    Queue *font;
    Queue *rear;
    MyCircularQueue(int k) : size(k), font(NULL), rear(NULL), frontIndex(0) {};

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        if (font == NULL)
        {
            font = new Queue(value);
            rear = font;
            frontIndex++;
            return true;
        }
        else
        {
            Queue *tmp = new Queue(value);
            rear->next = tmp;
            tmp->next = font;
            rear = tmp;
            frontIndex++;
            return true;
        }
    }

    bool deQueue()
    {
        if (isEmpty()) return false;
        if(font == rear) {
            delete font;
            font = rear = nullptr;
            return true;
        }
        else {
            Queue* tmp = font;
            rear->next = font->next;
            font = font->next;
            delete tmp;
            return true;
        }
        return true;
    }

    int Front()
    {
        if(isEmpty()) return -1;
        return font->value;
    }

    int Rear()
    {
        if(isEmpty()) return -1;
        return rear->value;
    }


    bool isFull()
    {
        return frontIndex == size;
    }

    bool isEmpty() {
        return frontIndex <= 0;
    }
    void print(Queue *font)
    {
        Queue *tmp = font;
        int count = 0;
        while (tmp != NULL && count < frontIndex)
        {
            cout << tmp->value << " ";
            tmp = tmp->next;
            count++;
        }
    }
};
int main()
{
    MyCircularQueue circularQueue(5);
    cout << circularQueue.enQueue(6) << endl;
    cout << circularQueue.enQueue(2) << endl;
    circularQueue.print(circularQueue.font);
    return 0;
}