// Key // Value
// 1   // 4
// 3   // 6
// 18  // 21
// 8   // 11
// 23  // 26
// 35  // 38
// 11  // 14
// 36  // 39
// 20  // 23
// 16  // 19

#include <iostream>
#define HASH_SIZE 10
using namespace std;
struct Node
{
    int val;
    Node *next;
};
Node *make_node(int x)
{
    Node *tmp = new Node;
    tmp->val = x;
    tmp->next = NULL;
    return tmp;
}
Node *hash_table[HASH_SIZE];
int hash_func(int x)
{
    return (x + 3);
}
void chaining(int x)
{
    int index = hash_func(x);
    Node *tmp = make_node(x);
    if (hash_table[index] == NULL)
    {
        hash_table[index] = tmp;
        return;
    }
    tmp->next = hash_table[index];
    hash_table[index] = tmp;
}
int find(int x)
{
    int index = hash_func(x);
    Node *tmp = hash_table[index];
    while (tmp != NULL)
    {
        if (tmp->val == x)
            return index;
        tmp = tmp->next;
    }
    return 0;
}

void print(int x)
{
    int index = hash_func(x);
    Node *tmp = hash_table[index];
    while (tmp != NULL)
    {
        cout << tmp->val << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL";
}
int main()
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
    chaining(1);
    chaining(3);
    chaining(18);
    chaining(8);
    chaining(23);
    chaining(35);
    chaining(11);
    chaining(36);
    chaining(20);
    chaining(16);

    cout << find(1) << "|";
    print(1);
    cout << endl;
    cout << find(3) << "|";
    print(3);
    cout << endl;
    cout << find(18) << "|";
    print(18);
    cout << endl;
    cout << find(8) << "|";
    print(8);
    cout << endl;
    cout << find(23) << "|";
    print(23);
    cout << endl;
    cout << find(35) << "|";
    print(35);
    cout << endl;
    cout << find(11) << "|";
    print(11);
    cout << endl;
    cout << find(36) << "|";
    print(36);
    cout << endl;
    cout << find(20) << "|";
    print(20);
    cout << endl;
    cout << find(16) << "|";
    print(16);
    cout << endl;
    return 0;
}