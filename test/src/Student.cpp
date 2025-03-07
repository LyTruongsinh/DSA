#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Student
{
    string id;
    string name;
    double gpa;
};
void print(const vector<Student> &student_list)
{
    for (int i = 0; i < student_list.size(); i++)
    {
        cout << student_list[i].id << " " << student_list[i].name << " " << student_list[i].gpa << endl;
    }
}
int find(const vector<Student> &student_list, string id)
{
    for (int i = 0; i < student_list.size(); i++)
    {
        if (student_list[i].id == id)
        {
            return i;
        }
    }
    return -1;
}
vector<Student> top3(const vector<Student> &student_list)
{
    vector<Student> sorted_list = student_list;

    for (int i = 0; i < sorted_list.size(); i++)
    {
        for (int j = i + 1; j < sorted_list.size(); j++)
        {
            if (sorted_list[i].gpa < sorted_list[j].gpa) 
            {
                swap(sorted_list[i], sorted_list[j]);
            }
        }
    }
    vector<Student> result;
    for (int i = 0; i < min(3, (int)sorted_list.size()); i++)
    {
        result.push_back(sorted_list[i]);
    }

    return result;
}

int main()
{
    vector<Student> students = {
        {"1", "Le Quang Duy", 5.5},
        {"2", "Nguyen Tan Dat", 6},
        {"10", "Cao Duy Manh", 3},
        {"4", "Nguyen Van Ngoc", 4.5},
        {"3", "Trieu Dinh Nguyen", 4}};
    vector<Student> top_students = top3(students);
    print(top_students);
    cout << find(students, "10") << endl;
    cout << find(students, "11") << endl;
}