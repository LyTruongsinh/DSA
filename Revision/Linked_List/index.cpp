#include <iostream>
using namespace std;
class LinkedList
{
private:
    int data;
    LinkedList *next;

public:
    LinkedList(int x) : data(x), next(nullptr) {}
    int size() const;
    void insert(LinkedList *&head, int x, int pos);
    void remove(LinkedList *&head, int pos);
    int find(int x);
    int find_middle_node();
    void print();
    LinkedList *reverse(LinkedList *&head);
    void sort();
    LinkedList* merge_two_sort_list(LinkedList *head, LinkedList *other);
    void remove_duplicates(LinkedList *&head);
};
void LinkedList::print()
{
    LinkedList *temp = this;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int LinkedList::size() const
{
    int count = 0;
    const LinkedList *temp = this;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void LinkedList::insert(LinkedList *&head, int x, int pos)
{
    LinkedList *newNode = new LinkedList(x); // tạo node mới
    if (pos == 1) // nếu vị trí là 1
    {
        newNode->next = head; // cho node mới trỏ vào head
        head = newNode; // cập nhật head là node mới
        return;
    }
    else // nếu ko phải vị trí 1
    {
        if (pos == head->size() + 1) // vị trí size + 1
        {
            // thêm vào cuối danh sách
            // duyệt đến cuối danh sách
            LinkedList *temp = head; 
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        else // ko phải vị trí đầu cũng ko phải vị trí cuối
        {
            LinkedList *temp = head;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}
void LinkedList::remove(LinkedList *&head, int pos)
{
    if (pos < 1 || pos > size()) // nếu vị trí ngoài danh sách
    {
        cout << "Indataid position" << endl;
        return;
    }
    LinkedList *temp = head;
    if (pos == 1) // ví trí 1
    {
        head = head->next;
        delete temp;
        return;
    }
    else // ví trí giữa
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        LinkedList *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
}
int LinkedList::find(int x)
{
    LinkedList *temp = this;
    int pos = 1;
    while (temp != nullptr)
    {
        if (temp->data == x)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1; // Not found
}
int LinkedList::find_middle_node()
{
    LinkedList *temp = this;
    if (this->size() % 2 == 0) // nếu chẵn 
    {
        int mid = this->size() / 2;
        for (int i = 1; i < mid; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    else // nếu lẻ 
    {
        int mid = this->size() / 2;
        for (int i = 1; i <= mid; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
}
LinkedList *LinkedList::reverse(LinkedList *&head)
{
    if (head->size() == 1 || head->size() == 0) // nếu chỉ có 1 phần tử
    {
        return head;
    }
    else if (head->size() % 2 == 0) // nếu số phần tử chẵn
    {
        int mid = head->size() / 2; // tìm mid
        LinkedList *temp = head;
        for (int i = 1; i < mid; i++)
        {
            temp = temp->next; // duyệt đến mid
        }
        LinkedList *right = temp->next;
        temp->next = nullptr; // Split the list into two halves
        LinkedList *left = head;
        LinkedList *rightHead = LinkedList::reverse(right);
        LinkedList *leftHead = LinkedList::reverse(left);
        // ------------ Merge the two halves---------------//
        LinkedList *tmp = rightHead;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = leftHead;
        // ------------ Merge the two halves---------------//
        return rightHead;
    }
    // nếu số phần tử lẻ
    int mid = (head->size() / 2) + 1; // tìm mid
    LinkedList *temp = head;
    for (int i = 1; i < mid - 1; i++)
    {
        temp = temp->next; // duyệt đến mid
    }
    LinkedList *middle = temp->next; // tìm middle
    LinkedList *right = middle->next; // tìm right
    //--------------Split the list into two halves----------------//
    middle->next = nullptr;
    temp->next = nullptr;
    //--------------Split the list into two halves----------------//
    LinkedList *left = head; // tìm left
    LinkedList *rightHead = LinkedList::reverse(right);
    LinkedList *leftHead = LinkedList::reverse(left);
    // ------------ Merge the two halves---------------//
    LinkedList *tmp = rightHead;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = middle;
    middle->next = leftHead;
    // ------------ Merge the two halves---------------//
    return rightHead;
}
void LinkedList::sort()
{
    LinkedList *temp = this;
    for (int i = 0; i < this->size() - 1; i++)
    {
        for (int j = i + 1; j < this->size() - 1; j++)
        {
            if (temp->data > temp->next->data)
            {
                swap(temp->data, temp->next->data);
            }
            temp = temp->next;
        }
    }
}
void LinkedList::remove_duplicates(LinkedList *&head)
{
    LinkedList *current = head;
    while (current != nullptr && current->next != nullptr)
    {
        if (current->data == current->next->data)
        {
            LinkedList *toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        }
        else
        {
            current = current->next;
        }
    }
}
LinkedList *LinkedList::merge_two_sort_list(LinkedList *head, LinkedList *other)
{
    LinkedList dummy(0); // Node giả
    LinkedList *tail = &dummy;
    while (head && other)
    {
        if (head->data < other->data)
        {
            tail->next = head;
            head = head->next;
        }
        else
        {
            tail->next = other;
            other = other->next;
        }
        tail = tail->next;
    }
    // Nối phần còn lại
    if (head)
        tail->next = head;
    else
        tail->next = other;
    return dummy.next; // Trả về đầu danh sách đã merge
}
int main()
{
    LinkedList *list = new LinkedList(1);
    cout << "Size of the linked list: " << list->size() << endl;
    list->insert(list, 2, 2);
    list->insert(list, 3, 3);
    list->insert(list, 4, 1);
    list->insert(list, 4, 1);
    list->insert(list, 4, 1);
    list->insert(list, 3, 1);
    list->insert(list, 2, 2);
    list->insert(list, 2, 2);
    cout << "Linked list after insertions: ";
    list->print();
    list->remove(list, 2);
    cout << "Linked list after removing element at position 2: ";
    list->print();
    cout << "Finding element 3 in the linked list: " << list->find(3) << endl;
    cout << "Finding middle node of the linked list: " << list->find_middle_node() << endl;
    cout << "Reversing the linked list: ";
    LinkedList *reversedList = list->reverse(list);
    reversedList->print();
    cout << "Removing duplicates from the linked list: ";
    reversedList->remove_duplicates(reversedList);
    reversedList->print();

    LinkedList *list1 = new LinkedList(1);
    list1->insert(list1, 3, 2);
    list1->insert(list1, 5, 3);

    LinkedList *list2 = new LinkedList(2);
    list2->insert(list2, 4, 2);
    list2->insert(list2, 6, 3);
    list2->insert(list2, 8, 4);
    cout << "Linked list 1: ";
    list1->print();
    cout << "Linked list 2: ";
    list2->print();
    cout << "Merging two sorted linked lists: ";
    LinkedList *mergedList = list1->merge_two_sort_list(list1, list2);
    mergedList->print();
    return 0;
}