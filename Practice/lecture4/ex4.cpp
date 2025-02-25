#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int ID;
    string name;
    string grade;
    Student *next;

    // Constructor
    Student() : ID(0), name(""), grade(""), next(NULL) {}
    Student(int ID, string name, string grade) : ID(ID), name(name), grade(grade), next(NULL) {}

    // Chèn sinh viên vào danh sách
    void Insert(Student *&List_Student, int ID, string Name, string grade)
    {
        Student *p = new Student(ID, Name, grade);
        if (List_Student == NULL)
        {
            List_Student = p;
        }
        else
        {
            Student *q = List_Student;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
        }
    }

    // Xóa sinh viên khỏi danh sách
    void Delete(Student *&List_Student, int ID)
    {
        if (List_Student == NULL)
            return;

        // Nếu phần tử đầu tiên là phần tử cần xóa
        if (List_Student->ID == ID)
        {
            Student *tmp = List_Student;
            List_Student = List_Student->next;
            delete tmp;
            return;
        }

        // Tìm phần tử cần xóa
        Student *prev = List_Student;
        Student *tmp = List_Student->next;

        while (tmp != NULL)
        {
            if (tmp->ID == ID)
            {
                prev->next = tmp->next;
                delete tmp;
                return;
            }
            prev = tmp;
            tmp = tmp->next;
        }
    }

    // Tìm thông tin sinh viên
    void Infor(Student *List_Student, int ID)
    {
        Student *tmp = List_Student;
        while (tmp != NULL)
        {
            if (tmp->ID == ID)
            {
                cout << "ID: " << tmp->ID << endl;
                cout << "Name: " << tmp->name << endl;
                cout << "Grade: " << tmp->grade << endl;
                return;
            }
            tmp = tmp->next; // Cập nhật con trỏ
        }
        cout << "NA,NA" << endl; // Không tìm thấy sinh viên
    }
};

int main()
{
    Student *List_Student = NULL;
    Student s;
    while (1)
    {
        int choice;
        cout << "----------------------------" << endl;
        cout << "1. Thêm sinh viên " << endl;
        cout << "2. Xóa sinh viên " << endl;
        cout << "3. Tìm sinh viên " << endl;
        cout << "4. EXIT " << endl;
        cout << "----------------------------" << endl;
        cout << "Nhâp lựa chọn: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int ID;
            string name, grade;
            cout << "Nhập ID :";
            cin >> ID;
            cout << "Nhập tên sinh viên :";
            cin >> name;
            cout << "Nhập lớp :";
            cin >> grade;
            s.Insert(List_Student, ID, name, grade);
            break;
        }
        case 2:
        {
            int ID;
            cout << "Nhập ID sinh viên cần xóa: ";
            cin >> ID;
            s.Delete(List_Student, ID);
            break;
        }
        case 3:
        {
            int ID;
            cout << "Nhập ID sinh viên cần tìm: ";
            cin >> ID;
            s.Infor(List_Student, ID);
            break;
        }
        default:
        {
            cout << "EXIT" << endl;
            return 0;
        }
        }
    }

    return 0;
}
