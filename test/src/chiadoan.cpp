#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;
vector<vector<int>> result;
vector<int> inputData;
int N;
void input()
{
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        inputData.push_back(x);
    }
}
void chiadoan() {

}
int main() {
    int N; cin >> N;
    input();
}