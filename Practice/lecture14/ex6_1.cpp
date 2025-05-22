// Đề bài:
// Cho một danh sách học sinh gồm các cặp (id, tên):
// (7,An),(3,Be),(11,Cu),(4,Da),(8,Gi),(16,En),(21,Ba),(5,Go)
// Nhiệm vụ của bạn là:

// Đề xuất một hàm băm (hash function).

// Vẽ bảng băm (hash table) sử dụng hàm băm đã đề xuất, áp dụng cả hai phương pháp xử lý va chạm (collision handling
// methods).

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    int id;
    string name;
    Student *next;

    Student(int _id, const string &_name) : id(_id), name(_name), next(nullptr) {}
};

class HashTableChaining
{
    int table_size;
    vector<Student *> table; // vector các con trỏ đầu linked list

  public:
    HashTableChaining(int size) : table_size(size), table(size, nullptr) {}
    ~HashTableChaining()
    {
        for (int i = 0; i < table_size; i++)
        {
            Student *current = table[i];
            while (current)
            {
                Student *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
    int hashFunction(int key) { return key % table_size; }
    void insert(int id, const string &name)
    {
        int idx = hashFunction(id);
        Student *newNode = new Student(id, name);
        newNode->next = table[idx];
        table[idx] = newNode;
    }
    void display()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << i << ": ";
            Student *current = table[i];
            while (current)
            {
                cout << "(" << current->id << "," << current->name << ") -> ";
                current = current->next;
            }
            cout << "nullptr\n";
        }
    }
};

int main()
{
    HashTableChaining ht(7);

    ht.insert(7, "An");
    ht.insert(3, "Be");
    ht.insert(11, "Cu");
    ht.insert(4, "Da");
    ht.insert(8, "Gi");
    ht.insert(16, "En");
    ht.insert(21, "Ba");
    ht.insert(5, "Go");

    ht.display();

    return 0;
}
