#include<iostream>
#include<vector>
#define HASH_SIZE 11
using namespace std;
int hash_func(int x) {
    return (x * 2 + 5) % 11;
}
void insert(vector<int> &hashTable, int x) {
    int index = hash_func(x);
    while(hashTable[index] != -1) {
        index = (index + 1) % HASH_SIZE;
    }
    hashTable[index] = x;
}
void print(vector<int> &hashTable) {
    for(int i = 0; i < HASH_SIZE;i++) {
        cout << hashTable[i] << " ";
    }
}
int main() {
    vector<int> hashTable;
    for(int i = 0; i < HASH_SIZE; i++) {
        hashTable.push_back(-1);
    }
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
    print(hashTable);
    return 0;
}