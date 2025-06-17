#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Student
{
    string id;
    string name;
    double gpa;
};
void print(const vector<Student> &student_list)
{
    for (auto x : student_list)
    {
        cout << x.id << " " << x.name << " " << x.gpa << endl;
    }
}
int find(const vector<Student> &student_list, string id)
{
    for (unsigned int i = 0; i < student_list.size(); i++)
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
    vector<Student> sortbyGpa = student_list;
    sort(sortbyGpa.begin(), sortbyGpa.end(), [](const Student &a, const Student &b) { return a.gpa > b.gpa; });
    return vector<Student>(sortbyGpa.begin(), sortbyGpa.begin() + 3);
}
int main()
{
    vector<Student> students = {{"1", "Le Quang Duy", 5.5},
                                {"2", "Nguyen Tan Dat", 6},
                                {"10", "Cao Duy Manh", 3},
                                {"4", "Nguyen Van Ngoc", 4.5},
                                {"3", "Trieu Dinh Nguyen", 4}};
    vector<Student> top_students = top3(students);
    print(top_students);
    cout << find(students, "10") << endl;
    cout << find(students, "11") << endl;
}