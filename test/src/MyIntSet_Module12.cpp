#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class MyIntSet {
   public:
    MyIntSet() : num(0) {}

    MyIntSet(int a[], int n) {
        if (n > MAX_SIZE)
            num = MAX_SIZE;
        else
            num = n;
        for (int i = 0; i < num; i++) elements[i] = a[i];
    }

    bool insertVal(int v);
    bool eraseVal(int v);
    void clearAll();
    bool findVal(int v) const;
    bool isEmpty() const;
    int getSize() const;
    const int* getBeginPtr() const;
    const int* getEndPtr() const;

   private:
    static const int MAX_SIZE = 1000;
    int elements[MAX_SIZE];
    int num;  // count real values in this set
};
bool MyIntSet::insertVal(int v) {
    if (num >= MAX_SIZE) return false;
    for (int i = 0; i < num; i++) {
        if (elements[i] == v) return false;
    }
    elements[num] = v;
    num++;
    return true;
}
bool MyIntSet::eraseVal(int v) {
    for (int i = 0; i < num; i++) {
        if (elements[i] == v) {
            for (int* p = elements + i; p < elements + num - 1; p++) {
                *p = *(p + 1);
            }
            num--;
            return true;
        }
    }
    return false;
}

void MyIntSet::clearAll() {
    for (int* p = elements; p < elements + num; p++) {
        *p = 0;
    }
    num = 0;
}
bool MyIntSet::findVal(int v) const {
    for (const int* p = elements; p < elements + num; p++) {
        if (*p == v) return true;
    }
    return false;
}

bool MyIntSet::isEmpty() const { return num == 0; }
int MyIntSet::getSize() const { return num; }
const int* MyIntSet::getBeginPtr() const { return elements; }
const int* MyIntSet::getEndPtr() const { return elements + num - 1; }
int main() {
    MyIntSet is1;
    is1.eraseVal(6);
    is1.insertVal(3);
    is1.insertVal(3);
    is1.insertVal(5);
    vector<int> res;
    for (auto p = is1.getBeginPtr(); p <= is1.getEndPtr(); p++) {
        res.push_back(*p);
    }
    sort(res.begin(), res.end());
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
}