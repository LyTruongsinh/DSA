#include <iostream>
using namespace std;
class MyString {
    char* str;
    int len;
    public:
    MyString();
    MyString(const char*);
    MyString(const MyString&);
    ~MyString();
    MyString operator=(const MyString&);
    MyString operator=(const char*);
    MyString operator+=(const MyString&);

    char& operator[] (unsigned int index);
    const char& operator[] (unsigned int index) const;

    int size();
    MyString lower() const;
    MyString upper() const;
    friend ostream& operator<< (ostream&, const MyString&);

    // Cac toan tu so sanh
    friend bool operator< (const MyString&, const MyString& );
    friend bool operator> (const MyString&, const MyString& );
    friend bool operator<= (const MyString&, const MyString& );
    friend bool operator>= (const MyString&, const MyString& );
    friend bool operator== (const MyString&, const MyString& );
    friend bool operator!= (const MyString&, const MyString& );
};
MyString::MyString() : 