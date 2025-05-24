#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> result;
bool visited[1001];
void permutation(int n)
{
    if (result.size() == n)
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            result.push_back(i);
            permutation(n);
            result.pop_back();
            visited[i] = false;
        }
    }

}
int main() {
    int n;
    memset(visited, false, sizeof(visited));
    cout << "Nhap n: ";
    cin >> n;
    permutation(n);
    return 0;
}