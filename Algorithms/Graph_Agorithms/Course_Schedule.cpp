#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> adj[1001];
        int InDegree[1001] = {0};
        // Xây dựng đồ thị
        for(auto x : prerequisites)
        {
            int v = x[0];
            int u = x[1];
            adj[u].push_back(v);
            InDegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(InDegree[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            cnt++;
            for(auto t : adj[course])
            {
                InDegree[t]--;
                if(InDegree[t] == 0)
                {
                    q.push(t);
                }
            }
        }
        return cnt == numCourses;
    }
};
int main()
{
    Solution solution;

    // Test case 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Test case 1: " << (solution.canFinish(numCourses1, prerequisites1) ? "true" : "false") << endl;

    // Test case 2
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Test case 2: " << (solution.canFinish(numCourses2, prerequisites2) ? "true" : "false") << endl;

    return 0;
}