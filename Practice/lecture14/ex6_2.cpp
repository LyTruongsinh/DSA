// Đề bài:
// Cho một danh sách học sinh gồm các cặp (id, tên):
// (7,An),(3,Be),(11,Cu),(4,Da),(8,Gi),(16,En),(21,Ba),(5,Go)
// Nhiệm vụ của bạn là:

// Đề xuất một hàm băm (hash function).

// Vẽ bảng băm (hash table) sử dụng hàm băm đã đề xuất, áp dụng cả hai phương pháp xử lý va chạm (collision handling methods).
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    bool isOccupied = false;
};

class HashTableLinearProbing {
    int table_size;
    Student* table;

public:
    HashTableLinearProbing(int size) {
        table_size = size;
        table = new Student[table_size];
    }

    int hashFunction(int key) {
        return key % table_size;
    }

    void insert(Student s) {
        int idx = hashFunction(s.id);
        int startIdx = idx;

        while (table[idx].isOccupied) {
            idx = (idx + 1) % table_size;
            if (idx == startIdx) {
                cout << "Hash table full, cannot insert\n";
                return;
            }
        }

        table[idx] = s;
        table[idx].isOccupied = true;
    }

    void display() {
        for (int i = 0; i < table_size; i++) {
            cout << i << ": ";
            if (table[i].isOccupied) {
                cout << "(" << table[i].id << "," << table[i].name << ")";
            } else {
                cout << "Empty";
            }
            cout << "\n";
        }
    }
};

int main() {
    Student students[] = {
        {7, "An"}, {3, "Be"}, {11, "Cu"}, {4, "Da"},
        {8, "Gi"}, {16, "En"}, {21, "Ba"}, {5, "Go"}
    };

    HashTableLinearProbing ht(7);

    for (auto &s : students) {
        ht.insert(s);
    }

    ht.display();

    return 0;
}
