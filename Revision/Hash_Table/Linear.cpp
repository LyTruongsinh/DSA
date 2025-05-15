#include <iostream>
#include <vector>
#define HASH_SIZE 11
using namespace std;

const int EMPTY = -1;
const int DELETED = -2;

int hash_func(int x) {
    return (x * 2 + 5) % HASH_SIZE;
}

void insert(vector<int> &hashTable, int x) {
    int index = hash_func(x);
    int start = index;
    while (hashTable[index] != EMPTY && hashTable[index] != DELETED) {
        index = (index + 1) % HASH_SIZE;
        if (index == start) {
            cout << "Hash table is full, cannot insert " << x << endl;
            return;
        }
    }
    hashTable[index] = x;
}

void print(const vector<int> &hashTable) {
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hashTable[i] == EMPTY)
            cout << "- ";
        else if (hashTable[i] == DELETED)
            cout << "x ";
        else
            cout << hashTable[i] << " ";
    }
    cout << endl;
}

void find(const vector<int> &hashTable, int x) {
    int index = hash_func(x);
    int start = index;
    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == x) {
            cout << "Found " << x << " at index " << index << endl;
            return;
        }
        index = (index + 1) % HASH_SIZE;
        if (index == start) break;
    }
    cout << x << " not found" << endl;
}

void remove(vector<int> &hashTable, int x) {
    int index = hash_func(x);
    int start = index;
    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == x) {
            hashTable[index] = DELETED;
            cout << "Removed " << x << " from index " << index << endl;
            return;
        }
        index = (index + 1) % HASH_SIZE;
        if (index == start) break;
    }
    cout << x << " not found, cannot remove" << endl;
}

int main() {
    vector<int> hashTable(HASH_SIZE, EMPTY);

    insert(hashTable, 12);
    insert(hashTable, 44);
    insert(hashTable, 13);
    insert(hashTable, 88);
    insert(hashTable, 23);
    insert(hashTable, 94);
    insert(hashTable, 11);
    insert(hashTable, 39);
    insert(hashTable, 20);
    insert(hashTable, 16);
    insert(hashTable, 5);

    cout << "Initial table:" << endl;
    print(hashTable);

    cout << "\nFind 23:" << endl;
    find(hashTable, 23);

    cout << "\nRemove 23:" << endl;
    remove(hashTable, 23);
    print(hashTable);

    cout << "\nFind 23 again:" << endl;
    find(hashTable, 23);

    cout << "\nInsert 99 (to reuse deleted slot):" << endl;
    insert(hashTable, 99);
    print(hashTable);

    return 0;
}
