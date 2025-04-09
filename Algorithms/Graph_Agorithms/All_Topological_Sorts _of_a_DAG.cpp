#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int>* adj; // Adjacency list
    vector<int> indegree; // Indegree of each verte
    // Utility function for all topological sorts
    void alltopologicalSortUtil(vector<int>& res, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void alltopologicalSort();
};
// Constructor
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
    for (int i = 0; i < V; i++)
        indegree.push_back(0);
}
// Add edge v -> w
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    indegree[w]++;
}
// Recursive utility to print all topological sorts
void Graph::alltopologicalSortUtil(vector<int>& res, bool visited[]) {
    bool flag = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && indegree[i] == 0) {
            // Visit i
            visited[i] = true;
            res.push_back(i);
            for (auto it : adj[i])
                indegree[it]--;

            alltopologicalSortUtil(res, visited);

            // Backtrack
            visited[i] = false;
            res.pop_back();
            for (auto it : adj[i])
                indegree[it]++;

            flag = true;
        }
    }
    // If no unvisited node with indegree 0, then print result
    if (!flag) {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}

// Function to call the recursive util
void Graph::alltopologicalSort() {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    vector<int> res;
    alltopologicalSortUtil(res, visited);
    delete[] visited;
}

// Main
int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "All Topological sorts:\n";
    g.alltopologicalSort();

    return 0;
}
