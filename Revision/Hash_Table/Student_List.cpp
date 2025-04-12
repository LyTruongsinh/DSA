#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 100;

struct Student {
    string id;
    string name;
    string className;
    Student* next;
    // Constructor
    Student(string id, string name, string className, Student* next)
        : id(id), name(name), className(className), next(next) {}
    // Destructor
    ~Student() {
        cout << "Destructor called for student: " << id << endl;
    }
};
int hashFunction(const string& id) {
    int hash = 0;
    for (char c : id) {
        hash = (hash * 31 + c) % TABLE_SIZE;
    }
    return hash;
}
Student* hashTable[TABLE_SIZE] = {nullptr};
void insertStudent(string id, string name, string className) {
    int index = hashFunction(id);
    Student* newStudent = new Student{id, name, className, hashTable[index]};
    hashTable[index] = newStudent;

    cout << "✔️ Đã thêm sinh viên " << id << endl;
}
Student* findStudent(const string& id) {
    int index = hashFunction(id);
    Student* current = hashTable[index];
    while (current != nullptr) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
void deleteStudent(const string& id) {
    int index = hashFunction(id);
    Student* current = hashTable[index];
    Student* prev = nullptr;

    while (current != nullptr) {
        if (current->id == id) {
            if (prev == nullptr)
                hashTable[index] = current->next;
            else
                prev->next = current->next;

            delete current;
            cout << "🗑️ Đã xóa sinh viên " << id << endl;
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "❌ Không tìm thấy sinh viên để xóa." << endl;
}
void printAllStudents() {
    cout << "\n📋 Danh sách sinh viên:\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Student* current = hashTable[i];
        while (current != nullptr) {
            cout << "Mã SV: " << current->id
                 << " | Họ tên: " << current->name
                 << " | Lớp: " << current->className << endl;
            current = current->next;
        }
    }
}
int main() {
    insertStudent("SV001", "Nguyen Van A", "CNTT1");
    insertStudent("SV002", "Le Thi B", "CNTT2");

    Student* s = findStudent("SV001");
    if (s != nullptr) {
        cout << "\n🔍 Tìm thấy: " << s->name << " - " << s->className << endl;
    } else {
        cout << "❌ Không tìm thấy sinh viên.\n";
    }

    deleteStudent("SV002");
    printAllStudents();

    return 0;
}

