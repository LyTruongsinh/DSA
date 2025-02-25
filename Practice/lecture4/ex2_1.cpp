// Key // value
// 12  // 7
// 44  // 5
// 13  // 9
// 88  // 5
// 23  // 7
// 94  // 6
// 11  // 5
// 39  // 6
// 20  // 1
// 16  // 4
// 5   // 4

#include <iostream>
#define HASH_SIZE 11
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
    return (x * 2 + 5) % 11;
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
        cout << tmp->val <<" -> ";
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
    chaining(12);
    chaining(44);
    chaining(13);
    chaining(88);
    chaining(23);
    chaining(94);
    chaining(11);
    chaining(39);
    chaining(20);
    chaining(16);
    chaining(5);

    cout << find(12) << "|"; print(12); cout << endl;
    cout << find(44) << "|"; print(44); cout << endl;
    cout << find(13) << "|"; print(13); cout << endl;
    cout << find(88) << "|"; print(88); cout << endl;
    cout << find(23) << "|"; print(23); cout << endl;
    cout << find(94) << "|"; print(94); cout << endl;
    cout << find(11) << "|"; print(11); cout << endl;
    cout << find(39) << "|"; print(39); cout << endl;
    cout << find(20) << "|"; print(20); cout << endl;
    cout << find(16) << "|"; print(16); cout << endl;
    cout << find(05) << "|"; print(5); cout << endl;
    return 0;
}